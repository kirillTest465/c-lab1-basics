#include <stdio.h>

int main()
{
    int x, y, z;
    int not_z, y_and_not_z, result;

    printf("Введите значения x, y, z (0 или 1, через пробел): ");
    scanf("%d %d %d", &x, &y, &z);

    // Вычисление отрицания z
    if (z == 0)
    {
        not_z = 1;
    }
    else
    {
        not_z = 0;
    }

    // Вычисление y ∧ not_z
    if (y == 1 && not_z == 1)
    {
        y_and_not_z = 1;
    }
    else
    {
        y_and_not_z = 0;
    }

    // Вычисление x ∨ (y ∧ not_z)
    if (x == 1 || y_and_not_z == 1)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    printf("Результат: %d\n", result);
    // Можно вывести текстом
    if (result == 1)
    {
        printf("Истина\n");
    }
    else
    {
        printf("Ложь\n");
    }

    return 0;
}