#include "../f_headers/teen48game_last_move.h"

#define NOERR 0

#define FAILED -1

int last_move_test_a()
{
    int rc;

    matrix_t a;

    rc = matrixgame_create_matrix(&a, 4, 4);
    if (rc)
        return FAILED;

    a.matrix[0][0] = 4;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 2;
    a.matrix[0][3] = 4;
    
    a.matrix[1][0] = 32;
    a.matrix[1][1] = 64;
    a.matrix[1][2] = 128;
    a.matrix[1][3] = 256;
    
    a.matrix[2][0] = 256;
    a.matrix[2][1] = 128;
    a.matrix[2][2] = 64;
    a.matrix[2][3] = 32;
    
    a.matrix[3][0] = 512;
    a.matrix[3][1] = 1024;
    a.matrix[3][2] = 2048;
    a.matrix[3][3] = 4096;

    if (!last_move(&a))
    {
        matrixgame_free_matrix(&a);
        return NOERR;
    }
    else
    {
        matrixgame_free_matrix(&a);        
        return FAILED;
    }
}

int last_move_test_b()
{
    int rc;

    matrix_t a;

    rc = matrixgame_create_matrix(&a, 4, 4);
    if (rc)
        return FAILED;

    a.matrix[0][0] = 2;
    a.matrix[0][1] = 4;
    a.matrix[0][2] = 8;
    a.matrix[0][3] = 16;
    
    a.matrix[1][0] = 32;
    a.matrix[1][1] = 64;
    a.matrix[1][2] = 128;
    a.matrix[1][3] = 256;
    
    a.matrix[2][0] = 512;
    a.matrix[2][1] = 1024;
    a.matrix[2][2] = 2048;
    a.matrix[2][3] = 4096;
    
    a.matrix[3][0] = 16;
    a.matrix[3][1] = 8;
    a.matrix[3][2] = 4;
    a.matrix[3][3] = 2;
    
    if (last_move(&a))
    {
        matrixgame_free_matrix(&a);
        return NOERR;
    }
    else
    {
        matrixgame_free_matrix(&a);        
        return FAILED;
    }

}

int teen48game_last_move_test()
{
    int errc = 0;

    errc += last_move_test_a();
    errc += last_move_test_b();

    return errc;
}

int main(void)
{
    if (teen48game_last_move_test())
        return FAILED;

    return NOERR;
}
