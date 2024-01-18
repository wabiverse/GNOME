/* GTK - The GIMP Toolkit
 * gtkprintbackendcpdb.h: Default implementation of GtkPrintBackend
 * for the Common Print Dialog Backends (CPDB)
 * Copyright (C) 2022, 2023 TinyTrebuchet <tinytrebuchet@protonmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __GTK_PRINT_BACKEND_CPDB_H__
#define __GTK_PRINT_BACKEND_CPDB_H__

#include <glib/glib-object.h>
#include <gtk/gtk.h>
#include "gtk/print/gtkprintbackendprivate.h"

G_BEGIN_DECLS

#define GTK_TYPE_PRINT_BACKEND_CPDB             (gtk_print_backend_cpdb_get_type ())
#define GTK_PRINT_BACKEND_CPDB(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_PRINT_BACKEND_CPDB, GtkPrintBackendCpdb))
#define GTK_IS_PRINT_BACKEND_CPDB(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_PRINT_BACKEND_CPDB))

typedef struct _GtkPrintBackendCpdbClass GtkPrintBackendCpdbClass;
typedef struct _GtkPrintBackendCpdb      GtkPrintBackendCpdb;

GtkPrintBackend  *gtk_print_backend_cpdb_new        (void);
GType             gtk_print_backend_cpdb_get_type   (void) G_GNUC_CONST;

G_END_DECLS

#endif /* __GTK_PRINT_BACKEND_CPDB_H__ */

