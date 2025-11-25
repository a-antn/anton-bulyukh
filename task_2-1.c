#include <stdio.h>
#include <stdlib.h>

/** @brief Перечисление порядковых номеров чисел
 * @details FIRST - Первое число
 *          SECOND - Второе число
 */
typedef enum{
    FIRST = 1,
    SECOND = 2
} NumberOrder;

/** @brief Получает значение первого числа
 * @param order порядковый номер числа, тип int
 * @return Полученное число типа double, -1 в случае ошибки ввода
 */
double get_number(int order);

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
typedef enum {
    AMOUNT,
    DIFFERENCE,
    MULTIPLICATION,
    DIVISION
} ActionType;

/** @brief Точка входа в программу.
 * @return 0 в случае успеха, -1 в случае ошибки ввода
 */
int main(void)
{
    const double A = get_number(1);
    const double B = get_number(2);
    const int Action = get_action();

    switch (Action)
    {
    case AMOUNT:
        printf("Сумма чисел равна: %lf", A + B);
        break;
    case DIFFERENCE:
        printf("Разность чисел равна: %lf", A - B);
        break;
    case MULTIPLICATION:
        printf("Произведение чисел равно: %lf", A * B);
        break;
    case DIVISION:
        if (B == 0)
        {
            printf("Ошибка: Деление на ноль");
            abort();
        }
        printf("Частное чисел равно: %lf", A / B);
        break;
    default:
        fprintf(stderr, "Ошибка вывода");
        abort();
    }
    return 0;
}

double get_number(int order)
{
    printf("", order);
    double number = 0;
    if(!scanf("%lf", &number)==1)
    {
        printf("Ошибка ввода\n");    
        abort();
        
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
        fprintf(stderr, "Ошибка ввода(неверный формат)\n");
        abort();
        
    }
    else if (action < AMOUNT || action > DIVISION)
    {
        fprintf(stderr, "Ошибка ввода(неверный номер операции)\n");
        abort();
    }
    return action;
}