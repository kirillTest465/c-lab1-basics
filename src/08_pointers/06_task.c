#include <stdio.h> // Подключаем библиотеку для ввода и вывода

int main()
{

    // Инициализируем целочисленный массив
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Количество элементов массива
    int size = sizeof(array) / sizeof(array[0]);

    // Инициализируем два указателя на первый и на послейдний элементы массива
    int *left = &array[0]; // указатель на первый элемент массив
    int *right = &array[size - 1];

    // Выводим исходный массив
    printf("Исходный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    while (left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;

        // сдвигаем указатели навстречу друг к другу
        left++;
        right--;
    }

    // Выводим новый массив
    printf("Развернутый массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0; // успешное завершение программы
}