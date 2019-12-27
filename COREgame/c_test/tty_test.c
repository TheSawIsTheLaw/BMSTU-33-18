// tty_test.c
#include "../c_test_headers/tty_test.h"

void test_silent(int argc, char **argv)
{
    tty(argc, argv);
    system("tty --silent");

}

void test_help(int argc, char **argv)
{
    tty(argc, argv);
    system("tty --help");
}

void test_version(int argc, char **argv)
{
    tty(argc, argv);
    system("tty --version");
}

int main(int argc, char **argv)
{
    puts("Test silent:");
    test_silent(argc, argv);

    puts("Test version:");
    test_version(argc, argv);

    puts("Test help:");
    test_help(argc, argv);
}
