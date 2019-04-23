void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    int t = 0;
    int s1 = 0;
    int s2 = 0;
    
    for ( ; s1 < len1 && s2 < len2; t++ ) {
        if ( src1[s1] <= src2[s2] ) {
            target[t] = src1[s1];
            s1 += 1;
        } else {
            target[t] = src2[s2];
            s2 += 1;
        }
    }
    if ( s1 < len1 ) {
        for ( ; s1 < len1; t++, s1++ ) {
            target[t] = src1[s1];
        }
    } else {
        for ( ; s2 < len2; t++, s2++ ) {
            target[t] = src2[s2];
        }
    }
}
