# Use Fedora Toolbox image - has proper init/systemd integration like distrobox
FROM registry.fedoraproject.org/fedora-toolbox:43

# Install development dependencies
RUN dnf install -y \
    appstream \
    bash-completion \
    cmake \
    desktop-file-utils \
    flatpak \
    gcc \
    gcc-c++ \
    git \
    gettext \
    libadwaita-devel \
    libdex-devel \
    flatpak-devel \
    glycin-devel \
    glycin-gtk4-devel \
    gtk4-devel \
    lcms2-devel \
    libxmlb-devel \
    libyaml-devel \
    libsoup3-devel \
    json-glib-devel \
    md4c-devel \
    meson \
    ninja-build \
    python3-gobject \
    && dnf clean all
