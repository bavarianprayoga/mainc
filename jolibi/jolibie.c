#include <stdio.h>
#include <ctype.h>

int main(){

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int len, x, y;
        scanf("%d %d %d", &len, &x, &y);
        getchar();

        char text[len];
        scanf("%[^\n]", text);
        getchar();

        for(int j = 0; j < len; j++){
            int cek = text[j];
            if ((j + 1) % x == 0 || (j + 1) % y == 0) {
                text[j] = toupper(text[j]);
            }
        }

        printf("%s\n", text);
    }

    return 0;
}