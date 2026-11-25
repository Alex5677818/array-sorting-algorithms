#include <stdio.h>
#include <stdlib.h>

// Funcție ajutătoare pentru a găsi valoarea maximă din vector
static int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort stabil în funcție de cifra reprezentată de exp (1, 10, 100...)
static void countingSort(int arr[], int n, int exp)
{
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Numărăm aparițiile fiecărei cifre (0-9)
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calculăm pozițiile cumulative pentru a păstra stabilitatea sortării
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construim vectorul sortat parcurgând de la dreapta la stânga
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copiem rezultatul înapoi în vectorul original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

static void sort(int arr[], int n)
{
    if (n <= 1) return;

    int max = getMax(arr, n);

    // Aplicăm countingSort pentru fiecare cifră (unități, zeci, sute...    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);

    printf("Vector sortat: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
