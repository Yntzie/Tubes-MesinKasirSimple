#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>

#define MAX 5
#define RESET     "\x1b[0m"
#define RED       "\x1b[31m"
#define GREEN     "\x1b[32m"
#define YELLOW    "\x1b[33m"
#define LIGHTBLUE "\033[94m"
#define MAGENTA   "\x1b[35m"
#define BLACK     "\033[30m"
#define BLUE      "\x1b[34m"
#define WHITE     "\x1b[37m"


typedef char string[100];

typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;

typedef struct{
    string nama;
    float harga;
}Pesanan;

typedef struct DataChild{
    string namaPesanan;
    float harga;
    int jumlah;
}DataChild;

typedef struct DataParent{
    int nomorNota;
    int nomorMeja;
    string tanggal;
    float total;
    bool status;
}DataParent;

typedef struct Child{
    DataChild dataChild;
    AddressChild next;
}NodeChild;

typedef struct Parent{
    DataParent dataParent;
    AddressParent next;
    AddressChild firstChild;
}NodeParent;

typedef struct{
    AddressParent firstParent;
}Multilist;

void tampilMenu(int *menu);
void initPesanan(Pesanan P[MAX][2]);
void createEmpty(Multilist *L);
float uiBayar(AddressParent P);
void TampilNota(AddressParent P, float bayar);

int random();
bool isEmpty(Multilist L);
bool haveChild(AddressParent addressParent);
bool isOnlyOneElement(Multilist L);
bool isOnlyHaveOneChild(AddressChild ap);
bool cekMenu(string banding, string makanan);

AddressChild alokasiPesanan(DataChild P);
AddressParent alokasiParent(DataParent data);

void PersegiPanjang(int x, int y, int postX, int postY); //x lebar, y panjang
void insertFirstChild(Multilist L, int nomorNota, DataChild data);
void insertLastChild(Multilist L, int nomorNota, DataChild data);

AddressParent cekMeja(Multilist L, int nomorMeja);
AddressParent findParent(Multilist L, int nomorNota);

float hitungOmzet(Multilist L);
void JumlahMenuTerbanyak(Multilist L, Pesanan P[MAX][2], int total[MAX][2]);

void splitBill(Multilist L, int nomorNota, int banyakNota);
AddressChild isMakan(AddressParent P, string makan);
void editMultilist(Multilist *L, AddressParent P, int jumlah, string makan);
void gabungNota(Multilist *L, AddressParent tampung, AddressParent pindah);
void deleteAllChild(AddressParent parent);
void deleteAtParent(Multilist *L, AddressParent P);

void tampilOmset(Multilist L);
void displayBomb(int count);
void animasiLoading(char *message);
void printGelasKopiBesarKanan();
void printGelasKopiBesarKiri();
void header();
