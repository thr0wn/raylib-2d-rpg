#include "tile.h"

typedef enum { TEXTURE_TITLEMAP = 0 } texture_asset;

typedef enum {
  TILE_TYPE_DIRT = 0,
  TILE_TYPE_GRASS,
  TILE_TYPE_TREE,
  TILE_TYPE_STONE
} TileType;

Texture2D textures[MAX_TEXTURES];
Tile world[WORLD_WIDTH][WORLD_HEIGHT];
Tile dungeon[WORLD_WIDTH][WORLD_HEIGHT];
Entity dungeonGate, chest;

TileType getRandomTileType() {
  return GetRandomValue(TILE_TYPE_DIRT, TILE_TYPE_TREE);
}

void tileStart() {
  Image image = LoadImage("resources/colored_tilemap_packed.png");
  textures[TEXTURE_TITLEMAP] = LoadTextureFromImage(image);
  UnloadImage(image);

  Tile tile, dungeonTile;
  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      tile = (Tile){.x = i, .y = j, .type = getRandomTileType()};
      dungeonTile = (Tile){.x = i, .y = j, .type = TILE_TYPE_DIRT};
      world[i][j] = tile;
      dungeon[i][j] = dungeonTile;
    }
  }

  dungeonGate = (Entity){.position = {.x = 10, .y = 10}, .zone = ZONE_ALL};
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

      switch (player.zone) {
      case ZONE_WORLD:
      default:
        tile = world[i][j];
        break;
      case ZONE_DUNGEON:
        tile = dungeon[i][j];
        break;
      }
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

  drawTile(dungeonGate.position.x * TILE_WIDTH,
           dungeonGate.position.y * TILE_HEIGHT, 8, 9);

  if (player.zone == chest.zone && chest.isAlive) {
    drawTile(chest.position.x * TILE_WIDTH,
             chest.position.y * TILE_HEIGHT, 9, 3);
  }
}

void tileStop() {
  for (int i = 0; i < MAX_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }
}

Entity createChest() {
  chest = (Entity){.position = enemy.position,
                   .zone = enemy.zone,
                   .isAlive = true,
                   .money = GetRandomValue(10, 100)};
  return chest;
}
