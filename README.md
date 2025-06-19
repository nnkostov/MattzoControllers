# MattzoControllers

**Smart controllers for automating LEGO and brick train layouts**

MattzoControllers are WiFi-enabled microcontroller devices that connect your LEGO trains and layout accessories to train automation software like [Rocrail](https://www.rocrail.net/). They act as a bridge between your physical LEGO components and digital train control systems.

## 🚂 What Can MattzoControllers Do?

- **Control trains** via Bluetooth (LEGO Powered Up, SBrick, BuWizz2) or Power Functions
- **Operate layout accessories** like switches, signals, and level crossings
- **Monitor sensors** to detect train positions and trigger automated actions
- **Connect wirelessly** to your train automation software via WiFi and MQTT
- **Provide remote control** using LEGO remotes for manual operation

## 📦 Controller Types

This repository contains firmware for three types of MattzoControllers:

### MTC4BT (Mattzo Train Controller for Bluetooth)
- **Purpose**: Controls Bluetooth-enabled train devices
- **Supported devices**: LEGO Powered Up, SBrick, BuWizz2, LEGO Remote Control
- **Hardware**: ESP32 microcontroller (required for Bluetooth)
- **Use case**: Modern LEGO trains with Bluetooth connectivity

### MTC4PF (Mattzo Train Controller for Power Functions)
- **Purpose**: Controls LEGO Power Functions trains
- **Supported devices**: LEGO Power Functions motors and lights
- **Hardware**: ESP8266 or ESP32 microcontroller
- **Use case**: Older LEGO trains using Power Functions system

### MLC (MattzoLayoutController)
- **Purpose**: Controls layout accessories and monitors sensors
- **Supported devices**: Servos (switches), LEDs (signals), sensors, level crossings
- **Hardware**: ESP8266 or ESP32 microcontroller + expansion boards
- **Use case**: Layout automation and accessory control

## 🛠️ Hardware Requirements

### For MTC4BT (Bluetooth Controller)
- **ESP32 development board** (Bluetooth required)
  - Tested boards: AZDelivery ESP32 NodeMCU, DOIT DEVKIT V1 ESP32-WROOM-32
- **Optional**: W5500 Ethernet module for wired connection
- **LEGO devices**: Powered Up hubs, SBrick, BuWizz2, or LEGO Remote Control

### For MTC4PF (Power Functions Controller)
- **ESP8266 or ESP32 development board**
- **Motor driver board** (L298N, L9110, or LEGO IR transmitter)
- **LEGO Power Functions**: Motors, lights, and receivers

### For MLC (Layout Controller)
- **ESP8266 or ESP32 development board**
- **PCA9685 PWM driver** (for servos/switches)
- **MCP23017 I/O expander** (optional, for more sensors)
- **Servos, LEDs, sensors** as needed for your layout

## 💻 Software Setup

### Step 1: Install Development Environment

1. **Download and install [Visual Studio Code](https://code.visualstudio.com/)**

2. **Install PlatformIO extension**:
   - Open VS Code
   - Click the Extensions icon (or press `Ctrl+Shift+X`)
   - Search for "PlatformIO IDE"
   - Click "Install"

3. **Open the project**:
   - Download or clone this repository
   - In VS Code: File → Open Workspace from File
   - Select `MattzoControllers.code-workspace`

### Step 2: Configure Your Controller

Each controller needs two configuration files in the `conf/my/` directory:

1. **Create the `my` folder**:
   ```
   src/[controller-type]/conf/my/
   ```

2. **Copy template files**:
   - Copy `network_config.h` from `conf/default/` to `conf/my/`
   - Copy `controller_config.h` from `conf/default/` to `conf/my/`

3. **Edit network configuration** (`network_config.h`):
   ```cpp
   const char* WIFI_SSID = "YourWiFiName";
   const char* WIFI_PASSWORD = "YourWiFiPassword";
   const char* MQTT_BROKER_IP = "192.168.1.100";  // Your Rocrail computer IP
   ```

4. **Edit controller configuration** (`controller_config.h`):
   - Configure pins, addresses, and device settings
   - See example files in `conf/examples/` for inspiration

### Step 3: Build and Upload Firmware

1. **Connect your microcontroller** via USB

2. **Select environment** in PlatformIO:
   - For ESP32: `esp32`
   - For ESP8266: `esp8266` (if available)

3. **Build and upload**:
   - Click the PlatformIO icon in VS Code
   - Click "Upload" for your environment

## 🔧 Basic Operation

### First Boot
1. **Power on** your controller
2. **Check status LED**: Should blink to indicate WiFi connection attempts
3. **Monitor serial output** (115200 baud) for connection status and errors

### Connecting to Rocrail
1. **Configure Rocrail** to connect to your MQTT broker
2. **Add controllers** in Rocrail with matching addresses from your config
3. **Test communication** by sending commands from Rocrail

### For MTC4BT (Bluetooth)
1. **Power on LEGO devices** (Powered Up hubs, SBrick, etc.)
2. **Controller will auto-discover** and connect to configured devices
3. **LED colors** on LEGO Remote indicate connection status:
   - Flashing: Searching for controller
   - 50% on/off: Connected but layout power off
   - Solid on: Connected and ready

### For MTC4PF (Power Functions)
1. **Connect motor drivers** and LEGO components according to your config
2. **Test train control** from Rocrail
3. **Adjust power levels** in configuration if needed

### For MLC (Layout Controller)
1. **Connect servos, LEDs, and sensors** according to your wiring config
2. **Test switches and signals** from Rocrail
3. **Monitor sensor feedback** in Rocrail

## 🔍 Troubleshooting

### WiFi Connection Issues
- Check SSID and password in `network_config.h`
- Ensure 2.4GHz WiFi (5GHz not supported)
- Check signal strength at controller location

### MQTT Connection Issues
- Verify MQTT broker IP address
- Check firewall settings on Rocrail computer
- Ensure MQTT broker is running

### Device Not Responding
- Check power supply (stable 5V recommended)
- Verify pin configurations match your wiring
- Monitor serial output for error messages

### Bluetooth Issues (MTC4BT)
- Ensure ESP32 board (ESP8266 doesn't support Bluetooth)
- Check device addresses in configuration
- Power cycle LEGO devices if connection fails

## 📚 Additional Resources

- **Official documentation**: https://www.mattzobricks.com
- **Community forum**: https://mattzobricks.com/forums
- **Rocrail documentation**: https://www.rocrail.net
- **Example configurations**: Check `src/[controller]/conf/examples/`

## 🤝 Getting Help

If you need help:
1. **Check the examples** in the `conf/examples/` directories
2. **Read the serial monitor** output for error messages
3. **Visit the community forum** at https://mattzobricks.com/forums
4. **Check the official documentation** at https://www.mattzobricks.com

---

*Happy model railroading!*

Cheers,
Mattze and the Mattzobricks core development team!

---

Copyright 2019 by Mattzobricks

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
