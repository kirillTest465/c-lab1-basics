#include <stdio.h>  // Подключаем библиотеку ввода/вывода
#include <stdlib.h> // Подключаем библиотеку для exit

int main()
{
    int hour; // переменная для ввода времени

    // Ввод времени
    printf("Введите время (Часы от 0 до 23): ");
    scanf("%d", &hour);

    // Проверка корректности ввода
    if (hour < 0 || hour > 23)
    {
        printf("Ошибка: часы должны быть в диапазоне 0-23.\n");
        exit(1); // Завершаем программу с кодом ошибки
    }

    // Выводим приветствие
    switch (hour)
    {
    // Ночь с 22 до 3 часов ночи
    case 22:
    case 23:
    case 0:
    case 1:
    case 2:
    case 3:
        printf("Good Night!\n");
        break;

    // Утро с 4-10
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        printf("Good Morning!\n");
        break;

    // День 11-14
    case 11:
    case 12:
    case 13:
    case 14:
        printf("Good Day!\n");
        break;

    // После полудня 15-16
    case 15:
    case 16:
        printf("Good Afternoon!\n");
        break;

    // Вечер 17-21
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
        printf("Good Evening!\n");
        break;

    // На случай, если вдруг значение не попало ни в один case (но проверка выше исключает это)
    default:
        printf("Неизвестное время.\n");
    }
    return 0; // Успешное завершение программы
}