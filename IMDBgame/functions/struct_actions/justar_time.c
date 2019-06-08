#include <stdio.h>
// #include "node.h"
#define OBJ_COUNT 20
/*
typedef struct
{
    unsigned int vertex_id : 24;
    unsigned int bacon : 8;
} Tree;

void make_tree(Tree *main_tree, node *actors, const int size_of_actors, int id) // id of main vertex of tree (Bacon's)
{
    unsigned int queue[AMOUNT_OF_ACTORS]; // очередь для вершин для поиска в ширину
    unsigned int visited[AMOUNT_OF_ACTORS / 30] = { 0 }; // список посещенных вершин
    unsigned int cur_pos = 0, max_pos = 0; // начало, конец очереди

    main_tree[id].vertex_id = 0;
    main_tree[id].bacon = 0;
    add_conn(visited, id);
    queue[max_pos++] = id;

    while(cur_pos < max_pos) // пока очередь не пуста
    {
        id = queue[cur_pos++]; // берем следующего по очереди актера
        for (int i = 1; i <= size_of_actors; i++) // найдем все необработанные связи для этого актера...
            if (get_conn(actors[id].connection, i) && !get_conn(visited, i)) // если найдена связь и она еще не была обработана
            {
                add_conn(visited, i); // добавить связь в обработанные
                queue[max_pos++] = i; // добавить данного актера в очередь
                main_tree[i].vertex_id = id;
                main_tree[i].bacon = main_tree[id].bacon + 1; // записать данные для данного актера
            }
    }
}

void get_route(Tree main_tree, const int index, int *route)
{
    int i = 0;
    route[i++] = index;
    while(main_tree[index].vertex_id != 0)
    {
        route[i++] = main_tree[index].vertex_id;
        index = main_tree[index].vertex_id;
    }
}
ГОВНОКОД?!?!?!
*/

typedef struct
{
    unsigned int id;
    char name[32];
    unsigned int connection[OBJ_COUNT];
    unsigned int count_connections;
} node;


int is_digit(char symb)
{
    return (symb - '0' >= 0 && symb - '0' < 10) ? 1 : 0;
}


void fill(node *vertex, char *str, int id)
{
    int i = 0, num = 0, flag = 0, k = 0;
    while(str[i])
    {
        if (!is_digit(str[i]) && flag)
        {
            vertex->connection[k++] = num;
            num = 0;
            flag = 0;
            i++;
        }
        else if (is_digit(str[i]))
            while (is_digit(str[i]))
            {
                flag = 1;
                num = num * 10 + (str[i] - '0');
                i++;
            }
        else
            i++;
    }
    if (flag)
    {
        vertex->connection[k++] = num;
    }
    vertex->count_connections = k;
}



void add_conn(unsigned int *const conn_arr, const unsigned int new_conn_id)
{
    conn_arr[new_conn_id / (sizeof(unsigned int) * 8)] |= 1 << (new_conn_id % (sizeof(unsigned int) * 8));
}


unsigned int get_conn(unsigned int *const conn_arr, const unsigned int id)
{
    return conn_arr[id / (sizeof(unsigned int) * 8)] & (1 << (id % (sizeof(unsigned int) * 8)));
}


int find_res(node *const graph, int data_len, const int id_from, const int id_to) // int route[] ??????
{
    unsigned int visited[data_len / 32 + 1];
    unsigned int queue[data_len];
    int cur_pos = 0, last_pos = 0, id;
    int cur_len = 0;
    int id_bits;

    for (int i = 0; i < data_len / 32 + 1; i++)
        visited[i] = 0;

    for (id_bits = 0; data_len > 0; id_bits++, data_len >>= 1);

    const int id_get = (1 << id_bits) - 1;
    queue[last_pos++] = id_from;

    add_conn(visited, id_from);

    while (cur_pos < last_pos)
    {
        printf("queue: ");
        for (int i = cur_pos; i < last_pos; i++)
             printf("%d   ", (queue[i] & id_get) + 1);
        printf("\ncur_len: %d\n\n", cur_len);
        id = queue[cur_pos] & id_get;
        cur_len = (queue[cur_pos++] >> id_bits) + 1;

        for (int i = 0; i < graph[id].count_connections; i++)
        {
            // printf("%d  ", graph[id].connection[i]);
            if (get_conn(visited, graph[id].connection[i]))
                continue;
            // printf("%d  ", graph[id].connection[i]);
            // printf("%d     %dx ", graph[id].connection[i], graph[id].count_connections);
            add_conn(visited, graph[id].connection[i]);
            if (graph[id].connection[i] == id_to)
                return cur_len;
            queue[last_pos++] = (cur_len << id_bits) | (graph[id].connection[i] & id_get);
        }
        // printf("\n");
    }
    return -1;
}


int main()
{
    node graph[OBJ_COUNT];

    int n1, n2;
    scanf("%d%d", &n1, &n2);

    fill(&graph[0], "1 6", 1);
    fill(&graph[1], "0 2 6", 2);
    fill(&graph[2], "1 4 5", 3);
    fill(&graph[3], "0 4 13", 4);
    fill(&graph[4], "2 7 10 19", 5);
    fill(&graph[5], "2 16", 6);
    fill(&graph[6], "0 1", 7);
    fill(&graph[7], "4 8 17", 8);
    fill(&graph[8], "7 9", 9);
    fill(&graph[9], "8 10 15 17", 10);
    fill(&graph[10], "4 9 12 15", 11);
    fill(&graph[11], "12", 12);
    fill(&graph[12], "10 11 15", 13);
    fill(&graph[13], "3 9 14", 14);
    fill(&graph[14], "13 18", 15);
    fill(&graph[15], "10 12", 16);
    fill(&graph[16], "5", 17);
    fill(&graph[17], "7 9 18", 18);
    fill(&graph[18], "14 17", 19);
    fill(&graph[19], "4", 20);


    printf("%d", find_res(graph, OBJ_COUNT, n1 - 1, n2 - 1));
    return 0;
}
