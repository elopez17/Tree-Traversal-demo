#include <draw_utils.h>

void draw(SDL_Renderer * renderer, BTree *node, int radius){
	if (node->visited)
		SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
	else
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	for (int i = 0; i <= radius; i++)
		drawCircle(renderer, node->x, node->y, i);

	if (node->left != nullptr){
		if (node->visited && node->left->visited)
			SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
		else
			SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		SDL_RenderDrawLine(renderer, node->x - 1, node->y - 1, node->left->x - 1, node->left->y - 1);
		SDL_RenderDrawLine(renderer, node->x, node->y, node->left->x, node->left->y);
		SDL_RenderDrawLine(renderer, node->x + 1, node->y + 1, node->left->x + 1, node->left->y + 1);
		draw(renderer, node->left, radius);
	}
	if (node->right != nullptr){
		if (node->visited && node->right->visited)
			SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
		else
			SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		SDL_RenderDrawLine(renderer, node->x - 1, node->y + 1, node->right->x - 1, node->right->y + 1);
		SDL_RenderDrawLine(renderer, node->x, node->y, node->right->x, node->right->y);
		SDL_RenderDrawLine(renderer, node->x + 1, node->y - 1, node->right->x + 1, node->right->y - 1);
		draw(renderer, node->right, radius);
	}
}

void drawCircle(SDL_Renderer * renderer, int centreX, int centreY, int radius)
{
	const int diameter = (radius * 2);

	int x = (radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = (tx - diameter);

	while (x >= y)
	{
		//  Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}
