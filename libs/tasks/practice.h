#ifndef PRACTICE_OP_PRACTICE_H
#define PRACTICE_OP_PRACTICE_H

#include <vector>

using namespace std;

struct point {
    double x{}, y{};
};

// Линейные алгоритмы
// В равнобедренном прямоугольном треугольнике известна высота,
// опущенная на гипотенузу. Найти стороны треугольника.
int task_1();

//Заданы координаты вершин треугольника на плоскости.
//Вывести их в порядке обхода по часовой стрелке (для проверки
//достаточно рассмотреть знаки внутренних углов).
void task_2(const point a, const point b, const point c, vector<pair<double, double>> &vec) ;

void task_3();

//Целочисленный массив k(n, n) заполнить нулями и единицами,
//расположив их в шахматном порядке.
void task_4(const size_t n);

#include "practice.cpp"

#endif //PRACTICE_OP_PRACTICE_H