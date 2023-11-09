#include <iostream>
#include <climits>
#include "Windows.h"
using namespace std;

void fillMatrix(int** matrix, int k, int n) {
    // «аповненн€ матриц≥ випадковими значенн€ми (можна зам≥нити на введенн€ користувача або ≥нше)
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100; // ¬ипадков≥ значенн€ в≥д 0 до 99
        }
    }
}

void printMatrix(int** matrix, int k, int n) {
    // ¬иведенн€ матриц≥ на екран
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void swapMinMaxInColumns(int** matrix, int k, int n) {
    int* minInEvenCol = new int[n / 2](); // ћ≥н≥мальний елемент кожного парного стовпц€
    int* maxInOddCol = new int[n / 2](); // ћаксимальний елемент кожного непарного стовпц€

    // «находженн€ м≥н≥мального елемента дл€ кожного парного стовпц€ та максимального дл€ непарного
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (i % 2 == 0) { // ѕарний стовпець
                if (matrix[j][i] < minInEvenCol[i / 2] || minInEvenCol[i / 2] == 0) {
                    minInEvenCol[i / 2] = matrix[j][i];
                }
            }
            else { // Ќепарний стовпець
                if (matrix[j][i] > maxInOddCol[i / 2]) {
                    maxInOddCol[i / 2] = matrix[j][i];
                }
            }
        }
    }

    // ћ≥н€Їмо м≥сц€ми м≥н≥мальний елемент кожного парного стовпц€ з максимальним елементом попереднього непарного стовпц€
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < k; j++) {
            // «находимо ≥ндекс непарного стовпц€
            int oddColIndex = (i > 0) ? i - 1 : n - 1;
            // ћ≥н€Їмо м≥сц€ми елементи
            swap(matrix[j][i], matrix[j][oddColIndex]);
        }
    }

    // ¬иводимо зм≥нену матрицю
    cout << "ћатриц€ п≥сл€ обм≥ну м≥н≥мум≥в ≥ максимум≥в:" << endl;
    printMatrix(matrix, k, n);

    delete[] minInEvenCol;
    delete[] maxInOddCol;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int k, n;

    cout << "¬вед≥ть к≥льк≥сть р€дк≥в (k): ";
    cin >> k;
    cout << "¬вед≥ть к≥льк≥сть стовпц≥в (n): ";
    cin >> n;

    int** matrix = new int* [k];
    for (int i = 0; i < k; i++) {
        matrix[i] = new int[n];
    }

    fillMatrix(matrix, k, n);

    cout << "ѕочаткова матриц€:" << endl;
    printMatrix(matrix, k, n);

    swapMinMaxInColumns(matrix, k, n);

    for (int i = 0; i < k; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
