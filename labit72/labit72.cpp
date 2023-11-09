#include <iostream>
#include <climits>
#include "Windows.h"
using namespace std;

void fillMatrix(int** matrix, int k, int n) {
    // ���������� ������� ����������� ���������� (����� ������� �� �������� ����������� ��� ����)
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100; // �������� �������� �� 0 �� 99
        }
    }
}

void printMatrix(int** matrix, int k, int n) {
    // ��������� ������� �� �����
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void swapMinMaxInColumns(int** matrix, int k, int n) {
    int* minInEvenCol = new int[n / 2](); // ̳�������� ������� ������� ������� �������
    int* maxInOddCol = new int[n / 2](); // ������������ ������� ������� ��������� �������

    // ����������� ���������� �������� ��� ������� ������� ������� �� ������������� ��� ���������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (i % 2 == 0) { // ������ ��������
                if (matrix[j][i] < minInEvenCol[i / 2] || minInEvenCol[i / 2] == 0) {
                    minInEvenCol[i / 2] = matrix[j][i];
                }
            }
            else { // �������� ��������
                if (matrix[j][i] > maxInOddCol[i / 2]) {
                    maxInOddCol[i / 2] = matrix[j][i];
                }
            }
        }
    }

    // ̳����� ������ ��������� ������� ������� ������� ������� � ������������ ��������� ������������ ��������� �������
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < k; j++) {
            // ��������� ������ ��������� �������
            int oddColIndex = (i > 0) ? i - 1 : n - 1;
            // ̳����� ������ ��������
            swap(matrix[j][i], matrix[j][oddColIndex]);
        }
    }

    // �������� ������ �������
    cout << "������� ���� ����� ������ � ���������:" << endl;
    printMatrix(matrix, k, n);

    delete[] minInEvenCol;
    delete[] maxInOddCol;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int k, n;

    cout << "������ ������� ����� (k): ";
    cin >> k;
    cout << "������ ������� �������� (n): ";
    cin >> n;

    int** matrix = new int* [k];
    for (int i = 0; i < k; i++) {
        matrix[i] = new int[n];
    }

    fillMatrix(matrix, k, n);

    cout << "��������� �������:" << endl;
    printMatrix(matrix, k, n);

    swapMinMaxInColumns(matrix, k, n);

    for (int i = 0; i < k; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
