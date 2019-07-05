#include "pushswap.h"

int			ft_count_numbers(char **arg, int limit)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < limit)
	{
		count = count + ft_is_single_arg(arg[i]);
		if (count < 0)
			return (count);
		++i;
	}
	return (count);
}

int	is_sorted(int *a, int count_a)
{
	while (--count_a > 0)
	{
		if (a[count_a] < a[count_a - 1])
		{
	//		printf("error at %d and %d\n", a[count_a], a[count_a - 1]);
			return (0);
		}
	}
	return (1);
}

int			there_are_duplicates(int *a, int quantity_args)
{
	int		i;
	int		j;

	i = 0;
	while (i < quantity_args)
	{
		j = 0;
		while (j < quantity_args)
		{
			if (i != j && a[i] == a[j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
