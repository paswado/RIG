#define COUNT 10
#define MAX 10
#define NEG 1
#define DELIM ','

typedef struct flags{
	int count;
	int negative;
	int max;
	char delim;
} Flags;

int set_flags(int argc, char **argv, Flags *f);

int* gen_list(Flags *f);
int r_value(int max);
int r_value_n(int max);
void print_list(int *list, Flags* f);
