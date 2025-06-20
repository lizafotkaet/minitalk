/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:31:16 by ebarbash          #+#    #+#             */
/*   Updated: 2025/06/20 11:33:31 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sign, siginfo_t *info, void *context)
{
	static unsigned char	curr_letter = 0;
	static int				i = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
		client_pid = info->si_pid;
	curr_letter = curr_letter << 1;
	if (sign == SIGUSR2)
		curr_letter = curr_letter | 1;
	if (++i == 8)
	{
		if (curr_letter == '\0')
		{
			write (1, "\n", 1);
			kill(client_pid, SIGUSR2);
		}
		else
			write (1, &curr_letter, 1);
		i = 0;
		curr_letter = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	server_sa;

	server_sa = {0};
	ft_printf("Server PID: %d\n", getpid());
	server_sa.sa_sigaction = sig_handler;
	server_sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &server_sa, 0);
	sigaction(SIGUSR2, &server_sa, 0);
	while (1)
		pause();
	return (0);
}
