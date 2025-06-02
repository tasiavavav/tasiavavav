#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

/**
 * @brief Получает целочисленное значение из ввода пользователя
 * @return Введенное пользователем целое число
 */
int getValue();

/**
 * @brief Получает размер массива из ввода пользователя
 * @return Размер массива как size_t
 */
size_t getSize();

/**
 * @brief Проверяет корректность размера массива
 * @param n - проверяемый размер
 */
void checkN(const int n);

/**
 * @brief Создает новый двумерный массив
 * @param m - количество строк
 * @param n - количество столбцов
 * @return Указатель на созданный массив
 */
int** getNewArray(const size_t m, const size_t n);

/**
 * @brief Выводит двумерный массив в консоль
 * @param array - указатель на массив
 * @param m - количество строк
 * @param n - количество столбцов
 */
void printArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заполняет массив значениями из ввода пользователя
 * @param array - указатель на массив
 * @param m - количество строк
 * @param n - количество столбцов
 */
void fillArray(int** array, const size_t m, const size_t n);

/**
 * @brief Меняет знак максимального по модулю элемента в каждой строке
 * @param array - указатель на массив
 * @param m - количество строк
 * @param n - количество столбцов
 */
void changeMaxAbsElementInLine(int** array, const size_t m, const size_t n);

/**
 * @brief Находит индекс максимального по модулю элемента в строке
 * @param array - указатель на строку массива
 * @param n - количество элементов в строке
 * @return Индекс максимального по модулю элемента
 */
size_t getMaxAbsIndexInLine(int* array, const size_t n);

/**
 * @brief Освобождает память, занятую двумерным массивом
 * @param array - указатель на массив
 * @param m - количество строк
 * @param n - количество столбцов
 */
void deleteArray(int** array, const size_t m, const size_t n);

/**
 * @brief Создает копию двумерного массива
 * @param array - указатель на исходный массив
 * @param m - количество строк
 * @param n - количество столбцов
 * @return Указатель на копию массива
 */
int** copyArray(int** array, const size_t m, const size_t n);

/**
 * @brief Вставляет первую строку после каждой четной строки
 * @param array - указатель на массив
 * @param m - ссылка на количество строк (изменяется при вставке)
 * @param n - количество столбцов
 * @return Указатель на новый массив с вставленными строками
 */
int** insertFirstLineAfterEven(int** array, size_t& m, const size_t n);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне
 * @param array - указатель на массив
 * @param m - количество строк
 * @param n - количество столбцов
 * @param start - начало диапазона
 * @param end - конец диапазона
 */
void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end);

using namespace std;

enum { MANUAL = 1, RANDOM = 2 };

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    cout << "Enter m: ";
    size_t m = getSize();
    cout << "Enter n: ";
    size_t n = getSize();

    int** array = getNewArray(m, n);

    cout << "Enter the way to fill array: " << (int)MANUAL <<
        " to fill manually, " << (int)RANDOM << " to fill randomly: ";
    int choice = getValue();
    int start = 0;
    int end = 0;

    switch (choice)
    {
    case RANDOM:    cout << "Enter start: ";
        start = getValue();
        cout << "Enter end: ";
        end = getValue();
        fillRandom(array, m, n, start, end);
        break;
    case MANUAL:    fillArray(array, m, n);
        break;
    default:        cout << "Error" << endl;
        return 1;
    }

    cout << "\nOriginal array:" << endl;
    printArray(array, m, n);

    int** arrayCopy1 = copyArray(array, m, n);
    changeMaxAbsElementInLine(arrayCopy1, m, n);
    cout << "\nArray after changing max absolute elements:" << endl;
    printArray(arrayCopy1, m, n);
    deleteArray(arrayCopy1, m, n);

    size_t new_m = m;
    int** arrayCopy2 = insertFirstLineAfterEven(array, new_m, n);
    cout << "\nArray after inserting first line after even lines:" << endl;
    printArray(arrayCopy2, new_m, n);
    deleteArray(arrayCopy2, new_m, n);

    deleteArray(array, m, n);

    return 0;
}

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end)
{
    srand(time(0));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            array[i][j] = rand() % (end - start + 1) + start;
        }
    }
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Error" << endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Error" << endl;
        abort();
    }
}

int** getNewArray(const size_t m, const size_t n)
{
    int** array = new int* [m];
    for (size_t i = 0; i < m; i++)
    {
        array[i] = new int[n];
    }
    return array;
}

void printArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << setw(6) << array[i][j];
        }
        cout << endl;
    }
}

void fillArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << "Enter array[" << i << "," << j << "] = ";
            array[i][j] = getValue();
        }
    }
}

size_t getMaxAbsIndexInLine(int* array, const size_t n)
{
    size_t maxIndex = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (abs(array[i]) > abs(array[maxIndex]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void changeMaxAbsElementInLine(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        size_t maxIndex = getMaxAbsIndexInLine(array[i], n);
        array[i][maxIndex] = -array[i][maxIndex];
    }
}

int** copyArray(int** array, const size_t m, const size_t n)
{
    int** result = getNewArray(m, n);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            result[i][j] = array[i][j];
        }
    }
    return result;
}

void deleteArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

int** insertFirstLineAfterEven(int** array, size_t& m, const size_t n)
{

    size_t evenLines = m / 2;
    size_t new_m = m + evenLines;

    int** newArray = getNewArray(new_m, n);

    size_t newIndex = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            newArray[newIndex][j] = array[i][j];
        }
        newIndex++;

        if ((i + 1) % 2 == 0)
        {
            for (size_t j = 0; j < n; j++)
            {
                newArray[newIndex][j] = array[0][j];
            }
            newIndex++;
        }
    }

    m = new_m;
    return newArray;
}
