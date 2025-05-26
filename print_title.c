#include "../libft/libft.h"

void	print_title(void)
{
	char	*s[7];
	size_t	i;

	s[0] = " __  __ _       _ _        _ _\n";
	s[1] = "|  \\/  (_)     (_) |      | | |\n";
	s[2] = "| \\  / |_ _ __  _| |_ __ _| | | __\n";
	s[3] = "| |\\/| | | '_ \\| | __/ _` | | |/ /\n";
	s[4] = "| |  | | | | | | | || (_| | |   <\n";
	s[5] = "|_|  |_|_|_| |_|_|\\__\\__,_|_|_|\\_\\\n";
	s[6] = NULL;
	i = 0;
	while (s[i])
	{
		write(1, s[i], ft_strlen(s[i]));
		i++;
	}
	return ;
}
