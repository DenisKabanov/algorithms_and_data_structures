#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min

int exponential_search(int arr[], int arr_size, int target, char bounds_history[], char search_history[])
{
    if(arr_size == 0)
        return -1;
 
    int i = 1;
    while(i < arr_size && arr[i] <= target)
    {
        sprintf(bounds_history, "%s %d(%d)", bounds_history, arr[i], i);
        i = i*2;
    }
    int left = i /2;
    int right = min(i, arr_size-1);
 
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(arr[mid] == target) 
        {
            sprintf(search_history, "%s %d(%d)", search_history, arr[mid], mid);
            return mid;
        }
        else if(arr[mid] < target)
        {
            sprintf(search_history, "%s %d(%d)", search_history, arr[mid], mid);
            left = mid + 1;
        }
        else
        {
            sprintf(search_history, "%s %d(%d)", search_history, arr[mid], mid);
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr_size = 0;
    int target = 0;

    scanf("%d %d", &arr_size, &target);

    int *input_arr = (int*)malloc(arr_size * sizeof(int));
    char *bounds_history = (char*) malloc(arr_size * sizeof(char));
    char *search_history = (char*) malloc(arr_size * sizeof(char));

    for(int i=0; i<arr_size; i++) 
    {
        scanf("%d", &input_arr[i]);
    }
    
    int exp_res = 0;
    exp_res = exponential_search(input_arr, arr_size, target, bounds_history, search_history);

    printf("Initial array:\n");
    for(int i=0; i<arr_size-1; i++)
        printf("%d ", input_arr[i]);
    printf("%d", input_arr[arr_size-1]);
    printf("\nTarget element: %d\n", target);
    if (exp_res != -1){
        printf("Bounds history: %s\n", bounds_history);
        printf("Search history: %s\n", search_history);
        printf("Target is found at: %d\n", exp_res);
    } else {
        printf("No targets\n");
    }

    free(input_arr);
    free(bounds_history);
    free(search_history);
    return 0;
}