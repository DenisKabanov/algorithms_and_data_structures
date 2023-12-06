#include <stdio.h>
#include <stdlib.h>
#include <string.h> // для работы со строками (массивами char)


int main(){
    int arr_size = 0; // переменная под размер входного массива
    int target = 0; // переменная под искомый таргет

    scanf("%d %d", &arr_size, &target); // считывание двух чисел - размер массива и таргет с консоли

    int *input_arr = (int*)malloc(arr_size * sizeof(int)); // динамическое создание массива под входные данные
    char *res = (char*) malloc(sizeof(char)); // динамическое создание массива под вывод
    
    for(int i=0; i<arr_size; i++) { // делаем arr_size раз 
        scanf("%d", &input_arr[i]); // считываем одно число и помещаем его в input_arr (в строке консоли идёт сразу несколько, разделеных пробелом)
        if (input_arr[i] == target){ // если считанное число совпадает с таргетом
            sprintf(res, "%s %d", res, i); // записываем его индекс в строку-ответ
        }
    }

    printf("Initial array:\n"); // вывод "заголовка"
    for(int i=0; i<arr_size; i++) // выводим поэлементно входной массив в одну строку консоли
        printf("%d ", input_arr[i]);
    printf("\nTarget element: %d\n", target); // вывод таргета
    if (strlen(res) > 0){ // если таргет был найден (длина строки>0) — выводим те позиции, где он нашёлся
        printf("Target is found at:%s\n", res);
    } else { // иначе — выводим сообщение об отсутствии таргета во входных данных
        printf("No targets\n");
    }

    free(input_arr); // очищаем память, что была выделена под динамический массив
    free(res); // очищаем память, что была выделена под динамический массив
    return 0; // выходим из функции с возвращением кода 0
}