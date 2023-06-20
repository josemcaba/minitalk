/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:06:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/20 19:56:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

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
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = SA_RESTART | SA_SIGINFO;
	sa1.sa_action = receive;


	signal(SIGUSR1, receive);
	signal(SIGUSR2, end);
	while (1)
		pause();
}
