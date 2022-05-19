#include <iostream>
#include <math.h>
#include <algorithm>
#include "tests_practice.h"
#include "matrix.h"


using namespace std;

template<typename Type>
void outputVector(vector<Type> &v) {
    for (auto &x: v) {
        cout << x << ' ';
    }
}

template<typename T>
void reverseVector(vector<T> &vec) {

}

void parseNum(int n, vector<int> &vec) {
    vec.push_back(n % 10);
    int temp = n / 10;
    if (temp == 0) {
        reverse(vec.begin(), vec.end());
        return;
    }
    parseNum(temp, vec);

}

vector<int> outputColumnMultiplication(vector<int> &vecA, vector<int> &vecB, const int result) {
    vector<int> vec;

    for (int i = 0; i < vecA.size(); ++i) {
        for (int j = 0; j < vecB.size(); ++j) {
            vec.push_back(vecA[i]);
        }
    }
}

void ff(vector<int> &vecA, vector<int> &vecB, const int result) {

}

void f(int a, int b) {
    vector<int> digitsNumberA;
    parseNum(a, digitsNumberA);

    vector<int> digitsNumberB;
    parseNum(b, digitsNumberB);

    outputVector(digitsNumberA);
    outputVector(digitsNumberB);
}

void test_struct_point_createPointInt() {
    point<int> a = {1, 2};
    assert(a.x == 1 && a.y == 2);
}

void test_struct_point_createPointDouble() {
    point<double> a = {1.23, 3.21};
    assert(a.x == 1.23 && a.y == 3.21);
}

void test_struct_point_allTests() {
    test_struct_point_createPointInt();
    test_struct_point_createPointDouble();
}

void test_struct_triangle_createTriangle() {
    point<int> a = {1, 2};
    point<int> b = {3, 4};
    point<int> c = {5, 6};
    triangle<int> abc;
    createTriangle(abc, a, b, c);

    assert(
            abc.A.x == 1 && abc.A.y == 2 &&
            abc.B.x == 3 && abc.B.y == 4 &&
            abc.C.x == 1 && abc.C.y == 6
    );
}

void test_struct_matrix_createMatrix_1x1() {
    matrix<int> m(1, 1);
    assert(m.getRows() == 1 && m.getCols() == 1);
}

void test_struct_matrix_createMatrix_5x5() {
    matrix<int> m(5, 5);
    assert(m.getRows() == 5 && m.getCols() == 5);
}

void test_struct_matrix_createMatrix_3x5() {
    matrix<int> m(3, 5);
    assert(m.getRows() == 3 && m.getCols() == 5);
}

void test_struct_matrix_createMatrixFromVector() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    matrix m (v);


}

void test_struct_matrix_createMatrix_allTest() {

}

int main() {
    matrix<int> m(5, 5);
    assert(m.getRows() == 5 && m.getCols());
    return 0;
}
