#include "tile.h"
#include "raylib.h"
#include "raymath.h"

typedef enum { TEXTURE_TITLEMAP = 0 } texture_asset;

typedef enum {
  TILE_TYPE_DIRT = 0,
  TILE_TYPE_GRASS,
  TILE_TYPE_TREE,
  TILE_TYPE_STONE
} tile_type;

Texture2D textures[MAX_TEXTURES];
Tile world[WORLD_WIDTH][WORLD_HEIGHT];

tile_type getRandomTileType() {
  return GetRandomValue(TILE_TYPE_DIRT, TILE_TYPE_TREE);
}

void tileStart() {
  Image image = LoadImage("resources/colored_tilemap_packed.png");
  textures[TEXTURE_TITLEMAP] = LoadTextureFromImage(image);
  UnloadImage(image);

  Tile tile;
  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      tile = (Tile){.x = i, .y = j, .type = getRandomTileType()};
      world[i][j] = tile;
    }
  }
}

void drawTile(int pos_x, int pos_y, int texture_index_x, int texture_index_y) {
  Rectangle source = {(float)(texture_index_x * TILE_WIDTH),
                      (float)(texture_index_y * TILE_HEIGHT), (float)TILE_WIDTH,
                      (float)TILE_HEIGHT};
  Rectangle destiny = {(float)(pos_x), (float)(pos_y), (float)TILE_WIDTH,
                       (float)TILE_HEIGHT};
  Vector2 origin = {0, 0};
  DrawTexturePro(textures[TEXTURE_TITLEMAP], source, destiny, origin, 0.0f,
                 WHITE);
}

void tileRender() {
  Tile tile;
  int texture_index_x = 4;
  int texture_index_y = 4;
  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      tile = world[i][j];

      switch (tile.type) {
      case TILE_TYPE_DIRT:
      default:
        texture_index_x = 4;
        texture_index_y = 4;
        break;
      case TILE_TYPE_GRASS:
        texture_index_x = 5;
        texture_index_y = 4;
        break;
      case TILE_TYPE_TREE:
        texture_index_x = 5;
        texture_index_y = 5;
        break;
      case TILE_TYPE_STONE:
        texture_index_x = 1;
        texture_index_y = 6;
        break;
      }

      drawTile(tile.x * TILE_WIDTH, tile.y * TILE_HEIGHT, texture_index_x,
               texture_index_y);
    }
  }
}

void tileStop() {
  for (int i = 0; i < MAX_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }
}
