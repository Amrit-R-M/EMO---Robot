#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <Arduino.h>

void initMicrophone(int wsPin, int sckPin, int sdPin);
void initSpeaker(int bclkPin, int lrcPin, int dinPin);

#endif