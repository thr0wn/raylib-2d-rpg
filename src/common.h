#pragma once
#include <stdio.h>
#include "raylib.h"
#include "raymath.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define WORLD_WIDTH 20
#define WORLD_HEIGHT 20

extern Camera2D camera;

typedef enum Zone {
  ZONE_ALL = 0,
  ZONE_WORLD,
  ZONE_DUNGEON,
} Zone;

typedef struct Entity {
  Vector2 position;
  Zone zone;
  int health;
  int damage;
  int isPassable;
  bool isAlive;
  int money;
  int experience;  
} Entity;

typedef struct Timer {
  double startTime;
  double endTime;
  bool isActive;  
} Timer;

// global entities
extern Entity player, enemy, chest;

// global timers
extern Timer damageTimer;

// global events
extern bool playerZoneChanged, playerPositionChanged, playerMoneyChanged, playerDamageChanged, enemyIsAliveChanged;
