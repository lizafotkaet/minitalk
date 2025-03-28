/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:25:00 by sergei_pilm       #+#    #+#             */
/*   Updated: 2025/03/28 20:28:13 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_handler(int signum)
{
    if (signum == SIGUSR1) //if the signal is equal to SIGUSR1 then he prints "Hello World"
		
    else if (signum == SIGUSR2)

}

void handle_signal(int signum) 
{
    static unsigned char current_char = 0;
    static int bit_count = 0;

    current_char <<= 1;  // shift to make room for next bit

    if (signum == SIGUSR2)  // assume SIGUSR2 = bit 1
        current_char |= 1;  // set the last bit to 1
    // else SIGUSR1 = bit 0, so we don't change anything

    bit_count++;

    if (bit_count == 8) 
	{
        write(1, &current_char, 1);  // print the character
        bit_count = 0;
        current_char = 0;
    }
}

int main(void)
{
    ft_printf("Server PID: %d\n", getpid());
    while (1)
    {
        pause();
    }
    return (0);
}