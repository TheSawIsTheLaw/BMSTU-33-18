#include "../c_test_headers/cksum_test.h"

void test_help()
{
    char *filename = "../../c_src_headers/cksum_headers/cksum_link.h";
    FILE *fp = fopen(filename, "rb");
    cksum(fp, "--help");
    system("cksum --help");
    fclose(fp);
}

void test_version()
{
    char *filename = "../../c_src_headers/cksum_headers/cksum_link.h";
    FILE *fp = fopen(filename, "rb");
    cksum(fp, "--version");
    system("cksum --version");
    fclose(fp);
}

void test_file()
{
    char *filename = "../../c_src_headers/cksum_headers/cksum_link.h";
    FILE *fp = fopen(filename, "rb");
    cksum(fp, filename);
    system("cksum cksum.c");
    fclose(fp);
}

void test_help_dl()
{
    void *handle = dlopen("../../libs/libcore.so", RTLD_LAZY);
    uint32_t (*cksum)(FILE *, const char *);
    char *filename = "../../c_src_headers/cksum_headers/cksum_link.h";
    FILE *fp = fopen(filename, "rb");
    cksum = dlsym(handle, "cksum");
    (*cksum)(fp, filename);
    system("cksum --help");
    fclose(fp);
    dlclose(handle);
}

void test_version_dl()
{
    void *handle = dlopen("../../libs/libcore.so", RTLD_LAZY);
    uint32_t (*cksum)(FILE *, const char *);
    char *filename = "../../c_src_headers/cksum_headers/cksum_link.h";
    FILE *fp = fopen(filename, "rb");
    cksum = dlsym(handle, "cksum");
    (*cksum)(fp, filename);
    system("cksum --version");
    fclose(fp);
    dlclose(handle);
}

void test_file_dl()
{
    void *handle = dlopen("../../libs/libcore.so", RTLD_LAZY);
    uint32_t (*cksum)(FILE *, const char *);
    char *filename = "../../c_src_headers/cksum_headers/cksum_link.h";
    FILE *fp = fopen(filename, "rb");
    cksum = dlsym(handle, "cksum");
    (*cksum)(fp, filename);
    system("cksum ../../c_src_headers/cksum_headers/cksum_link.h");
    fclose(fp);
    dlclose(handle);
}

int main()
{
    printf("TEST COMPOSE\n\n");
    printf("\nTEST --help OPTION\n\n");
    test_help();
    printf("\nTEST --version OPTION\n\n");
    test_version();
    printf("\nTEST FILE OPTION\n\n");
    test_file();
    printf("TEST DYNAMIC LOAD\n\n");
    printf("\nTEST --help OPTION\n\n");
    test_help_dl();
    printf("\nTEST --version OPTION\n\n");
    test_version_dl();
    printf("\nTEST FILE OPTION\n\n");
    test_file_dl();

    return 0;
}