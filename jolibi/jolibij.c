#include <stdio.h>
#include <string.h>

int main() {
    char S[5];
    scanf("%s", S);

    if (strcmp(S, "AC") == 0){
        printf("Accepted\n");
    } 
    else if(strcmp(S, "WA") == 0){
        printf("Wrong Answer\n");
    } 
    else if(strcmp(S, "TLE") == 0){
        printf("Time Limit Exceeded\n");
    } 
    else if(strcmp(S, "MLE") == 0){
        printf("Memory Limit Exceeded\n");
    } 
    else if(strcmp(S, "RTE") == 0){
        printf("Run Time Error\n");
    } 
    else if(strcmp(S, "CE") == 0){
        printf("Compile Error\n");
    } 
    else if(strcmp(S, "PE") == 0){
        printf("Presentation Error\n");
    } 
    else if(strcmp(S, "OT") == 0){
        printf("Output Limit\n");
    }
    else{
        printf("Verdict doesn't exist\n");
    }

    return 0;
}