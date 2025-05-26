/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:20:04 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/26 10:54:58 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*reverse(char *in);

char	*chartobin(int c)
{
	char	*out;
	int		i;

	if (c < 0 || c > 127)
		return (NULL);
	out = (char *)malloc(9 * sizeof(char));
	i = 0;
	while (i < 8)
	{
		while (c == 0)
		{
			out[i] = '0';
			if (i == 7)
				return ((out[i + 1] = 0), reverse(out));
			i++;
		}
		if (c % 2 == 1)
			out[i] = '1';
		else
			out[i] = '0';
		c /= 2;
		i++;
	}
	return (NULL);
}

char	*reverse(char *in)
{
	char	*out;
	size_t	i;
	size_t	j;

	out = (char *)malloc(9 * sizeof(char));
	if (!out)
		return (free(in), NULL);
	i = 0;
	j = 7;
	while (i < 8)
	{
		out[i] = in[j];
		i++;
		j--;
	}
	out[8] = 0;
	return (free(in), out);
}
