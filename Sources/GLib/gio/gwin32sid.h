/* GIO - GLib Input, Output and Streaming Library
 *
 * Copyright (C) 2018 Руслан Ижбулатов
 * Copyright (C) 2022 Red Hat, Inc.
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
 * Author: Руслан Ижбулатов <lrn1986@gmail.com>
 */

#ifndef __G_WIN32_SID_H__
#define __G_WIN32_SID_H__

#include <glib/glib.h>
#include <windows.h>

G_BEGIN_DECLS

SID      * _g_win32_process_get_access_token_sid         (DWORD    process_id,
                                                          GError **error);

gchar    * _g_win32_sid_to_string                        (SID     *sid,
                                                          GError **error);

gchar    * _g_win32_current_process_sid_string           (GError **error);

G_END_DECLS

#endif /* __G_WIN32_SID_H__ */
