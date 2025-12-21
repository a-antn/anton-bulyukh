#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Рассчитывает сумму чисел по заданным параметрам
 * @param x - значение x
 * @param y - значение y
 * @return Сумма заданных чисел
 */
double summ(const double x, const double y);

/**
 * @brief Рассчитывает разность чисел по заданным параметрам
 * @param x - значение x
 * @param y - значение y
 * @return Разность заданных чисел
 */
double diffirence(const double x, const double y);

/**
 * @brief Рассчитывает произведение чисел по заданным параметрам
 * @param x - значение x
 * @param y - значение y
 * @return Произведение заданных чисел
 */
double multiplication(const double x, const double y);

/**
 * @brief Рассчитывает частное чисел по заданным параметрам
 * @param x - значение x
 * @param y - значение y
 * @return Частное заданных чисел
 */
double division(const double x, const double y);

/** 
 * @brief Точка входа в программу
 * @return 0 В случае успеха
 */
int main(void)
{
    double x;
    double y;
    printf("Введите X: ");
    if(!scanf("%lf", &x)) {
        printf("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    printf("Введите Y: ");
    if (!scanf("%lf", &y)) {
        printf("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    printf("x + y = %lf\nx - y = %lf\nx * y = %lf\nx / y = %lf\n", summ(x, y), diffirence(x, y), multiplication(x, y), division(x, y));
    return 0;
}

double summ(const double x, const double y)
{
    return x + y;
}

double diffirence(const double x, const double y)
{
    return x - y;
}

double multiplication(const double x, const double y)
{
    return x * y;
}

double division(const double x, const double y)
{
    return x / y;
}
