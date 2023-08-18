/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:22:02 by idumenil          #+#    #+#             */
/*   Updated: 2023/07/20 15:22:37 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	getpid(void);
pid_t	g_clientpid = -1;

void	recompose(int bit_value, int pid)
{
	int				shift;
	static int		bit_position = 7;
	static char		received_char;

	if (bit_position == -1 || pid != g_clientpid)
	{
		bit_position = 7;
		received_char = 0;
		g_clientpid = pid;
	}
	shift = 1 << (bit_position);
	if (bit_value != 0)
		received_char = (received_char | shift);
	bit_position--;
	if (bit_position == -1)
		write (1, &received_char, 1);
}

void	sig_handler(int sig, siginfo_t *info, void *ptr)
{
	(void)ptr;
	if (sig == SIGUSR1)
		recompose(1, info->si_pid);
	else
		recompose(0, info->si_pid);
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	action.sa_flags = 0;
	action.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	pid = getpid();
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
