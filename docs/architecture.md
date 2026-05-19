# Code Architecture

## Module Structure
main.cpp
├── config.h (WiFi, API keys, pins)
├── wifi_manager (network connectivity)
├── ai_handler (Groq API integration)
├── display_manager (TFT screen control)
└── audio_manager (I2S mic/speaker)

## Data Flow
User speaks
↓
Microphone (I2S) → audio_manager
↓
Convert to WAV
↓
Whisper API → Speech-to-Text
↓
Text → ai_handler → Groq API
↓
AI Response
↓
Google TTS API → Audio
↓
Speaker (I2S) → audio_manager
↓
Robot speaks

## File Sizes
- config.h: ~1KB
- wifi_manager: ~3KB
- ai_handler: ~5KB
- display_manager: ~4KB
- audio_manager: ~4KB (in progress)
- main.cpp: ~6KB (in progress)
- Total firmware: ~938KB