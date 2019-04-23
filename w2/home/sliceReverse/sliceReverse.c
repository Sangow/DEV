#include <stdio.h>

void sliceReverse(int array[], int lo, int hi) {
    for ( ; lo < hi; lo++, hi-- ) {
        int tmp = array[lo];
        
        array[lo] = array[hi];
        array[hi] = tmp;
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // int size = sizeof(array) / 4;
    sliceReverse(array, 3, 8);

    for (int i = 0; i < 11; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
