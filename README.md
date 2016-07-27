## CKeyValueStore
A C library which implements a standard key value store(dictionary) data type, giving the ability to dynamically add and remove from the store's memory without initializing it as a fixed width structure.

### Current Functionality
* creating `kv_pair`'s and `kv_store`'s to store them
* adding `kv_pair`'s to `kv_store`
* searching the dictionary to see if `kv_pair`'s exist
* searching the dictionary to get the value of a specific `kv_pair` based on the key
* removing `key_value_pair`'s from the dictionary
* writing/appending `kv_store`'s to a specified file
