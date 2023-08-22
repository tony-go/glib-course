#include <glib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    GSList *list = NULL;
    list = g_slist_append(list, "Hello, ");
    list = g_slist_append(list, "World!");
    
    for (GSList *l = list; l != NULL; l = l->next) {
        printf("%s", (char*)l->data);
    }
    printf("\n");

    g_slist_free(list);
    return 0;
}

