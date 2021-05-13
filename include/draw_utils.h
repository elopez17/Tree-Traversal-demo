#ifndef draw_utils_h
#define draw_utils_h

#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#define WIN_X 1920
#define WIN_Y 1080

struct BTree {
	int val;
	int x;
	int y;
	bool visited;
	BTree *left;
	BTree *right;
	BTree() : val(0), left(nullptr), right(nullptr), visited(false) {}
	BTree(int x) : val(x), left(nullptr), right(nullptr), visited(false) {}
	BTree(int x, BTree *left, BTree *right) : val(x), left(left), right(right), visited(false) {}

};

void draw(SDL_Renderer *renderer, BTree *node, int radius);
void drawCircle(SDL_Renderer *renderer, int centreX, int centreY, int radius);
BTree* createTree(int nLevels, int lower_bound=INT_MIN, int upper_bound=INT_MAX);
void initCoords(BTree *node, int yLength, int xLength);
std::queue<BTree*> getPreorder(BTree* root);
std::queue<BTree*> getInorder(BTree* root);
std::queue<BTree*> getPostorder(BTree* root);
void resetVisited(BTree *root);

#endif
