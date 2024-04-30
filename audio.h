#include <Arduino.h>
#include "DYPlayerArduino.h"

DY::Player player;

void setupAudio() {
    player.begin();
    player.setVolume(20); // 50% Volume
    player.setCycleMode(DY::PlayMode::OneOff);
}

void playTrack(int trackIndex, int trackDelay=5000) {
    player.playSpecified(trackIndex);
    delay(trackDelay);
}
