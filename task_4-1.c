#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Получает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return Введенное значение
 */
int getValue(void);

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message сообщение о необходимости ввода массива
 * @return Размер массива
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param array массив
 * @param size размер массива
 */
void fillArray(int* array, const size_t size);

/**
 * @brief Выводит массив
 * @param array Массив
 * @param size Размер массива
 */
void printArray(int* array, const size_t size);

/**
 * @brief Вычисляет сумму чётных элементов массива
 * @param array массив
 * @param size размер массива
 */
void summEven(int* array, const size_t size);

/**
 * @brief Заполняет массив рандомными числами в пределах введённого диапазона
 * @param array массив
 * @param size размер массива
 */
void fillArrayRandom(int* array, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param array  массив
 * @param size размер массива
 * @return полученный массив
 */
int* copiedArray(const int* array, const size_t size);

/**
 * @brief Считает количество двузначных элементов массива
 * @param array массив
 * @param size размер массива
 */
void countDoubleDigitNums(int* array, const size_t size);

/**
 * @brief Заменяет крайний отрицательный элемент массива на модуль первого элемента массива
 * @param copiedArray копия массива
 * @param size размер массива
 * @return Возвращает 1, если функция выполнена корректно, 0 - если в массиве отсутствуют отрицательные элементы
 */
int replace(int* copiedArray, const size_t size);

/**
 * @brief RANDOM - заполнение массива рандомными числами в пределах введённого диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum {
    RANDOM=1,
    MANUAL
};

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void) {
    size_t size = getSize("Введите размер массива: ");
    int* array = malloc(size* sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Ошибка");
        exit(EXIT_FAILURE);
    }
    printf("Выберите способ заполнения массива: ");
    int way = getValue();
    switch (way)
        {
        case RANDOM:
            fillArrayRandom(array, size);
            break;
        case MANUAL:
            fillArray(array, size);
            break;
        default:
            fprintf(stderr, "Ошибка ввода");
            free(array);
            exit(EXIT_FAILURE);
        }
    printArray(array, size);
    summEven(array, size);
    countDoubleDigitNums(copiedArray, size);
    free(copiedArray);
    free(array);
    return 0;
}

int getValue(void) {
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1) {
        fprintf(stderr, "Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return value;
}

size_t getSize(char* message) {
    if (message == NULL) {
        fprintf(stderr, "Ошибка: message не может быть пустым");
        exit(EXIT_FAILURE);
    }
    printf("%s", message);
    int value = getValue();
    if (value <= 0) {
        fprintf(stderr, "Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return (size_t)value;
}

void fillArray(int* array, const size_t size) {
    if (array == NULL && size > 0) {
        fprintf(stderr, "Ошибка: array не может быть пустым.");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        printf("Введите %zu элемент массива: ", i);
        array[i] = getValue();
    }
}

void printArray(const int* array, const size_t size) {
    if (array == NULL && size > 0) {
        fprintf(stderr, "Ошибка: array не может быть пустым.");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

void sumEven(int* array, const size_t size) {
    if (array == NULL && size > 0) {
        fprintf(stderr, "Ошибка: array не может быть пустым.");
        exit(EXIT_FAILURE);
    }
    int result = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            result += array[i];
        }
    }
    printf("Сумма четных чисел %d.\n", result);
}

void fillRandom(int* array, const size_t size) {
    printf("Начало диапазона: ");
    const int start = getValue();
    printf("Конец диапазона: ");
    const int end = getValue();
    if (start >= end) {
        fprintf(stderr, "Ошибка введенного значения.");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % (end - start + 1) + start;
    }
}

int* copiedArray(const int* array, const size_t size) {
    if (array == NULL && size > 0) {
        fprintf(stderr, "Ошибка: array не может быть пустым.");
        exit(EXIT_FAILURE);
    }
    int* copiedArray = malloc(sizeof(int)*size);
    if (copiedArray == NULL) {
        fprintf(stderr, "Ошибка: память не выделена.");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        copiedArray[i] = array[i];
    }
    return copiedArray;
}

void countDoubleDigitNums(int* array, const size_t size) {
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if ((array[i] >= 10 && array[i] <= 99) || (array[i] <= -10 && array[i] >= -99)) {
            count++;
        }
        printf("Кол-во двузначных элементов: %d.\n", count);
    }
}

int replace(int* copiedArray, const size_t size) {
    int firstAbs = abs(copiedArray[0]);
    for (size_t i = size; i > 0; i--) {
        if (copiedArray[i-1] < 0) {
            copiedArray[i-1] = firstAbs;
            printf("Новый массив: \n");
            for (size_t j = 0; j < size; j++) {
                printf("%d", copiedArray[j]);
            }
            printf("\n");
            return 1;
        }
    }
    printf("В массиве нет отрицательных элементов.");
    return 0;
}
