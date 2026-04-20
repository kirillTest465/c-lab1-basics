#include <stdio.h>  // Подключаем библиотеку для ввода и вывода
#include <stdlib.h> // Подключаем библиотеку для функции rand
#include <time.h>   // Подключаем библиотеку для функции time

// Устанавливаем константное значение для строки и столбца двухмерного массива
#define ROWS 6
#define COLS 5

int main()
{
    // Инициализация двухмерного массива
    int matrix[ROWS][COLS];

    int row_sums[ROWS] = {0}; // Массив сумм по строкам
    int col_sums[COLS] = {0}; // Массив сумм по столбцам

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Заполнение матрицы случайными числами от 0 до 9999
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            matrix[i][j] = rand() % 10000;
            // Сразу накапливаем суммы по строкам и столбцам
            row_sums[i] += matrix[i][j];
            col_sums[j] += matrix[i][j];
        }
    }

    // Определяем ширину поля для выравнивания (4 символа для от 0 до 9999)
    const int width = 4;

    // Вывод матрицы с суммами строк справа
    printf("Сгенирированная матрица %dx%d:\n\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%*d ", width, matrix[i][j]); // %*d задает ширину через параметр
        }
        // Вывод суммы строки
        printf("| %*d\n", width, row_sums[i]); // Вертикальная черта и сумма
    }

    // Вывод разделительной линии
    for (int j = 0; j < COLS; j++)
    {
        printf("-----");
    }
    printf(" -----\n");

    // Вывод сумм столбцов
    for (int j = 0; j < COLS; j++)
    {
        printf("%*d ", width, col_sums[j]);
    }
    printf("\n");

    return 0;
}
