#include <stdio.h>

// Diziyi standart küçükten büyüğe sıralamak için yardımcı fonksiyon (Bubble Sort)
void sortArray(int arr[], int n) {
    int temp;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Bir en büyük, bir en küçük şekilde sıralayan ana fonksiyon
void maxMinSort(int arr[], int n) {
    sortArray(arr, n); // Önce küçükten büyüğe sırala
    
    int temp[n]; // Geçici dizi
    int left = 0; // En küçük elemanların indeksi
    int right = n - 1; // En büyük elemanların indeksi
    
    for (int i = 0; i < n; i++) {
        // Çift indekslere en büyükleri, tek indekslere en küçükleri yerleştir
        if (i % 2 == 0) {
            temp[i] = arr[right];
            right--;
        } else {
            temp[i] = arr[left];
            left++;
        }
    }
    
    // Sonuçları orijinal diziye kopyala
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    // Ödevdeki test dizisi
    int arr[] = {60, 80, 3, 9, 57, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Orijinal Dizi: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    maxMinSort(arr, n);

    printf("Ozel Siralanmis Dizi: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
