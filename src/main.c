#include "main.h"

void gameStart() {
  tileStart();
  playerStart();
  enemyStart();
  soundStart();  
}

void gameUpdate() {
  playerUpdate();
  enemyUpdate();
  soundUpdate();  
}

void gameRender() {
  BeginMode2D(camera);
  tileRender();
  playerRender();
  enemyRender();
  EndMode2D();
  debugRender();
}

void gameStop() {
  tileStop();
  soundStop();  
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

  gameStop();

  CloseWindow();

  return 0;
}
