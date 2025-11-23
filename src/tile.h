#include "raylib.h"
#include "common.h"

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

extern Texture2D textures[MAX_TEXTURES];
extern Tile world[WORLD_WIDTH][WORLD_HEIGHT];

void tileStart();
void tileRender();
void tileStop();
void drawTile(int pos_x, int pos_y, int texture_index_x, int texture_index_y);

#endif
