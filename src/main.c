#include "main.h"

void gameStart() {
  InitAudioDevice();
  tileStart();
  playerStart();
  enemyStart();
}

void gameUpdate() {
  playerUpdate();
  enemyUpdate();  
}

void gameRender() {
  BeginMode2D(camera);
  tileRender();
  playerRender();
  enemyRender();
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
