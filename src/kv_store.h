#ifndef _KV_STORE_H
#define _KV_STORE_H

#ifndef _KV_PAIR_H
#include "kv_pair.h"
#endif

struct kv_store {
    unsigned int length;
    struct kv_pair *first;
    struct kv_pair *last;    
};

/*
 *  Allocates space for a new kv_store
 *  and sets appropriate length & kv_pair
 *  node values
 */
struct kv_store *init_kv_store();


/*
 *  Adds a kv_pair to the specified kv_store.
 *  If kv_pair was initialized before this call
 *  via init_kv_pair(), it will automatically be 
 *  freed when the kv_store is freed.
 */
void add_kv_pair(struct kv_store *, struct kv_pair *);


/*  
 *  Iterates through the specified kv_store to check
 *  if specified kv_pair exists in the store.
 *  Return 1 if kv_pair exists, 0 otherwise.
 */
int contains_key(struct kv_store *, const char *);


/*  
 *  Iterates through the specified kv_store to get
 *  the value of the specified kv_pair, assuming
 *  it exists. Returns value as a char * if the key 
 *  exists, 0 otherwise.  
 */
char *lookup_value(struct kv_store *, char *);


/*  
 *  Removes the specified kv_pair from the
 *  specified kv_store, assuming it exists.
 */
void remove_kv_pair_by_key(struct kv_store *, const char[3]);


/*  
 *  Writes the specified kv_store to the 
 *  specified file using write mode 'w+',
 *  meaning any existing file contents will
 *  be deleted beforehand.
 */
int write_kv_store_to_file(struct kv_store *, const char *);


/*  
 *  Appends the specified kv_store to the 
 *  specified file using append mode 'a+'.
 */
int append_kv_store_to_file(struct kv_store *, const char *);


/*  
 *  Frees all kv_pair's in the specified
 *  store and frees itself (the kv_store)
 *  after. If a kv_pair was initialized separately
 *  outside of the kv_store using init_kv_pair and
 *  is still in the local scope, it will be freed
 *  here as well.
 */ 
void dispose_kv_store(struct kv_store *);

#endif