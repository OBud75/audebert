#include <stdio.h>
#include <stdlib.h>

#ifndef EXO_TP
#define EXO_TP

typedef struct Map {
	int height;
	int width;
	struct Block** blocks;
} Map;

typedef struct Block {
	int pos_x;
	int pos_y;
	struct Block* top;
	struct Block* right;
	struct Block* bot;
	struct Block* left;
} Block;

typedef struct Player {
	struct Block* position;
} Player;

Map* get_map(int height, int width);
void free_map(Map* map);
void load_blocks(Map* map);	
void move(Player* player, char direction);
void show_player(Map* map, Player players[]); // shows a player on a map
void clear_screen();

#endif
