#pragma once
#include "../common.h"

#define MAX_SOUNDS 5

typedef enum {
  SOUND_FOOT_GRASS = 0,
  SOUND_FOOT_STONE,
  SOUND_ATTACK,
  SOUND_DEATH,
  SOUND_COINS
} SoundAssets;

#define MAX_MUSICS 2
typedef enum {
  MUSIC_LIGHT_AMBIENCE = 0,
  MUSIC_DARK_AMBIENCE
} MusicAsset;

extern Sound sound[MAX_SOUNDS];
extern Music music[MAX_MUSICS];

void soundStart();
void soundStop();
void soundUpdate();
