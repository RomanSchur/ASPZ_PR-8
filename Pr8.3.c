#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* random_array() {
    int *arr = (int*)malloc(10000 * sizeof(int));
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() %1000000000000;
    }
    return arr;
}

int* reverse_array() {
    int *arr = (int*)malloc(10000 * sizeof(int));
    for (int i = 0; i < 10000; i++) {
        arr[i] = 10000 - i - 1;
    }
    return arr;
}

int* sorted_array() {
    int *arr = (int*)malloc(10000 * sizeof(int));
    for (int i = 0; i < 10000; i++) {
        arr[i] = i;
    }
    return arr;
}

double sort_time(int *arr, int size) {    
    clock_t start = clock();
    qsort(arr, size, sizeof(int), compare);
    clock_t end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));
    
    int *arr_rand= random_array();
    double time = sort_time(arr_rand, 10000); 
    printf("Час сортування масиву випадкових чисел: %f секунд\n", time);
    free(arr_rand);

    
    int *arr_rev = reverse_array();      
    double reverse_time = sort_time(arr_rev, 10000); 
    printf("Час сортування зворотньо відсортованого масиву: %f секунд\n", reverse_time);
    free(arr_rev);

    
    int *arr_sort = sorted_array();    
    double sorted_time = sort_time(arr_sort, 10000); // Передаємо розмір явно
    printf("Час сортування вже відсортованого масиву: %f секунд\n", sorted_time);
    free(arr_sort);

    return 0;
}