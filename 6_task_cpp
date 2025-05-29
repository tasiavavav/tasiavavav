#include <iostream> 
#include <cstdlib> 
#include <ctime> 
using namespace std;

/**
 * @brief считывает значение с клавиатуры и проверяет
 * @return введенное значение
 */
int getValue();

/**
 * @brief считывает значение с клавиатуры n и использует для проверки checkN()
 * @return введенное значение массива
 */
size_t getSize();

/**
 * @brief проверяет, что размер массива положительный
 * @param n - количество элементов массива
 * @throws завершает программу, если n <= 0
 */
void checkN(const int n);

/**
 * @brief заполняет массив значениями, введёнными пользователем.
 * @param arr  массив для заполнения
 * @param n - размер массива
 * @details заполняет каждый элемент через getValue()
 */
void fillArray(int* arr, const int n);

/**
 * @brief заполняет массив случайными числами в диапазоне [-10, 10].
 * @param arr - массив для заполнения
 * @param n - размер массива
 * @details использует rand() для генерации значений
 */
void fillArrayRandom(int* arr, const int n);

/**
 * @brief создает копию массива
 * @param arr - исходный массив
 * @param n - размер массива
 * @return указатель на новый массив-копию
 */
int* copyArray(int* arr, const int n);

/**
 * @brief выводит элементы массива в консоль
 * @param arr - указатель на массив
 * @param n - размер массива (выводит n элементов)
 */
void printArray(int* arr, const int n);

/**
 * @brief вычисляет сумму нечётных элементов массива
 * @param arr - указатель на массив
 * @param n - количество элементов
 * @return int - сумма нечётных элементов
 */
int sumOfElements(int* arr, const int n);

/**
 * @brief выводит индексы элементов, больших заданного числа A
 * @param arr - указатель на массив
 * @param n - количество элементов
 * @param A - число для сравнения
 */
void printIndicesGreaterThanA(int* arr, const int n, int A);

/**
 * @brief заменяет второй элемент на максимальный отрицательный
 * @param arr - указатель на массив
 * @param n - количество элементов
 * @details Если отрицательных нет, массив не изменяется
 */
void replaceSecondWithMaxNegative(int* arr, const int n);

/**
 * @brief Находит индекс первого отрицательного элемента в массиве
 * @param arr - указатель на массив
 * @param n - количество элементов
 * @return индекс первого отрицательного элемента или -1, если таких нет
 */
int findFirstNegativeIndex(int* arr, int n);

enum Range
{
    min_r = -10,
    max_r = 10
};

enum {
    FArray = 1,
    FRandom = 2
};

/**
* @brief точка входа в программу
* @return 0, если программа выполнена корректно, иначе 1
*/
int main()
{
    srand(time(0)); //инициализирование генератора rand(), чтобы при каждом запуске программы были разные случайные числа 
    size_t n = getSize(); //size_t беззнаковый целочисленный тип, используется  для индексов и размера массива 
    int* arr = new int[n]; //int* — это указатель на целое число, используетсяс для передачи массивов в функции 
    cout << "Enter the way to fill array: " << (int)FArray << " to find manually, " << (int)FRandom << " to fill randomly ? ";
    int choice = getValue();
    switch (choice)
    {
    case FArray:
        fillArray(arr, n);
        break;
    case FRandom:
        fillArrayRandom(arr, n);
        break;
    default:
        cout << "Invalid choice" << endl;
        delete[] arr;
        return 1;
    }
    int* arrCopy = copyArray(arr, n); // Создаем копию исходного массива 
    cout << "Original array: ";
    printArray(arr, n);
    cout << "Sum of odd elements: " << sumOfElements(arrCopy, n) << endl;// сумма нечетных чисел 
    cout << "Enter number A: ";
    int A = getValue();
    printIndicesGreaterThanA(arrCopy, n, A); //вывод чисел, которые больше А 

    replaceSecondWithMaxNegative(arrCopy, n); //замена второго элемента самым большим из отрицательных 
    cout << "Array after replacement: ";
    printArray(arrCopy, n);
    cout << "Original array: ";
    printArray(arr, n);

    delete[] arr;
    delete[] arrCopy;
    return 0;
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
    cout << "Enter n: ";
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

void fillArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i + 1 << "] = ";
        arr[i] = getValue();
    }
}

void fillArrayRandom(int* arr, const int n) {
    srand(time(0)); // Инициализация генератора случайных чисел 
    for (size_t i = 0; i < n; i++) {
        arr[i] = min_r + rand() % (max_r - min_r + 1);  // Генерация числа в диапазоне[-10, 10] //rand() % (max - min + 1) + min 
    }
}

int* copyArray(int* arr, const int n)
{
    int* newArr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }
    return newArr;
}

void printArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumOfElements(int* arr, const int n)
{
    int result = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (abs(arr[i]) % 2 == 1)
        {
            result += arr[i];
        }
    }
    return result;
}

void printIndicesGreaterThanA(int* arr, const int n, int A)
{
    cout << "Indices of elements greater than " << A << ": ";
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > A)
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int findFirstNegativeIndex(int* arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            return i;
        }
    }
    return -1;
}

void replaceSecondWithMaxNegative(int* arr, const int n)
{
    int maxNegIndex = findFirstNegativeIndex(arr, n);
    if (maxNegIndex == -1)
    {
        return;
    }
    for (size_t i = maxNegIndex + 1; i < n; i++)
    {
        if (arr[i] < 0 && arr[i] > arr[maxNegIndex])
        {
            maxNegIndex = i;
        }
    }
    if (maxNegIndex != -1 && n > 1)
    {
        int temp = arr[1];
        arr[1] = arr[maxNegIndex];
        arr[maxNegIndex] = temp;
    }
}
