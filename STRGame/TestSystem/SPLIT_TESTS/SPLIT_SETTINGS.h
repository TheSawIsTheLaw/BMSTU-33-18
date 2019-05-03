char SPLIT_TESTS_ADDRESS[COUNT_TESTS][K] = 
{
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_1.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_2.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_3.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_4.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_5.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_6.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_7.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_8.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_9.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_10.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_11.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_12.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_13.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_14.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_15.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_16.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_17.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_18.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_19.txt",
    "TestSystem/SPLIT_TESTS/TEST_SPLIT_20.txt"
};

char SPLIT_SEPARATORS[COUNT_TESTS] = 
{
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ',',
    '1',
    '0',
    '-',
    'X',
    '!',
    '?',
    '.',
    ';',
    'N'
};

int SPLIT_CORRECT_SIZE[COUNT_TESTS] =
{
    273,
    535,
    766,
    287,
    670,
    547,
    981,
    223,
    1067,
    412,
    7,
    11,
    6,
    6,
    5,
    14,
    1,
    32,
    7,
    1
};

int (*split[])(const char*, char matrix[][N], const char) =
{
    split_Sukocheva,
    split_Namestnik,
    split_Sarkisov,
    split_Lemeshkin,
    split_Kovalev,
    split_Yakuba,
    split_Simonenko,
    split_Chelyadinov,
    split_Akhmetov,
    split_Prokhorova,
    split_Nitenko,
    split_Aksenova,
    split_Burtelov,
    split_Perestoronin,
    split_Toporkov,
    split_Kononenko,
    split_Minenko,
    split_Saburov,
    split_Sverdlov,
    split_Krivozubov,
    split_Chernenko,
    split_Gurishev,
    split_Sokolov,
    split_Romanov
};

