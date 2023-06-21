/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 02:23:47 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null(pid_t pid)
{
	int	i;
	int	err;

	i = 0;
	while (i++ < 8)
	{
		err = kill(pid, SIGUSR1);
		if (err)
		{
			ft_printf("No signal was sent\n");
			break ;
		}
		usleep(200);
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

int	main(int argc, char *argv[])
{
	int		err;
	pid_t	server_pid;
	int		i;
	char	*bits;

	server_pid = get_pid(argc, argv);
	bits = ft_ctob(argv[2]);
	if (!bits)
		return (0);
	i = 0;
	while (bits[i])
	{
		if (bits[i] == '0')
			err = kill(server_pid, SIGUSR1);
		else
			err = kill(server_pid, SIGUSR2);
		if (err)
			return (ft_printf("No signal was sent\n"), 0);
		usleep(200);
		i++;
	}
	send_null(server_pid);
	free(bits);
	return (0);
}
