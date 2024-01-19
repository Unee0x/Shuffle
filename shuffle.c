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

void printarray( int *array ){
  int i = 0;
  int *tmp = array;
  while(i < MAXLEN-1){
    printf("At index %d is a %d\n", i, tmp[i]);
    i++;
  }
}

void swap( int *a, int *b ){
  int *t = a;
  a = b;
  b = t;
}

void shuffle( int *array ){
  int count = 0;
  int buf[] = {'\0'};
  int r = getrand(MIN, MAX);

  printf("Array[%d] is %d\n", r, array[r]);
  while(count < MAXLEN-1 && count != r){
    printf("Count is now %d\n", count);
    
    count++;
  }
}

int main(){
  
  srand(time(NULL));

  int *array = mkarray();
  
  printarray(array);

  shuffle(array);
  
  free(array);
  
  return 0;
}
