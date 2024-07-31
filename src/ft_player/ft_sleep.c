/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:36:40 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/31 14:40:44 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

// Function to read the current Time Stamp Counter (TSC)
static inline uint64_t	read_tsc(void)
{
	unsigned int	lo;
	unsigned int	hi;

	__asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
	return (((uint64_t)hi << 32) | lo);
}

// Function to sleep for a specified number of seconds using a busy-wait loop
void	ft_sleep(int seconds)
{
	uint64_t	start;
	uint64_t	end;
	uint64_t	frequency;

	frequency = 100000000;
	start = read_tsc();
	end = start + seconds * frequency;
	while (read_tsc() < end)
	{
	}
}
