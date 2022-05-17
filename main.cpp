#include <iostream>
#include <math.h>
#include "tests_practice.h"
#include "matrix.h"


using namespace std;


int main() {
    vector<int> v1 = {1, 1, 1, 0, 1, 1, 0, 0, 1};
    vector<int> v2 = {2, 2, 2, 0, 2, 2, 0, 0, 2};

    matrix m1(v1);
    matrix m2(v2);
    matrix<int> m3(5, 5);
    m3.multiplicationMatrices(m1, m2);

    vector<int> matrixM3;
    createVectorFromMatrix(matrixM3,m3);
    vector<int> testCase = {2, 4, 6, 0, 2, 4, 0, 0, 0};

    assert(matrixM3 == testCase);

    return 0;
}
