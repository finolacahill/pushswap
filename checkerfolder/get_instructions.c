/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 15:22:55 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/28 15:56:02 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static char	*ft_addchar(char *str, char c)
{
	char			*newstr;
	int				len;
	int				i;

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

static int	execute_instructions(int i, char **instruction, t_stacks *stack)
{
	if (ft_check_instructions(*instruction) == 0)
		return (instructions_error(*instruction));
	ft_move(*instruction, stack);
	free(*instruction);
	if ((*instruction = ft_strnew(1)) == NULL)
		return (0);
	++i;
	return (i);
}

static int	execute_end_flags(int i, int flag, SDL_Renderer *r, SDL_Window *w)
{
	if (flag == 2 || flag == 4)
		quit_window(0, r, w);
	if (flag == 3 || flag == 4)
		ft_printf("%d moves made\n", i);
	return (1);
}

static int	check_last_instruction(char *instruction)
{
	if (ft_strncmp(instruction, "\0\0", 2) != 0)
		return (instructions_error(instruction));
	free(instruction);
	return (1);
}

int			ft_get_instructions(int flag, char *instruction, t_stacks stack)
{
	char			c;
	int				i;
	SDL_Renderer	*renderer;
	SDL_Window		*window;

	i = 0;
	if (flag == 2 || flag == 4)
		init_window(&renderer, &window, stack);
	while ((c = ft_getchar(0)) > 0)
	{
		if (c != '\n')
			if ((instruction = ft_addchar(instruction, c)) == NULL)
				return (0);
		if (c == '\n')
		{
			if ((i = execute_instructions(i, &instruction, &stack)) == 0)
				return (0);
			if (flag == 2 || flag == 4)
				draw_stacks(stack, renderer);
		}
	}
	if (check_last_instruction(instruction) == 0)
		return (0);
	return (execute_end_flags(i, flag, renderer, window));
}
