#ifndef _KV_PAIR_H
#define _KV_PAIR_H

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#define MAX_KEY_LEN     30
#define MAX_VAL_SIZE    100

struct kv_pair {
    char *key;
    char *value;
    struct kv_pair *prev;
    struct kv_pair *next;
};

struct kv_pair *init_kv_pair(char *, char *);
void dispose_kv_pair(struct kv_pair *);

#endif