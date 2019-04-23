#include <stdio.h>

int main() {
    int home, opp;
    
    scanf("%d %d", &home, &opp);
    
    if ( home > opp ) {
        printf("Home team wins\n");
    } else if ( home < opp ) {
        printf("Away team wins\n");
    } else {
        printf("Draw\n");
    }
    
    return 0;
}
