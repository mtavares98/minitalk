/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:31:36 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/04 17:49:23 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>

void	char_to_binary(char c, pid_t pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	ft_atoi(char *str)
{
	int				i;
	unsigned int	num;

	i = -1;
	num = 0;
	while ((str[++i] > 8 && str[i] < 14) || str[i] == 32)
		;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
		if (num > INT_MAX)
			return (-1);
	}
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i])
		return (-1);
	return (num);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
		return (write(1, "Wrong number of arguments\n", 26));
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (write(1, "Invalid PID\n", 12));
	i = -1;
	while (av[2][++i])
		char_to_binary(av[2][i], pid);
	char_to_binary(av[2][i], pid);
}
