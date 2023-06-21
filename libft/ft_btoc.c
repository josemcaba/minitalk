/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:26:27 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 00:16:59 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_btoc() function converts the initial portion of the string pointed to
// by bits (char of bits) to char representation.

#include "libft.h"

static void	ft_fillchars(char **chars, char *str)
{
	size_t	i;
	int		j;
	char	b;

	i = 0;
	while (*str)
	{
		(*chars)[i] = 0;
		j = 7;
		while (j >= 0)
		{
			b = *str - '0';
			b = b << j;
			(*chars)[i] = (*chars)[i] | b;
			str++;
			j--;
		}
		i++;
	}
}

char	*ft_btoc(char *bits)
{
	size_t	chars_len;
	char	*chars;

	chars_len = ft_strlen(bits) / 8;
	chars = (char *)ft_calloc(chars_len + 1, sizeof(char));
	if (!chars)
		return (NULL);
	ft_fillchars(&chars, bits);
	return (chars);
}
