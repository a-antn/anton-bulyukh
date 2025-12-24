#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @brief Считывает целое значение из стандартного ввода с проверкой результата scanf
 * @return Считанное значение типа int
 */
int Value();

/**
 * @brief Выводит приглашение, считывает размер массива и проверяет, что он больше нуля
 * @param message Текст приглашения к вводу
 * @return Размер массива в виде size_t
 */
size_t getSize(char* message);

/**
 * @brief Заполняет двумерный массив значениями, введёнными пользователем
 * @param arr Указатель на массив
 * @param rows Количество строк
 * @param columns Количество столбцов
 */
void fillArray(int** arr, const size_t rows,const size_t columns);

/**
 * @brief Выводит двумерный массив на экран в табличном виде
 * @param arr Указатель на массив
 * @param rows Количество строк
 * @param columns Количество столбцов
 */
void printArray(int** arr, const size_t rows,const size_t columns);

/**
 * @brief Заполняет массив псевдослучайными числами в диапазоне, заданном пользователем
 * @param arr Указатель на массив
 * @param rows Количество строк
 * @param columns Количество столбцов
 */
void fillRandom(int** arr, const size_t rows,const size_t columns);

/**
 * @brief Выделяет память под двумерный массив заданного размера
 * @param rows Количество строк
 * @param columns Количество столбцов
 * @return Указатель на выделенный массив
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Освобождает память, выделенную под двумерный массив
 * @param arr Указатель на массив
 * @param rows Количество строк
 */
void freeArray(int** arr, const size_t rows);

/**
 * @brief В каждом столбце находит элемент с минимальным модулем и меняет его знак на противоположный
 * @param copyArr Указатель на массив
 * @param rows Количество строк
 * @param columns Количество столбцов
 */
void replaceMinOpposite(int** copyArr, const size_t rows, const size_t columns);

/**
 * @brief Исключает строки, содержащие глобальный максимум, и выводит оставшиеся строки
 * @param copyArr Указатель на массив
 * @param rows Количество строк
 * @param columns Количество столбцов
 * @return 0 если исключены все строки, иначе 1
 */
int delRowsWithMax(int** copyArr, const size_t rows, const size_t columns);

/**
 * @brief Проверяет корректность диапазона значений min..max
 * @param min Нижняя граница
 * @param max Верхняя граница
 */
void checkRange(const int min, const int max);

/**
 * @brief Создаёт полную копию двумерного массива
 * @param arr Исходный массив
 * @param rows Количество строк
 * @param columns Количество столбцов
 * @return Указатель на новый массив с теми же значениями
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief RANDOM — заполнение массива случайными числами
 * @brief MANUAL — заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении, иначе 1
 */
int main()
{

    size_t rows = getSize("Введите количество строк массива:\n");
    size_t columns = getSize("Введите количество столбцов массива:\n");
    int** arr = getArray(rows,columns);
    printf("Выберите способ заполнения массива:\n%d - случайными числами\n%d - вручную\n", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(arr, rows, columns);
                break;
            case MANUAL:
                fillArray(arr, rows, columns);
                break;
            default:
                printf("Ошибка");
                freeArray(arr, rows);
                return 1;
        }
    printArray(arr, rows, columns);
    int** copyArr = copyArray(arr, rows, columns);
    printf("Замена минимального по модулю элемента в каждом столбце:\n");
    replaceMinOpposite(copyArr, rows, columns);
    printArray(copyArr, rows, columns);
    printf("Удаление строк, содержащих максимальный элемент:\n");
    delRowsWithMax(copyArr, rows, columns);
    freeArray(arr, rows);
    freeArray(copyArr, rows);
    return 0;
}

int Value(void)
    {
        int value = 0;
        int result = scanf("%d", &value);
        if (result != 1){
            fprintf(stderr, "Ошибка ввода");
            exit(1);
        }
        return value;
    }

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ОШИБКА");
        abort();
    }
    return (size_t)value;
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j<columns; j++)
        {
            printf("Введите a[%zu,%zu] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    printf("Ваш массив:\n");
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j=0; j<columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows,const size_t columns)
{
    printf("Введите минимум:\n");
    int min = Value();
    printf("Введите максимум:\n");
    int max = Value();
    checkRange(min, max);
    srand(time(NULL));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (max - min + 1)) + min;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    for (size_t i = 0; i<rows; i++ ) {
        arr[i] = malloc(columns * sizeof(int));
        if (arr == NULL)
        {
            fprintf(stderr,"Ошибка");
            freeArray(arr, rows);
            exit(1);
        }
    }
    return arr;
}

void freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i<rows; i++ )
    {
        free(arr[i]);
    }
    free(arr);
}


void checkRange(const int min, const int max)
{
    if(min > max)
    {
        printf("Ошибка\n");
        exit(1);
    }
}

void replaceMinOpposite(int** copyArr, const size_t rows, const size_t columns) {
    for (size_t j = 0; j < columns; j++) {
        size_t minIndex = 0;
        int minAbs = abs(copyArr[0][j]);
        for (size_t i = 1; i < rows; i++) {
            if (minAbs > abs(copyArr[i][j])) {
                minAbs = abs(copyArr[i][j]);
                minIndex = i;
            }
        }
        copyArr[minIndex][j] = -copyArr[minIndex][j];
    }
}

int** copyArray(int** arr, const size_t rows, const size_t columns) {
    int** copyArr = malloc(rows * sizeof(int*));
    for (size_t i = 0; i<rows; i++ )
    {
        copyArr[i] = malloc(columns * sizeof(int));
    }
    if (copyArr == NULL)
    {
        printf("Ошибка");
        freeArray(copyArr, rows);
        exit(1);
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}

int delRowsWithMax(int** copyArr, const size_t rows, const size_t columns) {
    int max = copyArr[0][0];
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (copyArr[i][j] > max) {
                max = copyArr[i][j];
            }
        }
    }
    for (size_t i = 0; i < rows; i++) {
        bool containsMax = false;
        for (size_t j = 0; j < columns; j++) {
            if (copyArr[i][j] == max) {
                containsMax = true;
                break;
            }
        }
        if (containsMax == true) {
            for (size_t j = 0; j < columns; j++) {
                copyArr[i][j] = 0;
            }
        }
    }
    bool noChoicedRows = true;
    for (size_t i = 0; i < rows; i++) {
        bool noZeroRow = false;
        for (size_t j = 0; j < columns; j++) {
            if (copyArr[i][j] != 0) {
                noZeroRow = true;
                break;
            }
        }
        if (noZeroRow == true) {
            noChoicedRows = false;
            for (size_t j=0; j<columns; j++)
            {
                printf("%5d", copyArr[i][j]);
            }
            printf("\n");
        }
    }
    if (noChoicedRows == true) {
        printf("Все строки были удалены.");
        return 0;
    }
    return 1;
}
