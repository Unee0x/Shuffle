#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXLEN 9
int getlen(int *);

void swap( int *a, int *b ){
  printf("Swapping a --> %d with b --> %d\n", *a, *b);
  int *t;
  t = b;
  b = a;
  a = t;
  printf("Now a is %d with b is %d\n", *a, *b);

}

void printarray( int *array){

  int *tmp = array;
  // int l = getlen(array);
  int i = 0;
  if (!tmp)
    perror("Input Array Empty");
    
  while(i < MAXLEN){
    printf("At index %d is %d in address %p\n", i, tmp[i], &tmp[i]);
    i++;
  }
}

int getlen( int *array ){
  if(!array){
    perror("Empty!!!");
    return 0;
  }
  int i = 0;
  while(i < MAXLEN){
    array++;
    i++;
  }
  return i;
}

void shuffle( int *array ){
  srand(time(NULL));
  int *tmp = array;
  int len = getlen(tmp);

  if( !tmp )
    perror("Shuffle Input Array Empty");

  int i = 0;

  while(i < MAXLEN){
    int r = rand() % 8;
    printf("The random # is %d\n", r);
    printf("%d is in  %p and %d is in %p\n",tmp[i],&(tmp[i]),tmp[r], &(tmp[r]));
    swap(&(tmp[i]), &(tmp[r]));
    i++;
  }

  //puts("########## POST SHUFFLE ################\n");
  //printarray(tmp);
}


int main(){

  int *tmp = malloc(sizeof(int) * MAXLEN);

  printf("The address of tmp is %p\n", tmp);
  //  printf("The address of array is %p\n", array);
  //array = tmp;

  //  printf("\tThe address of array is %p\n", array);
  // printarray(array);

  for(int i = 0; i < MAXLEN; i++){
    tmp[i] = i+1;
  }

  printarray(tmp);
  
  shuffle(tmp);

  printarray(tmp);

  free(tmp);
  
  return 0;
}
