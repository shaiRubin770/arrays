#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_arr(int* arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void merge(int* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* left = malloc(n1 * sizeof(int));
    int* right = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    free(left);
    free(right);
}

void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;  
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int* arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);  
        quick_sort(arr, p + 1, high); 
    }
}

bool binary_search(int* arr, int arr_size, int val) {
    int l = 0, r = arr_size - 1;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (arr[mid] == val) {
            printf("Your number exists at index: %d\n", mid);
            return true;
        }
        else if (val > arr[mid]) l = mid + 1;
        else r = mid - 1;
    }
    printf("Your number does not exist\n");
    return false;
}

int main() {
    printf("Enter the size of the array: ");
    int num;
    scanf_s("%d", &num);
    int* arr = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        arr[i] = rand() % 1000;
    }

    print_arr(arr, num);

    printf("After merge sort:\n");
    merge_sort(arr, 0, num - 1);
    print_arr(arr, num);

    for (int i = 0; i < num; i++) {
        arr[i] = rand() % 1000;
    }
    printf("New numbers in the array:\n");
    print_arr(arr, num);

    printf("After quick sort:\n");
    quick_sort(arr, 0, num - 1);
    print_arr(arr, num);

    printf("Choose number to search: ");
    int search_val;
    scanf_s("%d", &search_val);
    binary_search(arr, num, search_val);

    free(arr);
    return 0;
}
