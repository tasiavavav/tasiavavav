#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Получает значение с клавиатуры с проверкой ввода
 * @return Возвращает значение, если оно корректное, иначе завершает программу
 */
double getValue();

/**
 * @brief Вычисляет значение функции y = cos(2/x) - 2*sin(1/x) + 1/x
 * @param x Входное значение
 * @return Результат вычисления функции
 */
double calculate_expression(const double x);

/**
 * @brief Проверяет, что шаг положительный
 * @return Положительный шаг
 */
double getPositiveStep();

/**
 * @brief Проверяет, что значение x входит в область определения функции (x ≠ 0)
 * @param x Проверяемое значение
 * @return true, если x ≠ 0, иначе false
 */
bool isInDomain(double x);

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getValue();
    
    cout << "Введите конечное значение x: ";
    double endX = getValue();
    
    cout << "Введите шаг: ";
    double step = getPositiveStep();
    
    cout << "x | y" << endl;
    cout << "--------" << endl;

    for (double x = startX; x <= endX + numeric_limits<double>::epsilon(); x += step)
    {
        if (isInDomain(x))
        {
            double y = calculate_expression(x);
            cout << x << " | " << y << endl;
        }
        else
        {
            cout << x << " | Функция не определена (x=0)" << endl;
        }
    }
    
    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    
    if (cin.fail())
    {
        cerr << "Некорректное значение. Программа будет завершена." << endl;
        exit(EXIT_FAILURE);
    }
    
    return value;
}

double calculate_expression(const double x) 
{
    return cos(2.0 / x) - 2.0 * sin(1.0 / x) + 1.0 / x;
}

double getPositiveStep()
{
    double step = getValue();
    
    if (step <= 0)
    {
        cerr << "Ошибка: шаг должен быть положительным. Программа будет завершена." << endl;
        exit(EXIT_FAILURE);
    }
    
    return step;
}

bool isInDomain(double x)
{
    return fabs(x) > numeric_limits<double>::epsilon();
}
