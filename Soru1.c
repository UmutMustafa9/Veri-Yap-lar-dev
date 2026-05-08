#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort (Araya Ekleme Sıralaması)
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort (Seçmeli Sıralama)
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n = 500;
    int X_insertion[n];
    int X_selection[n];
    
    // Rastgele sayı üreticiyi başlat
    srand(time(NULL));
    
    // 0-1000 arası 500 rastgele sayı üret ve iki diziye de aynı sayıları koy
    for(int i = 0; i < n; i++) {
        int r = rand() % 1001;
        X_insertion[i] = r;
        X_selection[i] = r;
    }

    clock_t start, end;
    double cpu_time_used;

    // Insertion Sort Süre Ölçümü
    start = clock();
    insertionSort(X_insertion, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort (Birlestirmeli/Araya Ekleme) siralama suresi: %f saniye\n", cpu_time_used);

    // Selection Sort Süre Ölçümü
    start = clock();
    selectionSort(X_selection, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort (Secmeli) siralama suresi: %f saniye\n", cpu_time_used);

    return 0;
}
