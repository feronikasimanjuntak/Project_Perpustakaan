/*KELOMPOK 04 - TOPIK 3*/
//1. 13320023-PAUL MARTIN PARSAULIAN NAINGGOLAN (D3-TK)
//2. 13320040-DODY IRMAN JOSUA NADAPDAP (D3-TK)
//3. 11320057-FERONIKA SIMANJUNTAK (D3-TI) 

typedef struct DataBuku dbuku;
struct DataBuku {
    char ISBN[10];
    char judul_buku[100];
    char jenis_buku[50];
    char author[50];
    char NIDN[20];
    int jumlah;
    dbuku * alamat;
};

typedef struct DataDosen ddosen;
struct DataDosen
{
    char NIDN[20];
    char nama[50];
    char no_telp[15];
    ddosen * alamat;
};

void cetakBuku(dbuku * data);
void cetakDosen(ddosen * data);
void cariBuku(dbuku *data, char *cari);
void cariNIDN(ddosen *data, dbuku * isi, char *cari);
ddosen *AddNewDataDosen(ddosen **nodeRef, ddosen *data);
ddosen *AddNextDataDosen(ddosen **nodeRef, ddosen *data);
dbuku *AddNewDataBuku(dbuku **nodeRef, dbuku *data);
dbuku *AddNextDataBuku(dbuku **nodeRef, dbuku *data);
char *getNIDN(ddosen *data, int pilihan);

