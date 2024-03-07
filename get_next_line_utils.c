/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:00:42 by plachard          #+#    #+#             */
/*   Updated: 2024/02/29 16:07:17 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	n;

	n = count * size;
	if (n == 0 || n/count != size)
		return (NULL);
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	while (n > 0)
	{
		*ptr = 0;
		++ptr;
		--n;
	}
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	ft_strline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_memcpy(char *dst, char *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst || !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strjoin(char *static_buffer, char *buffer)
{
	char	*s;
	size_t	static_len;
	size_t	buffer_len;

	if (!static_buffer)
		static_buffer = calloc(1, sizeof (char));	
	static_len = ft_strlen(static_buffer);
	buffer_len = ft_strlen(buffer);
	s = calloc((static_len + buffer_len + 1), sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, static_buffer, static_len);
	ft_memcpy(s + static_len, buffer, buffer_len);
	free(static_buffer);
	return (s);
}