#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
int getValue();

/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
double getDouble();

/**
 * @brief проверяет, что введенное значение удовлетваряет условию n>=1
 * @param n считанное значение
*/
void checkN(const int n);

/**
 * @brief Рассчитывает сумму n первых членов ряда
 * @param n заданное число членов
 * @return сумму n первых членов ряда
*/
double sumN(const int n);

/**
 * @brief Рассчитывает следующий член ряда через рекуррентное выражение
 * @param current текущий член ряда
 * @param k текущий индекс
 * @param factorial текущее значение факториала
 * @return следующий член ряда
*/
double getNext(double& current, const int k, double& factorial);

/**
 * @brief проверяет, что введенное значение удовлетваряет условию e>0
 * @param e считанное значение
*/
void checkE(const double e);

/**
 * @brief Рассчитывает сумму первых членов ряда, не превышающих по модулю e
 * @param e заданная точность
 * @return сумму первых членов ряда, не превышающих по модулю e
*/
double sumE(const double e);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена верно
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число членов ряда для рассчета последовательности: ";
    int n = getValue();
    checkN(n);
    cout << "a)Сумма " << n << " членов ряда равна " << sumN(n) << endl;
    cout << "b)Введите погрешность для рассчета последовательности: ";
    double e = getDouble();
    checkE(e);
    cout << "b)Сумма членов ряда с точностью е равна " << sumE(e) << endl;
    return 0;
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
    return value;
}

double getDouble()
{
    double value = 0.0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        abort();
    }
    return value;
}

void checkN(const int n)
{
    if (n < 1)
    {
        cout << "Ошибка ввода: n должно быть >= 1" << endl;
        abort();
    }
}

double sumN(const int n)
{
    double result = 0.0;
    double current = 0.0;
    double factorial = 1.0; // 0! = 1

    for (int k = 1; k <= n; ++k)
    {
        current = getNext(current, k, factorial);
        result += current;
    }
    return result;
}

double getNext(double& current, const int k, double& factorial) //  & Ссылка на переменную, хранящую текущий член ряда (может быть модифицирована внутри функции).
// double& factorial - Чтобы обновлять факториал между вызовами без пересчета с нуля
//

{
    factorial *= k; // k! = (k-1)! * k | // Меняет оригинальный factorial
    double sign = (k % 2 == 0) ? 1.0 : -1.0; // разбор числа k оно нак полож так и отриц потому что (-1)*k
    current = sign * pow(k, 4) / factorial; // sign = (-1)*k * k^4 / k! |  // Меняет оригинальный current
    return current;
}

void checkE(const double e)
{
    if (e <= 0)
    {
        cout << "Ошибка ввода: e должно быть > 0" << endl;
        abort();
    }
}

double sumE(const double e)
{
    double result = 0.0; // Общая сумма ряда
    double current = 0.0; // Текущий член ряда
    double factorial = 1.0; // Начинаем с 0! = 1
    int k = 1;  // Номер текущего члена (начинаем с k=1)
    // Пока текущий член по модулю >= e, добавляем его к сумме
    while (fabs(current) >= e)
    {
        result += current; // Добавляем член к сумме
        k++;// Переходим к следующему k
        current = getNext(current, k, factorial);// Вычисляем следующий член
    }
    return result;
}
