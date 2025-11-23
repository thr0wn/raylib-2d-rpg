#include "main.h"
#include "raylib.h"
#include "raymath.h"

void gameStart() {
  InitAudioDevice();
  tileStart();
  playerStart();
}

void gameUpdate() { playerUpdate(); }

void gameRender() {
  BeginMode2D(camera);
  tileRender();
  playerRender();
  EndMode2D();
  debugRender();
}

void gameShutdown() {
  tileStop();
  CloseAudioDevice();
}

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib 2D RPG");
  SetTargetFPS(60);

  gameStart();

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
