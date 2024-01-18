#include "config.h"

#include "gskdebugprivate.h"
#include "gdk/gdkprivate.h"

static const GdkDebugKey gsk_debug_keys[] = {
  { "renderer", GSK_DEBUG_RENDERER, "General renderer information" },
  { "cairo", GSK_DEBUG_CAIRO, "Cairo renderer information" },
  { "opengl", GSK_DEBUG_OPENGL, "OpenGL renderer information" },
  { "vulkan", GSK_DEBUG_VULKAN, "Vulkan renderer information" },
  { "shaders", GSK_DEBUG_SHADERS, "Information about shaders" },
  { "surface", GSK_DEBUG_SURFACE, "Information about surfaces" },
  { "fallback", GSK_DEBUG_FALLBACK, "Information about fallbacks" },
  { "glyphcache", GSK_DEBUG_GLYPH_CACHE, "Information about glyph caching" },
  { "verbose", GSK_DEBUG_VERBOSE, "Print verbose output while rendering" },
  { "geometry", GSK_DEBUG_GEOMETRY, "Show borders (when using cairo)" },
  { "full-redraw", GSK_DEBUG_FULL_REDRAW, "Force full redraws" },
  { "sync", GSK_DEBUG_SYNC, "Sync after each frame" },
  { "staging", GSK_DEBUG_STAGING, "Use a staging image for texture upload (Vulkan only)" },
};

static guint gsk_debug_flags;

static void
init_debug_flags (void)
{
  static gsize gsk_debug_flags__set;

  if (g_once_init_enter (&gsk_debug_flags__set))
    {
      gsk_debug_flags = gdk_parse_debug_var ("GSK_DEBUG",
                                             gsk_debug_keys,
                                             G_N_ELEMENTS (gsk_debug_keys));

      g_once_init_leave (&gsk_debug_flags__set, TRUE);
    }
}

gboolean
gsk_check_debug_flags (GskDebugFlags flags)
{
  init_debug_flags ();
  return (gsk_debug_flags & flags) != 0;
}

GskDebugFlags
gsk_get_debug_flags (void)
{
  init_debug_flags ();
  return gsk_debug_flags;
}

void
gsk_set_debug_flags (GskDebugFlags flags)
{
  init_debug_flags ();
  gsk_debug_flags = flags;
}
