#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>


int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/safhiram/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
        struct stat st = {0};
        char nama[1000];
        DIR* folder;
        struct dirent* rent;

    if (stat("modul2", &st) == -1) {
        mkdir("modul2",0777);
        mkdir("modul2/gambar", 0777);

    }
        folder = opendir("/home/safhiram/foldergambar");
        if(folder==NULL)
        {
                printf("eror\n");
        }
        else
        {
                while(1)
                {
                        printf("masuk\n");
                        if((rent=readdir(folder))!=NULL)
                        {
                                char from[10000], dest[100000], namafile[100000];
                                memset(dest, '\0', sizeof(dest));
                                memset(from, '\0', sizeof(from));
                                memset(namafile, '\0' , sizeof(namafile));

                                strcpy(nama,rent->d_name);
                                printf("%s\n",rent->d_name);

                                strcpy(from, "/home/safhiram/foldergambar/");
                                strcpy(dest,"/home/safhiram/modul2/gambar/");

                                if(strstr(nama,".png"))
                                {
                                        int jumlah = strlen(nama);
                                        strcat(from,nama);
                                        strncpy(namafile,nama,jumlah-4);
                                        strcat(namafile,"_grey.png");
                                        strcat(dest,namafile);
                                        printf("debug\n");
                                        printf("%s %s\n",from,dest);
                                        rename(from,dest);
                                }
                        }
                        else
                        {
                                break;
                        }
                }
                closedir(folder);
        }
    sleep(2);
  }
  exit(EXIT_SUCCESS);
}