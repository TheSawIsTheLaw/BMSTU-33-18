#include <stdio.h>
#define OBJ_LEN 10
#define NOT_PAST 0
#define STOP 127


void add_to_graph(node obj, int n, char past[OBJ_LEN / 8 + 1], char len[OBJ_LEN], char magic[8])
{
    for (int i = 0; i < obj.count_connections; i++)
    {
        int index_n = obj.connection[i] / 8;
        int index_m = obj.connection[i] % 8;
        if ((past[index_n] & magic[index_m]) == 0)
        {
            past[index_n] |= magic[index_m];
            len[obj.connection[i]] = n;
        }
    }
}

int find_result(node data[OBJ_LEN], int data_len, int from, int to)
{
    unsigned char magic[8];
    magic[0] = 0x80;
    magic[1] = 0x40;
    magic[2] = 0x20;
    magic[3] = 0x10;
    magic[4] = 0x8;
    magic[5] = 0x4;
    magic[6] = 0x2;
    magic[7] = 0x1;

    char len[data_len];
    for (int i = 0; i < data_len; i++)
        len[i] = -1;
    len[from] = 0;

    int past_len = data_len / 8 + 1;
    unsigned char past[past_len];
    for (int i = 0; i < past_len; i++)
        past[i] = NOT_PAST;
    int index_n = from / 8;
    int index_m = from % 8;

    int index_n_to = to / 8;
    int index_m_to = to % 8;

    past[index_n] |= magic[index_m];

    int n = 1;
    while (n != STOP)
    {
        for (int i = 0; i < data_len; i++)
        {
            index_n = i / 8;
            index_m = i % 8;
            if ((past[index_n] & magic[index_m]) == magic[index_m] && len[i] == n - 1)
            {
                add_to_graph(data[i], n, past, len, magic);
                if (past[index_n_to] & magic[index_m_to])
                    return n;
            }
        }
        n++;
    }

    return -1;
}