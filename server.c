/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:27:35 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/04 17:51:12 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	putnbr(int num)
{
	if (num > 9)
		putnbr(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

void	handler(int sig)
{
	static char	c = 0;
	static int	i = 0;

	c = (sig == SIGUSR2) << i++ | c;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "pid: ", 5);
	putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
