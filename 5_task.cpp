#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief Считывает целое число с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
int getValue();

/**
 * @brief Считывает вещественное число с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Проверяет, что введенное значение удовлетворяет условию n >= 1
 * @param n Проверяемое значение
 */
void checkN(const int n);

/**
 * @brief Проверяет, что введенное значение удовлетворяет условию e > 0
 * @param e Проверяемое значение
 */
void checkE(const double e);

/**
 * @brief Вычисляет текущий член ряда через предыдущий (рекуррентное соотношение)
 * @param prev_term Предыдущий член ряда
 * @param k Номер текущего члена
 * @return Текущий член ряда
 */
double getNextTerm(double prev_term, int k);

/**
 * @brief Вычисляет сумму первых n членов ряда
 * @param n Количество членов ряда
 * @return Сумма первых n членов ряда
 */
double sumN(const int n);

/**
 * @brief Вычисляет сумму членов ряда, по модулю не меньших e
 * @param e Заданная точность
 * @return Сумма членов ряда, удовлетворяющих условию
 */
double sumE(const double e);

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "Введите количество членов ряда (n >= 1): ";
    int n = getValue();
    checkN(n);
    cout << "Сумма первых " << n << " членов ряда: " << fixed << setprecision(10) << sumN(n) << endl;
    
    cout << "Введите точность (e > 0): ";
    double e = getDouble();
    checkE(e);
    cout << "Сумма членов ряда с точностью " << e << ": " << fixed << setprecision(10) << sumE(e) << endl;
    
    return 0;
}

int getValue() {
    int value;
    cin >> value;
    if (cin.fail()) {
        cerr << "Ошибка ввода: требуется целое число" << endl;
        abort();
    }
    return value;
}

double getDouble() {
    double value;
    cin >> value;
    if (cin.fail()) {
        cerr << "Ошибка ввода: требуется вещественное число" << endl;
        abort();
    }
    return value;
}

void checkN(const int n) {
    if (n < 1) {
        cerr << "Ошибка: n должно быть >= 1" << endl;
        abort();
    }
}

void checkE(const double e) {
    if (e <= 0) {
        cerr << "Ошибка: e должно быть > 0" << endl;
        abort();
    }
}

double getNextTerm(double prev_term, int k) {
    // Рекуррентное соотношение: a_k = -a_{k-1} * (k^4)/((k-1)^4 * k)
    return -prev_term * pow(k, 4) / (pow(k-1, 4) * k);
}

double sumN(const int n) {
    if (n == 0) return 0.0;
    
    double sum = -1.0; // Первый член ряда при k=1: (-1)^1 * 1^4 / 1! = -1
    double current_term = -1.0;
    
    for (int k = 2; k <= n; ++k) {
        current_term = getNextTerm(current_term, k);
        sum += current_term;
    }
    
    return sum;
}

double sumE(const double e) {
    double sum = 0.0;
    double current_term = -1.0; // Первый член ряда
    int k = 1;
    
    while (fabs(current_term) >= e) {
        sum += current_term;
        k++;
        current_term = getNextTerm(current_term, k);
        
        // Защита от бесконечного цикла для очень малых e
        if (k > 1000) break;
    }
    
    return sum;
}
