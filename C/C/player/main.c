#include <stdio.h>
#include <stdlib.h>
#include "TP.h"

void clear_screen() {
    printf("\033[H\033[J");
}

int main() {
	int height = 5, width = 5;
	Map* map = get_map(height, width);
	load_blocks(map);

	// Create player and set initial position to the top-left corner
	Player player;
	player.position = &map->blocks[1][1];

	// Example moves
	//move(&player, 'r');  // Move right
	//move(&player, 'b');  // Move down
	
	printf("%d %d\n", (*player.position).pos_x, (*player.position).pos_y);


	show_player(map, &player);

	char direction;
	int running = 1;
	while (running) {
		printf("Enter direction to move (t=up, h=right, g=down, f=left, q=quit): ");
		scanf(" %c", &direction);
		// Avec %c, seul le premier caractère sera pris par scanf, mais le reste restera dans le buffer d'entrée.
		// En c++ le std::endl vide le buffer d'entrée, mais en c il faut le faire manuellement.
		// Une solution rapide pour vider le buffer serait de faire
		// char ch;
		// while ((ch = getchar()) != '\n' && ch != EOF)
		//     continue;
		// Eventuellement si vous codez en C plus tard regardez du côté de gets() and fgets()
		if (direction == 'q') {
			running = 0;
		}
		else {
			clear_screen();
			move(&player, direction);
			show_player(map, &player);
		}
	}

  free_map(map);
	return 0;
}
