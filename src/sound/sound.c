#include "sound.h"
#include "raylib.h"

Sound sound[MAX_SOUNDS];
Music music[MAX_MUSICS];

void soundStart() {
  InitAudioDevice();

  sound[SOUND_FOOT_GRASS] = LoadSound("resources/Grass1.wav");
  sound[SOUND_FOOT_STONE] = LoadSound("resources/Concrete1.wav");
  sound[SOUND_ATTACK] = LoadSound("resources/07_human_atk_sword_2.wav");
  sound[SOUND_DEATH] = LoadSound("resources/24_orc_death_spin.wav");
  sound[SOUND_COINS] = LoadSound("resources/handleCoins.ogg");

  music[MUSIC_LIGHT_AMBIENCE] = LoadMusicStream("resources/light-ambience.mp3");
  music[MUSIC_DARK_AMBIENCE] = LoadMusicStream("resources/dark-ambience.mp3");
  PlayMusicStream(music[MUSIC_LIGHT_AMBIENCE]);
}

void soundUpdate() {
  // ambience music
  if (player.zone == ZONE_WORLD) {
    UpdateMusicStream(music[MUSIC_LIGHT_AMBIENCE]);

    if (playerZoneChanged) {
      StopMusicStream(music[MUSIC_DARK_AMBIENCE]);
      PlayMusicStream(music[MUSIC_LIGHT_AMBIENCE]);
    }
  } else if (player.zone == ZONE_DUNGEON) {
    UpdateMusicStream(music[MUSIC_DARK_AMBIENCE]);

    if (playerZoneChanged) {
      StopMusicStream(music[MUSIC_LIGHT_AMBIENCE]);
      PlayMusicStream(music[MUSIC_DARK_AMBIENCE]);
    }
  }

  // sfx
  if (playerPositionChanged) {
    if (player.zone == ZONE_WORLD) {
      PlaySound(sound[SOUND_FOOT_GRASS]);
    }
    if (player.zone == ZONE_DUNGEON) {
      PlaySound(sound[SOUND_FOOT_STONE]);
    }
  }
  if (playerMoneyChanged) {
    PlaySound(sound[SOUND_COINS]);
  }
  if (playerDamageChanged) {
    PlaySound(sound[SOUND_ATTACK]);
  }
  if (enemyIsAliveChanged) {
    PlaySound(sound[SOUND_DEATH]);
  }
}

void soundStop() {
  for (int i = 0; i < MAX_SOUNDS; i++) {
    UnloadSound(sound[i]);
  }
  for (int i = 0; i < MAX_MUSICS; i++) {
    StopMusicStream(music[i]);
    UnloadMusicStream(music[i]);
  }
  CloseAudioDevice();
}
