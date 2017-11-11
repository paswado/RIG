#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "rig.h"

#define SIZE 10
#define DELIM ','

int main(int argc, char *argv[]){
	int *l;
	long int size = SIZE;
	char *p;		// For strtol
	char delim = DELIM;
	int opt;
	static const char *optString = "c:d:h?";

	opt = getopt(argc, argv, optString);

	while(opt != -1){
		switch( opt ){
			case 'c':
				size = strtol(optarg, &p, 0);
				break;
			case 'd':
				delim = optarg[0];
				break;
			case '?':
			case 'h':
				printf("-c for count, -d for delimiter");
				break;
		}

		opt = getopt(argc, argv, optString);
	}

	




	srand(time(NULL));

	l = gen_list(size);
	print_list(l, size, delim);

	return 1;
}

int* gen_list(int len){
	int i;
	int *list = (int *) malloc(sizeof(int) * len);

	for(i = 0; i < len; i++)
			list[i] = r_value(10);
	
	return list;
}


// TODO: Negative Values between 0 & size

int r_value(int size){
	int n = rand();

	if(n > size)
			return n%(size + 1);

	return n;
}

void print_list(int *list, int len, char d){
		int i;

		for(i = 0; i < len; i++){
			printf("%d", list[i]);
			if(i < len - 1){
				printf("%c ", d);
			}
	}
}
