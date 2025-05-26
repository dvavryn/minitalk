#include <stddef.h>
#include <stdio.h>
#include "../libft/libft.h"

int power(int of);
int	bintoc(char *bin);
char *get_msg(char *binsnake);

// int main(int argc, char **argv)
int main(void)
{
	// int c = bintoc(argv[1]);
	char *binsnake;
	binsnake = ft_strdup("010010000110000101101100011011000110100101101000011000010110110001101100011011110000000000");
	char *s = get_msg(binsnake);
	if (!s)
		return (1);

	// printf("%s\n", binsnake);
	printf("%s", s);
	free(s);
}

char	*get_msg(char *binsnake)
{
	char *tmp;
	char *bin;
	char c;

	tmp = binsnake;
	while (ft_strlen(binsnake) >= 8)
	{
		bin = ft_strndup(binsnake, 8);
		c = bintoc(bin);
		free(bin);
		printf("%c", c);
		binsnake += 8;
	}
	free(tmp);
	return (NULL);
}

int	bintoc(char *bin)
{
	int		out;
	size_t	i;
	size_t	j;

	i = 7;
	j = 0;
	out = 0;
	while (i >= 0)
	{
		if (bin[j] == '1')
		{
			out += power(i);
		}
		if (i == 0)
			return (out);
		j++;
		i--;
	}
	return (0);
}

int power(int of)
{
	int out;

	out = 1;
	if (of == 0)
		return (out);
	else
		while (of > 0)
		{
			out *= 2;
			of--;
		}
	return (out);
}

