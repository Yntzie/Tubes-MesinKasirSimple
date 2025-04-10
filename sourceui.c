#include "header.h"

void header(){
    PersegiPanjang(5, 70, 28, 0);
    printf(LIGHTBLUE);
    gotoxy(29, 1);
    printf("`00`     '00'      .000'  '0 0 0    '00'   '00.. '0' '0000' '00000'");
    gotoxy(29, 2);
    printf(" 00      00 0      0 ===.  0 00     00 0    00 00 0   0   0  0====");
    gotoxy(29, 3);
    printf("_0000_ _00_ _0_   _'000'_ _0_ _0_ _00_ _0_ _00__000_ _0000_ _00000_");
    printf(RESET);
}

void printGelasKopiBesarKiri() {
	printf(WHITE);
	gotoxy(10, 0);
    printf("   (   (   (\n");
    gotoxy(10, 1);
    printf("   )   )   )\n");
    printf(RESET);
    printf(YELLOW);
    gotoxy(10, 2);
    printf("..............\n");
    gotoxy(10, 3);
    printf("|             |]\n");
    gotoxy(10, 4);
    printf("|             |]\n");
    gotoxy(10, 5);
    printf("|             |]\n");
    gotoxy(10, 6);
    printf("\\             /\n");
    gotoxy(10, 7);
    printf(" \\           /\n");
    gotoxy(10, 8);
    printf("  `----------'\n");
    printf(RESET);
}

void printGelasKopiBesarKanan() {
	printf(WHITE);
	gotoxy(100, 0);
    printf("   (   (   (\n");
    gotoxy(100, 1);
    printf("   )   )   )\n");
    printf(RESET);
    printf(YELLOW);
    gotoxy(100, 2);
    printf(" ..............\n");
    gotoxy(100, 3);
    printf("[|             |\n");
    gotoxy(100, 4);
    printf("[|             |\n");
    gotoxy(100, 5);
    printf("[|             |\n");
    gotoxy(100, 6);
    printf(" \\             /\n");
    gotoxy(100, 7);
    printf("  \\           /\n");
    gotoxy(100, 8);
    printf("   `----------'\n");
    printf(RESET);
}

void animasiLoading(char *message) {
    char spinner[] = {'|', '/', '-', '\\'}; // Karakter animasi
    int i = 0, j = 0;
	
	printf(GREEN);
	gotoxy(45,12);
    printf("Welcome to La Grande");

    while (j < 4) { // Animasi berjalan sebanyak 3 kali
    	gotoxy(47, 15);
        printf("%c %s", spinner[i], message); // Tampilkan karakter spinner
        Sleep(200); // Delay 200ms
        i = (i + 1) % 4; // Putaran spinner
        if (i == 0) j++; // Satu putaran selesai
    }
    printf(RESET);
    
}

void loginFailed() {//tampilan loading gagal
    
    int i, j;

    // Tampilan "LOGIN GAGAL"
 
    for (i = 0; i < 3; i++) {
    	gotoxy(40, 14);
        printf("!!! LOGIN GAGAL !!!");
        Sleep(400);
    }

    // Animasi teks terkunci
    gotoxy(40, 16);
    printf("System Lock");

    for (i = 0; i < 3; i++) {
        printf(" ...");
        Sleep(600);
    }
    
}

void displayBomb(int count) {
    printf(RED);
    system("cls");
    if (count == 1) {
    	gotoxy(45, 10);
        printf("     .\n");
        gotoxy(45, 11);
        printf("    . .\n");
        gotoxy(45, 12);
        printf("   .   .\n");
        gotoxy(45, 13);
        printf("    . .\n");
        gotoxy(45, 14);
        printf("     .\n");
    } else if (count == 2) {
    	
    	gotoxy(45, 10);
        printf("     .\n");
        gotoxy(45, 11);
        printf("   .   .\n");
        gotoxy(45, 12);
        printf("  .  *  .\n");
        gotoxy(45, 13);
        printf("   .   .\n");
        gotoxy(45, 14);
        printf("     .\n");
    } else if (count == 3) {
    	gotoxy(45, 10);
        printf("     *\n");
        gotoxy(45, 11);
        printf("   *   *\n");
        gotoxy(45, 12);
        printf("  *  B  *\n");
        gotoxy(45, 13);
        printf("   *   *\n");
        gotoxy(45, 14);
        printf("     *\n");
    } else if (count == 4) {
    	gotoxy(45, 10);
        printf("    BOOM!!!\n");
        gotoxy(45, 11);
        printf("   *   *   *\n");
        gotoxy(45, 12);
        printf("  *  * * *  *\n");
        gotoxy(45, 13);
        printf("   *   *   *\n");
        gotoxy(45, 14);
        printf("     *   *\n");
    }
    printf(RESET);
}

