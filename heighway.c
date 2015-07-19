#include <stdio.h>

typedef enum {UP, RIGHT, DOWN, LEFT} direction;

/* Expect either LEFT or RIGHT for turnDir */
direction changeDirection(direction currentDir, direction turnDir){
	switch (currentDir){
		case UP:
			if (turnDir == LEFT)
				return LEFT;
			else
				return RIGHT;
		case RIGHT:
			if (turnDir == LEFT)
				return UP;
			else
				return DOWN;
		case DOWN:
			if (turnDir == LEFT)
				return RIGHT;
			else
				return LEFT;
		case LEFT:
			if (turnDir == LEFT)
				return DOWN;
			else
				return UP;
	}
}

int main(int argc, char* args[]){
	if (argc < 1){
		return 1;
	}

	direction d = RIGHT;

	int n = atoi(args[1]);
	printf("(0, 0)\n");

	// Check for this first because ((((i & -i) << 1) & i) != 0) returns 0 for n = 0
	// when it should be 1 to indicate initial right turn
	if (n < 1){
		return 0;
	}
	else{
		printf("(1, 0)\n");
	}

	unsigned int i;
	unsigned int max = (1 << n); // 2^n
	int x = 1, y = 0;
	for (i = 1; i < max; i++){
		direction turn = ((((i & -i) << 1) & i) != 0) ? RIGHT : LEFT; // LEFT if 0, RIGHT if 1
		d = changeDirection(d, turn);
		switch (d){
			case UP:
				y++;
				break;
			case RIGHT:
				x++;
				break;
			case DOWN:
				y--;
				break;
			case LEFT:
				x--;
				break;
		}
		printf("(%d, %d)\n", x, y);
	}

	return 0;
}