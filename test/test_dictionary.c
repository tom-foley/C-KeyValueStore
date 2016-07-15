#include "../src/dictionary.h"
#include <stdio.h>


void print_dictionary(struct dictionary *dictionary) {
    if (dictionary->length) {
        struct kv_pair *current = dictionary->first;

        while (current != NULL) {
            printf("Key:\t%s\nValue:\t%s\n\n", current->key, current->value);
            current = current->next;
        }
    }
}


int main() {
    struct dictionary *dictionary = init_dictionary();
    struct kv_pair *pair;
    
    printf("Adding...\n");
    pair = init_kv_pair("Key1", "Value1");
    add_kv_pair(dictionary, pair);

    pair = init_kv_pair("Key2", "Value2");
    add_kv_pair(dictionary, pair);

    pair = init_kv_pair("Key3", "Value3");
    add_kv_pair(dictionary, pair);

    pair = init_kv_pair("Key4", "Value4");
    add_kv_pair(dictionary, pair);

    pair = init_kv_pair("Key5", "Value5");
    add_kv_pair(dictionary, pair);

    pair = init_kv_pair("Key6", "Value6");
    add_kv_pair(dictionary, pair);

    pair = init_kv_pair("Key7", "Value7");
    add_kv_pair(dictionary, pair);

    pair = init_kv_pair("Key8", "Value8");
    add_kv_pair(dictionary, pair);

    pair = init_kv_pair("Key9", "Value9");
    add_kv_pair(dictionary, pair);

    add_kv_pair(dictionary, init_kv_pair("Key10", "Value10"));
    add_kv_pair(dictionary, init_kv_pair("Key11", "Value11"));
    add_kv_pair(dictionary, init_kv_pair("Key12", "Value12"));
    add_kv_pair(dictionary, init_kv_pair("Key13", "Value13"));
    add_kv_pair(dictionary, init_kv_pair("Key14", "Value14"));
    add_kv_pair(dictionary, init_kv_pair("Key15", "Value15"));

    print_dictionary(dictionary);

    printf("Removing...\n");
    remove_kv_pair_by_key(dictionary, "Key1");
    remove_kv_pair_by_key(dictionary, "Key3");
    remove_kv_pair_by_key(dictionary, "Key5");
    remove_kv_pair_by_key(dictionary, "Key7");
    remove_kv_pair_by_key(dictionary, "Key9");

    print_dictionary(dictionary);

    printf("Checking...\n");
    printf("Contains 'Key15':\t%s\n", 
            contains_key(dictionary, "Key15") ? "true" : "false"
    );

    printf("Contains 'Key16':\t%s\n", 
            contains_key(dictionary, "Key16") ? "true" : "false"
    );    

    
    dispose_dictionary(dictionary);
    return 0;
}