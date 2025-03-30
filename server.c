/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:25:00 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/03/30 16:26:13 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

void handle_sigint(int sig) 
{
    printf("Caught SIGINT (%d), but not exiting\n", sig);
}

int main() 
{
    struct sigaction	sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    while (1) 
	{
		ft_printf("Sleeping...\n");
        sleep(1);
    }
    return 0;
}

// void	handler(int signum, siginfo_t *info, void *more_info)
// {
// 	(void)more_info;
// }

// void	handle_length(int signum)
// {
// 	static int length;
// 	static int bit_count;
	
// 	length = 0;
// 	bit_count = 0;
// 	length <<= 1;  // shift to make room for next bit
// 	if (signum == SIGUSR2)  // assume SIGUSR2 = bit 1
// 		length |= 1;  // set the last bit to 1
// 	bit_count++;
// 	if (bit_count == 32) 
// 		bit_count = 0;
// }

// void	handle_signal(int signum) 
// {
//     static unsigned char current_char = 0;
//     static int bit_count = 0;

//     current_char <<= 1;  // shift to make room for next bit

//     if (signum == SIGUSR2)  // assume SIGUSR2 = bit 1
//         current_char |= 1;  // set the last bit to 1
//     // else SIGUSR1 = bit 0, so we don't change anything
//     bit_count++;
//     if (bit_count == 8) 
// 	{
//         write(1, &current_char, 1);  // print the character
//         bit_count = 0;
//         current_char = 0;
//     }
// }

// int	main(void)
// {
// 	ft_printf("Server PID: %d\n", getpid());
// 	Signal(SIGUSR1, handler);
// 	while (1)
//         pause();
//     return (0);
// }