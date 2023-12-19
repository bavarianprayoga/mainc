#include <stdio.h>
#include <string.h>

typedef struct{
    char name[100];
    int age;
    float gpa;
} Students;

void clear(){
    for(int i = 0; i < 30; i++){
        puts("");
    }
}

void bubble(Students *st, int size){
    int swapped;
    do{
        swapped = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size - i - 1; j++){
                if(st[j].gpa < st[j+1].gpa){
                    Students temp = st[j];
                    st[j] = st[j+1];
                    st[j+1] = temp;
                    swapped = 1;
                }
            }
        }
    } while(swapped == 1);
}

int main(){

    Students st[15];
    int idx = 0;
    int size = sizeof(st)/sizeof(st[0]);

    FILE *file = fopen("student.txt", "r");

    if(file == NULL) perror("ERRRRRrrrrrrreooooooorrrrr");

    while(fscanf(file, "%[^_]_%d_%f\n", st[idx].name, &st[idx].age, &st[idx].gpa) != EOF){
        idx++;
    }

    fclose(file);

    bubble(st, idx);

    int choice = 0;

    do{
        puts("1. View students");
        puts("2. Add student");
        puts("3. Edit student");
        puts("4. Delete student");
        puts("5. Exit");

        printf(">> ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 5){
            puts("Invalid");
            continue;
        }

        switch(choice){
            case 1:
                printf("%-4s %-15s %-5s %s\n", "No", "Name", "Age", "GPA");
                for(int i = 0; i < idx; i++){
                    printf(" %-3d %-15s %-4d %.2f\n", i+1, st[i].name, st[i].age, st[i].gpa);
                }
                break;
            case 2:
                printf("Insert data:\n");
                puts("Enter 0 to cancel");
                printf("Name: ");
                scanf("%s", st[idx].name);
                if(st[idx].name[0] == '0') break;
                printf("Age: ");
                scanf("%d", &st[idx].age);
                printf("GPA: ");
                scanf("%f", &st[idx].gpa);
                idx++;
                clear();
                break;
            case 3:
                printf("Update data:\n");
                for(int i = 0; i < idx; i++){
                    printf("%d. %s\n", i+1, st[i].name);
                }
                puts("Enter 0 to cancel");
                printf("Choose: ");
                int upd;
                do{
                    scanf(" %d", &upd);
                    if(upd == 0) break;

                    printf("Name: ");
                    scanf(" %s", st[upd-1].name);
                    printf("Age: ");
                    scanf(" %d", &st[upd-1].age);
                    printf("GPA: ");
                    scanf(" %f", &st[upd-1].gpa);
                    clear();
                } while(upd < 1 || upd > idx);
                break;
            case 4:
                printf("Delete data:\n");
                for(int i = 0; i < idx; i++){
                    printf("%d. %s\n", i+1, st[i].name);
                }

                puts("Enter 0 to cancel");
                printf("Choose: ");
                int del;
                do{
                    scanf(" %d", &del);
                    if(del == 0) break;
                } while(del < 1 || del > idx);

                for(int i = del-1; i < idx-1; i++){
                    st[i] = st[i+1];
                }
                idx--;
                clear();
                break;
            case 5:
                printf("Save & Exit\n");
                file = fopen("student.txt", "w");
                for(int i = 0; i < idx; i++){
                    fprintf(file, "%s_%d_%.2f\n", st[i].name, st[i].age, st[i].gpa);
                }
                fclose(file);
                break;
            default:
                printf("Invalid\n");
                clear();
                break;
        }
        puts("");

    } while(choice != 5);

    return 0;
}