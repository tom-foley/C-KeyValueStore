#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#ifndef _KV_PAIR_H
#include "kv_pair.h"
#endif

struct dictionary {
    unsigned int length;
    struct kv_pair *first;
    struct kv_pair *last;    
};

struct dictionary *init_dictionary();

void add_kv_pair(struct dictionary *, struct kv_pair *);

int contains_key(struct dictionary *, char *);

void remove_kv_pair_by_key(struct dictionary *, char *);

void dispose_dictionary(struct dictionary *);

#endif