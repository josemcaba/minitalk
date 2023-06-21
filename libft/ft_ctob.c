/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:26:27 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 19:04:21 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_ctob() function converts the initial portion of the string pointed to
// by chars to bits representation.

#include "libft.h"

static void	ft_fillbits(char **bits, unsigned char *str)
{
	size_t			i;
	int				j;

	i = 0;
	while (*str)
	{
		j = 0;
		while (j < 8)
		{
			if (*str & 0x80)
				(*bits)[i] = '1';
			else
				(*bits)[i] = '0';
			*str = *str << 1;
			j++;
			i++;
		}
		str++;
	}
}

char	*ft_ctob(char *chars)
{
	size_t	bits_len;
	char	*bits;

	bits_len = 8 * ft_strlen(chars);
	bits = (char *)ft_calloc(bits_len + 1, sizeof(char));
	if (!bits)
		return (NULL);
	ft_fillbits(&bits, (unsigned char *)chars);
	return (bits);
}
