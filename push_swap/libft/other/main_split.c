#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

int	main(void)
{
	char	**split;
	int	i = 0;

	split = ft_split("   tripouille 42  test", ' ');
	while (split[i])
	{
	printf("%s\n", split[i++]);
	}
}
