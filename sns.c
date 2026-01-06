#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INFILENAME "input.txt"
#define OUTFILENAME "result_c.txt"

// Bubble sort and linear search
int sort_n_search(int arr[], int n, int val) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) return i;
    }
    return -1;
}

int main() {
    // Read input from file
    FILE *IFH = fopen(INFILENAME, "r");
    if (IFH == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }
    int count, target;
    fscanf(IFH, "%d %d", &count, &target);
    int arr[count];
    for (int i = 0; i < count; i++) fscanf(IFH, "%d", &arr[i]);
    fclose(IFH);

    int index = sort_n_search(arr, count, target); // Function call

    // Write search result and sorted array to output file
    FILE *OFH = fopen(OUTFILENAME, "w");
    if (OFH == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }
    if (index != -1) fprintf(OFH, "Value %d first found at index %d.\n", target, index);
    else fprintf(OFH, "Value %d not found.\n", target);
    for (int i = 0; i < count; i++) fprintf(OFH, "%d ", arr[i]);
    fclose(OFH);
}