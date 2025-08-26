# Shop_antitheft
# Shop Anti-theft Device

## 1. Introduction
Retail theft leads to major losses, especially for small and medium-sized businesses. This project presents a **low-cost, portable, and smart anti-theft system** using proximity sensing and wireless communication to alert staff of suspicious activity near shelves or exits.

## 2. Objectives
- Detect unauthorized hand movements or object removals.
- Provide loud alarm notifications.
- Enable optional wireless alerts via Wi-Fi or Bluetooth.
- Ensure portability with a rechargeable battery.

## 3. System Components
### 🔌 Microcontroller: ESP32-WROOM-32
- Reads sensor data and controls the system.
- Enables wireless notifications via Wi-Fi/Bluetooth.

### 📡 Proximity Sensor: VL53L0X or VL53L1X
- Time-of-Flight sensor to detect motion and proximity changes.

### 🔊 Alarm: Buzzer with PAM8302 Driver
- Loud audio output for instant alert.

### 🔋 Power Supply
- TP4057-based Li-ion battery charger.
- MP1584 / LM2576HVS regulator to power 3.3V devices.
- USB-C input for charging.

### 🧰 Debug Header
- UART + I²C access for firmware updates and calibration.

## 4. Operation
1. **Monitoring Mode:** Continuously checks proximity.
2. **Detection:** Flags sudden object removal or movement.
3. **Alarm:** Triggers loud buzzer.
4. **Optional:** Sends a wireless notification via Wi-Fi.
5. **Portable:** Battery-powered, no installation hassle.

## 5. Features
- 🔋 Rechargeable and portable
- 📢 Loud audible alarm
- 🌐 Wi-Fi/Bluetooth notification support
- 🛠️ Simple deployment
- 🔄 Low power consumption

## 6. Applications
- Retail and convenience stores
- Bookshops, pharmacies
- Temporary setups like kiosks or exhibitions

## 7. Conclusion
This device offers an easy-to-install, cost-effective alternative to expensive surveillance systems. By integrating modern sensing and IoT technology, it provides real-time theft deterrence for shops of all sizes.
