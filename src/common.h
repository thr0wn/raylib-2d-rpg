#include "raylib.h"

#ifndef TEST_H_COMMON
#define TEST_H_COMMON

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define WORLD_WIDTH 20
#define WORLD_HEIGHT 20

extern Camera2D camera;

typedef struct {
  int x;
  int y;
} GameEntity;

#endif
