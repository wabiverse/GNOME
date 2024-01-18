#ifndef __GDKCONFIG_H__
#define __GDKCONFIG_H__

#if !defined (__GDK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gdk/gdk.h> can be included directly."
#endif

#include <glib/glib.h>

G_BEGIN_DECLS


#if defined(__linux__)
# define GDK_WINDOWING_X11
#else /* !defined(__linux__) */
# undef GDK_WINDOWING_X11
#endif /* defined(__linux__) */

#undef GDK_WINDOWING_BROADWAY

#if defined(__APPLE__)
# define GDK_WINDOWING_MACOS
#else /* !defined(__APPLE__) */
# undef GDK_WINDOWING_MACOS
#endif /* defined(__APPLE__) */

#undef GDK_WINDOWING_WAYLAND

#if defined(_WIN32) || defined(_WIN64)
# define GDK_WINDOWING_WIN32
#else /* !defined(__APPLE__) */
# undef GDK_WINDOWING_WIN32
#endif /* defined(__APPLE__) */

#define GDK_RENDERING_CAIRO
#define GDK_RENDERING_GL
#undef GDK_RENDERING_VULKAN

G_END_DECLS

#endif  /* __GDKCONFIG_H__ */
