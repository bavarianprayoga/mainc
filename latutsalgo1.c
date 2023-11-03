#include <stdio.h>
#include <string.h>

int main(){
    
    int t;
    scanf("%d", &t);
    getchar();

    for(int i = 0; i < t; i++){
        char s[100000] = {0};
        scanf("%s", s);
        getchar();

        int freq[26] = {0};
        int len = strlen(s);
        for(int i = 0;  i < len; i++){
            freq[s[i] - 'a']++;
        }

        int min = len;
        int max = 0;

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                if(freq[i] > max){
                    max = freq[i]; 
                }

                if(freq[i] < min){
                    min = freq[i]; 
                }
            }
        }

        printf("Case #%d: ", i+1);

        if(max == min){
            printf("N/A\n");
        }
        else{
            int diff = 0;
            int apus = 'a';

            for(int j = 0; j < 26; j++){
                if(freq[j] == max){
                    diff++;
                    apus = j + 'a';
                }
            }
            if(diff == 1){
                printf("%c\n", apus);
            }
            else{
                printf("N/A\n");
            }
        }
    }

    return 0;
}
