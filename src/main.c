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

  EndMode2D();

  DrawRectangle(5, 5, 330, 120, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(5, 5, 330, 120, BLUE);

  DrawText(TextFormat("Camera Target: (%.2f, (%.2f))", camera.target.x,
                      camera.target.y),
           15, 10, 14, YELLOW);
  DrawText(TextFormat("Camera Zoom: %.2f", camera.zoom), 15, 30, 14, YELLOW);
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
