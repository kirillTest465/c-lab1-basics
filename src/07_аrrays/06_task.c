#include <stdio.h> // Подключаем библиотеку для ввода и вывода

int main()
{
    // Задаем два отсортированных по возрастанию массива
    int arr1[] = {2, 4, 6, 8, 10, 12, 14, 16};    // Первый массив
    int arr2[] = {1, 3, 5, 7, 9, 11, 13, 15, 17}; // Второй массив

    // Вычисляем размеры массивов
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = size1 + size2;

    // Создаем третий массив для результата
    int result[size3];

    // Индексы для обхода массивов
    int i = 0; // Индекс для arr1
    int j = 0; // Индекс для arr2
    int k = 0; // Индекс для result

    // Слиение пока есть элементы в обоих массивах
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            result[k] = arr1[i];
            i++;
        }
        else
        {

            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Если в первом массиве остались элементы
    while (i < size1)
    {
        result[k] = arr1[i];
        i++;
        k++;
    }

    // Если во втором массиве остались элементы
    while (j < size2)
    {
        result[k] = arr2[j];
        j++;
        k++;
    }

    // Выводим исходные массивы (для наглядности)
    printf("Первый массив: ");
    for (i = 0; i < size1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Второй массив: ");
    for (j = 0; j < size2; j++)
    {
        printf("%d ", arr2[j]);
    }
    printf("\n");

    // Выводим результат слияния
    printf("Результат слияния: ");
    for (k = 0; k < size3; k++)
    {
        printf("%d ", result[k]);
    }
    printf("\n");

    return 0; // Успешное завершение программы
}