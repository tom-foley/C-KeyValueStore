#include "../src/kv_store.h"
#include <stdio.h>


void print_dictionary(struct kv_store *store) {
    if (store->length) {
        struct kv_pair *current = store->first;

        while (current != NULL) {
            printf("Key:\t%s\nValue:\t%s\n\n", current->key, current->value);
            current = current->next;
        }
    }
}


int main() {
    struct kv_store *store = init_kv_store();
    struct kv_pair *pair;
    
    printf("Adding...\n");
    pair = init_kv_pair("Key1", "Value1");
    add_kv_pair(store, pair);

    pair = init_kv_pair("Key2", "Value2");
    add_kv_pair(store, pair);

    pair = init_kv_pair("Key3", "Value3");
    add_kv_pair(store, pair);

    pair = init_kv_pair("Key4", "Value4");
    add_kv_pair(store, pair);

    pair = init_kv_pair("Key5", "Value5");
    add_kv_pair(store, pair);

    pair = init_kv_pair("Key6", "Value6");
    add_kv_pair(store, pair);

    pair = init_kv_pair("Key7", "Value7");
    add_kv_pair(store, pair);

    pair = init_kv_pair("Key8", "Value8");
    add_kv_pair(store, pair);

    pair = init_kv_pair("Key9", "Value9");
    add_kv_pair(store, pair);

    add_kv_pair(store, init_kv_pair("Key10", "Value10"));
    add_kv_pair(store, init_kv_pair("Key11", "Value11"));
    add_kv_pair(store, init_kv_pair("Key12", "Value12"));
    add_kv_pair(store, init_kv_pair("Key13", "Value13"));
    add_kv_pair(store, init_kv_pair("Key14", "Value14"));
    add_kv_pair(store, init_kv_pair("Key15", "Value15"));

    print_dictionary(store);
    write_kv_store_to_file(store, "output.txt");
    append_kv_store_to_file(store, "output.txt");

    printf("Removing...\n");
    remove_kv_pair_by_key(store, "Key1");
    remove_kv_pair_by_key(store, "Key3");
    remove_kv_pair_by_key(store, "Key5");
    remove_kv_pair_by_key(store, "Key7");
    remove_kv_pair_by_key(store, "Key9");

    print_dictionary(store);

    printf("Checking...\n");
    printf("Contains 'Key15':\t%s\n", 
        contains_key(store, "Key15") ? "true" : "false"
    );

    printf("Contains 'Key16':\t%s\n", 
        contains_key(store, "Key16") ? "true" : "false"
    );    

    
    dispose_kv_store(store);
    return 0;
}