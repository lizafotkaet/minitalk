/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:31:24 by ebarbash          #+#    #+#             */
/*   Updated: 2025/06/01 18:14:27 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_sigstatus = READY;

static void	end_handler(int sig)
{
	if (sig == SIGUSR1)
		g_sigstatus = READY;
	else
	{
		write (1, "Message received\n", 17);
		exit(0);
	}
}

void	send_char(pid_t pid, char str)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (str >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		while (g_sigstatus == BUSY)
			pause();
		g_sigstatus = BUSY;
	}
}

void	send_msg(pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;
	struct sigaction	client_sa;

	if (argc != 3)
		(write(2, "Error\n", 7), exit(EXIT_FAILURE));
	server_pid = ft_atoi(argv[1], 0);
	str = argv[2];
	client_sa.sa_flags = SA_SIGINFO;
	client_sa.sa_handler = end_handler;
	sigemptyset(&client_sa.sa_mask);
	sigaction(SIGUSR1, &client_sa, NULL);
	sigaction(SIGUSR2, &client_sa, NULL);
	send_msg(server_pid, str);
	while (1)
	{
		pause();
	}
	return (0);
}
