
#include <stdio.h>

char    *extract_line(char  *basin_buffer);

int main()
{
    char *buffer = "12345\nabcd";

    printf("%s\n", extract_line(buffer));
} 