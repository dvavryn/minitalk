#include "minitalk.h"


void print_pid(pid_t server);

__sighandler_t get_0(char *out_bin)
{
	char *tmp;

	tmp = out_bin;
	out_bin = ft_strjoinc(out_bin, '0');
	if (tmp)
		free(tmp);
	if (!out_bin)
		return(1);
	// write(1, "0", 1);
	// return (0);
}
__sighandler_t get_1(char *out_bin)
{
	char *tmp;

	tmp = out_bin;
	out_bin = ft_strjoinc(out_bin, '1');
	if (tmp)
		free(tmp);
	if (!out_bin)
		return(1);
	// write(1, "1", 1);
	// return (0);
}

int main()
{
	pid_t	server;
	char *out_bin = NULL;

	out_bin = ft_strdup("");
	signal(SIGUSR1, get_0(out_bin));
	signal(SIGUSR2, get_1(out_bin));
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