#include <stdlib.h>
#include <stdio.h>

int	ft_l(char *st)
{
	int	i;

	i = 0;
	while (st[i])
		i++;
	return (i);
}

int	ft_size(char *str, char *charset)
{
	int	i;
	int	j;
	int	k;
	int	size;

	i = 0;
	k = 0;
	size = 0;
	while (str[i++])
	{
		j = 0;
		while (str[i - 1 + j] && charset[j] && str[i - 1 + j] == charset[j])
			j++;
		if (j != ft_l(charset))
			k++;
		if (j == ft_l(charset) && k)
		{
			k = 0;
			size++;
		}
	}
	if (k)
		size++;
	return (size);
}

char	**ft_fill(char **ms, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	ms = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		ms[i] = malloc(sizeof(char) * 100);
		while (j++ < 100)
			ms[i][j - 1] = '\0';
		j = 0;
		i++;
	}
	ms[i] = 0;
	return (ms);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**ms;

	i = 0;
	k = 0;
	l = 0;
	ms = ft_fill(ms, ft_size(str, charset));
	while (str[i++])
	{
		j = 0;
		while (str[i - 1 + j] && charset[j] && str[i - 1 + j] == charset[j])
			j++;
		if (!j || j < ft_l(charset))
			ms[l][k++] = str[i - 1];
		if (j == ft_l(charset) && k)
		{
			l++;
			i += (ft_l(charset) - 1);
			k = 0;
		}
	}
	return (ms);
}
/*int	main(void)
{
	int	i = 0;
	char *st = "  Batmobile race   1993 ";
	char *sep = "  ";
	char ** res = ft_split(st, sep);
	while (res[i])
		puts(res[i++]);
	return (0);
}*/
