/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:10:01 by idumenil          #+#    #+#             */
/*   Updated: 2023/08/06 10:07:28 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	shift;
	int	i;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i);
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1200);
		i--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, str[i]);
}

int	process_exists(pid_t pid)
{
	return (kill(pid, 0) == 0);
}

int	send(int pid, char *str)
{
	if (!process_exists(pid))
	{
		ft_putstr_fd("Invalid PID\n", 1);
		return (1);
	}
	else
	{
		if (pid == 0)
		{
			ft_putstr_fd("Invalid PID\n", 1);
			return (1);
		}
		send_message(pid, str);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid number of arguments.\
		Correct arguments : executable name, PID, and message", 1);
		return (1);
	}
	if (ft_atoi_mod(argv[1], &pid) == 0)
	{
		ft_putstr_fd("Invalid argument.\
		Correct arguments : executable name, PID, and message", 1);
		return (1);
	}
	else
		return (send(pid, argv[2]));
}
