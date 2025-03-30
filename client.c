/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:29:51 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/03/30 15:53:39 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void send_char(int server_pid, char c) 
{
	int	i;
	int	bit;
	
	i = 7;
	bit = 0;
    while (i-- >= 0) 
	{
        bit = (c >> i) & 1;

        if (bit == 0)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);

        usleep(100);  // ?? do i need this and how much of a delay
    }
}

void	send_length(int server_pid, int len)
{
	int	i;
	int	bit;

	i = 31;
	bit = 0;
	while (i-- >= 0)
	{
		bit = (len >> i) & 1;
		if (bit == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);  // ?? do i need this and how much of a delay 
	}
}

int	main(int argc, char **argv)
{
	int len;
	int pid;
	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
		return (1);
	pid = ft_atoi(argv[1], NULL);
	if (pid <= 0)
		return (1);
	len = ft_strlen(argv[2]);
	send_length(pid, len);
	while (*argv[2])
	{
		send_char(pid, *argv[2]);
		argv[2]++;
	}
	return (0);
}