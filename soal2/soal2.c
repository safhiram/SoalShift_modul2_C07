#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/dir.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>

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

  while(1) {
  DIR *folder;
  struct dirent *isi;

  struct stat infofile;

  chdir("/home/safhiram/");
  folder=opendir("hatiku");
  while((isi=readdir(folder)) != NULL){
      if(strcmp(isi->d_name,"elen.ku") == 0){

          stat("hatiku/elen.ku",&infofile);
		      struct passwd *user; 
          user = getpwuid(infofile.st_uid); 
            struct group *grup; 
            grup = getgrgid(infofile.st_gid);
            if( strcmp(user->pw_name,"www-data") == 0 && strcmp(grup->gr_name,"www-data") == 0){
              chmod("hatiku/elen.ku", 0777);
              remove("hatiku/elen.ku");
            }
      }    
  }
   closedir(folder);

   sleep(3);
  }
  
  exit(EXIT_SUCCESS);
}
