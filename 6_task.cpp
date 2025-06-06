#include <iostream>
using namespace std;

/**  
 * Получение числа от пользователя с обработкой ошибок  
 * @return Введенное пользователем число  
 */  
int getValue();  

/**  
 * Получение размера массива от пользователя с обработкой ошибок  
 * @return Размер массива  
 */  
size_t getSize();  

/**  
 * Проверка корректности размера массива (n > 0)  
 * @param n Размер массива для проверки  
 */  
void checkN(const int n);  

/**  
 * Заполнение массива значениями, введенными пользователем  
 * @param arr Указатель на массив  
 * @param n Размер массива  
 */  
void fillArray(int* arr, const int n);  

/**  
 * Вывод значений массива на экран  
 * @param arr Указатель на массив  
 * @param n Размер массива  
 */  
void printArray(int* arr, const int n);  

/**  
 * Замена последних k элементов массива на противоположные  
 * @param arr Указатель на массив  
 * @param n Размер массива  
 * @param k Количество элементов для замены  
 */  
void replaceLastElements(int* arr, const int n, int k);  

/**  
 * Вывод индексов элементов массива, кратных 3  
 * @param arr Указатель на массив  
 * @param n Размер массива  
 */  
void printIndicesMultiplesOf3(int* arr, const int n);  

/**  
 * Проверка наличия пары соседних элементов с заданной суммой  
 * @param arr Указатель на массив  
 * @param n Размер массива  
 * @param targetSum Целевая сумма для проверки  
 * @return true если найдена пара, иначе false  
 */  
bool hasPairWithSum(int* arr, const int n, int targetSum);  

/**  
 * Создание копии массива  
 * @param arr Указатель на исходный массив  
 * @param n Размер массива  
 * @return Указатель на новый массив-копию  
 */  
int* copyArray(int* arr, const int n);  

int main() {  
    // Получение размера массива от пользователя  
    size_t n = getSize();  
    int* arr = new int[n];  
    // Заполнение массива  
    fillArray(arr, n);  

    // Задание 1: Замена последних k элементов на противоположные  
    cout << "Введите количество элементов для замены: ";  
    int k = getValue();  
    replaceLastElements(arr, n, k);  
    cout << "Массив после замены " << k << " элементов: ";  
    printArray(arr, n);  

    // Задание 2: Вывод индексов элементов, кратных 3  
    cout << "Индексы элементов, кратных 3: ";  
    printIndicesMultiplesOf3(arr, n);  

    // Задание 3: Проверка наличия пары соседних элементов с заданной суммой  
    cout << "Введите сумму для проверки: ";  
    int targetSum = getValue();  
    if (hasPairWithSum(arr, n, targetSum)) {  
        cout << "Есть пара соседних элементов с суммой " << targetSum << endl;  
    } else {  
        cout << "Нет пары соседних элементов с суммой " << targetSum << endl;  
    }  

    delete[] arr;  
    return 0;  
}  

// Функция для получения одного числа от пользователя  
int getValue() {  
    int value = 0;  
    cin >> value;  
    if (cin.fail()) {  
        cout << "Ошибка ввода" << endl;  
        exit(1);  
    }  
    return value;  
}  

// Функция для получения размера массива  
size_t getSize() {  
    cout << "Введите размер массива n: ";  
    int n = getValue();  
    checkN(n);  
    return static_cast<size_t>(n);  
}  

// Функция для проверки корректности размера массива  
void checkN(const int n) {  
    if (n <= 0) {  
        cout << "Ошибка: размер массива должен быть положительным" << endl;  
        exit(1);  
    }  
}  

// Функция для заполнения массива  
void fillArray(int* arr, const int n) {  
    for (size_t i = 0; i < n; i++) {  
        cout << "Введите arr[" << i + 1 << "]: ";  
        arr[i] = getValue();  
    }  
}  

// Функция для вывода массива  
void printArray(int* arr, const int n) {  
    for (size_t i = 0; i < n; i++) {  
        cout << arr[i] << " ";  
    }  
    cout << endl;  
}  

// Задание 1: Замена последних k элементов на противоположные  
void replaceLastElements(int* arr, const int n, int k) {  
    if (n <= 0 || k <= 0) {  
        cout << "Некорректные значения" << endl;  
        return;  
    }  

    for (size_t i = n - k; i < n; i++) {  
        arr[i] = -arr[i];  
    }  
}
// Задание 2: Вывод индексов элементов, кратных 3  
void printIndicesMultiplesOf3(int* arr, const int n) {  
    bool found = false;  
    for (size_t i = 0; i < n; i++) {  
        if (arr[i] % 3 == 0) {  
            cout << i << " ";  
            found = true;  
        }  
    }  
    if (!found) {  
        cout << "Нет элементов, кратных 3";  
    }  
    cout << endl;  
}  

// Задание 3: Проверка наличия пары соседних элементов с заданной суммой  
bool hasPairWithSum(int* arr, const int n, int targetSum) {  
    if (n < 2) return false;  

    for (size_t i = 0; i < n - 1; i++) {  
        if (arr[i] + arr[i + 1] == targetSum) {  
            return true;  
        }  
    }  
    return false;  
}  

// Функция для создания копии массива  
int* copyArray(int* arr, const int n) {  
    int* copyArr = new int[n];  
    for (size_t i = 0; i < n; i++) {  
        copyArr[i] = arr[i];  
    }  
    return copyArr;  
}
