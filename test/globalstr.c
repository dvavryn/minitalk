#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s = NULL;

char *addc(char *s, int c)
{
	char *tmp;
	char *out;
	size_t	len;
	size_t	i;

	if (!s)
	{
		strdup("");
		if (!s)
			return (NULL);
	}
	len = strlen(s);
	out = (char *)malloc(len + 2);
	if (!out)
		return (out);
	tmp = s;
	i = 0;
	while (i < len - 1)
	{
		out[i] = tmp[i];
		i++;
	}
	out[i] = c;
	out[i + 1] = 0;
	if (tmp)
		free(tmp);
	return (out);
}

int main(void)
{
	s = addc(s, '-');
	s = addc(s, '-');
	s = addc(s, '-');
	printf("%s", s);
}