#include "dictionary.h"


struct dictionary *init_dictionary() {
    struct dictionary *dictionary = (struct dictionary *)malloc(sizeof(struct dictionary));
    dictionary->length = 0;
    dictionary->first = NULL;
    dictionary->last = NULL;
    return dictionary;
}


void add_kv_pair(struct dictionary *dictionary, struct kv_pair *pair) {
    if (dictionary->length >= 2) {
        struct kv_pair *last = dictionary->last;
        last->next = pair;
        pair->prev = last;
        pair->next = NULL;

        dictionary->last = pair;
    } else if (dictionary->length) {
        //  We can use pointer to dictionary->last
        dictionary->first->next = pair;
        pair->prev = dictionary->first;
        pair->next = NULL;

        dictionary->last = pair;
    } else {
        //  We can use pointer to dictionary->first
        pair->prev = NULL;
        pair->next = NULL;

        dictionary->first = pair;
    }

    dictionary->length++;
}


int contains_key(struct dictionary *dictionary, char *key) {
    if (dictionary->length) {
        struct kv_pair *current = dictionary->first;

        while (current != NULL) {
            if (!strncmp(current->key, key, MAX_KEY_LEN)) {
                return 1;
            }

            current = current->next;
        }
    }

    return 0;
}


void remove_kv_pair_by_key(struct dictionary *dictionary, char *key) {
    if (dictionary->length) {
        struct kv_pair *current = dictionary->first;

        while (current != NULL) {
            if (!strncmp(current->key, key, MAX_KEY_LEN)) {
                if (current->prev == NULL && current->next == NULL) {
                    dispose_kv_pair(current);
                } else if (current->prev == NULL) {
                    current->next->prev = NULL;
                    dictionary->first = current->next;

                    dispose_kv_pair(current); 
                } else if (current->next == NULL) {
                    current->prev->next = NULL;
                    dictionary->last = current->prev;

                    dispose_kv_pair(current);
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;

                    dispose_kv_pair(current);
                }

                dictionary->length--;
                break;
            } else {
                current = current->next;
            }
        }
    }
}


void dispose_dictionary(struct dictionary *dictionary) {
    if (dictionary->length) {
        struct kv_pair *current = dictionary->first;
        struct kv_pair *next;

        while (current != NULL) {
            next = current->next;
            dispose_kv_pair(current);
            current = next;
            dictionary->length--;
        }
        free(dictionary);
    }
}