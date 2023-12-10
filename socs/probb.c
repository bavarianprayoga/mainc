#include <stdio.h>
#include <string.h>

int main() {
    
    FILE *file = fopen("testdata.in", "r");
    
    int t, n;
    char str[10001];

    fscanf(file, "%d", &t);

    for(int i = 0; i < t; i++){
        fscanf(file, "%s\n", &str);
        fscanf(file, "%d\n", &n);
        
        int len = strlen(str);
        int mark[10001] = {0};

        for(int j = 0; j < n; j++){
            char first, switched;
            fscanf(file, "%c %c\n", &first, &switched);

            if(mark[first] == 0){
                mark[first] = 1;

                for(int k = 0; k < len; k++){
                    if(str[k] == first){
                        str[k] = switched;
                    }
                }
            }
        }

        int count[10000] = {0};
        for(int j = 0; j < len; j++){
            count[str[j]]++;
        }

        for(int j = 'A'; j <= 'Z'; j++){
            if(count[j] != 0){
                printf("%c %d\n", j, count[j]);
            }
        }
    }

    fclose(file);
    
    return 0;
}
