/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:25:27 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 12:05:49 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static char	*ft_addchar(char *str, char c)
{
	char	*newstr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str) + 1;
	if (!(newstr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		++i;
	}
	newstr[i] = c;
	newstr[i + 1] = '\0';
	free(str);
	return (newstr);
}

static int	instruction_error(char *instruction)
{
	free(instruction);
	return (0);
}

static int	ft_get_instructions(char *instruction, t_stacks stack)
{
	char	c;

	while ((c = ft_getchar(0)) > 0)
	{
		if (c != '\n')
			if ((instruction = ft_addchar(instruction, c)) == NULL)
				return (0);
		if (c == '\n')
		{
			if (ft_check_instructions(instruction) == 0)
				return (instruction_error(instruction));
			ft_move(instruction, &stack);
		//	ft_print_stacks(&stack);
			free(instruction);
			instruction = ft_strnew(1);
		}
	}
	if (ft_strncmp(instruction, "\0\0", 2) != 0)
		return (instruction_error(instruction));
	free(instruction);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stacks	stack;
	char		*instruction;
	char		*tmp;
	char		c;

	stack.b_count = 0;
	if (argc > 1)
	{
		if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) < 0)
			return (ft_pushswap_error(&stack));
		if (ft_buildstacks(&stack, &argv[1]) == 0)
			return (ft_pushswap_error(&stack));
		if ((there_are_duplicates(stack.a, stack.a_count)) == 1)
			return (ft_pushswap_error(&stack));
		instruction = ft_strnew(1);
		if (ft_get_instructions(instruction, stack) == 0)
			return (ft_pushswap_error(&stack));
		if (stack.b_count == 0 && (is_sorted(stack.a, stack.a_count) == 1))
			return (ft_pushswap_ok(&stack));
		else
			return (ft_pushswap_ko(&stack));
	}
	return (0);
}
