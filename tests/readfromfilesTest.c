
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../get_next_line.h"

char    *read_from_file(char *basin_buffer, int fd);

int main(void)
{
    int     fd;
    int     count;
    char    *line;

    count = 0;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return(1);
    }
    while (1)
    {
        line = read_from_file(line, fd);
        if (line == NULL)
            break;
        ++count;
        printf("[%d]:%s\n", count, line);
        free(line);
        line == NULL;
    }
    close(fd);
    return(0);
}