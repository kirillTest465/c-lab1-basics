#include <stdio.h>  // Подключаем библиотеку для ввода и вывода
#include <stdlib.h> // Подключаем библиотеку для функции rand
#include <time.h>   // Подключаем библиотеку для функции time

#define ROWS 5
#define COLS 6

int main()
{

    // Объявляем указатель на массив указателей на int (указателль на строки)
    int **matrix;

    // Переменная для накопления суммы элементов матрицы
    int sum = 0;

    // Выделяем память под массив указателей на строки (ROWS штук)
    matrix = (int **)malloc(ROWS * sizeof(int *));

    // Проверка
    if (matrix == NULL)
    {
        printf("Ошибка выделения памяти под указатели строк\n");
        return 1; // Завершаем программу с кодом ошибки
    }

    // Для каждой строки выделяем память под COLS целых чисел
    for (int i = 0; i < ROWS; i++)
    {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("Ошибка выделения памяти для строки: %d\n", i);
            // Освобождаем уже выделенные строки
            for (int k = 0; k < i; k++)
                free(matrix[k]);
            free(matrix);
            return 1;
        }
    }

    // Инициализуруем генератор случайных чисел
    srand(time(NULL));

    // Заполняем матрицу случайными числами и считаем сумму
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            matrix[i][j] = rand() % 100; // диапазон от 0 до 99
            sum += matrix[i][j];
        }
    }

    // Выводим матрицу на экран
    printf("Матрица %dx%d (случайные числа):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Выводим сумму всех элементов
    printf("Сумма всех элементов: %d\n", sum);

    // Освобождаем память
    for (int i = 0; i < ROWS; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0; // Успешное завершение программы
}