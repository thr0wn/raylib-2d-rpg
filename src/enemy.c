#include "enemy.h"
#include "raylib.h"

Entity enemy = {0};

void enemyStart() {
  enemy = (Entity){.position = {.x = 3, .y = 3},
                   .zone = ZONE_DUNGEON,
                   .health = 100,
                   .damage = 0,
                   .isPassable = false,
                   .isAlive = true,
                   .money = 0,
                   .experience = GetRandomValue(10, 100)};
}

void enemyUpdate() {}

void enemyRender() {
  if (player.zone == enemy.zone) {
    if (enemy.isAlive) {
      drawTile(enemy.position.x * TILE_WIDTH, enemy.position.y * TILE_HEIGHT,
               11, 0);
    }
    /* if (!enemy.isAlive) { */
    /*   drawTile(enemy.position.x * TILE_WIDTH, enemy.position.y * TILE_HEIGHT, 9, */
    /*            7); */
    /* } */
  }
}
