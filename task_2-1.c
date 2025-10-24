#include <stdio.h>
/** @brief Получает значение первого числа
 * @param order порядковый номер числа, тип int
 * @return Полученное число типа double
 */
double get_number(int order);
/** @brief Получает значение выбранного пользователем действия с переменными
 * @return Полученное число(номер операции) типа int
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
 * @return 0 в случае успеха
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
        printf("Частное чисел равно: %lf", A / B);
        break;
    default:
        printf("Ошибка вывода");
        return 1;
    }
    return 0;
};

double get_number(int order)
{
    printf("Введите %d число: ", order);
    double number = 0;
    scanf("%lf", &number);
    return number;
};

int get_action()
{
    printf("%d Сложение\n%d Вычитание\n%d Умножение\n%d Деление\n", Amount, Difference, Multiplication, Division);
    printf("Выберите операцию с переменными: ");
    int action;
    scanf("%d", &action);
    return action;
};