#include <stdio.h>  // Подключаем библиотеку для ввода и вывода
#include <stdlib.h> // Подключаем библиотеку для exit

int main()
{
    unsigned int cmd; // Переменная для хранения команды

    // Ввод команды
    printf("Введите 32-битовую команду (в виде целого числа ): ");
    if (scanf("%x", &cmd) != 1)
    {
        printf("Ошибка ввода!\n");
        exit(1); // Завершаем программу с кодом ошибки
    }

    // Извлечение типа операции (два старших бита 31-30)
    unsigned int type = (cmd >> 30) & 0x3;

    // Извлечение кода операции (следующие 4 бита 29-26)
    unsigned int op = (cmd >> 26) & 0xF;

    // Вывод типа и кода операции
    printf("Тип операции: %u\n", type);
    printf("Код операции: %u\n", op);

    // В зависимости от типа извлекаем остальные поля
    switch (type)
    {
    case 0: // F0: 00 | op | a | b | c (каждое по 4 бита)
    {
        unsigned int a = (cmd >> 22) & 0xF;
        unsigned int b = (cmd >> 18) & 0xF;
        unsigned int c = (cmd >> 14) & 0xF;

        printf("Формат F0: a = %u, b = %u, c = %u\n", a, b, c);
    }
    break;

    case 1: // F1: 01 | op | a | b | im
    {
        unsigned int a = (cmd >> 22) & 0xF;
        unsigned int b = (cmd >> 18) & 0xF;
        unsigned int im = (cmd >> 14) & 0xF;
        printf("Формат F1: a=%u, b=%u, im=%u\n", a, b, im);
    }
    break;

    case 2: // F2: 10 | op | a | b | disp
    {
        unsigned int a = (cmd >> 22) & 0xF;
        unsigned int b = (cmd >> 18) & 0xF;
        unsigned int disp = (cmd >> 14) & 0xF;
        printf("Формат F2: a=%u, b=%u, disp=%u\n", a, b, disp);
    }
    break;

    case 3: // F3: 11 | op (остальные биты не используются)
    {
        printf("Формат F3: без дополнительных операндов\n");
    }
    break;

    default:
        printf("Неизвестный тип (ошибка)\n");
    }

    // Дополнительный вывод в шестнадцатиричном виде
    printf("Команда (hex):  0x%08X\n", cmd);

    return 0; // Успешно завершаем программу
}
