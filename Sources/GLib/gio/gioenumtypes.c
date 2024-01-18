/*** BEGIN file-header ***/
/*
 * Copyright © 2007 Red Hat, Inc.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Matthias Clasen <mclasen@redhat.com>
 */

#ifndef GLIB_DISABLE_DEPRECATION_WARNINGS
#define GLIB_DISABLE_DEPRECATION_WARNINGS
#endif

#include "config.h"
#include "gioenumtypes.h"
#include <gio.h>

/*** END file-header ***/

/*** BEGIN file-production ***/
/* enumerations from "@filename@" */
/*** END file-production ***/

/*** BEGIN value-header ***/
GType
g_app_info_create_flags_get_type (void)
{
  static GType static_g_define_type_id = 0;

  if (g_once_init_enter_pointer (&static_g_define_type_id))
    {
      static const GAppInfoCreateFlags values[] = {
/*** END value-header ***/

/*** BEGIN value-production ***/
        { G_APP_INFO_CREATE_NONE, "G_APP_INFO_CREATE_NONE", "app-info-create-none" },
        { G_APP_INFO_CREATE_NEEDS_TERMINAL, "G_APP_INFO_CREATE_NEEDS_TERMINAL", "app-info-create-needs-terminal" },
        { G_APP_INFO_CREATE_SUPPORTS_URIS, "G_APP_INFO_CREATE_SUPPORTS_URIS", "app-info-create-supports-uris" },
        { G_APP_INFO_CREATE_SUPPORTS_STARTUP_NOTIFICATION, "G_APP_INFO_CREATE_SUPPORTS_STARTUP_NOTIFICATION", "app-info-create-supports-startup-notification" },
/*** END value-production ***/

/*** BEGIN value-tail ***/
        { 0, NULL, NULL }
      };
      GType g_define_type_id =
        g_app_info_create_flags_register_static (g_intern_static_string ("GAppInfoCreateFlagsEnum"), values);
      g_once_init_leave_pointer (&static_g_define_type_id, g_define_type_id);
    }

  return static_g_define_type_id;
}

/*** END value-tail ***/