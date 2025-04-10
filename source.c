#include "header.h"

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void hideCur(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void createEmpty(Multilist *L) {
    L->firstParent = NULL;
}

bool isEmpty(Multilist L) {
    return L.firstParent == NULL;
}

bool haveChild(AddressParent addressParent) {
    return addressParent->firstChild != NULL;
}

bool isOnlyOneElement(Multilist L){
	return L.firstParent->next == NULL;
}

bool isOnlyHaveOneChild(AddressChild ap){
	return ap->next==NULL;
}

int random(){
	return rand () % (4-1+1)+1;
}

void tampilMenu(int *menu){

    char pilih;
    int y=11;
    do
    {
        
        TampilanMenuUtama(y);
        hideCur();
        pilih = getch();
        switch(pilih){
            case 'w':
                    
                if(*menu == 1){
                    y=15;
                    *menu=5;
                }else{
                    y--;
                    *menu-=1;
                }
                    
                
            break;

            case 's':
    
                if(*menu == 5){
                    y=11;
                    *menu=1;
                }else{
                    y++;
                    *menu+=1;
                }
                
            break;
        }
    }while(pilih != 13);
}

void initPesanan(Pesanan P[MAX][2]){
    string nama[MAX][2] = {
        {"Nasi Goreng", "Es Teh"},
        {"Nasi Ayam Geprek", "Es Jeruk"},
        {"Steak Sapi Wahyu", "Wine"},
        {"Croissant", "Es Kopi"},
        {"Es Krim", "Teh Hijau"}
    };
    
    float harga[MAX][2] = {
        {21000 , 5000},
        {23000, 6000},
        {75000, 55000},
        {15000, 12000},
        {7500, 10000}
    };
    
    int i,j;

    for(i=0;i<MAX;i++){
        for(j=0;j<2;j++){
            strcpy(P[i][j].nama, nama[i][j]);
            P[i][j].harga = harga[i][j];
        }
    }
}

AddressChild alokasiChild(DataChild P){
    AddressChild temp;
    temp = (AddressChild)malloc(sizeof(NodeChild));
    temp->next = NULL;
    temp->dataChild.harga = P.harga;
    temp->dataChild.jumlah = P.jumlah;
    strcpy(temp->dataChild.namaPesanan, P.namaPesanan);
    return temp;
}

AddressParent alokasiParent(DataParent data) {
    AddressParent ap;

    ap = (AddressParent) malloc(sizeof(NodeParent));

    ap->next = NULL;
    ap->firstChild = NULL;
    ap->dataParent = data;

    return ap;
}

void insertFirstParent(Multilist *L, DataParent data) {
    AddressParent temp = alokasiParent(data);

    temp->next = L->firstParent;
    L->firstParent = temp;
}

void insertLastParent(Multilist *L, DataParent data) {
    AddressParent dataBaru = alokasiParent(data);

    if(isEmpty(*L)) {
        insertFirstParent(L, data);
    } else {
        AddressParent temp = L->firstParent;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = dataBaru;
    }
}

void insertFirstChild(Multilist L, int nomorNota, DataChild data){
    AddressParent parent = findParent(L, nomorNota);
	AddressChild dataBaru;
	
    if(parent != NULL) {
        dataBaru = alokasiChild(data);
        dataBaru->next = parent->firstChild;

        parent->firstChild = dataBaru;
    }
}

void insertLastChild(Multilist L, int nomorNota, DataChild data) {
    AddressParent parent = findParent(L, nomorNota);

    if(parent != NULL) {
        if(!haveChild(parent)) {
            insertFirstChild(L, nomorNota, data);
        } else {
            
            AddressChild temp = parent->firstChild;
            AddressChild dataBaru = alokasiChild(data);

			if(strcmpi(temp->dataChild.namaPesanan, data.namaPesanan)==0){
                    temp->dataChild.jumlah += data.jumlah;
                    return;
            }
                
            while(temp->next != NULL) {
                // kalo pesanannya sama biar ga ke dobel
                if(strcmpi(temp->dataChild.namaPesanan, data.namaPesanan)==0){
                    temp->dataChild.jumlah += data.jumlah;
                    return;
                }
                temp = temp->next;
            }
            temp->next = dataBaru;
        }
    }
}

AddressParent cekMeja(Multilist L, int nomorMeja){
    AddressParent temp = NULL;

    temp = L.firstParent;

    while(temp != NULL) {
        if(temp->dataParent.nomorMeja == nomorMeja){
            if(temp->dataParent.status==false){
                return temp;
            }
        }
        temp = temp->next;
    }
    return NULL;
}

AddressParent findParent(Multilist L, int nomorNota) {
    AddressParent temp = NULL;

    temp = L.firstParent;

    while(temp != NULL) {
        if(temp->dataParent.nomorNota == nomorNota){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

float hitungOmzet(Multilist L){
    AddressParent temp = L.firstParent;
    float total=0;
    while(temp!=NULL){
    	if(temp->dataParent.status == true){
    		total += temp->dataParent.total;
		}
        temp=temp->next;
    } 
   return total;
}


void JumlahMenuTerbanyak(Multilist L, Pesanan P[MAX][2], int total[MAX][2]){
    AddressParent temp = L.firstParent;
    AddressChild tempChild;
    bool cek = false;
    bool cekMakan = false, cekMinum = false;
    int i=4, j=0;
    int noMakan=0,noMinum=0;
    int tempTerbesar = 0, tempTerbesar2 = 0;
    
    system("cls");
    
    printGelasKopiBesarKiri();
    header();//tulisan lagrande
    printGelasKopiBesarKanan();
    
	gotoxy(55, 8);
	printf("        _____\n");
    gotoxy(55, 9);
    printf("       /     \\\n");
    gotoxy(55, 10);
    printf("      | O   O |\n");
    gotoxy(55, 11);
    printf("      |   >   |\n");
    gotoxy(55, 12);
    printf("      \\ \\___/ /\n");
    gotoxy(55, 13);
    printf("       \\_____/\n");
    gotoxy(55, 14);
    printf("        | | |\n");
    gotoxy(55, 15);
    printf("      __|_|_|__\n");
    gotoxy(55, 16);
    printf("     /         \\\n");
    gotoxy(55, 17);
    printf("    |           |\n");
    gotoxy(55, 18);
    printf("    |  [Omset]  |\n");
    gotoxy(55, 19);
    printf("     \\_________/\n");
    
    if(temp == NULL){
		gotoxy(56, 21);
		printf("Belom ada omset boss");
		return;
	}
	
	while(temp!=NULL){
		if(temp->dataParent.status == true){
			cek = true;
			break;
		}
		temp = temp->next;
	}
	
	if(cek == false){
		gotoxy(56, 21);
		printf("Belom ada yang bayar boss");
		return;
	}

    while(temp!=NULL){
        tempChild=temp->firstChild;
        if(haveChild(temp) && temp->dataParent.status == true){
            while(tempChild!=NULL){
                for(i=0;i<MAX;i++){
                    if(cekMenu(P[i][0].nama,tempChild->dataChild.namaPesanan)){
                    	cekMakan = true;
                    }else if(cekMenu(P[i][1].nama,tempChild->dataChild.namaPesanan)){
                    	cekMinum = true;
                    }
                }
                tempChild = tempChild->next;
            }
        }
        temp = temp->next;
    }
  
    for(i=0;i<MAX-1;i++){
        if(total[noMakan][0] < total[i+1][0]){
        	noMakan = i+1;
            tempTerbesar = i+1;
        }
        if(total[noMinum][1] < total[i+1][1]){
        	noMinum = i+1;	
            tempTerbesar2 = i+1;
        }
    }
    
	PersegiPanjang(6, 63, 40, 21);
	
    if(cekMakan == true){
    	gotoxy(41, 22);
    	printf("Makanan Terbanyak adalah : %s dengan jumlah %d",P[tempTerbesar][0].nama,total[tempTerbesar][0]);
	}else{
		gotoxy(41, 22);
    	printf("Belum ada yang memesan makanan");
	}
    
    if(cekMinum == true){
    	gotoxy(41, 23);
    	printf("Minuman Terbanyak adalah : %s dengan jumlah %d",P[tempTerbesar2][1].nama,total[tempTerbesar2][1]);
	}else{
		gotoxy(41, 23);
    	printf("Belum ada yang memesan minuman");
	}
    
    gotoxy(41, 24);
    printf("Dengan jumlah omset sebesar Rp %.2f",hitungOmzet(L));

}

bool cekMenu(string banding, string makanan){ //ngecek menu makanan ada atau tidak
    return strcmpi(banding,makanan)==0;
}

AddressChild isMakan(AddressParent P, string makan){
    AddressChild temp = P->firstChild;
    while(temp!=NULL){
        if(strcmpi(temp->dataChild.namaPesanan, makan)==0){
            return temp;
        }
        temp = temp->next;
    } 
    return NULL;
}

void editMultilist(Multilist *L, AddressParent P, int jumlah, string makan){//split
    AddressParent temp = (*L).firstParent;
    AddressChild tempC, hapus;
    float total=0;
    
    while(temp!=P){
        temp=temp->next;
    }
    
    tempC = temp->firstChild;
    while(tempC!=NULL){
        if(strcmpi(tempC->dataChild.namaPesanan, makan)==0){
            break;
        }
        tempC=tempC->next;
    }
    
    tempC->dataChild.harga = ((tempC->dataChild.harga / tempC->dataChild.jumlah) * (tempC->dataChild.jumlah - jumlah));
    tempC->dataChild.jumlah = tempC->dataChild.jumlah - jumlah;
    
    if(tempC->dataChild.jumlah==0){
    	
        tempC = temp->firstChild;
        if(tempC->next == NULL){
            temp->firstChild = temp->firstChild->next;
            free(tempC);
            tempC=NULL;
        }else{
        	
            if(strcmpi(tempC->dataChild.namaPesanan, makan)==0) {
			    hapus = tempC;
			    tempC = hapus->next;
			    temp->firstChild = tempC;
			    free(hapus);
			    hapus = NULL;
			    
			}else{
    
			    while(tempC->next != NULL) {
			        if(strcmpi(tempC->next->dataChild.namaPesanan, makan)==0) {
			            hapus = tempC->next;
			            tempC->next = hapus->next;
			            free(hapus);
			            hapus = NULL;
			            break;
			        }
			        tempC = tempC->next;
			    }
			}
        }
    }
    
    tempC = temp->firstChild;
    while(tempC!=NULL){
        total += tempC->dataChild.harga;
        tempC=tempC->next;
    }
    
    temp->dataParent.total = total;
}

void deleteAllChild(AddressParent parent){
    AddressChild temp;

    while(haveChild(parent)) {
        temp = parent->firstChild;
        parent->firstChild = parent->firstChild->next;
        free(temp);
    }
}

void gabungNota(Multilist *L, AddressParent tampung, AddressParent pindah){
    AddressChild temp = pindah->firstChild;
    AddressChild bantu;
    int kontrol = 0;
    float total=0;
    while(temp != NULL){
        kontrol = 0;
        bantu = tampung->firstChild;
        while(bantu!=NULL){
            if(strcmpi(bantu->dataChild.namaPesanan ,temp->dataChild.namaPesanan)==0){
                bantu->dataChild.jumlah += temp->dataChild.jumlah;
                bantu->dataChild.harga += temp->dataChild.harga;
                kontrol = 1;
            }
            bantu=bantu->next;
        }
        if(kontrol == 0){
            insertLastChild((*L),tampung->dataParent.nomorNota,temp->dataChild);
        }
        temp = temp->next;
    }
    if(tampung->dataParent.nomorNota > pindah->dataParent.nomorNota){
        tampung->dataParent.nomorNota = pindah->dataParent.nomorNota;
    }
    bantu = tampung->firstChild;
    while(bantu!=NULL){
        total += bantu->dataChild.harga;
        bantu=bantu->next;
    }
    tampung->dataParent.total = total;
    deleteAtParent(&(*L),pindah);
    
}

void deleteAtParent(Multilist *L, AddressParent P) {
    AddressParent temp = L->firstParent;
    AddressParent hapus;
    
    while(temp->next != NULL) {
        if(temp->next == P) {
            hapus = temp->next;
            temp->next = temp->next->next;

            deleteAllChild(hapus);
            free(hapus);
            hapus = NULL;
            break;
        }
        temp = temp->next;
    }
        
    
}

