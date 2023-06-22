/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 02:23:47 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_chars(pid_t pid, unsigned char *str)
{
	int	err;
	int	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if (*str & 0x80)
				err = kill(pid, SIGUSR2);
			else
				err = kill(pid, SIGUSR1);
			if (err)
			{
				ft_printf("No signal was sent\n");
				exit (0);
			}
			pause();
			*str = *str << 1;
			i++;
		}
		str++;
	}
}

pid_t	get_pid(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Wrong number of parameter\n");
		exit (0);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("PID server not valid\n");
		exit (0);
	}
	return (server_pid);
}

void	server_ack(int signal)
{
	if (signal != SIGUSR1)
		ft_printf("ACK server not valid\n");;
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	signal(SIGUSR1, server_ack);
	server_pid = get_pid(argc, argv);
	send_chars(server_pid, (unsigned char *)argv[2]);
	return (0);
}
