# 🛡️ Smart Sentinel

> A real-time IoT Intrusion Detection System with AI-powered anomaly detection.  
> Built with ESP32 (simulated via Wokwi), Python, and scikit-learn.

[![Milestone](https://img.shields.io/badge/Milestone-1%2F12-blue)]()
[![Firmware](https://img.shields.io/badge/Firmware-v0.1.0-green)]()
[![Wokwi](https://img.shields.io/badge/Simulate-Wokwi-blue?logo=data:...)](https://wokwi.com/github/YOUR_USERNAME/smart-sentinel)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

## 🔬 Live Simulation

> Click below to run the circuit in your browser — no hardware needed.

[![Open in Wokwi](https://wokwi.com/badge/open-in-wokwi.svg)](https://wokwi.com/github/YOUR_USERNAME/smart-sentinel)

## 📋 Milestone Progress

| # | Description | Status |
|---|-------------|--------|
| M1 | Project scaffolding + ESP32 heartbeat (Wokwi) | ✅ Complete |
| M2 | Sensor integration: PIR, DHT22, reed switch | 🔒 |
| M3 | MQTT communication: ESP32 → Python | 🔒 |
| M4 | Python data pipeline + SQLite | 🔒 |
| M5 | REST API with FastAPI | 🔒 |
| M6 | AI anomaly detection (Isolation Forest) | 🔒 |
| M7 | Real-time alerting system | 🔒 |
| M8 | TLS encryption + JWT authentication | 🔒 |
| M9 | Streamlit dashboard | 🔒 |
| M10 | GitHub Actions CI/CD | 🔒 |
| M11 | Docker containerization | 🔒 |
| M12 | Portfolio polish + release | 🔒 |

## 🏗️ Architecture

See [docs/architecture.md](docs/architecture.md) for full system design.

## 🚀 Running the Simulation

### Prerequisites
- VS Code + PlatformIO extension
- VS Code + Wokwi extension (free license at wokwi.com)

### Steps
```bash
git clone https://github.com/YOUR_USERNAME/smart-sentinel.git
cd smart-sentinel/firmware
pio run
# Then: Ctrl+Shift+P → "Wokwi: Start Simulator"