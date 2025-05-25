#include "minitalk.h"

void print_pid(pid_t server);

int get_0(void)
{
	write (1, "0", 1);
	return (0);
}
int get_1(void)
{
	write(1, "1", 1);
	return (0);
}

char	*get_char(char c)
{
	size_t	i;

	i = 0;
	while 
}


int main()
{
	pid_t	server;

	signal(SIGUSR1, get_0);
	signal(SIGUSR2, get_1);
	server = getpid();
	print_pid(server);
	while (1) ;

	return (0);
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