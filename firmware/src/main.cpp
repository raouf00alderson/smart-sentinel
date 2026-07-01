/**
 * @file    main.cpp
 * @brief   Smart Sentinel Firmware — Milestone 1: System Heartbeat
 * @version 0.1.0
 * @author  [Your Name]
 */

#include <Arduino.h>
#include "config.h"

// Forward declarations — tells the compiler these functions exist
// even though their bodies are defined BELOW where they're called
void heartbeat();
void printBanner();

// ─── Setup ────────────────────────────────────────────────────────────────────
void setup() {
    // 1. Start serial communication at 115200 baud
    //    Without this, Serial.println() does nothing
    Serial.begin(SERIAL_BAUD_RATE);

    // 2. Tell the ESP32 that GPIO 2 is an OUTPUT pin
    //    OUTPUT = we send voltage OUT to the LED
    //    INPUT  = we READ voltage coming IN (used for sensors)
    pinMode(PIN_LED_BUILTIN, OUTPUT);

    // 3. Print the startup banner to Serial Monitor
    printBanner();
}

// ─── Main Loop ────────────────────────────────────────────────────────────────
void loop() {
    // loop() runs forever — we just call heartbeat()
    // heartbeat() itself handles all the timing internally
    heartbeat();
}

// ─── Heartbeat ────────────────────────────────────────────────────────────────
void heartbeat() {
    // Step 1: Pulse the LED HEARTBEAT_PULSES times (defined as 2 in config.h)
    for (int i = 0; i < HEARTBEAT_PULSES; i++) {

        digitalWrite(PIN_LED_BUILTIN, HIGH);  // Turn LED ON  (3.3v on GPIO 2)
        delay(HEARTBEAT_ON_MS);               // Keep it ON  for 100ms

        digitalWrite(PIN_LED_BUILTIN, LOW);   // Turn LED OFF (0v on GPIO 2)
        delay(HEARTBEAT_OFF_MS);              // Keep it OFF for 100ms
    }

    // Step 2: Print uptime to Serial Monitor
    // millis() returns how many milliseconds have passed since boot
    Serial.print("[HEARTBEAT] alive | uptime: ");
    Serial.print(millis());
    Serial.println("ms");

    // Step 3: Pause between pulse groups
    delay(HEARTBEAT_PAUSE_MS);  // Wait 2000ms before next double-pulse
}

// ─── Print Banner ─────────────────────────────────────────────────────────────
void printBanner() {
    Serial.println("╔══════════════════════════════════════╗");
    Serial.println("║         SMART SENTINEL v" + String(FIRMWARE_VERSION) + "         ║");
    Serial.println("║   IoT Intrusion Detection System     ║");
    Serial.println("╚══════════════════════════════════════╝");
    Serial.print("[BOOT] Device: ");
    Serial.println(DEVICE_NAME);
    Serial.print("[BOOT] CPU Freq: ");
    Serial.print(getCpuFrequencyMhz());
    Serial.println(" MHz");

    // ⭐ BONUS: Print available heap memory
    // ESP.getFreeHeap() returns free RAM in bytes
    // Useful for detecting memory leaks in future milestones
    Serial.print("[BOOT] Free Heap: ");
    Serial.print(ESP.getFreeHeap());
    Serial.println(" bytes");

    Serial.println("[BOOT] System ready. Starting heartbeat...");
    Serial.println("─────────────────────────────────────────");
}