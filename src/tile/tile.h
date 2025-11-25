#include "../common.h"

#ifndef TILE_H
#define TILE_H

#define TILE_WIDTH 8
#define TILE_HEIGHT 8

#define MAX_TEXTURES 1

typedef struct {
  int x;
  int y;
  int type;
} Tile;

extern Entity dungeonGate;

void tileStart();
void tileRender();
void tileStop();
void drawTile(int pos_x, int pos_y, int texture_index_x, int texture_index_y);
Entity createChest();

#endif
