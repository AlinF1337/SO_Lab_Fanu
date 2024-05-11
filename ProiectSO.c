#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, const char* argv[]) 
{
    DIR *pDir[10];
    for (int i = 0; i < argc-1; i++)
    {
        pDir[i] = opendir(argv[i]);
        if (pDir[i] == NULL)
        {
            printf(("Nu se poate deschide directorul de input \"%s\" (Index arg. %d)"),argv[i], i);
            exit(404);
        }
    }
    DIR *OUTPUT = opendir(argv[argc-1]);
    if (OUTPUT == NULL)
        {
            printf(("Nu se poate deschide directorul de output \"%s\" "),argv[argc-1]);
            exit(000);
        }
    int opt;
    while ((opt = getopt(argc, argv, "o:")) != -1)
        switch (opt)
        {
            case 'o': OUTPUT = optarg;
        }

    struct dirent *entry;

    struct stat *buffer = malloc(sizeof(struct stat));

    pid_t pid = fork();

    for (int i = 0; i < argc; i++)
    {
        while ((entry = readdir(pDir[i])) != NULL)
        {
            if (pid == -1) 
            {
                perror("Fork isn't forking");
                exit(0);
            } 
        
            else if (pid == 0) 
            {
                printf("Procesare director: %s\n", pDir[i]);
            }

            char *fisier = entry->d_name;

            int input = open(fisier, O_RDONLY);

            cd argv[argc-1];

            FILE *fileP = fopen("output.txt","w");
            if (fileP == NULL)
            {
                touch output.txt;
                FILE *fileP = fopen("output.txt","w");
                
                if (fileP == NULL)
                {
                    printf("Fisierul nu poate fi deschis");
                    exit(1337);
                }
            }
            
        
            fstat(input,&buffer);

            cat buffer >> output.txt;
            echo "\n" >> output.txt;

            fclose(input);

            //md5sum(pDir[i]);

        }
        closedir(pDir[i]);
    }

    return 0;
}