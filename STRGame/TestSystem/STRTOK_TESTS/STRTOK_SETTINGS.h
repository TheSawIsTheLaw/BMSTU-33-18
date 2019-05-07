const char STRTOK_SEPARATORS[COUNT_SEPS] = 
{
    ' ', 
    ',', 
    '.', 
    ';', 
    ':' 
};

char STRTOK_TESTS_ADDRESS[COUNT_TESTS][K] =
{
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_1.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_2.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_3.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_4.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_5.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_6.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_7.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_8.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_9.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_10.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_11.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_12.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_13.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_14.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_15.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_16.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_17.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_18.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_19.txt",
    "TestSystem/STRTOK_TESTS/TEST_STRTOK_20.txt"
};

char* (*strtok[])(char*, const char*) =
{
    strtok_Sukocheva,
    strtok_Namestnik,
    strtok_Sarkisov,
    strtok_Lemeshkin,
    strtok_Kovalev,
    strtok_Yakuba,
    strtok_Simonenko,
    strtok_Chelyadinov,
    strtok_Akhmetov,
    strtok_Prokhorova,
    strtok_Nitenko,
    strtok_Aksenova,
    strtok_Burtelov,
    strtok_Perestoronin,
    strtok_Toporkov,
    strtok_Kononenko,
    strtok_Minenko,
    strtok_Saburov,
    strtok_Sverdlov,
    strtok_Krivozubov,
    strtok_Chernenko,
    strtok_Gurishev,
    strtok_Sokolov,
    strtok_Romanov
};

