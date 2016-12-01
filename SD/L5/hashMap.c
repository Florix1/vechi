#include "tlg.h"
#include "hashMap.h"

int compKey(char *key, void *ae)
{
  TEntry a = *(TEntry*)ae;
  
  return strcmp(key, a.name);
}

THMG alocaHashMap(size_t length)
{
  THMG hash_map = NULL;
  int i;

  hash_map = malloc(sizeof(THashMapG));
  hash_map->length = length;

  hash_map->vector = malloc(sizeof(TLG) * length);
  for (i = 0; i < length; i++)
  	hash_map->vector[i] = NULL;

  return hash_map;
}

void destroyHashMap(AHMG hash_map)
{
  int i;

  THMG aux = *hash_map;
  

  for (i = 0; i < aux->length; i++) {
    TLG curr_bucket = aux->vector[i];

  	Distruge(&curr_bucket);
  }

  free(aux->vector);
  free(aux);
  aux = NULL;
}

void printHashMap(THMG hash_map)
{
  int i;

  for (i = 0; i < hash_map->length; i++) {
  	printf("[%d]: ", i);

  	Afisare(&hash_map->vector[i], AfiEntry);
  }
}