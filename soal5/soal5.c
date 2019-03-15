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
#include <time.h>

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

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char namafile[125];
	char hehe[100];
	struct stat st = {0};
	DIR* folder;
	struct dirent* rent;
	int i;

	FILE * log;

	snprintf(namafile, sizeof(namafile), "/home/safhiram/log/%02d:%02d:%04d-%02d:%02d", tm.tm_mday,tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
	mkdir("/home/safhiram/log",0777);
    	mkdir(namafile,0777);
		i=1;
		while(1)
		{	
			if(i > 30)
			{
				i=1;
				t=time(NULL);
				tm = *localtime(&t);
				snprintf(namafile, sizeof(namafile), "/home/safhiram/log/%02d:%02d:%04d-%02d:%02d", tm.tm_mday,tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
				mkdir(namafile,0777);
				
			}
			char tambahan[100];
			snprintf(hehe, sizeof(hehe), "/home/safhiram/log/%02d:%02d:%04d-%02d:%02d/", tm.tm_mday,tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);	
			snprintf(tambahan,sizeof(tambahan),"log%d.log",i);
			strcat(hehe,tambahan);
			if(fork()==0)
			{
				execlp("cp","cp","/var/log/syslog", hehe, NULL);
			}
			
			
			i++;
			
			sleep(60);
		}
  exit(EXIT_SUCCESS);
}
