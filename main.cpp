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

void outputColumnMultiplication(vector<int> &vecA, vector<int> &vecB, const int result){

}

void ff(vector<int> &vecA, vector<int> &vecB, const int result){
    
}

void f(int a, int b) {
    vector<int> digitsNumberA;
    parseNum(a, digitsNumberA);

    vector<int> digitsNumberB;
    parseNum(b, digitsNumberB);

    outputVector(digitsNumberA);
    outputVector(digitsNumberB);
}

int main() {
    int a = 123;
    int b = 321;
    f(a, b);
    return 0;
}
