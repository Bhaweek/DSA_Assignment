#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comp = 0, swap = 0;

/* Print array */
void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* Bubble Sort */
void bubble(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swap++;
            }
        }
}

/* Selection Sort */
void selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int t = a[i]; a[i] = a[min]; a[min] = t;
            swap++;
        }
    }
}

/* Insertion Sort */
void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && (++comp && a[j] > key)) {
            a[j + 1] = a[j];
            swap++;
            j--;
        }
        a[j + 1] = key;
    }
}

/* Merge Sort helpers */
void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0, temp[r - l + 1];
    while (i <= m && j <= r) {
        comp++;
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
        swap++;
    }
    while (i <= m) temp[k++] = a[i++], swap++;
    while (j <= r) temp[k++] = a[j++], swap++;
    for (i = l, k = 0; i <= r; i++, k++) a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n, ch;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000 + 1;

    printf("\nBefore sorting:\n");
    print(a, n);

    printf("\nChoose sorting method:\n");
    printf("1. Bubble\n2. Selection\n3. Insertion\n4. Merge\nChoice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1: bubble(a, n); break;
        case 2: selection(a, n); break;
        case 3: insertion(a, n); break;
        case 4: mergeSort(a, 0, n - 1); break;
        default: printf("Invalid choice\n"); return 0;
    }

    printf("\nAfter sorting:\n");
    print(a, n);

    printf("\nComparisons: %lld", comp);
    printf("\nSwaps/Moves: %lld\n", swap);

    return 0;
}
