#include <stdio.h> // Подключаем библиотеку для ввода и вывода

int main()
{
    double num; // Переменная вещественного типа

    printf("Введите вещественное число: ");

    if (scanf("%lf", &num) != 1)
    {
        printf("Ошибка ввода!\n");
        return 1; // Завершаем программу с кодом ошибки
    }

    // Объединение для доступа к битам
    union
    {
        double double_val;
        unsigned long long int_val;

    } u;

    u.double_val = num; // Копируем значение в поле

    unsigned long long bits = u.int_val;

    // Вывод битового образа
    printf("Битовый образ числа %lf (64 бита):\n", num);
    for (int i = 63; i >= 0; i--)
    {
        printf("%d", (int)((bits >> i) & 1ULL));
        if (1 % 4 == 0 && i != 0)
        {
            printf(" ");
        }
    }

    printf("\n");

    int sign = (bits >> 63) & 1;
    int exponent = (bits >> 52) & 0x7FF;
    unsigned long long mantissa = bits & 0xFFFFFFFFFFFFFULL;
    printf("Знак: %d, Порядок: %d, Мантисса: 0x%013llX\n", sign, exponent, mantissa);

    return 0; // Успешное завершение программы
}