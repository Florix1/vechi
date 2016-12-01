/*-- testLG.c -- hash table */
#include "tlg.h"
#include "hashMap.h"
#include <string.h>


void printExNr(int exNr)
{
  printf("***************");
  printf(" EX number %d ", exNr);
  printf("***************\n");
}

void test_get(char *key, THMG hash_map)
{
  printf("GET result for %s: %s\n", key, get(key, hash_map));
}

//*********** Functii laborator *********
void AfiEntry(void * ae)
{
  //TO DO
  TEntry p = *(TEntry*)ae;
  printf("[%s %s] ", p.name, p.phone_nr);
}

int hash_function(char *key)
{
  //TO DO
  int i, cod = 0;
  int l = strlen(key);
  for (i = 0; i < l; i++) {
    cod = cod + key[i];
  }
  return cod;
}

int put(char *key, char *value, THMG hash_map)
{
  //TO DO
  int cod;
  TLG p;
  TEntry *d;

  d = (TEntry*) calloc(1, sizeof(TEntry));
  strcpy(d->name, key);
  strcpy(d->phone_nr, value);
  cod = hash_function(key) % hash_map->length;
 
  for (p = hash_map->vector[cod]; p != NULL; p = p->urm)
  {
    TEntry* el = (TEntry*)p->info;
    if (strcmp(el->name, d->name) == 0) {
      memcpy(el, d, sizeof(TEntry));
      return 0;
    }
  }
  InsLG (hash_map->vector + cod, d, sizeof(TEntry));
  free(d);
 
  return 0;
}

char *get(char *key, THMG hash_map)
{
  //TO DO
  int cod;
  TLG p;
  
  cod = hash_function(key) % hash_map->length;
  for (p = hash_map->vector[cod]; p != NULL; p = p->urm)
  {
    TEntry* d = (TEntry*)p->info;
    if (strcmp(d->name, key) == 0) {
      //printf("%s", ((TEntry*)p->info)->phone_nr);
      return d->phone_nr;
    }
  }
  
  return NULL;
}

int remove_el (char *key, THMG hash_map)
{
  int cod;
  TLG p, ant = NULL, aux;
  
  cod = hash_function(key) % hash_map->length;
  
  for (p = hash_map->vector[cod]; p != NULL; p = p->urm)
  {
    TEntry* d = (TEntry*)p->info;
    if (strcmp(d->name, key) == 0) {
      if (ant == NULL) {
        aux = p;
        hash_map->vector[cod] = p->urm;
        free(aux);
      }
      else {
        aux = p;
        ant->urm = p->urm;
        free(aux);
      }
	
      return 1;
    }
    ant = p;
  }

  return 0;
}
//***********************************************


int main()
{ 
  THMG hash_map = NULL;

  hash_map = alocaHashMap(2);
  printHashMap(hash_map);

  /* secvente de test */
  printExNr(1);
  //ex1: test hash function and print function

  printExNr(2);
  //ex2: test put function
  put("ana", "07245897568", hash_map);
  put("maria", "0722222222", hash_map);
  put("ionel", "07241117568", hash_map);
  put("ana", "0777777777", hash_map);
  put("boc", "07245897444", hash_map);
  put("cristiii", "0727777444", hash_map);
  printHashMap(hash_map);

  printExNr(3);
  //ex3: test get function
  test_get("ana", hash_map);
  test_get("maria", hash_map);
  test_get("a#aa", hash_map);
  test_get("boc", hash_map);
  test_get("cristiii", hash_map);
 
  //ex4: functia remove
  remove_el("cristiii", hash_map);
  printHashMap(hash_map);
  

  destroyHashMap(&hash_map);


  return 0;
}
