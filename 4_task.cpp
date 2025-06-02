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
    setlocale(LC_ALL, "RU");
    cout << "Введите начало интервала (xstart): ";
    double xstart = getValue();
    cout << "Введите конец интервала (xend): ";
    double xend = getValue();
    checkInterval(xstart, xend);  // Проверка, что 0 не входит в интервал

    cout << "Введите шаг (step): ";
    double step = getValue();
    checkStep(step);

    cout << fixed << setprecision(9);
    cout << "Табулирование функции y = cos(2/x) - 2*sin(1/x) + 1/x" << endl;
    cout << "x\t\ty(x)" << endl;
    cout << "---------------------" << endl;

    for (double x = xstart; x <= xend + numeric_limits<double>::epsilon(); x += step) {
        double y = getY(x);
        if (!isnan(y)) {  // Пропускаем NaN (если x слишком близок к 0)
            cout << x << "\t\t" << y << endl;
        }
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
