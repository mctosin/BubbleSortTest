#include <stdlib.h>
#include "gtest/gtest.h"
#include <time.h>

TEST(TestTemplate, PassingTest) {
    EXPECT_EQ(1, 1);
}

extern "C" void bubblesort(int* a, int N);

#define EXPECT_ARRAY_EQ(TARTYPE, reference, actual, element_count) \
    {\
        TARTYPE* reference_ = static_cast<TARTYPE *> (reference); \
        TARTYPE* actual_ = static_cast<TARTYPE *> (actual); \
        for(int cmp_i = 0; cmp_i < element_count; cmp_i++ ){\
          EXPECT_EQ(reference_[cmp_i], actual_[cmp_i]);\
        }\
    }

int intcmp(const void* a, const void* b)
{
    const int* ai = (const int*)a, * bi = (const int*)b;
    return *ai - *bi;
}

void test_bubblesort(int* a, int* a_ordenado, int num_els)
{
    memcpy(a_ordenado, a, num_els * sizeof(int));

    qsort(a_ordenado, num_els, sizeof(int), intcmp);

    bubblesort(a, num_els);
    EXPECT_ARRAY_EQ(int, a_ordenado, a, num_els);
}

TEST(Bubblesort, UmElemento) {
    int a[] = { 1337 };
    int a_ordenado[1];

    test_bubblesort(a, a_ordenado, sizeof(a) / sizeof(int));
}

TEST(Bubblesort, DoisElementosForaDeOrdem) {
    int a[] = { 31337, 1337 };
    int a_ordenado[2];

    test_bubblesort(a, a_ordenado, sizeof(a) / sizeof(int));
}

TEST(Bubblesort, DoisElementosEmOrdem) {
    int a[] = { 1337, 31337 };
    int a_ordenado[2];

    test_bubblesort(a, a_ordenado, sizeof(a) / sizeof(int));
}

TEST(Bubblesort, TresElementosEmOrdemInversa) {
    int a[] = { 31337, 1337, 0 };
    int a_ordenado[3];

    test_bubblesort(a, a_ordenado, sizeof(a) / sizeof(int));
}

TEST(Bubblesort, VinteElementosRandomicos) {
    int a[20];
    int a_ordenado[20];
    int i;

    srand((unsigned)time(0));
    for (i = 0; i < 20; i++) {
        a[i] = (rand() % 100) - 50; //De -50 a 49
    }
    test_bubblesort(a, a_ordenado, sizeof(a) / sizeof(int));
}