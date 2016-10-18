#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <error.h>

int main(int argc, char *argv[]) 
    {
    int fd, inode, i;
    char filename[255];
    if ( argc < 2 )
        {
        printf( "usage: %s [FILE]... \n", argv[0] );
        exit(1);
        }

    int dest_size = sizeof(filename);
    for(i = 1; i < argc; i++)
        {
        if (dest_size > 0)
            {
            filename[0] = '\0';
            strncat(filename, argv[i], dest_size - 1);
            int file = open(filename, O_RDONLY, 0400);
            if (file == -1)
                {
                perror(filename);
                //return(EXIT_FAILURE);
                }
                else
                {
                struct stat f_stat;
                int ret;
                ret = fstat (file, &f_stat);
                if (ret < 0)
                    {
                    perror(filename);
                    //return(EXIT_FAILURE);
                    }

                inode = f_stat.st_ino;
                printf("%s: %d\n",filename, inode);
                }
            }
        }

    return 0;
    }
