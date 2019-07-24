
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "../pushswap.h"

static int draw_stack_a(t_stacks stack, SDL_Renderer *renderer)
{
	SDL_Rect rect;
	size_t i;
	size_t j;
	int		total;
	
	j = 0;
	i = 0;
	total = stack.a_count + stack.b_count;
	while (i < stack.a_count)
		{  
			SDL_SetRenderDrawColor(renderer, 256 - (stack.a[i] * 10), 0, 0, 255);
			if (stack.a[i] <= total - (total / 3))
				SDL_SetRenderDrawColor(renderer, 0, 256 - (stack.a[i] * 10), 0, 255);
			if (stack.a[i] <= total / 3)
				SDL_SetRenderDrawColor(renderer, 0, 0, 256 - (stack.a[i] * 10), 255);
				
    		rect.w = stack.a[i] * 2;
    		rect.h = 5;
    		rect.x = 0;
    		rect.y = j;
			j = j + 5;	
			SDL_RenderFillRect(renderer, &rect);
			++i;
		}
	return (0);
}

static int draw_stack_b(t_stacks stack, SDL_Renderer *renderer)
{
	SDL_Rect rect;
	size_t i;
	size_t j;
	int total;
	
	total = stack.a_count + stack.b_count;
	j = 0;
	i = 0;
	while (i < stack.b_count)
		{  
			SDL_SetRenderDrawColor(renderer, 256 - (stack.b[i] * 10), 0, 0, 255);
			if (stack.b[i] <= total - (total / 3))
				SDL_SetRenderDrawColor(renderer, 0, 256 - (stack.b[i] * 10), 0, 255);
			if (stack.b[i] <= total / 3)
				SDL_SetRenderDrawColor(renderer, 0, 0, 256 - (stack.b[i] * 10), 255);
    		rect.w = stack.b[i] * 2;
    		rect.h = 5;
    		rect.x = 550;
    		rect.y = j;
			j = j + 5;	
			SDL_RenderFillRect(renderer, &rect);
			++i;
		}
	return (0);
}
int		draw_stacks(t_stacks stack, SDL_Renderer *renderer)
{
	SDL_Color black = {0, 0, 0, 0};

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, black.a);
	draw_stack_a(stack, renderer);
	draw_stack_b(stack, renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(50);
	return (0);

}

void stack_normalizer(t_stacks *stack)
{
	int i;
	int j;

	i = 0;

	while (i < stack->a_count)
	{
		j = 0;
		while (j < stack->a_count)
		{
			if (stack->a[i] == stack->c[j])
			{
				stack->a[i] = j + 1;
				j = stack->a_count;
			}
			++j;
		}
		++i;
	}
}

int main(int argc, char *argv[])
{
		t_stacks	stack;
	char		*instruction;
	char		*tmp;
	char		c;

	stack.b_count = 0;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int statut = EXIT_FAILURE;
  

	if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) < 0)
			return (ft_pushswap_error(&stack));
	if (ft_buildstacks(&stack, &argv[1]) == 0)
			return (ft_pushswap_error(&stack));
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    window = SDL_CreateWindow("PUSH-SWAP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                		1040, 880, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }
    
   
    
    if(0 != SDL_RenderClear(renderer))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }
	stack_normalizer(&stack);	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    instruction = ft_strnew(1);
	int 	i;

	i = 0;
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
	
			draw_stacks(stack, renderer);
			free(instruction);
			instruction = ft_strnew(1);
			++i;
			  
		}
	}
  
    
	SDL_Delay(5100);
    statut = EXIT_SUCCESS;

Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}

