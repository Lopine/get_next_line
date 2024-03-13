/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:00:42 by plachard          #+#    #+#             */
/*   Updated: 2024/03/08 13:30:31 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	unsigned char	*ptr;
	size_t			n;

	n = count * size;
	p = malloc(n);
	ptr = (unsigned char *)p;
	if (!ptr)
		return (NULL);
	if (n == 0)
		return (0);
	while (n > 0)
	{
		*ptr = 0;
		++ptr;
		--n;
	}
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
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
	if (n == 0)
		return (dst);
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
		static_buffer = ft_calloc(1, sizeof (char));
	static_len = ft_strlen(static_buffer);
	buffer_len = ft_strlen(buffer);
	s = ft_calloc((static_len + buffer_len + 1), sizeof(char));
	if (!s)
		return (static_buffer);
	ft_memcpy(s, static_buffer, static_len);
	ft_memcpy(s + static_len, buffer, buffer_len);
	free(static_buffer);
	return (s);
}
