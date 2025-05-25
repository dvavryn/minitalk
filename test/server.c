#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../libft/libft.h"

void	print_title(void);

void print_pid(pid_t server);

int main()
{
	pid_t	server;

	server = getpid();
	print_pid(server);
	
}

void print_pid(pid_t server)
{
	char *s;

	s = ft_itoa(server);
	if (!s)
		return ;
	print_title();
	write (1, "\nProcess ID: ", 13);
	write (1, s, ft_strlen(s));
	write (1, "\n\n", 2);
	free (s);
}