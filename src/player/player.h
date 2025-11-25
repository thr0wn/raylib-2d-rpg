#include "../common.h"
#include "../tile/tile.h"

#ifndef PLAYER_H
#define PLAYER_H

void playerStart();
void playerUpdate();
void playerRender();

void playerMove();
void playerDamage();
void playerEnterDungeon();
void playerPickChest();

void cameraZoom();

#endif
