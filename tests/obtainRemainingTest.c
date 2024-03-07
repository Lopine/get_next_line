

#include <stdio.h>

char    *obtain_remaining(char  *basin_buffer);

int main()
{
    char *buffer = "12345\nabcd";

    printf("%s\n", obtain_remaining(buffer));
} 