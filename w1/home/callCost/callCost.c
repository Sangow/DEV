#include <stdio.h>

int main() {
    int phone, min;
    
    scanf("%d %d", &phone, &min);
    
    if ( phone == 101 || phone == 102 || phone == 103 || phone == 104 || phone == 112 ) {
        printf("0$\n");
    } else if ( phone >= 1000000 && phone <= 9999999 ) {
        printf("%d$\n", min);
    } else if ( phone >= 100 && phone <= 999 ) {
        printf("%d$\n", min*40);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
