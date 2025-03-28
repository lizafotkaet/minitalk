/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:29:51 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/03/28 20:14:14 by sergei_pilm      ###   ########.fr       */
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
            kill(server_pid, SIGUSR1);  // signal for 0
        else
            kill(server_pid, SIGUSR2);  // signal for 1

        // sleep to give the server time to catch the signal
        usleep(100);  // you might need to tune this delay
    }
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	int pid = ft_atoi(argv[1]);
	int sig = ft_atoi(argv[2]);

	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	return (0);
}