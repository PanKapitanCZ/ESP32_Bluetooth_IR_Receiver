# ESP32_Bluetooth_IR_Receiver
 This code uses the ESP32 to receive infrared (IR) signals and transmit the decoded data via Bluetooth. It makes use of the BluetoothSerial library to enable communication between the ESP32 and any Bluetooth-enabled device, such as a smartphone or computer.


# ESP32 IR Signal Recorder

This project involves an ESP32 device that records infrared (IR) signals from remote controls (such as TV, amplifier, or RGB controllers) and sends the recorded signals to a mobile app via Bluetooth. The ESP32 captures these IR signals through an IR receiver, allowing the mobile app to bind them to buttons for later re-transmission.

## About the Project

The ESP32 device acts as an IR signal recorder. It receives signals from any IR remote control using an IR receiver, and then transmits those signals to a connected mobile app via Bluetooth. The signals can later be sent back to the ESP32 from the app, where the device can retransmit the IR signals to control a remote-controlled device.

<p align="center">
  <img src="https://github.com/user-attachments/assets/4a644d00-dec7-473a-9b7f-4fbba4ea83a6" alt="image1" width="300"/>
  <img src="https://github.com/user-attachments/assets/4de5eda4-ee98-46fa-84ad-52d04e5f4bb1" alt="image2" width="300"/>
  <img src="https://github.com/user-attachments/assets/9ff12c6d-860f-4dc3-995b-f196c9317d8a" alt="image3" width="300"/>
</p>

## Components

- **ESP32**
- **IR Receiver** (e.g., TSOP38238)
- **Switch**
- **4x AA Battery Case**
- **Stepdown Module** (to 3.3V)
- **Wires**

## Wiring Diagram

The ESP32 is connected to the IR receiver to record the signals. Here's how you should wire it:

| Component          | ESP32 Pin |
|--------------------|-----------|
| IR Receiver Signal | GPIO 14   |
| IR Receiver VCC    | 3.3V      |
| IR Receiver GND    | GND       |

<img src="https://github.com/user-attachments/assets/2110a3df-86b9-4b39-9610-a11e92c7a0a5" alt="image1" width="700"/>

## How to Upload the Code

1. **Install Arduino IDE** (if not already installed):  
   [Download Arduino IDE](https://www.arduino.cc/en/software)

2. **Install ESP32 Board in Arduino IDE**:  
   - Open Arduino IDE
   - Go to `File > Preferences`
   - In the "Additional Boards Manager URLs" field, add this URL:  
     ```bash
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Go to `Tools > Board > Board Manager`, search for "ESP32," and install the board.

3. **Connecting ESP32 to Your Computer for Programming**

To program your ESP32, you'll need a USB-UART converter such as the CH9102 or a similar programmer.

### Wiring for Programming the ESP32:

| USB-UART Programmer | ESP32 Pin  |
|---------------------|------------|
| RX                  | TX         |
| VCC                 | 3.3V       |
| GND                 | GND        |
| GND                 | GPIO2      |

You can use the CH9102 programmer or any similar programmer to connect your ESP32 to your computer.



4. **Upload the Code**:  
   - Open the code provided in this repository in Arduino IDE.
   - Select the correct board and port from the `Tools` menu.
   - Click the upload button to flash the code onto the ESP32.

## Usage

1. **Power On the ESP32**:  
   - Use the 4x AA battery case or connect the ESP32 via USB to power it on.

2. **Pair with Mobile App**:  
   - Open the mobile app and pair it with the ESP32 device over Bluetooth.

3. **Record IR Signals**:  
   - Once paired, use the app to start listening for IR signals. The ESP32 will capture the signals and send them to the app.

4. **Transmit Signals**:  
   - Use the app to replay the recorded IR signals by sending them back to the ESP32.
     
5. **To Use This Device**
   - you'll need an Mobile App to transmit IR signals. The setup for the Mobile-IR-bridge app, including code, can be found in the [Mobile-IR-Bridge](https://github.com/PanKapitanCZ/Mobile-IR-Bridge).

## License

This project is licensed under the MIT License.
