#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CANVAS_WIDTH 10
#define CANVAS_HEIGHT 20

typedef enum {
	RED=41,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
	BLACK=0,
}Color;

typedef enum {
	EMPTY=-1,
	I,
	J,
	L,
	O,
	S,
	T,
	Z

}ShapeId;

typedef struct {
	Color color;
	ShapeId shape;
	int size;
	char rotates[4][4][4];
}Shape;

Shape shapes[7] = {
	{
		.shape = I,
		.color = CYAN,
		.size = 4,
		.rotates = {
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,0,1,0},
				{0,0,1,0},
				{0,0,1,0},
				{0,0,1,0}
			},
			{
				{0,0,0,0},
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0}
			},

		}
	},
	{
		.shape = J,
		.color = BLUE,
		.size = 3,
		.rotates = {
			{
				
				{0,1,0},
				{0,1,0},
				{1,1,0}
			},
			{
				{1,0,0},
				{1,1,1},
				{0,0,0}
				
			},
			{
				
				{0,1,1},
				{0,1,0},
				{0,1,0}
			},
			{
				{0,0,0},
				{1,1,1},
				{0,0,1}
				
			},

		}
	},
	{
		.shape = L,
		.color = YELLOW,
		.size = 3,
		.rotates =
		{
			{
				{0,0,1},
				{1,1,1},
				{0,0,0}
			},
			{
				{0,1,0},
				{0,1,0},
				{0,1,1}
			},
			{
				{0,0,0},
				{1,1,1},
				{1,0,0}
			},
			{
				{1,1,0},
				{0,1,0},
				{0,1,0}
			}
		}
	},
	{
		.shape = O,
		.color = WHITE,
		.size = 2,
		.rotates =
		{
			{
				{1,1},
				{1,1}
			},
			{
				{1,1},
				{1,1}
			},
			{
				{1,1},
				{1,1}
			},
			{
				{1,1},
				{1,1}
			}
		}
	},
	{
		.shape = S,
		.color = GREEN,
		.size = 3,
		.rotates =
		{
			{
				{0,1,1},
				{1,1,0},
				{0,0,0}
			},
			{
				{0,1,0},
				{0,1,1},
				{0,0,1}
			},
			{
				{0,0,0},
				{0,1,1},
				{1,1,0}
			},
			{
				{1,0,0},
				{1,1,0},
				{0,1,0}
			}
		}
	},
	{
		.shape = T,
		.color = PURPLE,
		.size = 3,
		.rotates =
		{
			{
				{0,1,0},
				{1,1,1},
				{0,0,0}
			},
			{
				{0,1,0},
				{0,1,1},
				{0,1,0}
			},
			{
				{0,0,0},
				{1,1,1},
				{0,1,0}
			},
			{
				{0,1,0},
				{1,1,0},
				{0,1,0}
			}
		}
	},
	{
		.shape = Z,
		.color = RED,
		.size = 3,
		.rotates =
		{
			{
				{1,1,0},
				{0,1,1},
				{0,0,0}
			},
			{
				{0,0,1},
				{0,1,1},
				{0,1,0}
			},
			{
				{0,0,0},
				{1,1,0},
				{0,1,1}
			},
			{
				{0,1,0},
				{1,1,0},
				{1,0,0}
			}
		}
	},
};

typedef struct {
	int x;
	int y;
	int score;
	int rotate;
	int fallTime;
	ShapeId queue[4];
}State;

typedef struct {
	Color color;
	ShapeId shape;
	bool current;
}Block;

void resetBlock(Block* block) {
	block->color = BLACK;
	block->shape = EMPTY;
	block->current = false;
}

int main() {
	srand(time(NULL));
	State state = {
		.x = CANVAS_WIDTH / 2,
		.y = 0,
		.score = 0,
		.rotate = 0,
		.fallTime = 0
	};

	for (int i = 0; i < 4; i++)
	{
		state.queue[i] = rand() % 7;
	}

	Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
	for (int i = 0; i < CANVAS_HEIGHT; i++)
	{
		for (int j = 0; j < CANVAS_WIDTH; j++)
		{
			resetBlock(&canvas[i][j]);
		}
	}

	system("cls");
	printf("\e[?25l"); //hide cursor
	/*Color cur;
	for (int i = 0; i < 7; i++)
	{
		for (int r = 0; r < 4; r++)
		{
			for (int s = 0; s < shapes[i].size; s++)
			{
				for (int t = 0; t < shapes[i].size; t++)
				{
					if (shapes[i].rotates[r][s][t])
					{
						cur = shapes[i].color;
					}
					else
					{
						cur = WHITE;
					}
					printf("\033[%dm  \033[0m", cur);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;*/
}
