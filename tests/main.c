

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../get_next_line.h"

char    *get_next_line(int fd);

int main(void)
{
    int     fd;
    int     count;
    char    *line;

    count = 0;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return(0);

    while (count < 7)
    {
        line = get_next_line(fd);
        ++count;
        printf("----------LIGNE [%d]:%s|------------\n", count, line);
        free(line);
        line = NULL;
    }
    close(fd);
    return(0);
}