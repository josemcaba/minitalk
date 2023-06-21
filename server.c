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

void	add_bit(char *b)
{
	static char	*bits;
	char		*tmp;
	int			len;

	if (!bits)
		bits = ft_strjoin("", b);
	else
	{
		tmp = ft_strjoin(bits, b);
		free(bits);
		bits = tmp;
	}
	len = ft_strlen(bits);
	if ((len % 8) == 0)
	{	
		tmp = ft_btoc(bits);
		ft_printf("%s", tmp);
		free(bits);
		free(tmp);
		bits = NULL;
	}
}

void	receive(int signal)
{
	if (signal == SIGUSR1)
		add_bit("0");
	if (signal == SIGUSR2)
		add_bit("1");
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
