#include <stdio.h>
#include <string.h>

int subs(int k, char c, char *s){
    int len = strlen(s);
    int count = 0, bnyk = 0, left = 0;
    
    for(int right = 0; right < len; right++){
        if(s[right] == c){
                bnyk++;
            }
            
        while(bnyk > k){
            if(s[left] == c){
                bnyk--;
            }
        left++;
        }
        count += right - left + 1;
    }
    
    return count;
}

int main(){
    int t;
    scanf("%d", &t);
    getchar();

    for(int i = 0; i < t; i++){
        char c;
        int k;
        char s[20005];

        scanf(" %c %d", &c, &k);
        getchar();

        scanf("%s", s);

        int result = subs(k, c, s);
        printf("%d\n", result);
    }

    return 0;
}
