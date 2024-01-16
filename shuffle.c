#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLEN 10


int getrand(int min, int max){
  int r = rand() % max + min;
  return r;
}

int *newarray();

void *mkarray(){
  int *array = malloc(sizeof(int) * MAXLEN);
  array[MAXLEN-1] = '\0';
  if(!array)
    perror("Empty Array");

  int i = 0;
  int j = 0;
  while(i < MAXLEN-1){
    array[j] = j++;
    i++;
  }

  return array;
}

void printarray( int *array ){
  int i = 0;
  int *tmp = array;
  while(*tmp != '\0'){
    printf("At index %d is a %d\n", i, tmp[i]);
    tmp++;
    i++;
  }
}

int main(){
  srand(time(NULL));

  int *array = mkarray();

  //  int n = getrand(0, MAXLEN-1);

  printarray(array);

  free(array);
  
  return 0;
}
