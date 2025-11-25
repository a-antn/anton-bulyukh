#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief Проверяет, что переменная положительная
 * @param step - Значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief Проверяет, принадлежит ли значение аргумента
 * к ее области определения
 * @param x - Значение аргумента
 * @return True - если значение аргумента принадлежит к ООФ, иначе False
 */
bool defineOOF(const double x);

/**
 * @brief Рассчитывает значение функции по заданной формуле
 * @param x - Значение аргумента
 * @return Значение функции
 */
double getY(const double x);

int main(void) {
    SetConsoleCP(65001); // Установка котировки UTF-8 в поток ввода
    SetConsoleOutputCP(65001); // Установка котировки UTF-8 в поток вывода
    setlocale(LC_ALL, ".UTF-8"); 
    printf("Введите начальное значение x: ");
    const double xStart = getValue();   
    printf("Введите конечное значение x: ");
    const double xEnd = getValue();
    printf("Введите шаг: ");
    const double step = getValue();
    checkStep(step);
    for (double x = xStart; x <= xEnd+DBL_EPSILON; x = x + step) {
        if (defineOOF(x)) {
            printf("x = %.2lf, y = %.4lf\n", x, getY(x));
        } 
        else {
            printf("x = %.2lf, не принадлежит области определения функции\n", x);
        }
    }
    return 0;
}

double getValue () {
    double value = 0.0;
    if (!scanf("%lf", &value)) {
        fprintf(stderr, "Ошибка ввода значения X. Неверный тип данных.\n");
        abort();
    } 
    return(value);
}

void checkStep(const double step) {
    if (step <= 0.0) {
        fprintf(stderr, "Ошибка ввода шага. Шаг должен быть положительным числом.");
        abort();
    }
}

bool defineOOF(const double x) {
    return x > 0;
}

double getY(const double x) {
    
    return sin(log(x)) - cos(log(x)) + 2*log(x);
}
