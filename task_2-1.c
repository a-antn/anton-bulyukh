#include <stdio.h>
#include <stdlib.h>

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
enum
{
    Amount,
    Difference,
    Multiplication,
    Division
};
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
    case Amount:
        printf("Сумма чисел равна: %lf", A + B);
        break;
    case Difference:
        printf("Разность чисел равна: %lf", A - B);
        break;
    case Multiplication:
        printf("Произведение чисел равно: %lf", A * B);
        break;
    case Division:
        if (B == 0)
        {
            printf("Ошибка: Деление на ноль");
            abort();
        }
        printf("Частное чисел равно: %lf", A / B);
        break;
    default:
        printf("Ошибка вывода");
        abort();
    }
    return 0;
};

double get_number(int order)
{
    printf("Введите %d число: ", order);
    double number = 0;
    if(!scanf("%lf", &number)==1)
    {
        printf("Ошибка ввода\n");    
        abort();
        
    }
    return number;
};


int get_action()
{
    printf("%d Сложение\n%d Вычитание\n%d Умножение\n%d Деление\n", Amount, Difference, Multiplication, Division);
    printf("Выберите операцию с переменными: ");
    int action;
    if (!scanf("%d", &action) || action < Amount || action < Division)
    {
        printf("Ошибка ввода\n");
        abort();
        
    }
    return action;
};