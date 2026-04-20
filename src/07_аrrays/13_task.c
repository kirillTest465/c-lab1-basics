#include <stdio.h> // Библиотека для ввода и вывода

int main()
{
    int dim = 4;
    int i, j, N[dim], n[dim], num;
    num = 1;
    for (i = 0; i < dim; i++)
    {
        N[i] = i + 2;
        num *= N[i];
        n[i] = 0;
    }
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < dim; j++)
        {
            printf("%d ", n[j]);
        }
        printf("\n");

        j = dim - 1;
        do
        {
            n[j] = (n[j] + 1) % N[j];
        } while (n[j] == 0 && --j >= 0);
    }
}