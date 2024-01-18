// swift-tools-version: 5.5
import PackageDescription

let package = Package(
  name: "GNOME",

  // --- 📦 Package Products. ---
  products: [
    .library(
      name: "GLibConf",
      targets: ["GLibConf"]
    ),
    .library(
      name: "GLib",
      targets: ["GLib"]
    ),
    .library(
      name: "Gtk",
      targets: ["Gtk"]
    ),
  ],

  // --- 🦄 Package Dependencies. ---
  dependencies: [],

  // --- 🎯 Package Targets. ---
  targets: [
    .target(
      name: "GLibConf",
      path: "Sources/GLibConf",
      publicHeadersPath: "."
    ),
    .target(
      name: "GLib",
      dependencies: [
        .target(name: "GLibConf")
      ],
      path: "Sources/GLib",
      exclude: [
        "glib/tests",
      ],
      sources: [
        "gio",
        "gvdb",
        "proxy-libintl",
        "gmodule",
        "glib",
      ],
      publicHeadersPath: ".",
      cSettings: [
        .headerSearchPath("gio"),
        .headerSearchPath("glib"),
        .headerSearchPath("gvdb"),
        .headerSearchPath("proxy-libintl"),
        .headerSearchPath("gmodule"),
      ]
    ),
    .target(
      name: "Gtk",
      dependencies: [
        .target(name: "GLib")
      ],
      path: "Sources/Gtk",
      exclude: [
        "gtk/theme",
        "gtk/ui",
        "gtk/timsort/COPYING",
        "gtk/timsort/README.md",
        "gtk/text-input-unstable-v3.xml",
        "gtk/print/ui/gtkpagesetupunixdialog.ui",
        "gtk/print/ui/gtkprintunixdialog.ui",
        "gtk/print/meson.build",
        "gtk/roaring/COPYING",
        "gtk/roaring/README.md"
      ],
      sources: [
        "gtk",
        "gdk"
      ],
      publicHeadersPath: "."
    ),
  ],
  cLanguageStandard: .gnu17
)
