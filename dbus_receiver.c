/*****************************************************

Dbus Reception/Listner Validation

*****************************************************/


#include <dbus/dbus.h>
#include <stdio.h>
#include "dbus_common.h"

int main() {
    DBusError err;
    DBusConnection* conn;

    dbus_error_init(&err);
    conn = dbus_bus_get(DBUS_BUS_SESSION, &err);
    dbus_bus_request_name(conn, DBUS_SERVICE, DBUS_NAME_FLAG_REPLACE_EXISTING, &err);

    // Add signal match rule
    char match_rule[256];
    snprintf(match_rule, sizeof(match_rule),
             "type='signal',interface='%s'", DBUS_INTERFACE);
    dbus_bus_add_match(conn, match_rule, &err);
    dbus_connection_flush(conn);

    printf("Listening for D-Bus signals...\n");

    while (1) {
        dbus_connection_read_write(conn, 0);
        DBusMessage* msg = dbus_connection_pop_message(conn);

        if (msg == NULL) continue;

        if (dbus_message_is_signal(msg, DBUS_INTERFACE, DBUS_SIGNAL)) {
            const char* content;
            dbus_message_get_args(msg, &err, DBUS_TYPE_STRING, &content, DBUS_TYPE_INVALID);
            printf("Received signal: %s\n", content);
        }
        dbus_message_unref(msg);
    }

    return 0;
}
