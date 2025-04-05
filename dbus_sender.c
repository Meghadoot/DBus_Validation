/**********************************

DBus Sender Validation

**********************************/


#include <dbus/dbus.h>
#include <stdio.h>
#include "dbus_common.h"

void send_signal() {
    DBusConnection *conn;
    DBusMessage *msg;
    DBusError err;

    dbus_error_init(&err);
    conn = dbus_bus_get(DBUS_BUS_SESSION, &err);

    msg = dbus_message_new_signal(DBUS_OBJECT_PATH, DBUS_INTERFACE, DBUS_SIGNAL);
    const char *content = "Hello from Sender!";
    dbus_message_append_args(msg, DBUS_TYPE_STRING, &content, DBUS_TYPE_INVALID);
    dbus_connection_send(conn, msg, NULL);
    dbus_message_unref(msg);

    printf("Signal sent.\n");
}

int main() {
    send_signal();
    return 0;
}
