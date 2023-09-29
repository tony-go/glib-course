#include <glib.h>
#include <iostream>
#include <gio/gio.h>

int main(int argc, char *argv[]) {
    // Initialize GSettings with your schema
    GSettings *settings = g_settings_new("com.tonygo.app");

    // Set a value
    g_settings_set_string(settings, "example-key", "new_value");

    // Read the value back
    gchar *value = g_settings_get_string(settings, "example-key");
    g_print("Read value: %s\n", value);

    // Clean up
    g_free(value);
    g_object_unref(settings);

    return 0;
}
