/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:26:27 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 00:17:09 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_ctob() function converts the initial portion of the string pointed to
// by chars to bits representation.

#include "minitalk.h"

static void	ft_fillbits(char **bits, char *str)
{
	size_t			i;
	int				j;
	unsigned char	c;

	i = 0;
	while (*str)
	{
		c = *str;
		j = 0;
		while (j < 8)
		{
			if (c & 0x80)
				(*bits)[i] = '1';
			else
				(*bits)[i] = '0';
			c = c << 1;
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
	ft_fillbits(&bits, chars);
	return (bits);
}

// int	main(int argc, char *argv[])
// {
// 	char	*bits;
// 	char	*chars;

// 	bits = ft_ctob(argv[1]);
// 	if (!bits)
// 		return (0);
// 	ft_printf("%s\n", bits);
// 	chars = ft_btoc(bits);
// 	if (!chars)
// 	{
// 		free (bits);
// 		return (0);
// 	}
// 	ft_printf("%s\n", chars);
// 	ft_printf("\n");
// 	free(bits);
// 	free(chars);
// 	return (0);
// }
