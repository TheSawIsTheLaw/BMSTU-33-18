#define AMOUNT_OF_ACTORS 9000000

typedef struct
{
	int id;
	char name[32];
	int cinnection[AMOUNT_OF_ACTORS];
} node;

node graph[AMOUNT_OF_ACTORS];