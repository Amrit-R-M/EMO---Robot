#ifndef AI_HANDLER_H
#define AI_HANDLER_H

#include <Arduino.h>

void initAI(const char* apiKey);
String chatWithAI(String userMessage, String personality);
String getSystemPrompt(String personality);

#endif