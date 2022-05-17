#include "tests_practice.h"
#include "practice.h"
#include "matrix.h"
#include <cassert>


//1
void test_task_1() {
    // Сторона "C" всегда будет в 2 раза больше высоты h
    // Поэтому для удобства тестов будет возвращать ее

    auto h = 10;
    assert(task_1(h) == 20);

    h = 5;
    assert(task_1(h) == 10);

    h = 2.5;
    assert(task_1(h) == 5);
}


//2
void test_task_2_1() {
    point a = {1, 2};
    point b = {3, 4};
    point c = {5, 6};

    vector<pair<double, double>> points;
    task_2(a, b, c, points);

    assert(points[0].first == 1 && points[0].second == 2);
    assert(points[1].first == 3 && points[1].second == 4);
    assert(points[2].first == 5 && points[2].second == 6);
}

void test_task_2_2() {
    point a = {1, 4};
    point b = {10, 1};
    point c = {1, 1};

    vector<pair<double, double>> points;
    task_2(a, b, c, points);

    assert(points[0].first == 1 && points[0].second == 4);
    assert(points[1].first == 10 && points[1].second == 1);
    assert(points[2].first == 1 && points[2].second == 1);
}

void test_task_2() {
    test_task_2_1();
    test_task_2_2();
}


//3
#include <chrono>

void test_task_3() {
    int x = 30;

    // Тестируем время работы функции вычисления
    // способом бесконечного ряда
    auto start_time_Series = chrono::steady_clock::now();
    calcExpUsingSeries(x); // Тестируемая функция
    auto end_time_Series = chrono::steady_clock::now();
    auto runtimeSeries = chrono::duration_cast<chrono::microseconds>(end_time_Series - start_time_Series);


    // Тестируем время работы функции вычисления
    // способом бесконечной дроби
    auto start_time_InfFraction = chrono::steady_clock::now();
    //void calcExpUsingInfiniteFraction(x);    // Тестируемая функция
    auto end_time_InfFraction = chrono::steady_clock::now();
    auto runtimeInfFraction = chrono::duration_cast<chrono::microseconds>(
            end_time_InfFraction - start_time_InfFraction);

    cout << "Скорость сходимости вычислении e при x = " << x << '\n';
    cout << "Способ бесконечного ряда: " << runtimeSeries.count() << " ms" << '\n';
    cout << "Способ бесконечной дроби: " << runtimeInfFraction.count() << " ms" << '\n';
}


//4
void test_task_4() {
    int n = 5;
    matrix<int> matrix(n, n);
    matrix.generateChessMatrix();

    vector<int> v;
    createVectorFromMatrix(v, matrix);

    assert(isChessVector(v));
}


//5

void test_task_5_noZeros() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deleteZerosFromVector(v);

    assert(v.size() == 10);
}

void test_task_5_allZeros() {
    vector<int> v = {0, 0, 0};
    deleteZerosFromVector(v);

    assert(v.empty());
}

void test_task_5_randomZeros() {
    vector<int> v1 = {1, 2, 0, 4, 5, 6, 0, 8, 9, 10};
    deleteZerosFromVector(v1);

    assert(v1.size() == 8);

    vector<int> v2 = {1, 2, 0, 4, 5, 6, 0, 8, 0, 0};
    deleteZerosFromVector(v2);

    assert(v2.size() == 6);
}

void test_task_5() {
    test_task_5_allZeros();
    test_task_5_noZeros();
    test_task_5_randomZeros();
}


//6
void test_task_6_inStock() {
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 5;

    assert(linearSearch(v1, x) == 4);

    vector<int> v2 = {3, 4, 5, 7, 8, 9};
    x = 6;

    assert(linearSearch(v2, x) == 5);
}

void test_task_6_outOfStock() {
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 11;

    assert(linearSearch(v1, x) == -1);

    vector<int> v2 = {3, 4, 5, 7, 8, 9};
    x = 1;

    assert(linearSearch(v2, x) == -1);
}

void test_task_6() {
    test_task_6_inStock();
    test_task_6_outOfStock();
}


//7
void test_task_7();


//8
void test_task_8();


//9
void test_task_9();


//10
void test_task_10();


//11
void test_task_11();


//12
void test_task_12();


//13
void test_task_13();


//14
void test_task_14();


//15
void test_task_15();

void test_full_task() {
    test_task_1();
    test_task_2();
    test_task_5();
    test_task_6();
}