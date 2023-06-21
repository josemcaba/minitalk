/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 22:22:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_server_ack;

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
			g_server_ack = 0;
			while (!g_server_ack)
				pause();
			*str = *str << 1;
			i++;
		}
		str++;
	}
}

void	send_pid(pid_t pid, unsigned char *str)
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
			usleep(500);
			*str = *str << 1;
			i++;
		}
		str++;
	}
}

void	receive_ack(int signal)
{
	(void)signal;
	g_server_ack = 1;
}

pid_t	get_server_pid(int argc, char *argv[])
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

int	main(int argc, char *argv[])
{
	pid_t			server_pid;
	unsigned char	*client_pid;

	server_pid = get_server_pid(argc, argv);
	client_pid = (unsigned char *)ft_itoa(getpid());
	if (!client_pid)
		return (0);
	send_pid(server_pid, client_pid);
	free(client_pid);
	g_server_ack = 0;
	signal(SIGUSR1, receive_ack);
	send_chars(server_pid, (unsigned char *)argv[2]);
	return (0);
}
