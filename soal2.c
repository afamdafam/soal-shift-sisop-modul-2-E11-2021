#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <dirent.h>
char exceptdir[] = "*/*";
void listFilesRecursively(char *basePath);
int main() {
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
	  char deli2[]="";
	  char directory2[]="/home/refaldyka/modul2/petshop/";
	  strcpy(deli2,dp->d_name);
	  strtok(deli2,"_");
	  strcat(directory2,deli2);
	  strtok(deli2,";");
	  strcat(directory2,deli2);
	  printf("%s\n",directory2);

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
	  while ((wait(&status)) > 0);
	  child_d = fork();
	
	  while ((wait(&status)) > 0);
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


