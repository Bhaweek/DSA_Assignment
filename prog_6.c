#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_min(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify_min(arr, n, smallest);  
    }
}
void heapify_max(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
  
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify_max(arr, n, largest);
    }
}

void build_min_heap(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify_min(arr, n, i);
    }
}

void build_max_heap(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify_max(arr, n, i);
    }
}
void print_array(int arr[], int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
void print_heap(int arr[], int n, const char* heap_type) {
    printf("\n%s:\n", heap_type);
    printf("Array representation: ");
    print_array(arr, n);
    
    printf("\nTree structure:\n");
    int index = 0;
    int level = 0;
    int height = 0;

    int temp = n;
    while (temp > 0) {
        temp = temp / 2;
        height++;
    }
    
    for (level = 0; level < height; level++) {
        int level_size = 1 << level; 
        int remaining = n - index;
        if (remaining <= 0) break;
        
        if (level_size > remaining) {
            level_size = remaining;
        }
       
        int spacing = (1 << (height - level - 1)) - 1;
        int s;
        for (s = 0; s < spacing; s++) {
            printf(" ");
        }
    
        int i;
        for (i = 0; i < level_size; i++) {
            if (index < n) {
                printf("%3d", arr[index]);
                index++;
        
                for (s = 0; s < spacing * 2 + 1; s++) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void copy_array(int source[], int dest[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    int data[] = {12, 11, 13, 5, 6, 7, 15, 3, 9, 8};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Original unsorted array:\n");
    print_array(data, n);
    
    int min_heap_data[n];
    copy_array(data, min_heap_data, n);
    build_min_heap(min_heap_data, n);
    print_heap(min_heap_data, n, "MIN HEAP");
    
    int max_heap_data[n];
    copy_array(data, max_heap_data, n);
    build_max_heap(max_heap_data, n);
    print_heap(max_heap_data, n, "MAX HEAP");

    printf("\nTest with another array:\n");
    int data2[] = {4, 10, 3, 5, 1, 20, 15};
    int n2 = sizeof(data2) / sizeof(data2[0]);
    
    printf("Original: ");
    print_array(data2, n2);
    
    int min_heap_data2[n2];
    copy_array(data2, min_heap_data2, n2);
    build_min_heap(min_heap_data2, n2);
    printf("Min Heap: ");
    print_array(min_heap_data2, n2);
    
    int max_heap_data2[n2];
    copy_array(data2, max_heap_data2, n2);
    build_max_heap(max_heap_data2, n2);
    printf("Max Heap: ");
    print_array(max_heap_data2, n2);
    
    return 0;
}
