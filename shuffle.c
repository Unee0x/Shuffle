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
  printf("a is %d and b is %d\n", *a, *b);
  int *t = b;
  b = a;
  a = t;
  printf("Now a is %d and b is %d\n", *a, *b);
}

void shuffle( int *array ){
  int count = 0;
  int buf[] = {'\0'};
  int r = getrand(MIN, MAX);

  //printf("Array[%d] is %d\n", r, array[r]);
  while(count < MAXLEN-1){
    array[count] = array[getrand(MIN,MAX)];
    buf[count] = array[count];
    for(int i = 0; i < count;i++){
      if(buf[i] == array[count]){
	printf("Match at index %d with number %d\n", i, buf[i]);
	buf[i] = array[getrand(MIN,MAX)];
      }
    }
    count++;
  }
}

int main(){
  
  srand(time(NULL));

  int *array = mkarray();
  
  printarray(array);

  shuffle(array);
  
  printarray(array);
  
  free(array);
  
  return 0;
}
