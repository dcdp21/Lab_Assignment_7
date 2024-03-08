#include <stdio.h>
#include <stdlib.h>

typedef struct Swap {
    int data;
    int count;
} Swap;

void displaySwaps(Swap* swaps, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", swaps[i].data, swaps[i].count);
    }
}

void exchange(Swap* a, Swap* b) {
    Swap temp = *a;
    *a = *b;
    *b = temp;
}

int totalExchanges(Swap* swaps, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += swaps[i].count;
    }
    return total / 2;
}

Swap* bubbleSort(int* arr, int size) {
    Swap* swaps = (Swap*)malloc(sizeof(Swap) * size);
    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].count = 0;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (swaps[j].data > swaps[j + 1].data) {
                swaps[j].count++;
                swaps[j + 1].count++;
                exchange(&swaps[j], &swaps[j + 1]);
            }
        }
    }

    return swaps;
}

Swap* selectionSort(int* arr, int size) {
    Swap* swaps = (Swap*)malloc(sizeof(Swap) * size);
    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].count = 0;
    }

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (swaps[j].data < swaps[min_index].data) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swaps[min_index].count++;
            swaps[i].count++;
            exchange(&swaps[i], &swaps[min_index]);
        }
    }

    return swaps;
}

int main() {
    int data1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int data2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int size1 = sizeof(data1) / sizeof(data1[0]);
    int size2 = sizeof(data2) / sizeof(data2[0]);

    Swap* bubbleSort1 = bubbleSort(data1, size1);
    Swap* bubbleSort2 = bubbleSort(data2, size2);

    printf("Array1 Bubble Sort:\n");
    displaySwaps(bubbleSort1, size1);
    printf("Total swaps: %d\n\n", totalExchanges(bubbleSort1, size1));
    printf("Array2 Bubble Sort:\n");
    displaySwaps(bubbleSort2, size2);
    printf("Total swaps: %d\n\n", totalExchanges(bubbleSort2, size2));

    free(bubbleSort1);
    free(bubbleSort2);

    Swap* selectionSort1 = selectionSort(data1, size1);
    Swap* selectionSort2 = selectionSort(data2, size2);

    printf("Array1 Selection Sort:\n");
    displaySwaps(selectionSort1, size1);
    printf("Total swaps: %d\n\n", totalExchanges(selectionSort1, size1));
    printf("Array2 Selection Sort:\n");
    displaySwaps(selectionSort2, size2);
    printf("Total swaps: %d\n\n", totalExchanges(selectionSort2, size2));

    free(selectionSort1);
    free(selectionSort2);

    return 0;
}