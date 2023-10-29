#include <stdio.h>

void prob(int kue, int mincok, int maxcok, int minpis, int maxpis, int minstro, int maxstro){
    int total = 0;

    for(int ccoklat = mincok; ccoklat <= maxcok; ccoklat++){
        for(int cpisang = minpis; cpisang <= maxpis; cpisang++){
            for(int cstroberi = minstro; cstroberi <= maxstro; cstroberi++){
                if(ccoklat + cpisang + cstroberi == kue){
                    total++;
                }
            }
        }
    }
    printf("%d\n", total);
}

int main(){

    int kue, mincok, maxcok, minpis, maxpis, minstro, maxstro;
    scanf("%d", &kue);

    scanf("%d %d", &mincok, &maxcok);
    scanf("%d %d", &minpis, &maxpis);
    scanf("%d %d", &minstro, &maxstro);

    prob(kue, mincok, maxcok, minpis, maxpis, minstro, maxstro);

    return 0;
}