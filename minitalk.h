/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:57:05 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/26 10:47:35 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
//	write(), getpid(), pause(), sleep(), usleep(), 
# include <sys/types.h>
//	pid_t;

# include "../libft/libft.h"
//	ft_printf()

#include <signal.h>
//	signal(), sigemptyset(), sigaddset(), sigaction()
//	kill(), 

#include <stdlib.h>
//	malloc(), free(), exit()

void	print_title(void);
char	*chartobin(int c);

#endif