FROM registry.fedoraproject.org/fedora:43

# Install development dependencies
RUN dnf install -y \
    appstream \
    bash-completion \
    cmake \
    desktop-file-utils \
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
    sudo \
    mesa-libGL \
    mesa-libEGL \
    mesa-dri-drivers \
    mesa-libgbm \
    mesa-vulkan-drivers \
    libglvnd-glx \
    libglvnd-egl \
    libglvnd-gles \
    && dnf clean all

# Create a non-root user
ARG USERNAME=devuser
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME
