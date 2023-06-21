/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 22:14:46 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_client_pid;

void	add_bit(int signal)
{
	static char	bits[9];
	static int	i;
	char		c;
	char		b;

	b = 0;
	if (signal == SIGUSR2)
		b = 1;
	bits[i] = b;
	i++;
	if (i == 8)
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
	int	err;

	add_bit(signal);
	if (g_client_pid)
	{
		err = kill(g_client_pid, SIGUSR1);
		if (err)
		{
			ft_printf("No signal was sent\n");
			exit (0);
		}
	}
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
		return (ft_printf("Wrong number of parameter\n"), 0);
	ft_printf("PID : %d\n", getpid());
	g_client_pid = 0;
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		pause();
}
