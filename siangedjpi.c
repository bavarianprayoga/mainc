#include <stdio.h>

int main() {
	
    int t, n, k;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &k);
        
        char stairs[n];
        scanf("%s", stairs);

        int first = 0, last = 0, count = 0;

        for (int j = 0; j < n; j++) {
            if (stairs[j] == '1') {
                first = j + 1;
                break;
            }
        }
        
        for (int j = n - 1; j >= 0; j--) {
            if (stairs[j] == '1') {
                last = j;
                break;
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (stairs[j] == '1') {
                count++;
            }
        }
        
        if ((count == 0 || count == 1) && (n <= k) || ((first <= k) && (n - last) <= k) && count != 0 && count != 1) {
            printf("Case #%d: Alive\n", i + 1);
        } 
        else {
            printf("Case #%d: Dead\n", i + 1);
        }
    }
    
    return 0;
}



