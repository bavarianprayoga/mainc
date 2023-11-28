#include <stdio.h>

enum day {sunday, monday, tuesday, wednesday, thursday, friday, saturday};

int main(){

    enum day hari;

    for(hari = sunday; hari <= saturday; hari++){
        printf("%d\n", hari);
    }

    return 0;1
}
