#include "pch.h"
#include "CppUnitTest.h"
#include "../labit72/labit72.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		

        TEST_METHOD(TestSwapMinMaxInColumns)
        {
            const int k = 3;
            const int n = 4;
            int** matrix = new int* [k];
            for (int i = 0; i < k; i++)
                matrix[i] = new int[n];

            // Заповнюємо матрицю вручну або використовуючи функцію fillMatrix
            // В даному випадку використовуємо функцію fillMatrix
            fillMatrix(matrix, k, n);

            // Копіюємо вихідну матрицю для порівняння
            int** originalMatrix = new int* [k];
            for (int i = 0; i < k; i++) {
                originalMatrix[i] = new int[n];
                memcpy(originalMatrix[i], matrix[i], n * sizeof(int));
            }

            // Викликаємо функцію для тестування
            swapMinMaxInColumns(matrix, k, n);

            // Перевірка, чи відбувся обмін мінімумів і максимумів
            for (int i = 0; i < k; i++)
                for (int j = 0; j < n; j++)
                    Assert::AreNotEqual(originalMatrix[i][j], matrix[i][j]);

            // Очищення пам'яті
            for (int i = 0; i < k; i++)
                delete[] matrix[i];
            delete[] matrix;

            for (int i = 0; i < k; i++)
                delete[] originalMatrix[i];
            delete[] originalMatrix;
        }
    };
}