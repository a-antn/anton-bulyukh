#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define scanf_s scanf

enum
{
    RANDOM = 1,
    MANUAL
};

static const int DIVISOR = 7;

/**
 * @brief Считывает целое число с клавиатуры и завершает программу при ошибке ввода
 * @return Считанное целое значение
 */
int readIntChecked(void);

/**
 * @brief Запрашивает размер массива, выводя подсказку, и проверяет корректность ввода
 * @param prompt Текст подсказки для пользователя
 * @return Размер массива (количество элементов), строго больше нуля
 */
size_t readArraySize(const char *prompt);

/**
 * @brief Заполняет массив значениями, введёнными пользователем
 * @param arr Указатель на массив
 * @param size Количество элементов
 */
void inputArray(int *arr, const size_t size);

/**
 * @brief Печатает элементы массива.
 * @param arr Указатель на массив.
 * @param size Количество элементов.
 */
void printIntArray(const int *arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне [start; end]
 * @param arr Указатель на массив
 * @param size Количество элементов
 */
void fillArrayRandom(int *arr, const size_t size);

/**
 * @brief Создаёт динамическую копию массива
 * @param arr Исходный массив
 * @param size Количество элементов
 * @return Указатель на новый массив-копию
 */
int *cloneArray(const int *arr, const size_t size);

/**
 * @brief Заменяет первый отрицательный элемент значением первого положительного (если оба существуют)
 * @param copyArr Массив, в котором выполняется замена
 * @param size Количество элементов
 * @return 1 если замена выполнена, иначе 0
 */
int swapFirstNegativeWithFirstPositive(int *copyArr, const size_t size);

/**
 * @brief “Удаляет” элементы, кратные 7 и попадающие в диапазон
 * @param copyArr Массив, в котором выполняется операция
 * @param size Количество элементов
 * @return 1 при успешном выполнении, иначе 0
 * @note Фактическое удаление невозможно: подходящие элементы заменяются на 0
 *       затем все нули сдвигаются в конец массива функцией moveZerosToEnd()
 */
int removeMultiplesInRange(int *copyArr, const size_t size);

/**
 * @brief Перемещает все нулевые элементы в конец массива сохраняя порядок ненулевых
 * @param copyArr Массив для преобразования
 * @param size Количество элементов
 * @return Тот же указатель copyArr
 */
int *moveZerosToEnd(int *copyArr, const size_t size);

/**
 * @brief Преобразует массив по правилам задания (формирование массива A на месте).
 * @param copyArr Массив для преобразования
 * @param size Кол-во элементов
 * @return 1 если в итоговом массиве есть ненулевые элементы, иначе 0
 */
int buildArrayA(int *copyArr, const size_t size);

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении
 */
int main(void)
{
    size_t size = readArraySize("Введите размер массива:\n");

    int *arr = (int *)malloc(size * sizeof(*arr));
    if (arr == NULL)
    {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }

    printf("Выберите способ заполнения массива:\n"
           "%d — случайными числами\n"
           "%d — вручную\n",
           RANDOM, MANUAL);

    int choice = readIntChecked();
    switch (choice)
    {
    case RANDOM:
        fillArrayRandom(arr, size);
        break;
    case MANUAL:
        inputArray(arr, size);
        break;
    default:
        fprintf(stderr, "Ошибка: неизвестный вариант.\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    printIntArray(arr, size);

    int *copyArr = cloneArray(arr, size);
    swapFirstNegativeWithFirstPositive(copyArr, size);
    printf("\n");

    removeMultiplesInRange(copyArr, size);
    printf("\n");

    buildArrayA(copyArr, size);
    printf("\n");

    free(copyArr);
    free(arr);
    return 0;
}

int readIntChecked(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1)
    {
        fprintf(stderr, "Ошибка ввода.\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

size_t readArraySize(const char *prompt)
{
    printf("%s", prompt);
    int value = readIntChecked();
    if (value <= 0)
    {
        fprintf(stderr, "Ошибка: размер должен быть положительным.\n");
        exit(EXIT_FAILURE);
    }
    return (size_t)value;
}

void inputArray(int *arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент массива #%zu: ", i + 1);
        arr[i] = readIntChecked();
    }
}

void printIntArray(const int *arr, const size_t size)
{
    printf("Текущий массив:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillArrayRandom(int *arr, const size_t size)
{
    printf("Введите начало диапазона:\n");
    const int start = readIntChecked();

    printf("Введите конец диапазона:\n");
    const int end = readIntChecked();

    if (start > end)
    {
        fprintf(stderr, "Ошибка: начало диапазона не может быть больше конца.\n");
        exit(EXIT_FAILURE);
    }

    srand((unsigned)time(NULL));

    const int span = end - start + 1;
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (span > 0) ? (rand() % span + start) : start;
    }
}

int *cloneArray(const int *arr, const size_t size)
{
    int *copyArr = (int *)malloc(size * sizeof(*copyArr));
    if (copyArr == NULL)
    {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int swapFirstNegativeWithFirstPositive(int *copyArr, const size_t size)
{
    printf("Замена первого отрицательного элемента значением первого положительного:\n");

    int firstPositive = 0;
    int firstNegative = 0;
    size_t negativeIndex = 0;

    bool foundPositive = false;
    bool foundNegative = false;

    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] < 0 && !foundNegative)
        {
            firstNegative = copyArr[i];
            foundNegative = true;
            negativeIndex = i;
        }
        if (copyArr[i] > 0 && !foundPositive)
        {
            firstPositive = copyArr[i];
            foundPositive = true;
        }
        if (foundPositive && foundNegative)
        {
            break;
        }
    }

    if (!foundPositive)
    {
        printf("Положительных элементов нет — замена не выполнена.\n");
        return 0;
    }
    if (!foundNegative)
    {
        printf("Отрицательных элементов нет — замена не выполнена.\n");
        return 0;
    }

    (void)firstNegative; /* значение не используется напрямую, оставлено для смысла переменных */
    copyArr[negativeIndex] = firstPositive;

    printf("Результат:\n");
    for (size_t j = 0; j < size; j++)
    {
        printf("%d ", copyArr[j]);
    }
    printf("\n");
    return 1;
}

int removeMultiplesInRange(int *copyArr, const size_t size)
{
    printf("Исключение элементов, кратных %d и попадающих в заданный диапазон.\n", DIVISOR);

    printf("Введите min:\n");
    const int min = readIntChecked();

    printf("Введите max:\n");
    const int max = readIntChecked();

    if (min >= max)
    {
        printf("Некорректный диапазон: max должен быть больше min.\n");
        return 0;
    }

    size_t removed = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] % DIVISOR == 0 && min <= copyArr[i] && copyArr[i] <= max)
        {
            copyArr[i] = 0;
            removed++;
        }
    }

    if (removed == 0)
    {
        printf("Массив не изменился(нет подходящих элементов).\n");
        return 0;
    }
    if (removed == size)
    {
        printf("Массив полностью обнулён.\n");
        return 0;
    }

    moveZerosToEnd(copyArr, size);

    printf("Результат (без нулей):\n");
    for (size_t k = 0; k < size; k++)
    {
        if (copyArr[k] != 0)
        {
            printf("%d ", copyArr[k]);
        }
    }
    printf("\n");
    return 1;
}

int buildArrayA(int *copyArr, const size_t size)
{
    printf("Создание массива А:\n");

    size_t nonZeroCount = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] != 0)
        {
            if (i % 2 == 0)
            {
                copyArr[i] = copyArr[i] * copyArr[i] + (int)i;
            }
            else
            {
                copyArr[i] = copyArr[i] * (int)i;
            }
            nonZeroCount++;
        }

        /* чтобы не ломать общий вид функции, но убрать ошибочный ранний выход */
        if (i == size - 1 && nonZeroCount == 0)
        {
            printf("Ненулевых элементов нет — преобразование не выполнено.\n");
            return 0;
        }
    }

    printf("Результат (без нулей):\n");
    for (size_t j = 0; j < size; j++)
    {
        if (copyArr[j] != 0)
        {
            printf("%d ", copyArr[j]);
        }
    }
    printf("\n");
    return 1;
}

int *moveZerosToEnd(int *copyArr, const size_t size)
{
    size_t nonZeroPos = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] != 0)
        {
            copyArr[nonZeroPos] = copyArr[i];
            nonZeroPos++;
        }
    }

    for (size_t j = nonZeroPos; j < size; j++)
    {
        copyArr[j] = 0;
    }

    return copyArr;
}
