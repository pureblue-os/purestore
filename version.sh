#!/bin/sh

INSTR="$1"

VERSION=0.5.11
DATE_PART="$(date +%Y%m%d)"
INCREMENT=1

# Determine git root directory
GIT_DIR="${MESON_SOURCE_ROOT:-.}"

# Try to find existing tags for today and increment
if command -v git >/dev/null 2>&1 && [ -d "$GIT_DIR/.git" ]; then
    LATEST_TAG="$(git -C "$GIT_DIR" tag -l "${VERSION}.pure.${DATE_PART}.*" | sort -V | tail -n1)"
    if [ -n "$LATEST_TAG" ]; then
        # Extract the increment number from the last tag
        LAST_INCREMENT="$(echo "$LATEST_TAG" | sed -E "s/.*\.([0-9]+)$/\1/")"
        INCREMENT=$((LAST_INCREMENT + 1))
    fi
fi

PURE_SUFFIX=".pure.${DATE_PART}.${INCREMENT}"

case "$INSTR" in
    get-vcs)
        VCS_VERSION="$(git -C "$GIT_DIR" rev-parse --short HEAD 2>/dev/null)"
        if [ -n "$VCS_VERSION" ]; then
            # Check if working directory is dirty
            if ! git -C "$GIT_DIR" diff-index --quiet HEAD 2>/dev/null; then
                VCS_VERSION="${VCS_VERSION}-dirty"
            fi
            echo "${VERSION}${PURE_SUFFIX} (vcs=${VCS_VERSION})"
        else
            echo "${VERSION}${PURE_SUFFIX}"
        fi
        ;;
    get-version)
        echo "${VERSION}${PURE_SUFFIX}"
        ;;
    *)
        echo invalid arguments 1>&2
        exit 1
        ;;
esac
