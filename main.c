#include "header.h"

int main(){
    Multilist L;
    string username, password;
    string tanggal = "09-12-2024";
    string makan;
    
    int kesempatan = 3, login = 0;
    int noNota = 0000, x,y;
    int menu, subMenu, subMenuBayar = 1, count, index1 = 0, index2 = 0, i, j, in;
    int jumlah, meja;
    
    
    float uang = 0;
    char pilih;
    
    DataChild P;
    DataParent D;
    
    AddressParent tempP, tempP2;
    AddressChild tempC;
    
    Pesanan pesanan[MAX][2];
    int totalMenu[MAX][2];
    
    initPesanan(pesanan);
    createEmpty(&L);

	for(i=0;i<MAX;i++){//init jumlah menu makan dan minum jadi 0
        for(j=0;j<2;j++){
            totalMenu[i][j] = 0;
        }
    }
	
    do{
    	system("cls");
        // harus ada nama restoran sama ui buat username password
        printGelasKopiBesarKiri();
        header();//tulisan lagrande
        printGelasKopiBesarKanan();
        
        PersegiPanjang(4, 50, 35, 6);
    	gotoxy(36, 7);
    	printf("Masukan username : ");fflush(stdin);gets(username);
    	gotoxy(36, 8);
    	printf("Masukan Password : ");fflush(stdin);gets(password);
        
        if(strcmp(username,"LaGrande")==0 && strcmp(password,"Admin123")==0){
            // tampil ui pake sleep
 			hideCur();// untuk menghilangkan cursor
            animasiLoading("Loading...");

			gotoxy(40, 18);
            printf("Tekan ENTER untuk melanjutkan..."); // Tunggu input
            login = 1;
        }else if(kesempatan == 0){
            // tampil ui kesempatan habis
            hideCur();
            loginFailed();

            for(count = 1; count < 5; count++){
                displayBomb(count);
                Sleep(600); // Delay 1 detik untuk setiap tahap
            }
            printf(RED);// Warna merah
            gotoxy(42, 16);
            printf("SILAKAN COBA LAGI NANTI.");
            printf(RESET); 
            
            return 0;
        }else{
            // pasword salah
            printf(RED);
            gotoxy(40, 13);
            printf("Username / Password salah");
            gotoxy(40, 15);
            printf("Try Again...");
            printf(RESET);
            kesempatan--;
        }
        getch();
    }while(login != 1);

    do{
        menu = 1;
		system("cls");
        printGelasKopiBesarKiri();
        header();//tulisan lagrande
        printGelasKopiBesarKanan();
        tampilMenu(&menu);

        switch(menu){

            case 1:
                gotoxy(45, 19);
                printf("Masukan nomor meja pemesanan : ");scanf("%d",&D.nomorMeja);
                
                while(D.nomorMeja <=0){
                	gotoxy(45, 21);
                    printf("[!] Nomor meja tidak boleh kurang dari sama dengan 0");getch();
                    gotoxy(45, 21);
					printf("                                                        ");
                    gotoxy(45, 19);
                    printf("Masukan nomor meja pemesanan :         ");
					gotoxy(76, 19);
					scanf("%d",&D.nomorMeja);					
                }
                
                tempP = cekMeja(L,D.nomorMeja);
                if(tempP!=NULL){
                	gotoxy(45, 21);
                    printf("[!] Meja tersebut sudah terpakai");
                    break;
                }
                
                D.nomorNota = ++noNota;
                strcpy(D.tanggal,tanggal);
                D.total=0;
                D.status=false;
                insertLastParent(&L, D);
                
                tempP = cekMeja(L,D.nomorMeja);
                
                do{
                	index1 = 0;
                	index2 = 0;
                	x = 49;
                	y = 11;
                    do{
                        system("cls");
				        printGelasKopiBesarKiri();
				        header();//tulisan lagrande
				        printGelasKopiBesarKanan();
                        TampilBukuMenu(x,y,pesanan);
                        pilih = getch();
                        switch(pilih){
                            case 'w':
                            	
                            	if(y == 19){
									y = 15;
									if(index2 == 0){
										x = 49;
									}else{
										x = 69;
									}
									index1 = 4;
									break;
								}

                                if(index1 == 0){
                                    y = 19;
                                	x = 64;
                                }else{
                                    y--;
                                    index1--;
                                }

                            break;

                            case 'a':
                            	
								if(y == 19){
									continue;
								}
								
                                if(index2 == 0){
                                    x = 69;
                                    index2 = 1;
                                }else{
                                    x = 49;
                                    index2 = 0;
                                }

                            break;

                            case 's':
								
								if(y == 19){
									y = 11;
									if(index2 == 0){
										x = 49;
									}else{
										x = 69;
									}
									index1 = 0;
									break;
								}
								
                                if(index1 == MAX-1){
                                	y = 19;
                                	x = 64;
                                }else{
                                    y++;
                                    index1++;
                                }

                            break;

                            case 'd':
                            	
                            	if(y == 19){
									continue;
								}

                                if(index2 == 1){
                                    x = 49;
                                    index2 = 0;
                                }else{
                                    x = 69;
                                    index2 = 1;
                                }

                            break;
                        }
                    }while(pilih != 13);
                    
                    if(y == 19){
                    	gotoxy(49, 22);
                    	printf("Sudahi pemesanan ? (y / Y untuk berhenti) ");pilih = getche();
                    	if(pilih == 'y' || pilih == 'Y'){
                    		if(!haveChild(tempP)){
                    			gotoxy(49, 24);
                    			printf("[!] Membatalkan pesanan [!]");
                    			deleteAtParent(&L, tempP);
							}
                    		break;
						}else{
							continue;
						}
					}
                    strcpy(P.namaPesanan,pesanan[index1][index2].nama);
                    
                    do{
                    	gotoxy(49, 22);
                        printf("Masukan Jumlah Pesanan %s : ",pesanan[index1][index2].nama);scanf("%d",&jumlah);
                        if(jumlah > 0){
                            P.jumlah = jumlah;
                            P.harga = jumlah * pesanan[index1][index2].harga;
                            tempP->dataParent.total += P.harga;
                            break;
                        }
                        gotoxy(49, 24);
                        printf("Harus pesan lebih dari sama dengan 1 !!");getch();
                        gotoxy(49, 22);
                        printf("                                                     ");
                        gotoxy(49, 24);
                        printf("                                                     ");
                    }while(1);
                    
                    for(i=0;i<MAX;i++){
	                    if(cekMenu(pesanan[i][0].nama, P.namaPesanan)){
	                        totalMenu[i][0] += jumlah;
	                    }else if(cekMenu(pesanan[i][1].nama, P.namaPesanan)){
	                        totalMenu[i][1] += jumlah;
	                    }
	                }
                    
                    insertLastChild(L, tempP->dataParent.nomorNota, P);
                    

                }while(1); // ganti kondisi kalo dia mau lanjut pesen dimeja itu apa engga
                
            break;

			case 2:

                if(!isEmpty(L)){
                	i = 11;
                	subMenu = 1;
                    do{
                    	system("cls");
                    	printGelasKopiBesarKiri();
				        header();//tulisan lagrande
				        printGelasKopiBesarKanan();
                    	tampilBayar(i);
                    	
                    	pilih = getch();
                    	switch(pilih){
                    		case 'w':
                    			
                    			if(i == 11){
				                    i=14;
				                    subMenu=4;
				                }else{
				                    i--;
				                    subMenu-=1;
				                }
                    			
                    		break;
                    		
                    		case 's':
                    			
                    			if(i == 14){
				                    i=11;
				                    subMenu=1;
				                }else{
				                    i++;
				                    subMenu+=1;
				                }
				                    			
                    		break;
						}
					}while(pilih != 13);
                    
                        switch(subMenu){
                        	do{
								system("cls");

	                            case 1: // bayar
		                            gotoxy(45, 17);
					                printf("Masukan nomor meja pemesanan : ");scanf("%d",&D.nomorMeja);
					                while(D.nomorMeja <=0){
					                	gotoxy(45, 19);
					                    printf("[!] Nomor meja tidak boleh kurang dari sama dengan 0");getch();
					                    gotoxy(45, 19);
										printf("                                                        ");
					                    gotoxy(45, 17);
					                    printf("Masukan nomor meja pemesanan :         ");
										gotoxy(76, 17);
										scanf("%d",&D.nomorMeja);					
					                }
		                                
	                                tempP = cekMeja(L,D.nomorMeja);
	                                if(tempP!=NULL){
	                                	gotoxy(45, 19);
	                                    printf("[1]. Cash");
	                                    gotoxy(45, 20);
										printf("[2]. Qris");
										gotoxy(45, 22);
										printf(">>> ");scanf("%d", &subMenuBayar);
										
	                                    switch(subMenuBayar){
	                                        case 1:
		                                		uang = uiBayar(tempP);
	                                            TampilNota(tempP , uang);
	                                            tempP->dataParent.status = true;
		                                        
	                                        break;
	                                        
	                                        case 2:
	                                            system("cls");
	                                            // TOLONG KASIH GOTOXY YA KASIH DI TENGAH
	                                            srand(time(NULL));
	                                            PersegiPanjang(17, 37, 35, 0);
	                                            for(i =0; i<15; i++){
	                                                for(j=0;j<35;j++){
	                                                    gotoxy(36+j,1+i);
	                                                    in = random();
	                                                    if(in == 1){
	                                                        printf("%c",222);
	                                                    }else if(in == 2){
	                                                        printf("%c",220);
	                                                    }else if(in == 3){
	                                                        printf("%c",254);
	                                                    }else if(in == 4){
	                                                        printf("%c",32);
	                                                    }
	                                                }
	                                                
	                                            }
	                                            
	                                            
	                                            printf("\n\n\n\t\t\t\tTotal Harga : Rp %.2f",tempP->dataParent.total);
                                                sleep(5);
                                                TampilNota(tempP,tempP->dataParent.total);
                                                tempP->dataParent.status = true;
                                                
	                                        break;
                                    	}
                                    
	                                }else{
	                                	gotoxy(45, 20);
	                                    printf("Meja sudah terbayar / Meja tidak tersedia");
	                                }

                            	break;
	
	                            case 2: // merge bill
	                            	if(L.firstParent->next == NULL){
	                            		gotoxy(45, 17);
					               		printf("[!] Hanya terdapat satu pesanan");
					               		break;
									}
	                                gotoxy(45, 17);
					                printf("Masukan nomor meja pemesanan : ");scanf("%d",&D.nomorMeja);
					                while(D.nomorMeja <=0){
					                	gotoxy(45, 19);
					                    printf("[!] Nomor meja tidak boleh kurang dari sama dengan 0");getch();
					                    gotoxy(45, 19);
										printf("                                                        ");
					                    gotoxy(45, 17);
					                    printf("Masukan nomor meja pemesanan :         ");
										gotoxy(76, 17);
										scanf("%d",&D.nomorMeja);					
					                }
	                                tempP = cekMeja(L,D.nomorMeja);
	
	                                if(tempP!=NULL){
	                                    do{
	                                    	gotoxy(45, 19);
											printf("                                                        ");
		                                	gotoxy(45, 19);
		                                    printf("Masukan nomor meja pemesanan yang dimasukan : ");scanf("%d",&meja);
	                                    	if(meja == D.nomorMeja){
	                                    		gotoxy(45, 21);
	                                        	printf("[!] Nomor meja tidak boleh sama");getch();
	                                        	gotoxy(45, 21);
												printf("                                                        ");
											}else if(meja<=0){
												gotoxy(45, 21);
	                                       		printf("[!] Nomor meja tidak boleh kurang dari sama dengan 0\n");getch();
	                                       		gotoxy(45, 21);
												printf("                                                        ");
											}else{
												break;
											}
	                                    }while(1);
	                                    tempP2 = cekMeja(L,meja);
	                                     if(tempP2!=NULL){
	                                     	gotoxy(45, 21);
	                                        printf("Apakah anda yakin untuk menggabungkan ? (y/n) ");pilih = getche();
	                                        if(pilih == 'y'){
	                                            // logika gabung nota
	                                            gabungNota(&L, tempP, tempP2);
	                                            gotoxy(45, 23);
	                                            printf("[*] Nota berhasil di gabungkan");
	                                        }else if(pilih =='n'){
	                                        	gotoxy(45, 23);
	                                            printf("[!] Tidak jadi menggabungkan nota");
	                                        }else{
	                                        	gotoxy(45, 23);
	                                            printf("[!] Tidak ada pilihan tersebut");
	                                        }
	                                     }else{
	                                     	gotoxy(45, 21);
	                                     	printf("[!] Meja yang ingin digabungkan tidak ditemukan");
										 }
	                                }else{
	                                	gotoxy(45, 20);
	                                    printf("[!] Meja tersebut sudah terpakai");
	                                }
	                                
	                            break;
	
	                            case 3: // split bill
	                            
					                do{
					                	gotoxy(45, 17);
					                	printf("Masukan nomor meja pemesanan : ");scanf("%d",&D.nomorMeja);
					                		if(D.nomorMeja <= 0){
					                			gotoxy(45, 19);
							                    printf("[!] Nomor meja tidak boleh kurang dari sama dengan 0");getch();
							                    gotoxy(45, 19);
												printf("                                                        ");
							                    gotoxy(45, 17);
							                    printf("                                     ");
							                    continue;
											}
					                	break;					
					                }while(1);
					                
					                if(cekMeja(L, D.nomorMeja)==NULL){
					                	gotoxy(45, 20);
					                	printf("[!] Meja tidak ditemukan");
										break;
									}
									
									tempP = cekMeja(L,D.nomorMeja);
									tempP2 = L.firstParent;
									
									if(tempP->dataParent.status == true){
										while(tempP2 != NULL){
					                		if(tempP2->dataParent.nomorMeja == tempP->dataParent.nomorMeja && tempP2->dataParent.status == false){
					                			tempP = tempP2;
											}
											tempP2 = tempP2->next;
										}
									}
									
									if(tempP->dataParent.status==true){
										gotoxy(45, 20);
										printf("[$] Meja sudah terbayar");
										break;
									}
									
	                                if(tempP->firstChild == NULL || (tempP->firstChild->next == NULL && tempP->firstChild->dataChild.jumlah == 1)){
	                                	gotoxy(45, 20);
	                                	printf("[!] Hanya terdapat satu makanan / minuman yang dipesan");
	                                	break;
									}
									
	                                if(tempP!=NULL){
		                                D.nomorNota = ++noNota;
		                                strcpy(D.tanggal,tanggal);
		                                D.total=0;
		                                D.status=0;
		                                
		                                insertLastParent(&L, D);
		                                tempP2 = findParent(L, D.nomorNota);
	                                    //tampil menu dalam nota
	                                    
	                                    do{
	                                    	if(tempP->firstChild == NULL || (tempP->firstChild->next == NULL && tempP->firstChild->dataChild.jumlah == 1)){
			                                	gotoxy(45, 20);
			                                	printf("[!] Hanya terdapat satu makanan / minuman yang dipesan");
			                                	break;
											}
	                                        do{
	                                        	gotoxy(45, 19);
	                                        	printf("                                                                    ");
	                                        	gotoxy(45, 19);
	                                            printf("Masukkan menu yang ingin di split bill : ");fflush(stdin);gets(makan);
	                                            tempC=isMakan(tempP, makan);
	                                            
	                                            if(tempC==NULL){
	                                            	gotoxy(45, 21);
	                                                printf("[!] Menu tidak ditemukan");getch();
	                                                gotoxy(45, 21);
	                                        		printf("                                                                    ");
	                                            }
	                                        }while(tempC==NULL);
	                                        
	                                        do{
	                                        	gotoxy(45, 21);
	                                            printf("Masukkan jumlah : ");scanf("%d", &jumlah);
	                                            if(jumlah>tempC->dataChild.jumlah){
	                                            	gotoxy(45, 23);
	                                                printf("Jumlah melebihi pesanan");
	                                        		getch();
	                                                gotoxy(45, 23);
	                                        		printf("                                                                    ");
	                                                continue;
	                                            }
	                                            if(jumlah<=0){
	                                            	gotoxy(45, 23);
	                                                printf("Jumlah harus lebih dari 0");
	                                       			getch();
	                                                gotoxy(45, 23);
	                                       			printf("                                                                    ");
	                                                continue;
	                                            }
	                                            break;
	                                        }while(1);
	                                        
	                                        // isi data child
	                                        P.harga = ((tempC->dataChild.harga / tempC->dataChild.jumlah) * jumlah);
	                                        strcpy(P.namaPesanan, tempC->dataChild.namaPesanan);
	                                        P.jumlah = jumlah;
	                                        
	                                        // edit data dalam multilist
	                                        editMultilist(&L, tempP, jumlah, makan); //done
	                                        
	                                        // insert last child
	                                        insertLastChild(L, D.nomorNota, P);
	                                        
	                                        tempP2->dataParent.total += P.harga;
	                                        // konfirmasi
	                                        gotoxy(45, 23);
	                                        printf("Apakah hanya itu saja yang ingin di split ? (y / Y untuk berhenti) ");pilih = getche();
	                                        if(pilih == 'y' || pilih == 'Y'){
	                                        	break;
											}
											gotoxy(45, 19);
	                                        printf("                                                                    ");
	                                        gotoxy(45, 20);
	                                        printf("                                                                    ");
	                                        gotoxy(45, 21);
	                                        printf("                                                                    ");
											gotoxy(45, 23);
	                                        printf("                                                                    ");
	                                    }while(1);
	
	                                }else{
	                                	gotoxy(45, 19);
	                                    printf("Meja tidak ditemukan");
	                                }
	
	                            break;
	
	                            case 4: // cancel
	                            	gotoxy(49, 19);
	                                printf("Kembali ke menu utama");
	                            break;
                        }while(menu!=13);
                    }
                }else{
                	gotoxy(50, 18);
                    printf("[!] Data masih kosong");
                }

            break;
			
            case 3:
                // tambah pesanan
                gotoxy(45, 19);
                printf("Masukan nomor meja pemesanan : ");scanf("%d",&D.nomorMeja);
                while(D.nomorMeja <=0){
                	gotoxy(45, 21);
                    printf("[!] Nomor meja tidak boleh kurang dari sama dengan 0");getch();
                    gotoxy(45, 21);
					printf("                                                        ");
                    gotoxy(45, 19);
                    printf("Masukan nomor meja pemesanan :         ");
					gotoxy(76, 19);
					scanf("%d",&D.nomorMeja);					
                }
                
                tempP = cekMeja(L,D.nomorMeja);
                    if(tempP!=NULL){
                        do{
                        	index1 = 0;
		                	index2 = 0;
		                	x = 49;
		                	y = 11;
							do{
                                system("cls");
                                
                                // tampil menu makanan (input menu) kasih nomor meja juga
                                printGelasKopiBesarKiri();
						        header();//tulisan lagrande
						        printGelasKopiBesarKanan();
						        
                                TampilBukuMenu(x,y,pesanan);
                                pilih = getch();
                                switch(pilih){
		                            case 'w':
		                            	
		                            	if(y == 19){
											y = 15;
											if(index2 == 0){
												x = 49;
											}else{
												x = 69;
											}
											index1 = 4;
											break;
										}
		
		                                if(index1 == 0){
		                                    y = 19;
		                                	x = 64;
		                                }else{
		                                    y--;
		                                    index1--;
		                                }
		
		                            break;
		
		                            case 'a':
		                            	
										if(y == 19){
											continue;
										}
										
		                                if(index2 == 0){
		                                    x = 69;
		                                    index2 = 1;
		                                }else{
		                                    x = 49;
		                                    index2 = 0;
		                                }
		
		                            break;
		
		                            case 's':
										
										if(y == 19){
											y = 11;
											if(index2 == 0){
												x = 49;
											}else{
												x = 69;
											}
											index1 = 0;
											break;
										}
										
		                                if(index1 == MAX-1){
		                                	y = 19;
		                                	x = 64;
		                                }else{
		                                    y++;
		                                    index1++;
		                                }
		
		                            break;
		
		                            case 'd':
		                            	
		                            	if(y == 19){
											continue;
										}
		
		                                if(index2 == 1){
		                                    x = 49;
		                                    index2 = 0;
		                                }else{
		                                    x = 69;
		                                    index2 = 1;
		                                }
		
		                            break;
		                        }
                            }while(pilih != 13);
                            
                            strcpy(P.namaPesanan,pesanan[index1][index2].nama);
                
	                        if(y == 19){
		                    	gotoxy(49, 22);
		                    	printf("Sudahi pemesanan ? (y / Y untuk berhenti) ");pilih = getche();
		                    	if(pilih == 'y' || pilih == 'Y'){
		                    		break;
								}else{
									continue;
								}
							}
							
                            do{
		                    	gotoxy(49, 22);
		                        printf("Masukan Jumlah Pesanan %s : ",pesanan[index1][index2].nama);scanf("%d",&jumlah);
		                        if(jumlah > 0){
		                            P.jumlah = jumlah;
		                            P.harga = jumlah * pesanan[index1][index2].harga;
		                            tempP->dataParent.total += P.harga;
		                            break;
		                        }
		                        gotoxy(49, 24);
		                        printf("Harus pesan lebih dari sama dengan 1 !!");getch();
		                        gotoxy(49, 22);
		                        printf("                                                     ");
		                        gotoxy(49, 24);
		                        printf("                                                     ");
		                    }while(1);
		                    
                            for(i=0;i<MAX;i++){
			                    if(cekMenu(pesanan[i][0].nama, P.namaPesanan)){
			                        totalMenu[i][0] += jumlah;
			                    }else if(cekMenu(pesanan[i][1].nama, P.namaPesanan)){
			                        totalMenu[i][1] += jumlah;
			                    }
			                }
			                
                            insertLastChild(L, tempP->dataParent.nomorNota, P);

                        }while(1);
                    }else{
                    	gotoxy(45, 21);
                        printf("[!] Meja tersebut tidak tersedia");
                    }
                    
            break;

            case 4:
				JumlahMenuTerbanyak(L, pesanan, totalMenu);
            break;
            
            case 5:
            	for(count = 1; count < 5; count++){
            		
	                displayBomb(count);
	                Sleep(600); // Delay 1 detik untuk setiap tahap
            	}
            	
            	gotoxy(37, 16);
            	printf(RED);
            	printf("Selamat atas kerja kerasnya huraaa");
            	printf(RESET);
            break;

            default:
            	gotoxy(50, 18);
                printf("[!] Menu tidak tersedia");
            break;
            
        }getch();
    }while(menu!=5);
    return 0;
}
