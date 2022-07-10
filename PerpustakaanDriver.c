/*KELOMPOK 04 - TOPIK 3*/
//1. 13320023-PAUL MARTIN PARSAULIAN NAINGGOLAN (D3-TK)
//2. 13320040-DODY IRMAN JOSUA NADAPDAP (D3-TK)
//3. 11320057-FERONIKA SIMANJUNTAK (D3-TI) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PerpustakaanHeader.h"

int main() {
    dbuku *B1 = (dbuku *)malloc(sizeof(dbuku) * 1);
    dbuku *B2 = (dbuku *)malloc(sizeof(dbuku) * 1);
    ddosen *D1 = (ddosen *)malloc(sizeof(ddosen) * 1);
    ddosen *D2 = (ddosen *)malloc(sizeof(ddosen) * 1);
    int opsi, pilih_dosen = 1, batas, i;
    char NIDN[20];

    strcpy(B1->ISBN, "B012345");
    strcpy(B1->judul_buku, "Kancil yang Cerdik");
    strcpy(B1->jenis_buku, "Dongeng");
    strcpy(B1->author, "Jaka Tembung");
    strcpy(B1->NIDN, "0124098904");
    B1->jumlah = 2;
    B1->alamat = B2;

    strcpy(B2->ISBN, "B098765");
    strcpy(B2->judul_buku, "Puteri Raja yang Cantik");
    strcpy(B2->jenis_buku, "Rakyat");
    strcpy(B2->author, "Joko Purnawan");
    strcpy(B2->NIDN, "0117109301");
    B2->jumlah = 2;
    B2->alamat = NULL;

    strcpy(D1->NIDN, "0124098904");
    strcpy(D1->nama, "Hernawati Susanti Samosir, SST., M.Kom");
    strcpy(D1->no_telp, "082198765432");
    D1->alamat = D2;

    strcpy(D2->NIDN, "0117109301");
    strcpy(D2->nama, "Sari Muthia Silalahi, S.Pd., M.Ed");
    strcpy(D2->no_telp, "082198765409");
    D2->alamat = NULL;

    printf("SELAMAT DATANG DI PERPUSTAKAAN IT DEL\n");
    printf("------------------menu------------------\n");
    printf("0. Keluar\n");
    printf("1. Tampilkan Semua Buku\n");
    printf("2. Tampilkan Data Dosen\n");
    printf("3. Cari Buku Berdasarkan ISBN\n");
    printf("4. Cari Buku Berdasarkan NIDN\n");
    printf("5. Tambahkan Buku\n");
    printf("6. Tambahkan Dosen\n");

    do {
        printf("\nPILIH MENU\t: ");
        scanf("%d", &opsi);

        switch (opsi)
        {
        case 1:
            printf("\n------DATA BUKU------\n");
            cetakBuku(B1);
            printf("\n");
            break;            
        case 2:
            printf("\n------DATA DOSEN------\n");
            cetakDosen(D1);
            printf("\n");
            break;            
        case 3:
            printf("\nCARI BUKU BERDASARKAN ISBN\n");
            char cari[100];
            printf("Masukkan ISBN: ");
            scanf("%s", &cari);
            cariBuku(B1, cari);
            printf("\n");
            break;            
        case 4:
            printf("\nCARI JUMLAH BUKU HIBAHAN DOSEN\n");
            char search[100];
            printf("Masukkan NIDN: ");
            scanf("%s", &search);
            cariNIDN(D1, B1, search);
            printf("\n");
            break;
        case 5:
            printf("TAMBAH DATA BUKU\n");
            printf("Data Dosen\n");
            cetakDosen(D1);
            if(D1==NULL){
                printf("Data Dosen masih kosong!\n");
                break;
            } else {
                printf("Pilih dosen yang ingin donasi buku: ");
                scanf("%i", &pilih_dosen);
                if(getNIDN(D1, pilih_dosen) == NULL){
                    break;
                } else {
                    strcpy(NIDN, getNIDN(D1, pilih_dosen));
                }
            }
            printf("Masukkan Jumlah Data Buku:");
            scanf(" %d", &batas);
            
            for (i = 1; i <= batas; i++)
            {
                dbuku *DataBuku = malloc(sizeof(dbuku) * 1);
                printf("Masukkan ISBN %d: ", i);
                scanf("%s", DataBuku->ISBN);
                getchar();
                printf("Masukkan Judul Buku %d: ", i);
                scanf("%[^\t\n]s", DataBuku->judul_buku);
                getchar();
                printf("Masukkan Jenis Buku %d: ", i);
                scanf("%[^\t\n]s", DataBuku->jenis_buku);
                getchar();
                printf("Masukkan Author %d: ", i);
                scanf("%[^\t\n]s", DataBuku->author);
                getchar();
                strcpy(DataBuku->NIDN, NIDN);
                printf("Masukkan Jumlah %d: ", i);
                scanf("%d", &DataBuku->jumlah);

                if(B1==NULL){
                    AddNewDataBuku(&B1, DataBuku);
                } else{
                    AddNextDataBuku(&B1, DataBuku);}
            }
            printf("\n");
            cetakBuku(B1);
            break;
        case 6:
            printf("====Tambah DATA Dosen====\n");
            printf("Masukkan Jumlah Data Dosen:");
            scanf("%i", &batas);
    
            for (i = 1; i <= batas; i++)
            {
                ddosen *DataDosen = malloc(sizeof(ddosen) * 1);
                printf("Masukkan NIDN %d:", i);
                scanf("%s", DataDosen->NIDN);
                getchar();
                printf("Masukkan Nama Dosen %d:", i);
                scanf("%[^\n]s", DataDosen->nama);
                getchar();
                printf("Masukkan Nomor Telepon %d:", i);
                scanf("%s", DataDosen->no_telp);
                getchar();
                    if(D1==NULL){
                        AddNewDataDosen(&D1, DataDosen);
                    } else{
                        AddNextDataDosen(&D1, DataDosen);}
            }
            printf("\n");
            cetakDosen(D1);
           break;
        case 0:
            printf("Anda keluar dari program!\n");
            break;
        default:
            break;
        }

    } while (opsi != 0);

    return 1;
}

