#include <stdio.h>

unsigned long long int rev(unsigned long long int total){
    unsigned long long int revs = 0;
    while(total > 0){
        revs = revs * 10 + total % 10;
        total = total / 10;
    }
    return revs;
}

int main(){

    int t;
    scanf(" %d", &t);
    unsigned long long int total[t];

    for(int i = 0; i < t; i++){
        scanf(" %llu", &total[i]);
    }

    for(int i = 0; i < t; i++){
        printf("Case #%d: %llu\n", i+1, total[i] + rev(total[i]));
    }

    return 0;
}