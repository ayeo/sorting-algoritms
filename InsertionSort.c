#include <stdio.h>

void insertionSort(int *arr, unsigned len) {
    for (unsigned next = 1; next < len; next++) {
        unsigned curr = next;
        unsigned temp = arr[next];
        
        while((curr > 0) && (temp < arr[curr - 1])) {
            arr[curr] = arr[curr - 1];
            curr--;
        }
        
        arr[curr] = temp;
    }
}

int main(int argc, const char * argv[]) {
    int data[] = {5, 1, 6, 2, 4, 7, 3};
    //5, 1, 6, 2, 4, 7, 3
    //1, 5, 6, 2, 4, 7, 3
    //1, 5, 6, 2, 4, 7, 3
    //1, 5, 2, 6, 4, 7, 3
    //1, 2, 5, 6, 4, 7, 3
    //1, 2, 5, 4, 6, 7, 3
    //1, 2, 4, 5, 6, 7, 3
    //1, 2, 4, 5, 6, 7, 3
    //1, 2, 4, 5, 6, 3, 7
    //1, 2, 4, 5, 3, 6, 7
    //1, 2, 4, 3, 5, 6, 7
    //1, 2, 3, 4, 5, 6, 7
    
    insertionSort(data, 7);
    
    return 0;
}
