#include <stdio.h> // Подключаем библиотеку для ввода и вывода

int main()
{
    // Объявляем и заполняем массив
    int array[] = {10, 20, 30, 40, 50};

    // Количество элементов массива
    int size = sizeof(array) / sizeof(array[0]);

    // Целевой массив такой же длины
    int destination[size];

    // Указатели на начала массивов
    int *array_ptr = array;             // Указывает на первый элемент массива array
    int *destination_ptr = destination; // Указывает на первый элемент массива destination

    // Копируем пока не дойдем до конца исходного массива
    for (int i = 0; i < size; i++)
    {
        *destination_ptr = *array_ptr; // Копируем значение на которое указывает array_ptr в ячейку destination_ptr

        array_ptr++;       // Сдвигаем указатель исходного массива вправо
        destination_ptr++; // Сдвигаем указатель целевого массива вправо
    }

    // Вывод исходного массива для проверки
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Вывод исходного массива
    for (int i = 0; i < size; i++)
    {
        printf("%d ", destination[i]);
    }
    printf("\n");

    return 0; // Успешное завершение программы
}