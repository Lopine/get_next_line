

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../get_next_line.h"

char    *get_next_line(int fd);

int main(void)
{
    int     fd1;
    int     fd2;
    int     count;
    char    *line1;
    char    *line2;
    count = 0;
    fd1 = open("test.txt", O_RDONLY);
    fd2 = open("nl.txt", O_RDONLY);
    /*if (fd == -1)
        return(0);
    */
    while (count < 2)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        ++count;
        printf("----------LIGNE1 [%d]:%s|------------\n", count, line1);
        printf("----------LIGNE2 [%d]:%s|------------\n", count, line2);
        free(line1);
        free(line2);
        line1 = NULL;
        line2 = NULL;
    }
    close(fd1);
    close(fd2);
    return(0);
}