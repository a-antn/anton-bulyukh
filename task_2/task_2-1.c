#include <float.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** @brief Получает значение первого числа
 * @param order порядковый номер числа, тип int
 * @return Полученное число типа double, -1 в случае ошибки ввода
 */
double get_number();

/** @brief Получает значение выбранного пользователем действия с переменными
 * @return Полученное число(номер операции) типа int, -1 в случае ошибки ввода
 */
int get_action();

/**
 * @brief Перечисление действий с переменными
 * @details Amount - Сложение
 *          Difference - Вычитание
 *          Multiplication - Умножение
 *          Division - Деление
 */
typedef enum
{
    AMOUNT = 1,
    DIFFERENCE,
    MULTIPLICATION,
    DIVISION
} ActionType;

/** @brief Точка входа в программу.
 * @return 0 в случае успеха, -1 в случае ошибки ввода
 */
int main(void)
{
    printf("Введите первое число: ");
    const double A = get_number();
    printf("Введите второе число: ");
    const double B = get_number();
    const int Action = get_action();

    switch (Action)
    {
    case AMOUNT:
        printf("Сумма чисел равна: %.2lf\n", A + B);
        break;
    case DIFFERENCE:
        printf("Разность чисел равна: %.2lf\n", A - B);
        break;
    case MULTIPLICATION:
        printf("Произведение чисел равно: %.2lf\n", A * B);
        break;
    case DIVISION:
        if (fabs(B) < DBL_EPSILON)
        {
            printf("Ошибка: Деление на ноль\n");
            exit(EXIT_FAILURE);
        }
        printf("Частное чисел равно: %.2lf\n", A / B);
        break;
    default:
        fprintf(stderr, "Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

double get_number()
{
    double number = 0;
    if (!scanf("%lf", &number))
    {
        printf("Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    return number;
}

int get_action()
{
    printf("%d Сложение\n%d Вычитание\n%d Умножение\n%d Деление\n", AMOUNT, DIFFERENCE, MULTIPLICATION, DIVISION);
    printf("Выберите операцию с переменными: ");
    int action = 0;
    if (!scanf("%d", &action))
    {
        printf("Ошибка ввода(неверный формат)\n");
        exit(EXIT_FAILURE);
    }
    if (action < AMOUNT || action > DIVISION)
    {
        printf("Ошибка ввода(неверный номер операции)\n");
        exit(EXIT_FAILURE);
    }
    return action;
}
