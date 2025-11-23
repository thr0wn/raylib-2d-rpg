#include "debug.h"
#include "raylib.h"

void debugRender() {
  DrawRectangle(5, 5, 330, 120, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(5, 5, 330, 120, BLUE);

  DrawText(TextFormat("Camera Target: (%.2f, (%.2f))", camera.target.x,
                      camera.target.y),
           15, 10, 14, YELLOW);
  DrawText(TextFormat("Camera Zoom: %.2f", camera.zoom), 15, 30, 14, YELLOW);
}
