/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/20 01:58:33 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

void	receive(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("SIGUSR1 received\n");
	else if (signal == SIGUSR2)
	{
		ft_printf("SIGUSR2 received\n");
		exit (0);
	}
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
		return (ft_printf("Wrong number of parameter\n"), 0);
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		pause();
}
