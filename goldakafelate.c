#include <stdio.h>

typedef struct{
    char id[12];
    char nama[100];
    double gpa;
    int algo;
} Student;

int main(){

    Student murid[3];

    for(int i = 0; i < 3; i++){
        scanf("%s", &murid[i].id);
        getchar();
        scanf("%[^\n]", &murid[i].nama);
        getchar();
        scanf("%lf", &murid[i].gpa);
        getchar();
        scanf("%d", &murid[i].algo);
        getchar();
    }

    for(int i = 0; i < 3; i++){
        printf("Student %d: %s, %s, %.1lf, %d\n", i + 1, murid[i].id, murid[i].nama, murid[i].gpa, murid[i].algo);
    }

    return 0;
}
