#include "raylib.h"
#include "raymath.h"

#ifndef COMMON_H
#define COMMON_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define WORLD_WIDTH 20
#define WORLD_HEIGHT 20

extern Camera2D camera;

typedef enum {
  ZONE_ALL = 0,
  ZONE_WORLD,
  ZONE_DUNGEON,
} Zone;

typedef struct {
  Vector2 position;
  Zone zone;
  int health;
  int damage;
  int isPassable;
  bool isAlive;
  int money;
  int experience;  
} Entity;

// global entities
extern Entity player, enemy, chest;

// global events
extern bool playerZoneChanged, playerPositionChanged, playerMoneyChanged, playerDamageChanged, enemyIsAliveChanged;

#endif
