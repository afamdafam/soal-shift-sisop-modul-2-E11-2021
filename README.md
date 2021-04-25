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
## Penjelasan Nomor 2A dan 2B
Untuk soal 2A, kita diminta untuk mengekstrak file pets.zip pada tujuan `/home/(user)/modul2/petshop/` tetapi hanya file dengan extension `.jpg` yang diekstrak(Nomor 2A). Kemudian, membuat folder sesuai dengan jenis hewan(Nomor 2B). Maka dari itu, kami menggunakan command `execv()` dan untuk mengekstrak dan membuat directory tujuan kami menggunakan fork dengan beberapa child.
```
pid_t child_a, child_b;
  int status;

  child_a = fork();

  if (child_a < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_b < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_a == 0) {
    // this is child

    char *argv[] = {"mkdir", "-p", "/home/refaldyka/modul2/petshop/", NULL};
    execv("/bin/mkdir", argv);
  } else {
    while ((wait(&status)) > 0);
    child_b = fork();
    if (child_b == 0){
    char *argv[] = {"unzip", "pets.zip", "-x", exceptdir,"-d","/home/refaldyka/modul2/petshop/", NULL};
    execv("/usr/bin/unzip", argv);
}
else {
    while ((wait(&status)) > 0);
    listFilesRecursively("/home/refaldyka/modul2/petshop/");
  }
}
}
```
Dapat dilihat bahwa child a akan membuat folder pada file directory tujuan dan kemudian setelah berhasil dieksekusi maka child b akan mengeksekusi pengekstrakan pada directory tujuan. Dalam fungsi unzip kami menggunakan command `-x` yang artinya exception  dan `*/*` untuk yang selain `.jpg`. Untuk Parentnya (Nomor 2B) kami memanggil fungsi untuk mencatat list file dalam directory tujuan dalam bentuk string. 
```
void listFilesRecursively(char *basePath)
{
    int status;
    char location[]= "/home/refaldyka/modul2/petshop/";
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
	  char deli[]="";
	  char directory[]="/home/refaldyka/modul2/petshop/";
	  
	  strcpy(deli,dp->d_name);
          strtok(deli,";");
          strcat(directory,deli);
	  pid_t child_c, child_d;
          child_c = fork();
	  if (child_c < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
	  if (child_c == 0){
	  char *argv[] = {"mkdir", "-p", directory, NULL};
	  execv("/bin/mkdir", argv);
}
	  else{
	  ((wait(&status)) > 0);
}
	  
         

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFilesRecursively(path);
        }
    }

    closedir(dir);
}
```
intinya ada pada `if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)`. kami menyimpan nama nama file pada directory `/home/refaldyka/modul2/petshop/` dalam array `deli` yang tak hingga commandnya seperti berikut.
```
strcpy(deli,dp->d_name);
```
kemudian membuatnya hanya menyimpan hingga bertemu dengan delimiter `;`. Dibawah ini adalah commandnya.
```
strtok(deli,";");
```
Kemudian menggabungkan string yang ada pada array `deli` ke array `directory` dengan command :
```
strcat(directory,deli);
```
Setelah berhasil maka membuat child process baru yang prosesnya hanya membuat folder baru yang nama foldernya sesuai dengan string yang ada pada array `directory` dengan command:
```
char *argv[] = {"mkdir", "-p", directory, NULL};
	  execv("/bin/mkdir", argv);
```
