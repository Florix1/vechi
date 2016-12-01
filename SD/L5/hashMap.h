#include "tlg.h"

typedef struct hashmapg
{
	TLG *vector;
	int length;
} THashMapG, *THMG, **AHMG;

typedef struct { char name[20], phone_nr[11]; } TEntry; /* struct name and telephone nr */

void AfiEntry(void * ae);

// fucntion used to comapare key with name from a TEntry struct
int compKey(char *key, void *ae);

THMG alocaHashMap(size_t length);

void destroyHashMap(AHMG hash_map);

void printHashMap(THMG hash_map);

//function used to compute the hash code from a key
int hash_function(char *key);

int put(char *key, char *value, THMG hash_map);

char *get(char *key, THMG hash_map);
