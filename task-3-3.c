#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Считывает вещественное число с клавиатуры
 * @return Введённое значение
 */
double getDouble(void);

/**
 * @brief Проверяет корректность границ интервала, требуется min < max
 * @param min нижняя граница интервала
 * @param max верхняя граница интервала
 */
void checkMinMax(const double min, const double max);

/**
 * @brief Проверяет, что шаг положительный
 * @param step значение шага
 */
void checkStep(const double step);

/**
 * @brief Проверяет, что значение строго положительное
 * @param value проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Вычисляет cos(x)
 * @param x аргумент функции
 * @return значение cos(x)
 */
double cosFunc(const double x);

/**
 * @brief Вычисляет множитель рекуррентной формулы для очередного члена ряда
 * @param i номер члена ряда
 * @param x аргумент x
 * @return множитель для перехода к следующему члену
 */
double getRecurent(const int i, const double x);

/**
 * @brief Суммирует ряд для cos(x) до достижения заданной точности e
 * @param e требуемая точность по модулю очередного члена
 * @param x аргумент x
 * @return сумма ряда с заданной точностью
 */
double getSumE(const double e, const double x);

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении, иначе 1
 */
int main(void)
{
    printf("Введите минимальное значение:\n");
    const double min = getDouble();
    printf("Введите максимальное значение:\n");
    const double max = getDouble();
    checkMinMax(min, max);
    printf("Введите шаг:\n");
    const double step = getDouble();
    checkStep(step);
    printf("Введите точность e:\n");
    double e = getDouble();
    checkPositive(e);
    for (double x = min; x < max + step; x += step) {
        printf("x = %.6lf, cos(x) = %.6lf, сумма ряда = %.6lf\n", x, cosFunc(x), getSumE(e, x));
        }
    return 0;
}

double getDouble()
{
    double value = 0;
    const double result = scanf("%lf", &value);
    if (result != 1){
        fprintf(stderr, "Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return value;
}

void checkMinMax(const double min, const double max) {
    if (min > max || fabs(min - max) <= DBL_EPSILON) {
        fprintf(stderr, "Верхняя граница должна быть больше нижней");
        exit(EXIT_FAILURE);
    }
}

void checkStep(const double step) {
    if (step < DBL_EPSILON) {
        fprintf(stderr, "Шаг должен быть больше нуля");
        exit(EXIT_FAILURE);
    }
}

void checkPositive(const double value)
{
    if (value <= 0)
    {
        fprintf(stderr, "Значение должно быть больше нуля");
        exit(EXIT_FAILURE);
    }
}

double cosFunc(const double x) {
    return cos(x);
}

double getRecurent(const int i, const double x)
{
    return -(x * x)/((2 * i - 1) * (2 * i));
}

double getSumE(const double e, const double x)
{
    double current = 1;
    double result = current;
    for (int i = 1; fabs(cosFunc(x) - result) > e; i++)
    {
        current *= getRecurent(i, x);
        result += current;
    }
    return result;
}
