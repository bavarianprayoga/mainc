#include <stdio.h>

int check(int n, char stairs[], int k){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(stairs[i] == '0'){
            count++;
            if (count == k) return 0;
        } 
        else{
            count = 0;
        }
    }
    return 1;
}

int main(){

    int t;
    scanf("%d", &t);

    int results[t];

    for(int i = 0; i < t; i++){
        int n, k;
        scanf("%d %d", &n, &k);

        char stairs[n+1];
        scanf("%s", stairs);

        int fate = check(n, stairs, k);
        results[i] = fate;
    }

    for (int i = 0; i < t; i++){
        printf("Case #%d: %s\n", i + 1, (results[i] == 1) ? "Alive" : "Dead");
    }

    return 0;
}