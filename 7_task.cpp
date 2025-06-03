#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    // Ввод размеров матрицы
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    // Создание и ввод матрицы
    int** matrix = new int*[rows];
    cout << "\nВведите элементы матрицы:\n";
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Вывод исходной матрицы
    cout << "\nИсходная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    // 1. Находим максимальные элементы в каждой строке
    int* row_max = new int[rows];
    for (int i = 0; i < rows; i++) {
        row_max[i] = *max_element(matrix[i], matrix[i] + cols);
    }

    // 2. Заменяем максимальные элементы на противоположные
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == row_max[i]) {
                matrix[i][j] = -row_max[i];
                break;
            }
        }
    }

    cout << "\nПосле замены максимумов:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    // 3. Определяем столбцы, содержащие максимальные элементы (до замены)
    bool* has_max = new bool[cols]();
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == -row_max[i]) { // Ищем измененные максимумы
                has_max[j] = true;
                break;
            }
        }
    }

    // 4. Подсчитываем новые столбцы
    int new_cols = cols;
    for (int j = 0; j < cols; j++) {
        if (has_max[j]) new_cols++;
    }

    // 5. Создаем новую матрицу с нулевыми столбцами
    int** new_matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        new_matrix[i] = new int[new_cols];
    }

    // 6. Заполняем новую матрицу
    int new_j = 0;
    for (int j = 0; j < cols; j++) {
        // Копируем текущий столбец
        for (int i = 0; i < rows; i++) {
            new_matrix[i][new_j] = matrix[i][j];
        }
        new_j++;

        // Вставляем нулевой столбец после столбца с максимумом
        if (has_max[j]) {
            for (int i = 0; i < rows; i++) {
                new_matrix[i][new_j] = 0;
            }
            new_j++;
        }
    }

    // Вывод результата
    cout << "\nРезультат с нулевыми столбцами:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            cout << setw(5) << new_matrix[i][j];
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
        delete[] new_matrix[i];
    }
    delete[] matrix;
    delete[] new_matrix;
    delete[] row_max;
    delete[] has_max;

    return 0;
}