void PersegiPanjang(int x, int y, int postX, int postY){
	int i, j;
	for(i=0;i<x;i++){
		gotoxy(postX, postY+i);
		for(j=0;j<y;j++){
			if(i==0 || i==x-1 ){
				if(i==0 && j==y-1){
					printf("%c", 191);
				}else if(i==0 && j==0){
					printf("%c", 218);
				}else if(i==0 && j==y-1){
					printf("%c", 179);
				}else if(i==x-1 && j==0){
					printf("%c", 192);
				}else if(i==x-1 && j==y-1){
					printf("%c", 217);
				}else{
					printf("%c", 196);
				}
			}else if(j==0 || j==y-1){
					printf("%c", 179);
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void TampilanMenuUtama(int y){
    PersegiPanjang(7, 18, 51, 10);
	    if(y==11){
	   		printf(RED);
		}
        gotoxy(52, 11);
		printf("   Input Menu");
		printf(RESET);
		
		if(y==12){
	   		printf(RED);
		}
		gotoxy(52, 12);
		printf("     Bayar");
		printf(RESET);
		
		if(y==13){
	   		printf(RED);
		}
		gotoxy(52, 13);
		printf(" Tambah Pesanan");
		printf(RESET);
		
		if(y==14){
	   		printf(RED);
		}
		gotoxy(52, 14);
		printf("     Omset");
		printf(RESET);
		
		if(y==15){
	   		printf(RED);
		}
		gotoxy(52, 15);
		printf("    Log Out");
		printf(RESET);
}

void tampilBayar(int y){
	
	PersegiPanjang(6, 18, 51, 10);
	if(y==11){
	   		printf(RED);
		}
        gotoxy(52, 11);
		printf("     Bayar");
		printf(RESET);
		
		if(y==12){
	   		printf(RED);
		}
		gotoxy(52, 12);
		printf("    Gabung");
		printf(RESET);
		
		if(y==13){
	   		printf(RED);
		}
		gotoxy(52, 13);
		printf("   Split Bill");
		printf(RESET);
		
		if(y==14){
	   		printf(RED);
		}
		gotoxy(52, 14);
		printf("     Back");
		printf(RESET);
}

void TampilBukuMenu(int kiri, int kanan, Pesanan P[MAX][2]){
	PersegiPanjang(3, 21, 45, 8);
	gotoxy(45,9);
	printf("	    Makanan");
	PersegiPanjang(8, 21, 45, 10);
	
	PersegiPanjang(3, 21, 66, 8);
	gotoxy(66,9);
	printf("	  Minuman");
	PersegiPanjang(8, 21, 66, 10);
	int i, j, x = 49, y=11;
	for(i=0;i<MAX;i++){
		j=0;
		x = 49;
		
        if(x==kiri && y+i==kanan){
		    printf(RED);
		}
        gotoxy(x, y+i);
        printf("%s", P[i][j].nama);
        printf(RESET);
		j=1;
		x= 69;
		
        if(x==kiri && y+i==kanan){
		    printf(RED);
		}
        gotoxy(x, y+i);
        printf("%s", P[i][j].nama);
        printf(RESET);
	}
	PersegiPanjang(3,42, 45, 18);
	gotoxy(64, 19);
	
	if(64==kiri && 19==kanan){
	    printf(RED);
	}
	printf("Exit");
	printf(RESET);
}

void TampilNota(AddressParent P, float bayar){
	int i=11, j=0;
	AddressChild temp = P->firstChild;
	
	system("cls");
	gotoxy(10, 3);
	printf("        _____\n");
    gotoxy(10, 4);
    printf("       /     \\\n");
    gotoxy(10, 5);
    printf("      | O   O |\n");
    gotoxy(10, 6);
    printf("      |   >   |\n");
    gotoxy(10, 7);
    printf("      \\ \\___/ /\n");
    gotoxy(10, 8);
    printf("       \\_____/\n");
    gotoxy(10, 9);
    printf("        | | |\n");
    gotoxy(10, 10);
    printf("      __|_|_|__\n");
    gotoxy(10, 11);
    printf("     /         \\\n");
    gotoxy(10, 12);
    printf("    |           |\n");
    gotoxy(10, 13);
    printf("    |   [====]  |\n");
    gotoxy(10, 14);
    printf("     \\_________/\n");
    gotoxy(8, 16);
    printf("[*] Pembayaran Berhasil [*]");
    	
	while(temp!=NULL){
		temp=temp->next;
		j++;
	}
	PersegiPanjang(12+(j*2), 58, 49, 3);
	temp= P->firstChild;
	gotoxy(56, 4);
	printf("		 La Grande");
	gotoxy(50, 5);
	printf("- Tanggal : %s",P->dataParent.tanggal);
	gotoxy(50, 7);
	printf("- No Meja : %02d",P->dataParent.nomorMeja);
	gotoxy(50, 9);
	printf("- No Nota : %04d",P->dataParent.nomorNota);

	while(temp!=NULL){
		gotoxy(50, i);
		printf("%s---------------- %d x Rp.%.2f",temp->dataChild.namaPesanan, temp->dataChild.jumlah, temp->dataChild.harga);
		i+=2;
		temp = temp->next;
	}
	gotoxy(50, i);
	printf("                   Total = Rp %.2f", P->dataParent.total);
    i+=1;
	gotoxy(50, i);
	printf("                   Bayar = Rp %.2f", bayar);
    i+=1;
	gotoxy(50, i);
	printf("               Kembalian = Rp %.2f", bayar - P->dataParent.total);
	i+=3;
	PersegiPanjang(4, 37, 55, i);
	i+=1;
	gotoxy(56,i);
	printf("Jangan Lupa Datang Lagi yaaaaaa :)");
    
}

void tampilOmset(Multilist L){
	int i=4, j=0;
	float count;
	
	AddressParent temp = L.firstParent;
	
	system("cls");
	gotoxy(10, 3);
	printf("        _____\n");
    gotoxy(10, 4);
    printf("       /     \\\n");
    gotoxy(10, 5);
    printf("      | O   O |\n");
    gotoxy(10, 6);
    printf("      |   >   |\n");
    gotoxy(10, 7);
    printf("      \\ \\___/ /\n");
    gotoxy(10, 8);
    printf("       \\_____/\n");
    gotoxy(10, 9);
    printf("        | | |\n");
    gotoxy(10, 10);
    printf("      __|_|_|__\n");
    gotoxy(10, 11);
    printf("     /         \\\n");
    gotoxy(10, 12);
    printf("    |           |\n");
    gotoxy(10, 13);
    printf("    |   [====]  |\n");
    gotoxy(10, 14);
    printf("     \\_________/\n");
    
	PersegiPanjang(4, 37, 55, 20);
	gotoxy(56, 21);
	printf("Jangan Lupa Datang Lagi yaaaaaa :)");
	
	if(temp == NULL){
		system("cls");
		gotoxy(56, 10);
		printf("Belom ada omset boss");
		return;
	}
	
	while(temp != NULL){
		temp=temp->next;
		j++;
	}
	
	PersegiPanjang(12+(j*2), 58, 49, 3);
	
	temp = L.firstParent;

	while(temp != NULL){
		if(temp->dataParent.status == true){
			gotoxy(50, i);
			printf(" Meja %d---------------- Rp.%.2f",temp->dataParent.nomorMeja, temp->dataParent.total);
			count += temp->dataParent.total;
			i+=2;
		}
		temp = temp->next;
	}
	
	gotoxy(70, (12+(j*2))-1);
	printf("Total : %.2f", count);
}

float uiBayar(AddressParent P){
	float uang;
	
	do{
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
	    printf("    |   [====]  |\n");
	    gotoxy(55, 19);
	    printf("     \\_________/\n");
		PersegiPanjang(3, 30, 55, 20);
	 	gotoxy(56, 21);
	 	printf("Rp %.2f", P->dataParent.total);
 	
 
 		
 		gotoxy(56, 24);
 		printf("Masukan uang anda :         ");
		gotoxy(77, 24);
		scanf("%f", &uang);
		
 		if(uang >= P->dataParent.total){
			return uang;
		}else{
		
		
			gotoxy(0, 25);
			printf("                                                                                         ");
			gotoxy(56, 26);
			printf("[!] Uang anda kurang");getch();
		}
	}while(1);
}
