# Smart Sentinel — System Architecture

## Overview

Smart Sentinel is a real-time IoT security system that detects anomalies
using sensor fusion and machine learning.

## High-Level Data Flow

```text
                 MQTT/TLS
[ESP32 Node] ----------------------> [Python Broker Client] -----------------> [ML Anomaly Engine]
      |                                        |                                       |
      |                                        |                                       |
  [Sensors]                             [SQLite Database]                      [Alert System]
      |
      +-- PIR Motion
      +-- DHT22 Temperature
      +-- Door Switch
```

## Technology Stack

| Layer | Technology | Milestone |
|-------|------------|-----------|
| Firmware | C++ / Arduino / ESP32 (Wokwi) | M1–M3 |
| Protocol | MQTT over TLS (EMQX broker) | M3 |
| Backend | Python / FastAPI | M4–M5 |
| Database | SQLite | M4 |
| ML | scikit-learn / Isolation Forest | M6 |
| Alerting | smtplib / Webhooks | M7 |
| Security | TLS 1.3, JWT, Input Validation | M8 |
| Dashboard | Streamlit | M9 |
| DevOps | GitHub Actions / Docker | M10–M11 |

## Simulation

All hardware is simulated using **Wokwi**.

After publishing this repository to GitHub, add the Wokwi simulation badge to the `README.md` so visitors can launch the simulation directly.