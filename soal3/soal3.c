#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>


int main()
{
        int file1[2];
        int file2[2];
        int status;

    	pid_t pid1;
	pid1=fork();

	pipe(file1);
        pipe(file2);

	//if(stat("campur2",&cek)!=0) 
        //{
               //char *un[3] = {"unzip","campur2.zip",NULL};
		//execv("/usr/bin/unzip",un);
        //}

    if(pid1 == 0)
	{
         	 char *un[3] = {"unzip","campur2.zip",NULL};
          	execv("/usr/bin/unzip",un);
    }else
	{
        while(wait(&status)>0);

    	pid_t pid2;

	pid2=fork();

        if(pid2==0)
	{
            close(file1[0]);
            dup2(file1[1],STDOUT_FILENO);
            close(file1[1]);

	    execlp("ls","ls","campur2",NULL);

        }
	else{
        	while(wait(&status)>0);

    		pid_t pid3;

		pid3=fork();

            if(pid3==0)
		{
			close(file1[1]);
                	dup2(file1[0],STDIN_FILENO);
                	close(file1[0]);

                	close(file2[0]);
                	dup2(file2[1],STDOUT_FILENO);
                	close(file2[1]);


                	char *grep[]={"grep",".txt$", NULL};
                	execv("/bin/grep",grep);

            }else{
                        close(file1[0]);
                        close(file1[1]);
			close(file2[1]);
			char isi[100000];
			FILE* isifile=fdopen(file2[0],"r");
			FILE *daftar=fopen("daftar.txt","w");
			while(fgets(isi, sizeof(isi), isifile)!=NULL)
			{
				if(strstr(&isi[strlen(isi)-5],".txt")!=NULL)
				{
					fprintf(daftar,"%s",isi);
				}
			}
			fclose(daftar);
            }
        }
    }
}
