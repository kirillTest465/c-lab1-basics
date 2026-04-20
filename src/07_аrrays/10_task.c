#include <stdio.h>  // Подключаем библиотеку для ввода и вывода
#include <stdlib.h> // Подключаем библиотеку для функции rand
#include <time.h>   // Подключаем библиотеку для функции time

// Устанавливаем константное значение для размера двухмерного размера
#define SIZE 5

int main()
{

    // Инициализация двухмерного массива
    int matrix[SIZE][SIZE];

    int main_diag_sum = 0;      // Сумма главной диагонали
    int secondary_diag_sum = 0; // Сумма обратной диагонали

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Заполнение матрицы и вывод на экран
    printf("Сгенерированная матрица %dx%d:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 10000; // Число от 0 до 9999
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Вычисление сумм диагоналей
    for (int i = 0; i < SIZE; i++)
    {
        main_diag_sum += matrix[i][i];                 // Элемент главной диагонали
        secondary_diag_sum += matrix[i][SIZE - 1 - i]; // Элемент обратной диагонали
    }

    // Вывод результатов
    printf("\nСумма элементов главной диагонали: %d\n", main_diag_sum);
    printf("Сумма элементов обратной диагонали: %d\n", secondary_diag_sum);

    return 0; // успешное завершение программы
}
