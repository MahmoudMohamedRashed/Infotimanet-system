# Infotainment System — Static UI (Qt / QML)

![Language](https://img.shields.io/badge/language-C++-blue.svg)
![UI](https://img.shields.io/badge/UI-QML-lightgrey.svg)
![Build](https://img.shields.io/badge/build-CMake-orange.svg)
![MQTT](https://img.shields.io/badge/MQTT-Mosquitto-green.svg)
![License](https://img.shields.io/badge/license-MIT-lightgrey.svg)

## Project overview
This project implements an **initial static infotainment UI** using **Qt / QML**.  
The UI simulates common in-vehicle screens and includes three main sections:

1. **Climate Control**
   - Set cabin temperature
   - Set fan speed and airflow direction
   - Display current cabin temperature

2. **Trip Information**
   - Start / stop trip
   - Show trip fuel consumption (km/L)
   - Show trip average and maximum speed
   - Show trip distance (km)

3. **Dashboard Information**
   - Speedometer (current speed)
   - RPM meter (engine revs)
   - Fuel level gauge
   - Engine temperature gauge
   - Turn-signal indicators simulation
   - Warning indicator light
   - Door lock status
   - Seat-belt warning

The UI is static (no full vehicle backend yet) but wired to support data flow via **protobuf** messages and **MQTT** (Mosquitto) for later real-time integration.

---

## Tech stack & tools used
- **C++** (application shell and backend glue)  
- **Qt (QML)** — UI implementation (Qt Creator project)  
- **CMake** / `.pro` (project files supported)  
- **Protocol Buffers (protobuf)** — message definitions and codegen  
- **MQTT (Mosquitto)** — message broker for publish/subscribe (optional runtime)  
- **clang-tidy** & static analysis for code quality  
- **cmake**, **make** / **ninja** for building

---

## Features (UI -> mapping)
- Climate UI widgets (temperature dial, fan speed, airflow icons)  
- Trip controls (Start / Stop button) and readouts (consumption, avg/max speed, distance)  
- Dashboard widgets (speedometer, RPM, fuel, engine temp) implemented with QML animated gauges (static demo values)  
- Visual indicators: turn signals, warnings, door lock, seatbelt  
- Prototype data path prepared using protobuf message definitions and MQTT topics (for future real-time integration)

---

## Prerequisites (Ubuntu / Windows)
- Qt 5.x or Qt 6.x + Qt Creator  
- C++ compiler (g++ / clang on Linux, MSVC on Windows)  
- CMake (if building with CMake)  
- Protocol Buffers (`protoc`)  
- Mosquitto (optional — for MQTT demo)  
- clang-tidy (optional — static checks)

Example Ubuntu install:
```bash
# Qt Creator: use official Qt installer or apt for distro packages
sudo apt update
sudo apt install build-essential cmake git protobuf-compiler libprotobuf-dev
# Mosquitto (MQTT broker)
sudo apt install mosquitto mosquitto-clients
# clang-tidy (static analysis)
sudo apt install clang-tidy
