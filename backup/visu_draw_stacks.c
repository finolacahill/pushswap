#include "pushswap.h"

static int colour_it(int i, SDL_Renderer *renderer, t_stacks stack)
{
	int block; 

	block = (stack.a_count + stack.b_count) / 10;
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
	int speed;

	speed = 4000 / (stack.a_count + stack.b_count);	
	SDL_SetRenderDrawColor(renderer, peach.r, peach.g, peach.b, peach.a);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, peach.r, peach.g, peach.b, peach.a);
	draw_stack_a(stack, renderer);
	draw_stack_b(stack, renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(speed);
	return (0);

}