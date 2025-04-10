# Tubes_B

Proyek ini merupakan tugas besar untuk mata kuliah Struktur Data menggunakan bahasa C.

## Deskripsi

Aplikasi ini dibuat untuk menyelesaikan suatu permasalahan tertentu membuat mesin kasir sederhana. Program ini terdiri dari beberapa modul utama seperti input/output, antarmuka pengguna, dan proses inti.

## Struktur File

- `main.c` - Fungsi utama program
- `source.c` - Berisi fungsi-fungsi pendukung
- `sourceui.c` - Antarmuka pengguna
- `header.h` - Header file yang mendeklarasikan fungsi dan struct
- `Makefile.win` - File make untuk build otomatis (khusus Windows)
- `Project1.dev` - File proyek Dev-C++ atau Code::Blocks

## Cara Kompilasi dan Menjalankan

1. Gunakan compiler C seperti GCC (MinGW untuk Windows).
2. Kompilasi dengan command:
   ```bash
   gcc main.c source.c sourceui.c -o Project1.exe
