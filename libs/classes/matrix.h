#ifndef PRACTICE_OP_MATRIX_H
#define PRACTICE_OP_MATRIX_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <malloc.h>
#include <cassert>

using namespace std;

template<class T>
class matrix {
private:
    T *m_values;

    size_t m_rows{};
    size_t m_cols{};
public:

    matrix(size_t nRows, size_t nCols);

    matrix(matrix &m1);

    explicit matrix(vector<T> &v);

    ~matrix();

    int getRows();

    int getCols();

    int getPointer();

    int getIndex(const size_t i, const size_t j);

    void inputKeyboard();

    void output();

    void generateChessMatrix();

    vector<T> createArray(vector<T> v);

    void resize(const size_t rows, const size_t cols);

    bool can_multiply(const matrix &other);

    void multiply(const matrix &other);

    void multiplicationMatrices(const matrix<T> &m1, const matrix<T> &m2);
};


// Конструктор матрицы размерностью nRows * nCols
template<class T>
matrix<T>::matrix(size_t nRows, size_t nCols) {
    m_rows = nRows;
    m_cols = nCols;
    m_values = new T[nRows * nCols];

}

// Конструктор копирования матрицы
template<class T>
matrix<T>::matrix(matrix &m1) {
    this->m_rows = m1.getRows();
    this->m_cols = m1.getCols();
    this->m_values = new T[m_rows * m_cols];
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j)
            m_values[i * m_cols + j] = m1.getIndex(i, j);
    }
}

// Конструктор квадратной матрицы из вектора
template<class T>
matrix<T>::matrix(vector<T> &v) {
    size_t sizeRowsAndCols = sqrt(v.size());
    m_rows = sizeRowsAndCols;
    m_cols = sizeRowsAndCols;

    m_values = new T[m_rows * m_cols];

    for (int i = 0; i < v.size(); ++i) {
        m_values[i] = v[i];
    }
}

// Деструктор матрицы
template<class T>
matrix<T>::~matrix() {
    if (nullptr != m_values)
        delete m_values;
}


// Генерирую матрицы 0 и 1 расположенных в шахматном порядке
template<class T>
void matrix<T>::generateChessMatrix() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            if ((i + j) % 2 == 0) {
                m_values[i * m_cols + j] = 0;
            } else {
                m_values[i * m_cols + j] = 1;
            }
        }
    }
}

template<class T>
void matrix<T>::inputKeyboard() {
    if (m_values == nullptr) {
        cout << "memory not allocated";
        return;
    }

    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            cin >> m_values[i * m_cols + j];
        }
    }
}

template<class T>
void matrix<T>::output() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            cout << m_values[i * m_cols + j] << ' ';
        }
        cout << '\n';
    }
}

template<class T>
int matrix<T>::getRows() {
    return m_rows;
}

template<class T>
int matrix<T>::getCols() {
    return m_cols;
}

template<class T>
int matrix<T>::getPointer() {
    return *m_values;
}

template<class T>
int matrix<T>::getIndex(const size_t i, const size_t j) {
    return m_values[i * m_cols + j];
}

template<class T>
vector<T> matrix<T>::createArray(vector<T> v) {
    return vector<T>();
}

template<class T>
void matrix<T>::resize(const size_t rows, const size_t cols) {
    m_rows = rows;
    m_cols = cols;
    if (m_values)
        delete[] m_values;
    m_values = new double[m_rows * m_cols];
}

template<class T>
bool matrix<T>::can_multiply(const matrix &other) {
    return m_rows == other.m_cols;
}

template<class T>
void matrix<T>::multiply(const matrix &other) {
    if (false == can_multiply(other)) {
        matrix empty;
        return ;
    }
    matrix result(m_rows, other.m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < other.m_cols; j++) {
            result.m_values[i * m_cols + j] = 0;
            for (int k = 0; k < m_cols; k++) {
                result.m_values[i * m_cols + j] += getIndex(i, k) * other.get(k, j);
            }
        }
    }
    return ;
}

template<class T>
void matrix<T>::multiplicationMatrices(const matrix<T> &m1, const matrix<T> &m2) {
    assert(m1.m_cols == m2.m_rows);

    matrix<T> result(m1.m_rows, m2.m_cols);
    for (int i = 0; i < m1.m_rows; ++i) {
        for (int j = 0; j < m2.m_cols; ++j) {
            for (int k = 0; k < m1.m_cols; ++k) {
                result.m_values[i * m_cols + j] += m1.m_values[i * m_values + k] * m2.m_values[k * m_values + j];
            }
        }
    }
}



#endif