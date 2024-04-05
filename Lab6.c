#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char* argv[]) 
{
    DIR *pDir = opendir(argv[1]);

    if (pDir == NULL)
    {
        printf(("Nu se poate deschide directorul \"%s\" "),argv[1]);
        exit(404);
    }

    struct dirent *entry;


    while ((entry = readdir(pDir)) != NULL)
    {
        char *fisier = entry->d_name;
        /*if()
        {
            
        }
        */
        FILE *input = open(fisier, O_RDONLY);
        
    }



    closedir(pDir);
    
    return 0;
}