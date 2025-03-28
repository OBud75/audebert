#include "TP.h"


Map* get_map(int height, int width) {
    Map* map = malloc(sizeof(Map));
    map->height = height;
    map->width = width;
    map->blocks = malloc(height * sizeof(Block*));
    for (int i = 0; i < height; i++) {
        map->blocks[i] = malloc(width * sizeof(Block));
    }
    return map;
    // Pensez à vérifier si malloc a réussi
}

void free_map(Map* map) {
    // Free each row of blocks
    for (int i = 0; i < map->height; i++) {
        free(map->blocks[i]);
    }
    // Free the array of pointers to rows
    free(map->blocks);
    // Free the map itself
    free(map);
}

void load_blocks(Map* map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            Block* current_block = &map->blocks[i][j];
            current_block->pos_x = i;
            current_block->pos_y = j;
            current_block->top = (i > 0) ? &map->blocks[i - 1][j] : NULL;
            current_block->bot = (i < map->height - 1) ? &map->blocks[i + 1][j] : NULL;
            current_block->left = (j > 0) ? &map->blocks[i][j - 1] : NULL;
            current_block->right = (j < map->width - 1) ? &map->blocks[i][j + 1] : NULL;
        }
    }
}

void show_player(Map* map, Player* player){
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (player->position->pos_x == i && player->position->pos_y == j){
                printf("o");
            }
            else {
                printf("-");
            }
        }
    printf("\n");
    }
}

void move(Player* player, char direction) {
    /*
    directions: 
    - 't': top
    - 'g': down
    - 'f': right
    - 'h': left
    */

    Block* current_position = player->position;
    switch (direction) {
        case 't':
            if (current_position->top != NULL) {
                player->position = current_position->top;
                printf("Moved up to (%d, %d)\n", player->position->pos_x, player->position->pos_y);
            } else {
                printf("Cannot move up from (%d, %d)\n", current_position->pos_x, current_position->pos_y);
            }
            break;
        case 'h':
            if (current_position->right != NULL) {
                player->position = current_position->right;
                printf("Moved right to (%d, %d)\n", player->position->pos_x, player->position->pos_y);
            } else {
                printf("Cannot move right from (%d, %d)\n", current_position->pos_x, current_position->pos_y);
            }
            break;
        case 'g':
            if (current_position->bot != NULL) {
                player->position = current_position->bot;
                printf("Moved down to (%d, %d)\n", player->position->pos_x, player->position->pos_y);
            } else {
                printf("Cannot move down from (%d, %d)\n", current_position->pos_x, current_position->pos_y);
            }
            break;
        case 'f':
            if (current_position->left != NULL) {
                player->position = current_position->left;
                printf("Moved left to (%d, %d)\n", player->position->pos_x, player->position->pos_y);
            } else {
                printf("Cannot move left from (%d, %d)\n", current_position->pos_x, current_position->pos_y);
            }
            break;
        default:
            printf("Invalid direction\n");
            break;
    }
}

