#include <glib.h>
#include <iostream>

int main(int argc, char *argv[]) {
    const gchar *path = "settings.ini";

    GKeyFile *keyfile = g_key_file_new();
    GError *load_error = NULL;
    
    // load file from file
    if (!g_key_file_load_from_file(keyfile, path, G_KEY_FILE_NONE, &load_error)) {
        std::cerr << "Error: " << load_error->message << std::endl;
        g_error_free(load_error);

        // save the file
        GError *save_error = NULL;
        if (!g_key_file_save_to_file(keyfile, path, &save_error)) {
            std::cerr << "Error: " << save_error->message << std::endl;
            g_error_free(save_error);
            return 1;
        }

    }

    // set the value
    g_key_file_set_string(keyfile, "general", "name", "John Doe");

    // get the value
    GError *get_error = NULL;
    const gchar *name = g_key_file_get_string(keyfile, "general", "name", &get_error);
    if (get_error != NULL) {
        std::cerr << "Error: " << get_error->message << std::endl;
        g_error_free(get_error);
        return 1;
    }

    std::cout << "Name: " << name << std::endl;

    return 0;
}
