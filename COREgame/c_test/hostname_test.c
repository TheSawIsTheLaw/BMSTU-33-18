#include "../c_test_headers/hostname_test.h"

int is_equal(const char *const first, char *const second)
{
    if (strcmp(first, second))
    {
        printf("Expected hostname notorious, but %s is current\n", first);
        return ERROR;
    }

    return OK;
}

int getname_test(char *const name)
{
    if (hostname(NULL, name) != OK)
    {
        return ERROR;
    }

    if (is_equal(name, "notorious") != OK)
    {
        return ERROR;
    }

    return OK;
}

int setname_test(char *const name)
{
    if (hostname("notorious", name) != OK)
    {
        return ERROR;
    }

    if (is_equal(name, "notorious") != OK)
    {
        return ERROR;
    }

    return OK;
}

int start_dash(char *const name)
{
    if (hostname("-notorious", name) == OK)
    {
        return ERROR;
    }

    return OK;
}

int end_dash(char *const name)
{
    if (hostname("notorious-", name) == OK)
    {
        return ERROR;
    }

    return OK;
}

int random_error(char *const name)
{
    if (hostname("notor...ious", name) == OK)
    {
        return ERROR;
    }

    return OK;
}

int analize_result(FILE *const stream, const int code)
{
    if (!code)
    {
        fprintf(stdout, "TEST PASSED!\n");
    }
    else
    {
        fprintf(stdout, "TEST FAILED!\n");
    }

    return code;
}

int main()
{
    int err_counter = 0;
    char current_hostname[MAX_HOSTNAME_LENGTH], test_hostname[MAX_HOSTNAME_LENGTH];
    gethostname(current_hostname, MAX_HOSTNAME_LENGTH);  
    void *func = NULL; 

    fprintf(stdout, "1) Testing set hostname\n");
    err_counter += analize_result(stdout, setname_test(test_hostname));

    fprintf(stdout, "2) Testing get hostname\n");
    err_counter += analize_result(stdout, getname_test(test_hostname));

    fprintf(stdout, "3) Testing invalid hostname set(name start with '-')\n");
    err_counter += analize_result(stdout, start_dash(test_hostname));

    fprintf(stdout, "4) Testing invalid hostname set(name end with '-')\n");
    err_counter += analize_result(stdout, end_dash(test_hostname));
    
    fprintf(stdout, "5) Testing invalid hostname set(random)\n");
    err_counter += analize_result(stdout, random_error(test_hostname));

    sethostname(current_hostname, strlen(current_hostname));

    
    fprintf(stdout, "6) Testing upload\n");

    if ((func = get_hostname()) == NULL)
    {
        err_counter++;
    } 
    else
    {
        fprintf(stdout, "Upload properly passed!\n");
    }

    if (err_counter)
    {
        printf("Testing failed with %d errors\n", err_counter);
        return ERROR;
    }

    printf("Testing passed!\n");
    printf("Your standart hostname \"%s\" recovered", current_hostname);
    return OK;
}
