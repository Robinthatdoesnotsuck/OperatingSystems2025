#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
volatile int counter = 0;

int loops;

void *thread_worker(void *arg) {
	int i;

	for (i = 0; i < loops; i++){
		counter++;
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("like dude what the hell\n");
	}
	if(strcmp(argv[1], "CPU") == 0){
		printf("Start CPU example\n");
		char *str = argv[2];
		while(1) {
			
			printf("%s\n", str);
		}
		
	}
	else if ( strcmp(argv[1], "Memory")== 0) {
		int *p = malloc(sizeof(int));
		assert(p != NULL);
		*p = 0;
		printf("Start memory example \n");
		while(1) {
			*p = *p +1;
			printf("Soy ese: %s p: %p\n",  argv[2], p);
		}
	}
	else if ( strcmp(argv[1], "Concurrency") == 0) {
		printf("Start concurrent example \n");
		loops = atoi(argv[2]);

		pthread_t p1, p2;

		pthread_create(&p1, NULL, thread_worker, NULL);
		pthread_create(&p2, NULL, thread_worker, NULL);
		pthread_join(p1, NULL);
		pthread_join(p2, NULL);
		printf("Counter final value : %d\n", counter);
	}
	else if( strcmp(argv[1], "File persistence")) {
		printf("Start persistence example \n");
	}

	return 0;
}
