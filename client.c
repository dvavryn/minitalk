/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:08:07 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/24 23:01:50 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// testing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// testing end

void	send_msg(pid_t server, char *msg);
char	*get_msg(char *s);

int	main(int argc, char **argv)
{
	char	*msg;
	pid_t	server;

	if (argc != 3)
		return (printf("Usage: ./client <pid> \"<message>\"\n"));
	server = atoi(argv[1]);
	msg = get_msg(argv[2]);
	if (!msg)
		return (1);
	send_msg(server, msg);
	printf("pid: %i\nmsg: %s\n", server, msg);
	free(msg);
	return (0);
}

char	*get_msg(char *s)
{
	char	*tmp;
	char	*out;
	char	*bin;
	size_t	i;

	i = 0;
	out = ft_strdup("");
	while (s[i])
	{
		tmp = out;
		bin = chartobin(s[i]);
		out = ft_strjoin(out, bin);
		free(tmp);
		free(bin);
		i++;
	}
	tmp = out;
	out = ft_strjoin(out, "00000000");
	free(tmp);
	return (out);
}

void	send_msg(pid_t server, char *msg)
{
	size_t	i;

	i = 0;
	while (msg[i])
	{
		if (msg[i] == '0')
			kill(server, SIGUSR1);
		if (msg[i] == '1')
			kill(server, SIGUSR2);
		usleep(20000);
		i++;
	}
	i = 8;
	while (i > 0)
	{
		kill(server, SIGUSR1);
		i--;
	}
}
