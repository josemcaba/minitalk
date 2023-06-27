/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:58:07 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/27 17:36:29 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_client_pid;

void	add_bit(char b)
{
	static char	bits[9];
	static int	i;
	char		c;
	static int	prev_client_pid;

	if (g_client_pid != prev_client_pid)
	{
		prev_client_pid = g_client_pid;
		i = 0;
	}
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

void	receive(int signal, siginfo_t *info, void *ucontext)
{
	int	err;

	(void)ucontext;
	g_client_pid = info->si_pid;
	if (signal == SIGUSR1)
		add_bit(0);
	if (signal == SIGUSR2)
		add_bit(1);
	usleep(200);
	err = kill(g_client_pid, SIGUSR1);
	if (err)
	{
		ft_printf("No signal was sent\n");
		exit (0);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					err;

	(void)argv;
	if (argc != 1)
		return (ft_printf("Wrong number of parameter\n"), 0);
	ft_printf("PID : %d\n", getpid());
	sa.sa_sigaction = receive;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	err = sigaction(SIGUSR1, &sa, NULL);
	err += sigaction(SIGUSR2, &sa, NULL);
	if (err)
	{
		ft_printf("Fail setting the signals handler\n");
		return (0);
	}
	while (1)
		pause();
}
