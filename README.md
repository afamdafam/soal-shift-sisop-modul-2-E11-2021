# soal-shift-sisop-modul-2-E11-2021
## Nama Anggota
```
1. Aimar Wibowo 05111940000034
2. Refaldyka Galuh Pratama 05111940000209
3. Adam Hadi Prasetyo 05111940000224
```

## Penjelasan Nomor 1 A, B, dan C
Untuk soal 1A, kita dapat membuat folder dengan perintah `mkdir` melalui `execv()`. Kemudian masukkan parameter yang sesuai agar folder yang dibuat memenuhi ketentuan. Pada kasus ini kita akan membuat folder **Pyoto**, **Musyik** , dan **Fylm**. 

```
char *argv[] = {"mkdir", "-p", "Musyik","Pyoto","Fylm", NULL};
            execv("/bin/mkdir", argv);
```

Kemudian pada soal 1B, kita diminta mendownload file foto, film, dan musik dari link yang sudah diberikan. Kita akan menggunakan `execv()` dengan `wget` untuk mendownload file dari link yang diberikan, seperti pada contoh berikut.
```
char *argv1[] = {"--no-check-certificate" ,"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O","Pyoto.zip", NULL};
           execv("/usr/bin/wget", argv1);
```
Tidak lupa kita berikan parameter tambahan agar file yang didownload sesuai dengan keinginan.

Setelah mendownload semua file foto, musik, dan film, kita diminta untuk mengekstrak file `.zip` yang didownload dari google drive. Kita akan menggunakan `execv()` dengan `unzip` seperit pada contoh di bawah ini.
```
 char *argv1[] = {"unzip","Pyoto.zip", NULL};
                execv("/usr/bin/unzip", argv1);
```


