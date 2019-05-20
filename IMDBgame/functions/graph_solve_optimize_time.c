#include <stdio.h>
// кол-во актеров
#define OBJ_LEN 10
#define NOT_PAST 'F'
#define PAST 'T'
#define STOP 127

typedef struct
{
    int id;
    int connection[10];
    int count_connections;
} node;

node graph[OBJ_LEN];

void add_to_graph(node obj, int n, char past[OBJ_LEN], char len[OBJ_LEN])
{
    for (int i = 0; i < obj.count_connections; i++)
    {
        if (past[obj.connection[i]] == NOT_PAST)
        {
            past[obj.connection[i]] = PAST;
            len[obj.connection[i]] = n;
        }
    }
}

int find_result(node data[OBJ_LEN], int data_len, int from, int to)
{
    char len[data_len];
    for (int i = 0; i < data_len; i++)
        len[i] = -1;
    len[from] = 0;

    char past[data_len];
    for (int i = 0; i < data_len; i++)
        past[i] = NOT_PAST;
    past[from] = PAST;

    int n = 1;
    while (n != STOP)
    {
        for (int i = 0; i < data_len; i++)
        {
            if (past[i] == PAST && len[i] == n - 1)
            {
                add_to_graph(data[i], n, past, len);
                if (past[to] == PAST)
                    return n;
            }
        }
        n++;
    }

    return -1;
}

// пример вызова ф-ции
//int result = find_result(graph, OBJ_LEN, 6, 2);

