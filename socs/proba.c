#include <stdio.h>
#include <string.h>

int main(){

    int t;
    char name[100000];
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";

    scanf("%d", &t);
    
    int final[t];

    for(int i = 0; i < t; i++){
        scanf(" %[^\n]", name);

        int alphaCount = 0;
        int isAlpha[26] = {0};

        for (int i = 0; name[i] != '\0'; i++){
            char ch = name[i];
            if (ch >= 'a' && ch <= 'z'){
                if (strchr(name, ch) != NULL){
                    if (!isAlpha[ch - 'a']) {
                        isAlpha[ch - 'a'] = 1;
                        alphaCount++;
                    }
                }
            }
        }

        final[i] = alphaCount;

    }

    for(int i = 0; i < t; i++){
        if(final[i] % 2 == 0){
            printf("Case #%d: Yay\n", i+1);
        }
        else{
            printf("Case #%d: Ewwww\n", i+1);
        }
    }

    return 0;
}
