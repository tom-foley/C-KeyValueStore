#include "kv_pair.h"


struct kv_pair *init_kv_pair(char *key, char *value) {
    struct kv_pair *pair = (struct kv_pair *)malloc(sizeof(struct kv_pair));

    size_t key_len = strnlen(key, MAX_KEY_LEN) + sizeof(char);
    size_t val_len = strnlen(value, MAX_VAL_LEN) + sizeof(char);

    pair->key = (char *)malloc(sizeof(char) * key_len);
    pair->value = (char *)malloc(sizeof(char) * val_len);
    
    strncpy(pair->key, key, key_len);
    strncpy(pair->value, value, val_len);

    return pair;
}


void dispose_kv_pair(struct kv_pair *pair) {
    free(pair->key);
    free(pair->value);
    free(pair);
}