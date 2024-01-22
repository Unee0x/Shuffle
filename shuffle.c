#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLEN 10

#define MIN 0
#define MAX 8


int getrand(int min, int max){
  int r = rand() % max + min;
  return r;
}

void *mkarray(){
  int *array = malloc(sizeof(int) * MAXLEN);
  
  array[MAXLEN-1] = '\0';
  if(!array)
    perror("Empty Array");

  static int i = 0;
  int j = 0;
  while(j < MAXLEN-1){
    array[j] = ++i;
    j++;
  }
  return array;
}

void swap( int a, int  b ){
  int *t;
  int *x = malloc(sizeof(a));
  x = &a;
  int *y = malloc(sizeof(b));
  y = &b;
  t = b;
  *y = *x;
  *x = a
}

void printarray( int *array ){
  int i = 0;
  int *tmp = array;
  while(i < MAXLEN-1){
    printf("At index %d is a %d\n", i, tmp[i]);
    i++;
  }
}
                                                                                                                                
void shuffle( int *array ){
  srand(time(NULL));  
  for(int i = MAXLEN-2; i > 0;i--){
    int r = rand()% (i + 1);
    int buf = array[i];
    array[i] = array[r];
    array[r] = buf;
      }
  }


int main(){

  int *array = mkarray();
  
  printarray(array);

  shuffle(array);

  puts("##################SHUFFLED#####################");
  
  printarray(array);
  
  free(array);
  
  return 0;
}
