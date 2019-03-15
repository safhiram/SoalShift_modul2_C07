
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>

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

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  
  
  int n = 1;

  while(1)
  {

        struct stat filestat;
                char a[]="/home/safhiram/makanan/makan_enak.txt";
                stat(a,&filestat);
                time_t program=time(NULL);
                time_t buka=filestat.st_atime;

                if(difftime(program, buka)<=30)
        {


                char nama[30] = "/home/safhiram/makanan/makan_sehat";
                char hasil[35];

                sprintf(hasil, "%s%d", nama, n);
                strcat(hasil,".txt");

                FILE * fp;
                fp = fopen(hasil, "w");
                fclose(fp);
                n = n+1;

        }

        sleep(5);
  }

  exit(EXIT_SUCCESS);
}

