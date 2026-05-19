# EMO V1 — Desktop AI Robot

A voice-interactive desktop companion featuring real-time AI conversation, dynamic personality modes, memory retention, and integrated mini-games.

---

## Overview

EMO V1 is a compact AI robot designed for natural voice interaction and emotional expression. Built on ESP32-S3 architecture with cloud-based AI processing, it serves as an intelligent desktop companion capable of learning user preferences and adapting its personality to context.

---

## Technical Specifications

### Compute Architecture
- ESP32-S3 N16R8 dual-core processor (240 MHz)
- 16 MB Flash, 8 MB PSRAM for audio buffering
- WiFi 802.11 b/g/n for cloud API communication

### Display System
- 1.28-inch Round Color IPS (240×240 resolution)
- SPI interface
- RGB color emotion rendering engine

### Audio Pipeline
- I2S MEMS microphone (INMP441)
- I2S digital amplifier (MAX98357A)
- 3W 8Ω speaker element
- 16-bit 16 kHz audio sampling

### Input Interface
- Three tactile push buttons
- Debounced interrupt-driven input handling

---

## Software Architecture

### AI Processing Stack
- Speech-to-Text: OpenAI Whisper API
- Language Model: Groq Llama 3.1 (8B parameters)
- Text-to-Speech: Google Cloud TTS
- Total latency: sub-2-second response time

### Core Systems
- Multi-personality framework (Funny, Serious, Assistant modes)
- SPIFFS-based persistent memory storage
- Real-time animation state machine
- Game engine with 60 FPS rendering

### Memory Capabilities
- User preference tracking
- Conversation history retention
- Context-aware response generation

---

## Project Structure
EMO---Robot/
│
├── firmware/
│   ├── src/
│   │   ├── main.cpp
│   │   ├── wifi_manager.cpp
│   │   ├── ai_handler.cpp
│   │   ├── display_manager.cpp
│   │   └── audio_manager.cpp
│   ├── include/
│   │   ├── config.h
│   │   ├── wifi_manager.h
│   │   ├── ai_handler.h
│   │   ├── display_manager.h
│   │   └── audio_manager.h
│   └── platformio.ini
│
├── hardware/
│   ├── schematics/
│   └── wiring.md
│
└── docs/
└── dev_log.md
---

## Development Roadmap

### Phase 1 — Core AI Integration (Week 1-2)
- WiFi connectivity and API authentication
- Voice input/output pipeline
- Basic emotion display system
- Cloud AI integration testing

### Phase 2 — Personality & Display (Week 3)
- Multi-mode personality implementation
- Round color IPS display integration
- Dynamic facial expression system
- Button input handling

### Phase 3 — Memory & Polish (Week 4)
- SPIFFS memory integration
- User preference learning
- Conversation context retention
- Final system integration

---

## Installation

### Prerequisites
- PlatformIO IDE
- Groq API key (free tier: groq.com)
- Google Cloud account (free TTS tier)

### Setup

1. Clone repository
```bash
   git clone https://github.com/Amrit-R-M/EMO---Robot.git
   cd EMO---Robot
```

2. Configure credentials in `firmware/include/config.h`
```cpp
   #define WIFI_SSID "your_network"
   #define WIFI_PASSWORD "your_password"
   #define GROQ_API_KEY "your_groq_key"
```

3. Build and upload
```bash
   pio run --target upload
```

---

## API Cost Analysis

| Service | Tier | Monthly Limit | Cost |
|---------|------|---------------|------|
| Groq Llama 3.1 | Free | 14,400 requests/day | $0.00 |
| Google Cloud TTS | Free | 1M characters | $0.00 |
| OpenAI Whisper | Pay-as-you-go | Unlimited | $0.006/min |

Estimated cost for 100 conversations: $0.30

---

## Hardware Bill of Materials

| Component | Specification | Quantity | Unit Cost |
|-----------|--------------|----------|-----------|
| ESP32-S3-N16R8 | Dual-core 240 MHz, 16MB/8MB | 1 | ₹1,270 |
| Round Color IPS | 1.28" 240x240 RGB SPI | 1 | ₹600 |
| MEMS Microphone | INMP441 I2S | 1 | ₹208 |
| Audio Amplifier | MAX98357A I2S | 1 | ₹150 |
| Speaker | 3W 8Ω | 1 | ₹80 |
| Push Buttons | Tactile 12mm | 3 | ₹30 |
| Breadboard | 840 tie-points | 1 | ₹81 |
| Jumper Wires | Male-to-female | 40 | ₹71 |
| Camera | OV3660 (disabled V1) | 1 | Included |

Total: ₹2,490 (~$30 USD)

---

## License

MIT License — Copyright (c) 2026

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files, to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software.

---

## Contributors

Developed by Amrit and Rishav

Hardware integration partner: Rishav Raj

---

**Last Updated:** May 2026
**Status:** Hardware Ordered — Awaiting Delivery
**Target Completion:** June 2026
---

## Recent Updates

### May 11, 2026
- ✅ Display manager rewritten for round color IPS (TFT_eSPI)
- ✅ All compilation errors fixed (30+ bugs resolved)
- ✅ Firmware builds successfully (938KB, 14% RAM usage)
- ⏳ Audio manager implementation in progress
- ⏳ Main program loop completion pending

---

## Recent Updates

### May 2026
- ✅ All firmware modules created and tested
- ✅ Round color IPS display selected (1.28" 240x240 RGB)
- ✅ ESP32-S3 N16R8 ordered (upgraded to 16MB Flash / 8MB PSRAM)
- ✅ Complete parts list finalized
- ⏳ Hardware delivery expected: May 6-9, 2026
- ⏳ Display code rewrite for TFT_eSPI library pending

### Current Phase
Waiting for hardware components to arrive. Code architecture complete and ready for integration testing.

**Next Steps:**
1. Hardware arrives → wire components on breadboard
2. Rewrite display_manager.cpp for round color screen
3. First power-on and WiFi connection test
4. AI conversation integration test
5. Design and 3D print enclosure