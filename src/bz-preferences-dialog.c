/* bz-preferences-dialog.c
 *
 * Copyright 2025 Adam Masciola
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "bz-preferences-dialog.h"
#include <glib/gi18n.h>

struct _BzPreferencesDialog
{
  AdwPreferencesDialog parent_instance;

  GSettings *settings;

  /* Template widgets */
  AdwSwitchRow *git_forge_star_counts_switch;
  AdwSwitchRow *search_only_foss_switch;
  AdwSwitchRow *search_only_flathub_switch;
  AdwSwitchRow *search_debounce_switch;
  AdwSwitchRow *hide_eol_switch;
};

G_DEFINE_FINAL_TYPE (BzPreferencesDialog, bz_preferences_dialog, ADW_TYPE_PREFERENCES_DIALOG)

static void bind_settings (BzPreferencesDialog *self);

static void
bz_preferences_dialog_dispose (GObject *object)
{
  BzPreferencesDialog *self = BZ_PREFERENCES_DIALOG (object);

  g_clear_object (&self->settings);

  G_OBJECT_CLASS (bz_preferences_dialog_parent_class)->dispose (object);
}

static void
bind_settings (BzPreferencesDialog *self)
{
  if (self->settings == NULL)
    return;

  /* Bind all boolean settings to their respective switches */
  g_settings_bind (self->settings, "show-git-forge-star-counts",
                   self->git_forge_star_counts_switch, "active",
                   G_SETTINGS_BIND_DEFAULT);

  g_settings_bind (self->settings, "search-only-foss",
                   self->search_only_foss_switch, "active",
                   G_SETTINGS_BIND_DEFAULT);

  g_settings_bind (self->settings, "search-only-flathub",
                   self->search_only_flathub_switch, "active",
                   G_SETTINGS_BIND_DEFAULT);

  g_settings_bind (self->settings, "search-debounce",
                   self->search_debounce_switch, "active",
                   G_SETTINGS_BIND_DEFAULT);

  g_settings_bind (self->settings, "hide-eol",
                   self->hide_eol_switch, "active",
                   G_SETTINGS_BIND_DEFAULT);
}

static void
bz_preferences_dialog_class_init (BzPreferencesDialogClass *klass)
{
  GObjectClass   *object_class = G_OBJECT_CLASS (klass);
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  object_class->dispose = bz_preferences_dialog_dispose;

  gtk_widget_class_set_template_from_resource (widget_class, "/io/github/pureblueos/purestore/bz-preferences-dialog.ui");

  gtk_widget_class_bind_template_child (widget_class, BzPreferencesDialog, git_forge_star_counts_switch);
  gtk_widget_class_bind_template_child (widget_class, BzPreferencesDialog, search_only_foss_switch);
  gtk_widget_class_bind_template_child (widget_class, BzPreferencesDialog, search_only_flathub_switch);
  gtk_widget_class_bind_template_child (widget_class, BzPreferencesDialog, search_debounce_switch);
  gtk_widget_class_bind_template_child (widget_class, BzPreferencesDialog, hide_eol_switch);
}

static void
bz_preferences_dialog_init (BzPreferencesDialog *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

AdwDialog *
bz_preferences_dialog_new (GSettings *settings)
{
  BzPreferencesDialog *dialog = NULL;

  g_return_val_if_fail (G_IS_SETTINGS (settings), NULL);

  dialog           = g_object_new (BZ_TYPE_PREFERENCES_DIALOG, NULL);
  dialog->settings = g_object_ref (settings);
  bind_settings (dialog);

  return ADW_DIALOG (dialog);
}
