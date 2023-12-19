#include <stdio.h>
#include <string.h>

typedef struct{
    char namaJalan[100];
    int nomorRumah;
} Alamat;

typedef struct{
    char name[100];
    int gpa;
    Alamat address;
} Mahasiswa;

int main(){

    Mahasiswa daftarMhs[100];

    strcpy(daftarMhs[0].name, "Budi");
    daftarMhs[0].gpa = 3.5;
    strcpy(daftarMhs[0].address.namaJalan, "Jalan A");
    daftarMhs[0].address.nomorRumah = 77;

    printf("%s %d %s %d", daftarMhs[0].name, daftarMhs[0].gpa, daftarMhs[0].address.namaJalan, daftarMhs[0].address.nomorRumah);

    return 0;
}