#include "pushswap.h"

static int colour_it(int i, SDL_Renderer *renderer, t_stacks stack)
{
	int total;
	int block; 

	total = stack.a_count + stack.b_count;
	block = total / 10;
	if (block == 0)
		block = 1;
	if (i > block * 9)
		SDL_SetRenderDrawColor(renderer, 14, 98, 81, 255 - i);
	if (i <= block * 9)
		SDL_SetRenderDrawColor(renderer, 81, 46, 95, 255 - i);
	if (i <= block * 8)
		SDL_SetRenderDrawColor(renderer, 26, 82, 118, 255 - i);
	if (i <= block * 7)
		SDL_SetRenderDrawColor(renderer, 231, 76, 60, 255- i);
	if (i <= block * 6)
		SDL_SetRenderDrawColor(renderer, 187, 143, 206, 255 - i);
	if (i <= block * 5)
		SDL_SetRenderDrawColor(renderer, 52, 152, 219, 255 - i);
	if (i <= block * 4)
		SDL_SetRenderDrawColor(renderer, 174, 182, 191, 255 - i);
	if (i <= block * 3)
		SDL_SetRenderDrawColor(renderer, 247, 220, 111, 255 - i);
	if (i <= block * 2)
		SDL_SetRenderDrawColor(renderer, 163, 228, 215, 255 - i);	
	if (i <= block)
		SDL_SetRenderDrawColor(renderer, 235, 245, 251, 255 - i);
	return (0);
}

static int draw_stack_a(t_stacks stack, SDL_Renderer *renderer)
{
	SDL_Rect rect;
	SDL_Color peach = {250, 219, 216, 250};
	size_t i;
	size_t j;
	int		total;
	
	j = 0;
	i = 0;
	total = stack.a_count + stack.b_count;
	int x = 540 / total;
	while (i < stack.a_count)
		{  
			/*
			SDL_SetRenderDrawColor(renderer, 256 - (stack.a[i] * 10), 0, 0, 255);
			if (stack.a[i] <= total - (total / 3))
				SDL_SetRenderDrawColor(renderer, 0, 256 - (stack.a[i] * 10), 0, 255);
			if (stack.a[i] <= total / 3)
				SDL_SetRenderDrawColor(renderer, 0, 0, 256 - (stack.a[i] * 10), 255);
			*/
			colour_it(stack.a[i], renderer, stack);	
    		rect.w = ((float)stack.a[i] / total)  * 620;
    		rect.h = 1080 / total;
    		rect.x = 0;
    		rect.y = j;
			j = j + 1080 / total;	
			SDL_RenderFillRect(renderer, &rect);
			SDL_SetRenderDrawColor(renderer, peach.r, peach.g, peach.b, peach.a);
			++i;
		}
	return (0);
}

static int draw_stack_b(t_stacks stack, SDL_Renderer *renderer)
{
	SDL_Rect rect;
	SDL_Color peach = {250, 219, 216, 250};
	size_t i;
	size_t j;
	int total;
	
	total = stack.a_count + stack.b_count;
	j = 0;
	i = 0;
	while (i < stack.b_count)
		{  
			colour_it(stack.b[i], renderer, stack);
			/*
			SDL_SetRenderDrawColor(renderer, 256 - (stack.b[i] * 10), 0, 0, 255 );
			if (stack.b[i] <= total - (total / 3))
				SDL_SetRenderDrawColor(renderer, 0, 256 - (stack.b[i] * 10), 0, 255);
			if (stack.b[i] <= total / 3)
				SDL_SetRenderDrawColor(renderer, 0, 0, 256 - (stack.b[i] * 10), 255);*/
    		rect.w = ((float)stack.b[i] / total) * 620;
    		rect.h = 1080 / total;
    		rect.x = 620;
    		rect.y = j;
			j = j + 1080 / total;	
			SDL_RenderFillRect(renderer, &rect);
			SDL_SetRenderDrawColor(renderer, peach.r, peach.g, peach.b, peach.a - 100);
			++i;
		}
	return (0);
}
int		draw_stacks(t_stacks stack, SDL_Renderer *renderer)
{
	SDL_Color black = {0, 0, 0, 0};
	SDL_Color peach = {250, 219, 216, 250};
	SDL_SetRenderDrawColor(renderer, peach.r, peach.g, peach.b, peach.a);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, peach.r, peach.g, peach.b, peach.a);
	draw_stack_a(stack, renderer);
	draw_stack_b(stack, renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(100);
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
int quit_window(int i, SDL_Renderer *renderer, SDL_Window *window)
{
	if (i == 1)
		ft_putendl_fd("Erreur SDL_Init", 2);
	if (i == 0)
		SDL_Delay(5100);
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
}

int init_window(SDL_Renderer **renderer, SDL_Window *window)
{
 if(0 != SDL_Init(SDL_INIT_VIDEO))
		return(quit_window(1, *renderer, window));
	
    window = SDL_CreateWindow("PUSH-SWAP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                		1240, 1080, SDL_WINDOW_SHOWN);
    if(NULL == window)
   		return(quit_window(1, *renderer, window));
    *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == *renderer)
   		return(quit_window(1, *renderer, window));
    if(0 != SDL_RenderClear(*renderer))
   		return(quit_window(1, *renderer, window));
	return (1);
   
}
/*
int main(int argc, char *argv[])
{
		t_stacks	stack;
	char		*instruction;
	char		*tmp;
	char		c;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
	
		
	stack.b_count = 0;
    instruction = ft_strnew(1);
	if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) < 0)
			return (ft_pushswap_error(&stack));
	if (ft_buildstacks(&stack, &argv[1]) == 0)
			return (ft_pushswap_error(&stack));
	stack_normalizer(&stack);	
	int 	i;

	i = 0;
	init_window(&renderer, window);
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
	
	quit_window(0, renderer, window);
}


*/