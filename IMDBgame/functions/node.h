#define AMOUNT_OF_ACTORS 9000000

typedef struct
{
	unsigned int id;
	char name[32];
	unsigned int connection[AMOUNT_OF_ACTORS];
    unsigned int len;
} node;

node graph[AMOUNT_OF_ACTORS];
