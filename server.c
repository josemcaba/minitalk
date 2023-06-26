/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 02:39:07 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	add_bit(char b)
{
	static char	bits[9];
	static int	i;
	char		c;

	bits[i] = b;
	if (++i == 8)
	{	
		c = 0;
		i--;
		while (i >= 0)
		{
			b = bits[7 - i] << i;
			c = c | b;
			i--;
		}
		ft_printf("%c", c);
		i = 0;
	}
}

void	receive(int signal)
{
	if (signal == SIGUSR1)
		add_bit(0);
	if (signal == SIGUSR2)
		add_bit(1);
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
		return (ft_printf("Wrong number of parameter\n"), 0);
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		pause();
}
