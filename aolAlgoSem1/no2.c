#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Bavarian Endra Prayoga
//2702344280
//LN01
//AOL Algoprog Sem 1

typedef struct{
    char location[31];
    char city[31];
    int price;
    int rooms;
    int bathroom;
    int carpark;
    char buildType[10];
    char furnish[15];
} Property;

char* sortColumn;
char* sortOrder;

void case1(Property properties[], int idx); //Taking care of case 1. Displaying data.
void case2(Property properties[], int idx); //Taking care of case 2. Searching data.
void case3(Property properties[], int idx); //Taking care of case 3. Sorting data.
void case4(Property properties[], int idx); //Taking care of case 4. Exporting data.
int comp(const void* a, const void* b); //Comparing function for qsort inside case 3

int main(){

    FILE *file = fopen("file.csv", "r");

    if(file == NULL){
        puts("ERRRORRRRRR");
        return -1;
    }

    Property properties[4000];

    int idx = 0;

    char buffer[100];
    fgets(buffer, sizeof(buffer), file);

    while(fscanf(file, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", properties[idx].location, properties[idx].city, &properties[idx].price, &properties[idx].rooms, &properties[idx].bathroom, &properties[idx].carpark, properties[idx].buildType, properties[idx].furnish) != EOF){
        idx++;
    }

    int choice, rows;

    do{
        puts("=============================");
        puts("What do you want to do?");
        puts("1. Display Data");
        puts("2. Search Data");
        puts("3. Sort Data");
        puts("4. Export Data");
        puts("5. Exit");
        puts("=============================");

        printf("Your choice: ");
        do{
            scanf(" %d", &choice);
        } while(choice < 1 || choice > 5);

        switch(choice){
            case 1:
                case1(properties, idx);
                break;
            case 2:
                case2(properties, idx);
                break;
            case 3:
                case3(properties, idx);
                break;
            case 4:
                case4(properties, idx);
                break;
            case 5:
                puts("Thank you!"); 
                puts("Exiting program...");
                break;
            default:
                puts("Invalid choice! Please enter a number between 1 and 5.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}

void case1(Property properties[], int idx){
    printf("Number of rows: ");
    int rows;
    do{
        scanf(" %d", &rows);
    } while(rows < 0);
                
    if(rows > idx){
        rows = idx;
    }

    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
    for(int i = 0; i < rows; i++){
        printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
    }
}

void case2(Property properties[], int idx){ //Taking care of case 2. Searching data.
    printf("Choose column: ");
    char column[15];
    scanf(" %[^\n]", column);

    printf("What data do you want to find? ");
    char data[31];
    scanf(" %[^\n]", data);

    int dataInt, isItInt, found = 0;
    if(strcmpi(column, "price") == 0 || strcmpi(column, "rooms") == 0 || strcmpi(column, "bathroom") == 0 || strcmpi(column, "carpark") == 0){
        dataInt = atoi(data);
        isItInt = 1;
    }

    if(isItInt == 1){
        for(int i = 0; i < idx; i++){
            if(strcmpi(column, "price") == 0 && dataInt == properties[i].price){
                if(found == 0){
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
                    found = 1;
                }
                printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
            }
            else if(strcmpi(column, "rooms") == 0 && dataInt == properties[i].rooms){
                if(found == 0){
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
                    found = 1;
                }
                printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
            }
            else if(strcmpi(column, "bathroom") == 0 && dataInt == properties[i].bathroom){
                if(found == 0){
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
                    found = 1;
                }
                printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
            }
            else if(strcmpi(column, "carpark") == 0 && dataInt == properties[i].carpark){
                if(found == 0){
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
                    found = 1;
                }
                printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
            }
        }
    }
    else{
        for(int i = 0; i < idx; i++){
            if(strcmpi(column, "location") == 0 && strcmpi(data, properties[i].location) == 0){
                if(found == 0){
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
                    found = 1;
                }
                printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
            } 
            else if(strcmpi(column, "city") == 0 && strcmpi(data, properties[i].city) == 0){
                if(found == 0){
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
                    found = 1;
                }
                printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
            }
            else if(strcmpi(column, "type") == 0 && strcmpi(data, properties[i].buildType) == 0){
                if(found == 0){
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
                    found = 1;
                }
                printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
            }
            else if(strcmpi(column, "furnish") == 0 && strcmpi(data, properties[i].furnish) == 0){
                if(found == 0){
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
                    found = 1;
                }
                printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
            }
        }
    }

    if(found == 0){
        printf("Data not found!");
    }

    printf("\n\n");
}

void case3(Property properties[], int idx){ //Taking care of case 3. Sorting data.
    printf("Choose column: ");
    char column[15];
    scanf(" %[^\n]", column);

    int found = 0;
    if(strcmpi(column, "location") == 0 || strcmpi(column, "city") == 0 || strcmpi(column, "price") == 0 || strcmpi(column, "rooms") == 0 || strcmpi(column, "bathroom") == 0 || strcmpi(column, "carpark") == 0 || strcmpi(column, "type") == 0 || strcmpi(column, "furnish") == 0){
        found = 1;
        sortColumn = column;
    }

    if(found == 0){
        printf("Column not found!\n");
        return;
    }

    printf("Sort ascending or descending? (asc/desc) ");
    char sort[5];
    scanf(" %[^\n]", sort);
    sortOrder = sort;

    qsort(properties, idx, sizeof(Property), comp);

    printf("%-30s %-30s %-10s %-10s %-10s %-10s %-12s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");
    for(int i = 0; i < 10; i++){
        printf("%-30s %-30s %-10d %-10d %-10d %-10d %-12s %-10s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
    }
}

void case4(Property properties[], int idx){ //Taking care of case 4. Exporting data.
    printf("File name: ");
    char fileName[100];
    scanf(" %[^\n]", fileName);
    strcat(fileName, ".csv");

    FILE *file = fopen(fileName, "w");

    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Build Type", "Furnish");

    for(int i = 0; i < idx; i++){
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n", properties[i].location, properties[i].city, properties[i].price, properties[i].rooms, properties[i].bathroom, properties[i].carpark, properties[i].buildType, properties[i].furnish);
    }

    fclose(file);

    printf("Data successfully written to file %s!\n\n", fileName);
}

int comp(const void* a, const void* b){ //Comparing function for qsort inside case 3
    Property* propertyA = (Property*)a;
    Property* propertyB = (Property*)b;
    int result;

    if(strcmp(sortColumn, "location") == 0){
        result = strcmp(propertyA->location, propertyB->location);
    }
    else if(strcmp(sortColumn, "city") == 0){
        result = strcmp(propertyA->city, propertyB->city);
    }
    else if(strcmp(sortColumn, "price") == 0){
        result = propertyA->price - propertyB->price;
    }
    else if(strcmp(sortColumn, "rooms") == 0){
        result = propertyA->rooms - propertyB->rooms;
    }
    else if(strcmp(sortColumn, "bathroom") == 0){
        result = propertyA->bathroom - propertyB->bathroom;
    }
    else if(strcmp(sortColumn, "carpark") == 0){
        result = propertyA->carpark - propertyB->carpark;
    }
    else if(strcmp(sortColumn, "type") == 0){
        result = strcmp(propertyA->buildType, propertyB->buildType);
    }
    else if(strcmp(sortColumn, "furnish") == 0){
        result = strcmp(propertyA->furnish, propertyB->furnish);
    }

    if(strcmp(sortOrder, "desc") == 0) {
        result = -result;
    }

    return result;
}