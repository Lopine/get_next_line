#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *append_buffer(char *basin_buffer, char *read_buffer);

int main()
{
    char    *_buffer = "12345";
    char    *stash  = "abcd";

    char    *buffer;

    buffer = malloc(6);
    strcpy(buffer, _buffer);
    buffer[5] = 0;

    printf("%s\n", append_buffer(buffer, stash));
} 