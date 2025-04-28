#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;
/**
 * @brief - Функция для вычисления y
 * @return - возвращает значение y
 */
double getY(const double x);
/**
 * @brief считывает значение с клавиатуры с проверкой ввода
 * @return введенное значение
 */
double getValue();
/**
 * @brief проверяет существование шага
 * @param step - шаг
 */
void checkStep(const double step);
/**
 *@brief - Точка входа в программу
 *@return - возвращает 0, если программа выполнена корректно
 */
int main() {
    // russification
    setlocale(LC_ALL, "RU");
    // Ввод данных
    cout << "Введите начало интервала (xstart): ";
    double xstart = getValue();
    // Ввод конца интервала
    cout << "Введите конец интервала (xend): ";
    double xend = getValue();
    // Ввод шага
    cout << "Введите шаг (step): ";
    double step = getValue();
    checkStep(step);
    cout << fixed << setprecision(9);
    // Табулирование функции
    cout << "Табулирование функции y = cos(2/x) - 2*sin(1/x) + 1/x" << endl;
    cout << "x\t\ty(x)" << endl;
    cout << "---------------------" << endl;
    for (double x = xstart; x <= xend + numeric_limits<double>::epsilon(); x += step) {
        cout << x << "\t\t" << getY(x) << endl;
    }
    return 0;
}

double getValue()
{
    double value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Incorrect value" << endl;
        abort();
    }
    return value;
}
void checkStep(const double step)
{
    if (step <= 0)
    {
        cout << "Error value" << endl;
        abort();
    }
}
double getY(const double x) {
    return  cos(2.0 / x) - 2.0 * sin(1.0 / x) + 1.0 / x;
}
