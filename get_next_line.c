/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:38:52 by plachard          #+#    #+#             */
/*   Updated: 2024/03/05 15:21:46 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

/*  Extract the char from \n + 1 to \0 include  */
char	*next_line(char *static_buf)
{
	int 	end;
	size_t 	len;
	char	*next;

    end = ft_strline(static_buf);
    if (end < 0)
        return (free (static_buf), NULL);
    len = ft_strlen(static_buf) - end;
    next = calloc(len + 1, sizeof (char));
    if (!next)
        return (NULL);
    next = ft_memcpy(next, static_buf + end + 1, len);
	free (static_buf);
    return (next);
}

/*  copy the line and the end sign  */
char	*get_line(char *static_buf)
{
    int     end;
	size_t	len;
	char	*line;

    if (!static_buf[0])
        return (NULL);
    end = ft_strline(static_buf);
	len = ft_strlen(static_buf);
    if (end < 0)
	{
        line = calloc(len + 1, sizeof(char));
        ft_memcpy(line, static_buf, len);
	}
    if (end >= 0)
    {
        line = calloc((end + 2), sizeof(char));
        ft_memcpy(line, static_buf, end + 1);
    }
    return (line);
}

/*  read n bytes from the file descriptor   */
char    *read_line(char *static_buf, int fd)
{
    int         bytes_read;
    char        *buffer;
    
    buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while ((ft_strline(static_buf)) < 0 && (bytes_read != 0))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return(free(buffer), NULL);
		buffer[bytes_read] = '\0';
        static_buf = ft_strjoin(static_buf, buffer);
    }
    free(buffer);
    return (static_buf);
}


/*      get the next line from the file descriptor    */
char    *get_next_line(int fd)
{
    static char    *static_buf[OPEN_MAX];
    char           *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return (0);
    static_buf[fd] = read_line(static_buf[fd], fd);
    if (!static_buf[fd])
        return (NULL);
    line = get_line(static_buf[fd]);
    static_buf[fd] = next_line(static_buf[fd]);
    return (line);
}
