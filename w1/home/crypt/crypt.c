#include stdio.h

int main() {
    int plain1, encrypted1;
    int plain2, encrypted2;
    int length;
    int keyA, keyB;
    int input, output;
    
    scanf(%d %d %d %d %d, &plain1, &encrypted1, &plain2, &encrypted2, &length);
    
    keyA = (encrypted2 - encrypted1)  (plain2 - plain1);
    keyB = encrypted1 - plain1  keyA;
    
    for ( int i = 1; i  length; i++ ) {
        scanf(%d, &input);
        output = (input - keyB)  keyA;
        printf(%d , output);
    }
    scanf(%d, &input);
    output = (input - keyB)  keyA;
    printf(%dn, output);
    
    return 0;
}
