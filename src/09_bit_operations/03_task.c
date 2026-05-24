#include <stdio.h> // Подключаем библиотеку для ввода и вывода

int main()
{
    int num; // Переменная для хранения введенного числа

    // Ввод числа
    printf("Введите целое число: ");
    scanf("%d", &num);

    // Умножение на 8: сдвиг влево на 3 бита
    int multiplied = num << 3;

    // Делениие на 8: сдвиг вправо на 3 бита
    int divided = num >> 3;

    // Вывод операций на числом
    printf("%d * 8 = %d\n", num, multiplied);
    printf("%d / 8 = %d\n", num, divided);

    // Вывод двоичного представления для наглядности
    printf("Двоичное представление %d: ", num);
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i != 0)
        {
            printf(" ");
        }
    }

    printf("\n");

    printf("После сдвига влево на 3: ");
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (multiplied >> i) & 1);
        if (i % 4 == 0 && i != 0)
            printf(" ");
    }
    printf("\n");

    printf("После сдвига вправо на 3: ");
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (divided >> i) & 1);
        if (i % 4 == 0 && i != 0)
            printf(" ");
    }
    printf("\n");

    return 0; // Успешное завершение программы
}