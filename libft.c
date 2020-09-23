/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:18:50 by flavon            #+#    #+#             */
/*   Updated: 2020/08/13 12:20:24 by flavon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *dst)
{
	char	*src;
	size_t	index;

	if (!(src = malloc(sizeof(char) * (ft_strlen(dst) + 1))))
		return (NULL);
	index = 0;
	while (dst[index] != '\0')
	{
		src[index] = dst[index];
		index++;
	}
	src[index] = '\0';
	return (src);
}

int		ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

char	ft_strchr(int symbol, char *string)
{
	int index;

	index = 0;
	while (string[index] != 0)
		if (string[index++] == symbol)
			return (1);
	return (0);
}

int		ft_strlen(char *dst)
{
	int count;

	count = 0;
	while (dst[count] != 0)
		count++;
	return (count);
}

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
