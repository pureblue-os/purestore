# Store

A modern app store for GNOME that lets you discover and install applications from Flatpak remotes, particularly [Flathub](https://flathub.org/).

![Screenshot showing Store's Flathub page](screenshots/flathub.png)

Store is fast and highly multi-threaded, providing a smooth browsing experience. You can queue multiple downloads and run them simultaneously while exploring apps. It runs as a service, maintaining state even when windows are closed, and integrates with GNOME Shell search.

## Features

- Fast & responsive multi-threaded architecture
- Queue and manage multiple downloads simultaneously
- Runs as a background service
- GNOME Shell search integration
- Curated content support for distributors

## Extra Features
- While uninstalling you have option to also delete or leave app data.

## Build and Run

```sh
meson setup build --prefix=/usr/local
ninja -C build
sudo ninja -C build install
purestore
```

---

This repo is a minimal fork of [kolunmi/bazaar](https://github.com/kolunmi/bazaar), go support the original project

---

Don't expect updates to this fork. This project will be replaced by [pureblue-os/apps](https://github.com/pureblue-os/apps).
