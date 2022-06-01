/*
 *  Copyright 2020-2022 Jesse Lentz
 *
 *  This file is part of iwgtk.
 *
 *  iwgtk is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  iwgtk is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with iwgtk.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _IWGTK_MAIN_H
#define _IWGTK_MAIN_H

typedef struct GlobalData_s GlobalData;

#define WINDOW_LAUNCH_PENDING (1 << 0)
#define IWD_DOWN (1 << 1)

struct GlobalData_s {
    GtkApplication *application;
    GDBusObjectManager *manager;
    GQuark iwd_error_domain;

    Window *window;
    Indicator *indicators;

    gboolean indicators_enable;
    gboolean notifications_disable;
    guint8 state;
};

extern GlobalData global;

void object_manager_callback(GDBusObjectManagerClient *manager, GAsyncResult *res);
void iwd_up(GDBusConnection *connection);
void iwd_down(GDBusConnection *connection);
void startup(GtkApplication *app);
gint handle_local_options(GApplication *application, GVariantDict *options);
gint command_line(GApplication *application, GApplicationCommandLine *command_line);
void shutdown();

#endif
