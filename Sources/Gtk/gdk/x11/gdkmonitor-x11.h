/*
 * Copyright © 2016 Red Hat, Inc
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <glib/glib.h>
#include <gio/gio.h>
#include <X11/Xlib.h>

#include "gdkmonitorprivate.h"

#include "gdkx11monitor.h"


struct _GdkX11Monitor
{
  GdkMonitor parent;

  XID output;
  guint add     : 1;
  guint remove  : 1;
};

struct _GdkX11MonitorClass {
  GdkMonitorClass parent_class;
};

