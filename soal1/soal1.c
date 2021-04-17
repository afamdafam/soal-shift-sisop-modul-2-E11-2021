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
  pid_t child_a, child_b,child_c,child_d,child_e,child_f;
  int status;

  child_a = fork();


  if (child_a < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_b < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
   if (child_c < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
   if (child_d < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
   if (child_e < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
   if (child_f < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  
  if (child_a == 0) {
    //B
    char *argv[] = {"--no-check-certificate" ,"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","-O","Musyik.zip", NULL};
    execv("/usr/bin/wget", argv);
  } 

  else {
    while ((wait(&status)) > 0);
    child_b = fork();
      if (child_b == 0){
        //C
            char *argv[] = {"unzip","Musyik.zip", NULL};
            execv("/usr/bin/unzip", argv);

      }
      else {
        while ((wait(&status)) > 0);
        child_c = fork();
        if (child_c == 0){
          //B
           char *argv1[] = {"--no-check-certificate" ,"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O","Pyoto.zip", NULL};
           execv("/usr/bin/wget", argv1);
        }
        else{
          while ((wait(&status)) > 0);
          child_d=fork();
          if(child_d==0){
            //C
                char *argv1[] = {"unzip","Pyoto.zip", NULL};
                execv("/usr/bin/unzip", argv1);

          }
          else{
            while ((wait(&status)) > 0);
            child_e=fork();
            if(child_e==0){
              //B
                  char *argv2[] = {"--no-check-certificate" ,"https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","-O","Fylm.zip", NULL};
                  execv("/usr/bin/wget", argv2);
            }
            else{
              while ((wait(&status)) > 0);
              child_f=fork();
              if(child_f==0){
                //C
                char *argv2[] = {"unzip","Fylm.zip", NULL};
                execv("/usr/bin/unzip", argv2);
              }
              else{
                while ((wait(&status)) > 0);
                //A
                char *argv[] = {"mkdir", "-p", "Musyik","Pyoto","Fylm", NULL};
	              execv("/bin/mkdir", argv);
              }
            }
          }
        }
  }
  }
  
  return 0;

}

