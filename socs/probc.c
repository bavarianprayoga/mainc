#include <stdio.h>

long long int binary(long long int target, long long int left, long long int right){
    long long int temp2;

    while(left <= right){
        unsigned long long int mid = left + (right - left) / 2;
        unsigned long long int temp = mid * (mid + 1) * (2 * mid + 1) / 6;

        if(temp >= target){
            temp2 = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return temp2;
}

int main(){

	int t;
    scanf(" %d", &t);

    long long int final[t];

    for(int i = 0; i < t; i++){
        long long int target;
        scanf(" %lld", &target);

        final[i] = binary(target, 0, 1000000000000000001);
    }

    for(int i = 0; i < t; i++){
        printf("Case #%d: %lld\n", i+1, final[i]);
    }

    return 0;
}