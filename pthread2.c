#include<stdio.h>
#include<pthread.h>

void *entry(void *arg) {
  printf("\nHello from the 2nd thread\n");
  return NULL;
}

void main() {
  pthread_t thread;
  printf("\nHello from the main thread\n");
  pthread_create(&thread,NULL,entry,NULL);
  pthread_join(thread,NULL);
}
