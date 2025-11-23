#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

const int screenWidth = 800;
const int screenHeight = 600;

#define TILE_WIDTH 8
#define TILE_HEIGHT 8

#define MAX_TEXTURES 1

#define WORLD_WIDTH 20
#define WORLD_HEIGHT 20

typedef enum { TEXTURE_TITLEMAP = 0 } texture_asset;

Texture2D textures[MAX_TEXTURES];

typedef struct {
  int x;
  int y;
} sTile;

typedef struct {
  int x;
  int y;
} sEntity;

sEntity player;

sTile world[WORLD_WIDTH][WORLD_HEIGHT];

Camera2D camera = {0};

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

void gameStartup() {
  InitAudioDevice();
  Image image = LoadImage("resources/colored_tilemap_packed.png");
  textures[TEXTURE_TITLEMAP] = LoadTextureFromImage(image);
  UnloadImage(image);

  sTile tile;
  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      tile = (sTile){.x = i, .y = j};
      world[i][j] = tile;
    }
  }

  player = (sEntity){.x = WORLD_WIDTH/2, .y = WORLD_HEIGHT/2};

  camera.target.x = player.x;
  camera.target.y = player.y;
  camera.offset = (Vector2){(float)screenWidth / 2, (float)screenHeight / 2};
  camera.rotation = 0.0f;
  camera.zoom = 3.0f;
}

void gameUpdate() {
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

void gameRender() {
  BeginMode2D(camera);

  sTile tile;
  int texture_index_x = 4;
  int texture_index_y = 4;
  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      tile = world[i][j];
      texture_index_x = 4;
      texture_index_y = 4;

      drawTile(tile.x * TILE_WIDTH, tile.y * TILE_HEIGHT, texture_index_x,
               texture_index_y);
    }
  }

  drawTile(camera.target.x, camera.target.y, 4.0f, 0);

  EndMode2D();

  DrawRectangle(5, 5, 330, 120, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(5, 5, 330, 120, BLUE);

  DrawText(TextFormat("Camera Target: (%.2f, (%.2f))", camera.target.x,
                      camera.target.y),
           15, 10, 14, YELLOW);
  DrawText(TextFormat("Camera Zoom: %.2f", camera.zoom), 15, 30, 14, YELLOW);
}

void gameShutdown() {
  for (int i = 0; i < MAX_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }

  CloseAudioDevice();
}

int main(void) {
  InitWindow(screenWidth, screenHeight, "Raylib 2D RPG");
  SetTargetFPS(60);

  gameStartup();

  while (!WindowShouldClose()) {
    gameUpdate();

    BeginDrawing();
    ClearBackground(GRAY);

    gameRender();

    EndDrawing();
  }

  gameShutdown();

  CloseWindow();

  return 0;
}
