#include <iostream>
#include <stdlib.h>
#include <iomanip>  // Для форматирования вывода
#include <locale>   // Для locale
#include <limits>  // Для numeric_limits

using namespace std;

/
 * @brief считывает значение с клавиатуры с проверкой ввода
 * @return введенное значение
 */
double getValue();

/
 * @brief переводит значение веса из граммов в унции
 * @param grams - вес в граммах
 * @return вес в унциях
 */
double convertGramsToOunces(double g);

/
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main() {
    // Устанавливаем русскую локаль
    setlocale(LC_ALL, "RU");

    cout << "Введите вес в граммах: ";
    double g = getValue(); // Используем getValue для безопасного ввода

    // Проверка на количество граммов
    if (g <= 0) {
        cout << "Ошибка: Вес должен быть больше 0." << endl;
        return 1; // Выходим из программы с кодом ошибки
    }

    double u = convertGramsToOunces(g);

    cout << fixed << setprecision(2) << "Полученный вес в унциях: " << u << endl; 

    cout << "Нажмите Enter для выхода..."; 
    cin.get(); // Ожидаем нажатия Enter

    return 0;
}

/
 * @brief считывает значение с клавиатуры с проверкой ввода
 * @return введенное значение
 */
double getValue() {
    double value = 0;
    cin >> value;

    if (cin.fail()) {
        cout << "Incorrect value" << endl;
        abort(); // Лучше обработать ошибку более корректно, но для простоты abort()
    }

}

/**
 * @brief переводит значение веса из граммов в унции
 * @param grams - вес в граммах
 * @return вес в унциях
 */
double convertGramsToOunces(double g) {
    const double g_v_u = 28.3;
    return g / g_v_u;
}
