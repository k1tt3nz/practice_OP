#include "practice.h"
#include "matrix.h"
#include <iostream>
#include <math.h>


// Задача 1
template<typename Type>
Type task_1(Type h) {
    auto a = h * sqrt(2);
    auto c = 2 * h;

    return c; // Вернем c для автоматизированного теста
}


// Задача 2

template<typename Type1, typename Type2>
void outputPairVector(vector<pair<Type1, Type2>> vec) {
    for (auto &x: vec) {
        cout << x.first << ';' << x.second << ' ';
    }
}

void task_2(const point a, const point b, const point c, vector<pair<double, double>> &vec) {
    if (a.x * b.y - a.y * b.x < 0) {
        vec.emplace_back(a.x, a.y);
        vec.emplace_back(b.x, b.y);
        vec.emplace_back(c.x, c.y);
    } else {
        vec.emplace_back(b.x, b.y);
        vec.emplace_back(a.x, a.y);
        vec.emplace_back(c.x, c.y);
    }

}

int _getFactorial(const int x) {
    int factorial = 1;
    for (int i = 1; i <= x; ++i) {
        factorial *= i;
    }
    return factorial;
}

int factorial(const int x) {
    return _getFactorial(x);
}

void calcExpUsingSeries(const int x) {
    double exp = 2;
    for (int i = 1; i <= x; ++i) {
        exp += 1 / factorial(i);
    }
}

void calcExpUsingInfiniteFraction() {}

void task_3() {

}

// 4 Задание

template<typename Type1, typename Type2>
void createVectorFromMatrix(vector<Type1> &v, matrix<Type2> m) {
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            v.push_back(m.getIndex(i, j));
        }
    }
}

template<typename T>
bool isChessVector(vector<T> v) {
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) return false;
    }
    return true;
}

// 5 Задание
void inputVector(vector<int> &a) {
    for (auto &x: a) {
        cin >> x;
    }
}

//template<typename Type>
//void outputVector(vector<Type> &v) {
//    for (auto &x: v) {
//        cout << x << ' ';
//    }
//}

void deleteZerosFromVector(vector<int> &a) {
    auto iterDel = a.cbegin();
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0) {
            a.erase(iterDel + i);
        }
    }
}

void task_5() {
    int sizeVector;
    cin >> sizeVector;

    vector<int> a(sizeVector);
    inputVector(a);
    deleteZerosFromVector(a);
    //outputVector(a);

    cout << '\n' << a.size();
}


int linearSearch(vector<int> &v, const int x) {
    if (x < v[0] || x > v[v.size() - 1]) {
        return -1;
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] <= x && x <= v[i + 1]) {
            return v[i];
        }
    }

    return -1;
}

void task_6() {
    int sizeVector;
    cin >> sizeVector;

    vector<int> a(sizeVector);
}