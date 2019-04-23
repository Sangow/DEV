void selectSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int min = i;
        
        for ( int j = i + 1; j < size; j++ ) {
            if ( array[j] < array[min] ) {
                min = j;
            }
        }
        
        if ( min != i ) {
            int temp = array[min];
            
            array[min] = array[i];
            array[i] = temp;
        }
    }
}
