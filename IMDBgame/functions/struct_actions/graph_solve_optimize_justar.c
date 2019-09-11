#include <stdio.h>
#define OBJ_LEN 10
#define NOT_PAST 0
#define STOP 127


void add_to_graph(node obj, int n, char past[OBJ_LEN / 8 + 1], char len[OBJ_LEN])
{
    int num, index;
    for (int i = 0; i < obj.count_connections; i++)
    {
        index = obj.connection[i] / 8;
        num = 1 << (obj.connection[i] % 8);
        if ((past[index] & num)
        {
            past[index] |= num;
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

    int past_len = data_len / 8 + 1;
    unsigned char past[past_len];
    for (int i = 0; i < past_len; i++)
        past[i] = NOT_PAST;
    int index = from / 8;
    int num = 1 << (from % 8);

    int index_to = to / 8;
    int num_to = 1 << (to % 8);

    past[index] |= num;

    int n = 1, flag_end;

    while (n != STOP)
    {
        flag_end = 1;
        for (int i = 0; i < data_len; i++)
        {
            index = i / 8;
            num = 1 << (i % 8);
            if ((past[index] & num) && len[i] == n - 1)
            {
                flag_end = 0;
                add_to_graph(data[i], n, past, len);
                if (past[index_to] & num_to)
                    return n;
            }
        }
        if (flag_end)
            return -1;
        else
            n++;
    }

    return -1;
}
