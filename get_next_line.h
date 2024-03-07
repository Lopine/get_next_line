/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:30 by plachard          #+#    #+#             */
/*   Updated: 2024/03/05 15:21:05 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
int 	ft_strline(char *str);
char	*ft_strjoin(char *static_buf, char *buffer);
char	*ft_memcpy(char *dst, char *src, size_t n);
char    *get_next_line(int fd);
char    *read_line(char *static_buf, int fd);
char    *get_line(char *static_buf);
char    *next_line(char *static_buf);

# endif