#include <stdio.h>
#define PI 3.14

int main(){

    int t;
    scanf("%d", &t);

    double score[t];

    for(int i = 0; i < t; i++){
        int r, h;
        scanf("%d %d", &r, &h);

        score[i] = 2 * PI * r * (r + h);
    }

    for(int i = 0; i < t; i++){
        printf("Case #%d: %.2lf\n", i+1, score[i]);
    }


    return 0;
}
