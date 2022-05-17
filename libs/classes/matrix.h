#ifndef PRACTICE_OP_MATRIX_H
#define PRACTICE_OP_MATRIX_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <malloc.h>

using namespace std;

template<class T>
class matrix {
private:
    T *m_values;

    size_t m_rows{};
    size_t m_cols{};
public:
    matrix();

    matrix(size_t nRows, size_t nCols);

    matrix(matrix &m1);

    ~matrix();

    int getRows();

    int getCols();

    int getIndex(const size_t i, const size_t j);

    void inputKeyboard();

    void output();

    void generateChessMatrix();

    vector<T> createArray(vector<T> v);

    void generate_1();
};

template<class T>
matrix<T>::matrix() {
    m_rows = 0;
    m_cols = 0;
    m_values = nullptr;
}

template<class T>
matrix<T>::matrix(size_t nRows, size_t nCols) {
    m_rows = nRows;
    m_cols = nCols;
    m_values = new T[nRows * nCols];

}

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

template<class T>
matrix<T>::~matrix() {
    if (nullptr != m_values)
        delete m_values;
}


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
int matrix<T>::getIndex(const size_t i, const size_t j) {
    return m_values[i * m_cols + j];
}

#endif