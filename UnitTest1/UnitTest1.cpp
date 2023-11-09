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

            // ���������� ������� ������ ��� �������������� ������� fillMatrix
            // � ������ ������� ������������� ������� fillMatrix
            fillMatrix(matrix, k, n);

            // ������� ������� ������� ��� ���������
            int** originalMatrix = new int* [k];
            for (int i = 0; i < k; i++) {
                originalMatrix[i] = new int[n];
                memcpy(originalMatrix[i], matrix[i], n * sizeof(int));
            }

            // ��������� ������� ��� ����������
            swapMinMaxInColumns(matrix, k, n);

            // ��������, �� ������� ���� ������ � ���������
            for (int i = 0; i < k; i++)
                for (int j = 0; j < n; j++)
                    Assert::AreNotEqual(originalMatrix[i][j], matrix[i][j]);

            // �������� ���'��
            for (int i = 0; i < k; i++)
                delete[] matrix[i];
            delete[] matrix;

            for (int i = 0; i < k; i++)
                delete[] originalMatrix[i];
            delete[] originalMatrix;
        }
    };
}