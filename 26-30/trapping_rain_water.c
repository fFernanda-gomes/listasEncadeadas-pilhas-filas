#include <stdio.h>

int trappingRainWater(int* altura, int n) {
    int esq = 0, dir = n - 1;
    int max_esq = 0, max_dir = 0, agua = 0;

    while (esq <= dir) {
        if (altura[esq] < altura[dir]) {
            if (altura[esq] >= max_esq)
                max_esq = altura[esq];
            else
                agua += max_esq - altura[esq];
            esq++;
        } else {
            if (altura[dir] >= max_dir)
                max_dir = altura[dir];
            else
                agua += max_dir - altura[dir];
            dir--;
        }
    }

    return agua;
}

int main() {
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Água retida: %d\n", trappingRainWater(arr, n));
    return 0;
}
