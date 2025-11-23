#include "raylib.h"
#include "player.h"

Camera2D camera = {0};
GameEntity player = {0};

void playerStart() {
  player = (GameEntity){.x = WORLD_WIDTH / 2, .y = WORLD_HEIGHT / 2};

  camera.target.x = player.x;
  camera.target.y = player.y;

  camera.offset.x = SCREEN_WIDTH / 2;
  camera.offset.y = SCREEN_HEIGHT / 2;

  camera.rotation = 0.0f;
  camera.zoom = 3.0f;
}

void playerUpdate() {
  float x = player.x;
  float y = player.y;

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

  float wheel = GetMouseWheelMove();
  if (wheel != 0) {
    const float zoomIncrement = 0.125f;
    camera.zoom += (wheel * zoomIncrement);
    if (camera.zoom < 3.0f)
      camera.zoom = 3.0f;
    if (camera.zoom > 8.0f)
      camera.zoom = 8.0f;
  }

  player.x = x;
  player.y = y;

  camera.target.x = TILE_WIDTH * player.x;
  camera.target.y = TILE_HEIGHT * player.y;
}
