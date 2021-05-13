#include <draw_utils.h>

int main(int argc, char *argv[]){
	int nLevels = 6;
	int yPerLevel = WIN_Y / nLevels;
	int radius = yPerLevel * 0.15;
	BTree *root = createTree(nLevels, 0, 100);
	root->x = WIN_X / 2;
	root->y = radius * 2;
	initCoords(root, yPerLevel, root->x);
	std::queue<BTree*> traversalOrder;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		std::cout << "error initializing SDL: " << SDL_GetError() << std::endl;
	SDL_Window *window = SDL_CreateWindow("Traversal Algorithms, Binary Tree", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event e;
	bool quit = false;
	while (SDL_PollEvent(&e) || !quit){
		SDL_SetRenderDrawColor(renderer, 7, 54, 66, 0);
		SDL_RenderClear(renderer);
		BTree *node;
		if (!traversalOrder.empty()){
			node = traversalOrder.front();
			node->visited = true;
			traversalOrder.pop();
		}
		draw(renderer, root, radius);
		if (e.type == SDL_QUIT){
			quit = true;
		} else if (e.type == SDL_KEYDOWN){
			switch (e.key.keysym.sym){
				case SDLK_DOWN:
					resetVisited(root);
					while (!traversalOrder.empty())
						traversalOrder.pop();
					break;
				case SDLK_LEFT:
					traversalOrder = getPreorder(root);
					break;
				case SDLK_UP:
					traversalOrder = getInorder(root);
					break;
				case SDLK_RIGHT:
					traversalOrder = getPostorder(root);
					break;
			}
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(500);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}
