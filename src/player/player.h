#pragma once
#include "../common.h"
#include "../timer/timer.h"
#include "../tile/tile.h"

void playerStart();
void playerUpdate();
void playerRender();

void playerMove();
void playerDamage();
void playerEnterDungeon();
void playerPickChest();

void cameraZoom();
