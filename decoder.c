#include <stddef.h>
#include <stdio.h>
#include "../../libft/libft.h"

int power(int of);
int	bintoc(char *bin);
char *get_msg(char *binsnake);

// int main(int argc, char **argv)
int main(void)
{
	// int c = bintoc(argv[1]);
	char *binsnake = "010010000110010101101100011011000110111100100000010101110110111101110010011011000110010000000000000";
	char *s = get_msg(binsnake);
	if (!s)
		return (1);

	printf("%s\n", binsnake);
	printf("%s", s);
	free(s);
}

char *get_msg(char *binsnake)
{
	char	*out;
	char	*charinbin;
	char	*tmp;

	if (!binsnake)
		return (NULL);
	out = ft_strdup("");
	while (ft_strlen(binsnake) >= 16);
	{
		charinbin = ft_strndup(binsnake, 8);
		if (!charinbin)
			return (free(out), NULL);
		tmp = out;
		out = ft_strjoinc(out, bintoc(charinbin));
		if (!out)
			return (free(tmp), free(charinbin), NULL);
		free(tmp);
		tmp = binsnake;
		binsnake = ft_substr(binsnake, 8, ft_strlen(binsnake) - 8);
		if (!binsnake)
			return (free(tmp), free(out), free(charinbin), NULL);
		printf("%s\n", binsnake);
		free(tmp);
	}
	return (out);
}



/* 
char *get_msg(char *binsnake)
{
	char	*out;
	char	*charinbin;
	charinbin = ft_strndup(binsnake, 8);
	if (!charinbin)
		return (NULL);
	out = (char *)malloc(2);
	if (!out)
		return (free(charinbin), NULL);
	out[0] = bintoc(charinbin);
	out[1] = 0;
	return (free(charinbin), out);
} */









/* char *addc(char *buffer, char *binsnake, int c)
{
	char	*bin;
	char	*tmp;

	if (!buffer)
		ft_strdup("");
	bin = ft_strndup(binsnake, 8);
	if (!bin)
		return (NULL);
	tmp = binsnake;
	binsnake = ft_substr(binsnake, 8, ft_strlen(binsnake) - 8);
	if (!binsnake)
		return (free(bin), free(tmp), NULL);
	free(tmp);
	tmp = buffer;
	buffer = ft_stradd(buffer, c);
	if (!buffer)
		return (free(bin), free(tmp), NULL);
	free(tmp);
	return (buffer);
}
 */

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

