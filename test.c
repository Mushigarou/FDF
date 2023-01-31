#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LOW_HEX "0123456789abcdef"
#define UPP_HEX "0123456789ABCDEF"

int is_hexa(char c);
int ft_strtol(char *str);


int main()
{
	char *s = "0xFF";

	puts(s + 2);

	printf("strtol : %ld\n", strtol(s, NULL, 16));
	printf("mine : %d", ft_strtol(s + 2));
}

int	ft_strtol(char *str) // str + 2, to skip "0x"
{
	int	res;
	int	indice;
	int	transparency;
	int	i = 0;

	res = 0;
	transparency = 0;
	if (!str) 
		return (-1);
	while (*str)
	{
		indice = is_hexa(*str);
		if (indice == -1)
			return (perror("One of the values is not a hexa number"), -1);
		res = (res * 16) + indice;
		str++;
	}
	return ((res + transparency));
}

int	is_hexa(char c)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		if (LOW_HEX[i] == c || UPP_HEX[i] == c)
			return (i);
	}
	return (-1);
}
