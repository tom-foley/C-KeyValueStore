#ifndef _KV_PAIR_H
#define _KV_PAIR_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#define MAX_KEY_LEN     30
#define MAX_VAL_LEN    100

struct kv_pair {
    char *key;
    char *value;
    struct kv_pair *prev;
    struct kv_pair *next;
};


/*
 *  Allocates space for a new kv_pair
 *  and sets appropriate length & kv_pair
 *  node values
 */
struct kv_pair *init_kv_pair(const char *, const char *);


/*
 *  Frees all memory held by specified kv_pair
 */
void dispose_kv_pair(struct kv_pair *);

#endif