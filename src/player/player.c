#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include <unistd.h>

Camera2D camera = {0};
Entity player = {0};

// events
bool playerZoneChanged, playerPositionChanged, playerMoneyChanged, playerDamageChanged, enemyIsAliveChanged = false;

void playerStart() {
  player = (Entity){.position = {.x = 10, .y = 10},
                    .zone = ZONE_WORLD,
                    .health = 100,
                    .damage = 0,
                    .isPassable = false,
                    .isAlive = true,
                    .money = 1000,
                    .experience = 0};

  camera.target.x = player.position.x;
  camera.target.y = player.position.y;

  camera.offset.x = SCREEN_WIDTH / 2;
  camera.offset.y = SCREEN_HEIGHT / 2;

  camera.rotation = 0.0f;
  camera.zoom = 3.0f;
}

void playerUpdate() {
  cameraZoom();
  playerMove();
  playerEnterDungeon();
  playerDamage();
  playerPickChest();
}

void playerRender() { drawTile(camera.target.x, camera.target.y, 4, 0); }

void cameraZoom() {
  float wheel = GetMouseWheelMove();
  if (wheel != 0) {
    const float zoomIncrement = 0.125f;
    camera.zoom += (wheel * zoomIncrement);
    if (camera.zoom < 3.0f)
      camera.zoom = 3.0f;
    if (camera.zoom > 8.0f)
      camera.zoom = 8.0f;
  }
}

void playerMove() {
  float x = player.position.x;
  float y = player.position.y;

  if (IsKeyPressed(KEY_LEFT)) {
    x -= 1;
  } else if (IsKeyPressed(KEY_RIGHT)) {
    x += 1;
  }

  if (IsKeyPressed(KEY_UP)) {
    y -= 1;
  } else if (IsKeyPressed(KEY_DOWN)) {
    y += 1;
  }

  // event playerPositionChanged
  playerPositionChanged = player.position.x != x || player.position.y != y;

  player.position.x = x;
  player.position.y = y;

  camera.target.x = TILE_WIDTH * player.position.x;
  camera.target.y = TILE_HEIGHT * player.position.y;
}

void playerEnterDungeon() {
  bool shouldEnter =
      IsKeyPressed(KEY_E) &&
      Vector2Distance(player.position, dungeonGate.position) <= .5f;
  if (shouldEnter) {
    switch (player.zone) {
    case ZONE_WORLD:
    default:
      player.zone = ZONE_DUNGEON;
      break;
    case ZONE_DUNGEON:
      player.zone = ZONE_WORLD;
      break;
    }
  }

  // event
  playerZoneChanged = shouldEnter;
}

double lastDamageTime = 0;
void playerDamage() {
  double elapsedTime = GetTime() - lastDamageTime;
  bool shouldDamage = elapsedTime > 1.0f && player.zone == enemy.zone &&
                      enemy.isAlive &&
                      Vector2Distance(player.position, enemy.position) <= 1.0f;
  if (shouldDamage) {
    int damage = GetRandomValue(2, 20);
    enemy.health -= damage;
    enemy.damage = damage;

    if (enemy.health <= 0) {
      enemy.health = 0;
      enemy.isAlive = false;
      player.experience += enemy.experience;
      createChest();
    }
    lastDamageTime = GetTime();
  }

  playerDamageChanged = shouldDamage;
  enemyIsAliveChanged = shouldDamage && enemy.health <= 0;
}

void playerPickChest() {
  bool shouldPick = IsKeyPressed(KEY_E) && player.zone == enemy.zone &&
                    chest.isAlive &&
                    Vector2Distance(player.position, chest.position) <= 1.0f;
  if (shouldPick) {
    chest.isAlive = false;
    player.money += chest.money;
  }

  playerMoneyChanged = shouldPick;
}
