#include <iostream>
#include <math.h>
#include "tests_practice.h"
#include "matrix.h"


using namespace std;


template<typename Type>
void outputVector(vector<Type> &v) {
    for (auto &x: v) {
        cout << x << ' ';
    }
}

int main() {
    test_task_10();

    return 0;
}
