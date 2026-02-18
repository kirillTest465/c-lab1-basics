#include <stdio.h>  // Подключаем библиотеку для ввода/вывода
#include <stdlib.h> // Подключаем библиотеку для exit

int main()
{
    // Объявляем переменные
    double number_1, number_2;

    // Вводим делимое
    printf("Введите делимое: ");
    scanf("%lf", &number_1);

    // Вводим делитель
    printf("Введите делитель: ");
    scanf("%lf", &number_2);

    // Выводим ошибку если делитель равен нулю
    if (number_2 == 0)
    {
        printf("Ошибка: деление на ноль!\n");
        exit(1); // Завершаем программу с кодом ошибки
    }

    // Выводим результат деления
    double result = number_1 / number_2;
    printf("Результат: %.2f\n", result);
    return 0;
}