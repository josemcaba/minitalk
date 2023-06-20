/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/20 02:45:46 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

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

	server_pid = get_pid(argc, argv);
	i = 0;
	while (i++ < 5)
	{
		err = kill(server_pid, SIGUSR1);
		if (err)
			return (ft_printf("No signal was sent\n"), 0);
		ft_printf("SIGUSR1 was sent\n");
		usleep(10);
	}
	err = kill(server_pid, SIGUSR2);
	if (err)
		return (ft_printf("No signal was sent\n"), 0);
	ft_printf("SIGUSR2 was sent\n");
	return (0);
}
