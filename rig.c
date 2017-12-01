#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "rig.h"

Flags* init(){
    Flags *f = (Flags *)malloc(sizeof(Flags));
    time_t s;

    f->count = COUNT;
    f->max = MAX;
    f->negative = NEG;
    f->delim = DELIM;

   time(&s);
    srand((unsigned int) s); 

    return f;

}

int main(int argc, char **argv){
	int *list;

	Flags *f = init();

	if(f == NULL)
		exit(1);

	set_flags(argc, argv, f);

    list = gen_list(f);

    print_list(list, f);
	return 0;
}

int set_flags(int argc, char **argv, Flags *f){
	static const char *opt_string = "c:d:m:nh?";
	char *p; // for strtol
	int opt;

	opt = getopt(argc, argv, opt_string);
	f->negative = 0;

	while(opt != -1){
		switch( opt ){
			case 'c':
				f->count = strtol(optarg, &p, 0);
				break;
			case 'm':
				f->max = strtol(optarg, &p, 0);
			case 'd':
				f->delim = optarg[0];
				break;
			case 'n':
				f->negative = 1;	
				break;
			case '?':
			case 'h':
				break;
		}

		opt = getopt(argc, argv, opt_string);
	}

	return 0;
}

int* gen_list(Flags* f){
	int* l = (int *)malloc(sizeof(int) * (f->count));
	int i;

	if(f->negative)
		for( i = 0; i < f->count; i++){
			l[i] = r_value_n(f->max);
    }    
	else
		for(i = 0; i < f-> count; i++)
			l[i] = r_value(f->max);

	return l;
}

void print_list(int *list, Flags* f){
    int i;

    for(i = 0; i < f->count; i++){
        printf("%d%c ", list[i], f->delim);
    }
    printf("\n");
}

int r_value(int max){
	return (rand())%(max + 1);
}

int r_value_n(int max){
		return (rand() - rand())%(max + 1);
}
