/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/21 00:18:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive(int signal)
{
	(void)signal;
	ft_printf("SIGUSR1 received\n");
}

void	end(int signal)
{
	(void)signal;
	ft_printf("SIGUSR2 received\n");
	exit (0);
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
		return (ft_printf("Wrong number of parameter\n"), 0);
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, receive);
	signal(SIGUSR2, end);
	while (1)
		pause();
}
