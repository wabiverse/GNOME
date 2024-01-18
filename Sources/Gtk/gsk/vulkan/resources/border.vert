#version 450

#include "clip.vert.glsl"
#include "rounded-rect.glsl"

layout(location = 0) in mat3x4 inRect;
layout(location = 3) in vec4 inBorderWidths;
layout(location = 4) in mat4 inBorderColors;

layout(location = 0) out vec2 outPos;
layout(location = 1) out flat vec4 outColor;
layout(location = 2) out flat RoundedRect outRect;
layout(location = 5) out flat vec4 outBorderWidths;

vec2 offsets[6] = { vec2(0.0, 0.0),
                    vec2(1.0, 0.0),
                    vec2(0.0, 1.0),
                    vec2(1.0, 1.0),
                    vec2(0.0, 1.0),
                    vec2(1.0, 0.0) };

#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3

#define TOP_LEFT 0
#define TOP_RIGHT 1
#define BOTTOM_RIGHT 2
#define BOTTOM_LEFT 3

#define SLICE_TOP_LEFT 0
#define SLICE_TOP 1
#define SLICE_TOP_RIGHT 2
#define SLICE_RIGHT 3
#define SLICE_BOTTOM_RIGHT 4
#define SLICE_BOTTOM 5
#define SLICE_BOTTOM_LEFT 6
#define SLICE_LEFT 7

void main() {
  int slice_index = gl_VertexIndex / 6;
  int vert_index = gl_VertexIndex % 6;

  vec4 corner_widths = max (inRect[1], inBorderWidths.wyyw);
  vec4 corner_heights = max (inRect[2], inBorderWidths.xxzz);

  Rect rect;

  switch (slice_index)
    {
    case SLICE_TOP_LEFT:
      rect = rect_from_gsk (vec4(inRect[0].xy, corner_widths[TOP_LEFT], corner_heights[TOP_LEFT]));
      rect = rect_round_larger (rect);
      vert_index = (vert_index + 3) % 6;
      break;
    case SLICE_TOP:
      rect = rect_from_gsk (vec4(inRect[0].x + corner_widths[TOP_LEFT], inRect[0].y, inRect[0].z - corner_widths[TOP_LEFT] - corner_widths[TOP_RIGHT], inBorderWidths[TOP]));
      rect = rect_round_smaller_larger (rect);
      outColor = inBorderColors[TOP];
      break;
    case SLICE_TOP_RIGHT:
      rect = rect_from_gsk (vec4(inRect[0].x + inRect[0].z - corner_widths[TOP_RIGHT], inRect[0].y, corner_widths[TOP_RIGHT], corner_heights[TOP_RIGHT]));
      rect = rect_round_larger (rect);
      break;
    case SLICE_RIGHT:
      rect = rect_from_gsk (vec4(inRect[0].x + inRect[0].z - inBorderWidths[RIGHT], inRect[0].y + corner_heights[TOP_RIGHT], inBorderWidths[RIGHT], inRect[0].w - corner_heights[TOP_RIGHT] - corner_heights[BOTTOM_RIGHT]));
      rect = rect_round_larger_smaller (rect);
      outColor = inBorderColors[RIGHT];
      break;
    case SLICE_BOTTOM_RIGHT:
      rect = rect_from_gsk (vec4(inRect[0].x + inRect[0].z - corner_widths[BOTTOM_RIGHT], inRect[0].y + inRect[0].w - corner_heights[BOTTOM_RIGHT], corner_widths[BOTTOM_RIGHT], corner_heights[BOTTOM_RIGHT]));
      rect = rect_round_larger (rect);
      break;
    case SLICE_BOTTOM:
      rect = rect_from_gsk (vec4(inRect[0].x + corner_widths[BOTTOM_LEFT], inRect[0].y + inRect[0].w - inBorderWidths[BOTTOM], inRect[0].z - corner_widths[BOTTOM_LEFT] - corner_widths[BOTTOM_RIGHT], inBorderWidths[BOTTOM]));
      rect = rect_round_smaller_larger (rect);
      break;
    case SLICE_BOTTOM_LEFT:
      rect = rect_from_gsk (vec4(inRect[0].x, inRect[0].y + inRect[0].w - corner_heights[BOTTOM_LEFT], corner_widths[BOTTOM_LEFT], corner_heights[BOTTOM_LEFT]));
      vert_index = (vert_index + 3) % 6;
      rect = rect_round_larger (rect);
      break;
    case SLICE_LEFT:
      rect = rect_from_gsk (vec4(inRect[0].x, inRect[0].y + corner_heights[TOP_LEFT], inBorderWidths[LEFT], inRect[0].w - corner_heights[TOP_LEFT] - corner_heights[BOTTOM_LEFT]));
      rect = rect_round_larger_smaller (rect);
      break;
    }

  rect = clip_rect (rect);

  vec2 pos;
  if ((slice_index % 4) != 0 || (vert_index % 3) != 2)
    pos = mix (rect.bounds.xy, rect.bounds.zw, offsets[vert_index]);
  else
    pos = mix (rect.bounds.zy, rect.bounds.xw, offsets[vert_index]);
  gl_Position = push.mvp * vec4 (pos, 0.0, 1.0);
  outColor = inBorderColors[((gl_VertexIndex / 3 + 15) / 4) % 4];
  outPos = pos;
  outRect = RoundedRect(inRect[0].xyxy + vec4(0,0,inRect[0].zw), inRect[1], inRect[2]);
  outRect = rounded_rect_scale (outRect, push.scale);
  outBorderWidths = inBorderWidths * push.scale.yxyx;
}
