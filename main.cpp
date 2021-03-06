#include <iostream>

using namespace std;

int outArray(int** arr, int rows, int cols) {
    int **arr1 = new int* [rows];//размещает в динамической памяти новый массив указателей
    for (int i = 0; i < rows; i++) {//создание выводного массива
        arr1[i] = new int[cols / 2];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            arr1[i][j] = arr[i][2 * j + 1];
        }
    }

    cout << "Output matrix:" << endl;//функция, овтечающая за вывод матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            cout << arr1[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr1[i];
    }
    delete[] arr1;
//delete []arr, delete []arr1 - удаление динамических массовов за ненадобностью
    return 0;
}

int main() {
    int rows, cols, inArr = 0;
    cout << "Enter rows count:" << endl;//ввод количества строк
    cin >> rows;
    cout << "Enter columns count:" << endl;//ввод количества столбцов
    cin >> cols;

//int **arr - выделение памяти для хранения указателя
//(который может указывать на другой указатель, который указывает на int)
//**arr адресует на arr[0][0]
//двойной указатель - на двумерный массив, массив из массивов

    int **arr = new int* [rows];//размещает в динамической памяти новый массив указателей
    for (int i = 0; i < rows; i++) {//создание исходного массива
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inArr++;
            arr[i][j] = inArr;
        }
    }

    cout << "Input matrix:" << endl;
    for (int i = 0; i < rows; i++) {//вывод исходного массива
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;

    outArray(arr, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}