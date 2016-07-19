#include "kv_store.h"


struct kv_store *init_kv_store() {
    struct kv_store *store = (struct kv_store *)malloc(sizeof(struct kv_store));
    store->length = 0;
    store->first = NULL;
    store->last = NULL;
    return store;
}


void add_kv_pair(struct kv_store *store, struct kv_pair *pair) {
    if (store->length >= 2) {
        struct kv_pair *last = store->last;
        last->next = pair;
        pair->prev = last;
        pair->next = NULL;

        store->last = pair;
    } else if (store->length) {
        //  We can use pointer to store->last
        store->first->next = pair;
        pair->prev = store->first;
        pair->next = NULL;

        store->last = pair;
    } else {
        //  We can use pointer to store->first
        pair->prev = NULL;
        pair->next = NULL;

        store->first = pair;
    }

    store->length++;
}


int contains_key(struct kv_store *store, const char *key) {
    if (store->length) {
        struct kv_pair *current = store->first;

        while (current != NULL) {
            if (!strncmp(current->key, key, MAX_KEY_LEN)) {
                return 1;
            }

            current = current->next;
        }
    }

    return 0;
}


char *lookup_value(struct kv_store *store, char *key) {
    if (store->length) {
        struct kv_pair *current = store->first;

        while (current != NULL) {
            if (!strncmp(current->key, key, MAX_KEY_LEN)) {
                return current->value;
            }

            current = current->next;
        }
    }

    return 0;
}


void remove_kv_pair_by_key(struct kv_store *store, const char *key) {
    if (store->length) {
        struct kv_pair *current = store->first;

        while (current != NULL) {
            if (!strncmp(current->key, key, MAX_KEY_LEN)) {
                if (current->prev == NULL && current->next == NULL) {
                    dispose_kv_pair(current);
                } else if (current->prev == NULL) {
                    current->next->prev = NULL;
                    store->first = current->next;

                    dispose_kv_pair(current); 
                } else if (current->next == NULL) {
                    current->prev->next = NULL;
                    store->last = current->prev;

                    dispose_kv_pair(current);
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;

                    dispose_kv_pair(current);
                }

                store->length--;
                break;
            } else {
                current = current->next;
            }
        }
    }
}


int write_to_file(struct kv_store *store, const char *file_name, const char mode[3]) {
    if (!store->length) {
        return 0;
    }

    FILE *fp;

    fp = fopen(file_name, mode);
    if (fp == NULL) {
        //  Error opening file
        return 0;
    } else {
        if (!strncmp(mode, "w+", 3)) {
            fprintf(fp, "%25s\t%.100s\n", "Key", "Value");
            fprintf(fp, "%25s\t%.100s\n", "===", "=====");
        }

        struct kv_pair *current = store->first;
        while (current != NULL) {
            fprintf(fp, "%25s\t%.100s\n", current->key, current->value);
            current = current->next;
        }

        fclose(fp);
        return 1;
    }
}


int write_kv_store_to_file(struct kv_store *store, const char *file_name) {
    return write_to_file(store, file_name, "w+");
}


int append_kv_store_to_file(struct kv_store *store, const char *file_name) {
    return write_to_file(store, file_name, "a+");
}


void dispose_kv_store(struct kv_store *store) {
    if (store->length) {
        struct kv_pair *current = store->first;
        struct kv_pair *next;

        while (current != NULL) {
            next = current->next;
            dispose_kv_pair(current);
            current = next;
            store->length--;
        }
        free(store);
    }
}