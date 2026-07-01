/**
 * @file    config.h
 * @brief   Hardware configuration and compile-time constants for Smart Sentinel.
 *
 * Design decision: All magic numbers live here.
 * If we rewire the board, we change ONE file — not hunt through all source files.
 * If we deploy to a different ESP32 variant, we only update this file.
 */

#ifndef SMART_SENTINEL_CONFIG_H
#define SMART_SENTINEL_CONFIG_H

// ─── GPIO Pin Assignments ──────────────────────────────────────────────────
// Built-in LED: GPIO 2 on ESP32 DevKit v1
// In Wokwi, this LED is shown on the board itself
#define PIN_LED_BUILTIN     2

// ─── Serial ───────────────────────────────────────────────────────────────
#define SERIAL_BAUD_RATE    115200

// ─── Device Identity ──────────────────────────────────────────────────────
#define DEVICE_NAME         "smart-sentinel-node-01"

// ─── Heartbeat Timing (milliseconds) ──────────────────────────────────────
#define HEARTBEAT_ON_MS     100   // LED on duration
#define HEARTBEAT_OFF_MS    100   // LED off duration
#define HEARTBEAT_PULSES    2     // Number of pulses per cycle
#define HEARTBEAT_PAUSE_MS  2000  // Pause between pulse groups

#endif // SMART_SENTINEL_CONFIG_H