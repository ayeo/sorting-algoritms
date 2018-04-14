#include <stdio.h>

unsigned counter = 0;

unsigned indexOfMin(int* S, unsigned i, unsigned len) {
    unsigned min = i;
    while (i < len) {
        counter++;
        if (S[min] > S[i]) {
            min = i;
        }
        i++;
    }
    
    return min;
}

void swap(int* S, unsigned i, unsigned mini) {
    int temp = S[i];
    S[i] = S[mini];
    S[mini] = temp;
}

void selectionSort(int *S, unsigned len) {
    int i = 0;
    while (i < len) {
        unsigned mini = indexOfMin(S, i, len);
        swap(S, i, mini);
        i++;
    }
}

int main(int argc, const char * argv[]) {
    //int S[] = {7, 3, 2, 6, 5, 10, 3, 4, 9, 1, 8};
    int S[] = {3, 2, 1, 7, 6, 4, 5};
    selectionSort(S, 3);
    
    // 1 - 1 (+1)
    // 2 - 3 (+2)
    // 3 - 6 (+3)
    // 4 - 10 (+4)
    // 5 - 15 (+5)
    // 6 - 21 (+6)
    // 7 - 28 (+7)
    printf("%d", counter); //output 66
    return 0;
}
