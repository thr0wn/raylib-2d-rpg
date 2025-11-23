#include "raylib.h"

#ifndef COMMON_H
#define COMMON_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define WORLD_WIDTH 20
#define WORLD_HEIGHT 20

extern Camera2D camera;

typedef struct {
  int x;
  int y;
} Entity;

#endif
