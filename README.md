# Mechatronic Robot Design & Embedded Systems 🤖

[![STM32](https://img.shields.io/badge/Platform-STM32-blue?logo=arm&logoColor=white)](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)
[![Arduino](https://img.shields.io/badge/Platform-Arduino-red?logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Status](https://img.shields.io/badge/Status-Completed-success)](https://github.com/yourusername/Mechatronic-Robot-Design)

A custom-designed mechatronic robot featuring **line-following and obstacle avoidance**. Combines 3D printed mechanical design with embedded systems programming on **STM32 and Arduino** microcontrollers.

---

##  Overview

This project demonstrates a complete **mechatronic system** integrating mechanical design, electronics, and embedded programming:

- **3D Printed Robot Chassis:** Designed in **Fusion 360** for sensor and component integration.  
- **Embedded Systems:** Programmed in **C** for microcontrollers (STM32 & Arduino).  
- **Autonomous Behavior:** Robot can **follow lines** and **avoid obstacles** using sensors.

The project highlights skills in **mechanical design, electronics, and embedded programming**, which are highly valued in internships and robotics projects.

---

##  Features

- **Custom Robot Chassis:** Optimized for sensor placement and stability.  
- **Line-Following:** Uses IR sensors to detect and follow a predefined path.  
- **Obstacle Avoidance:** Ultrasonic sensors detect obstacles and adjust robot movement.  
- **Modular Design:** Easy to upgrade with additional sensors or actuators.  

---

##  Tech Stack

- **Mechanical Design:** Fusion 360  
- **3D Printing:** PLA / ABS materials  
- **Microcontrollers:** STM32 / Arduino  
- **Programming Language:** C (embedded systems)  
- **Sensors:** IR sensors, Ultrasonic distance sensors  
- **Actuators:** DC motors, motor driver modules (L298N or similar)  

---

##  How It Works

1. **Chassis & Sensors:** The 3D printed chassis houses motors, sensors, and microcontroller.  
2. **Line Following:** IR sensors detect black lines on the ground; the microcontroller adjusts motor speed to stay on track.  
3. **Obstacle Avoidance:** Ultrasonic sensors measure distance; if an object is detected, the robot stops or changes direction.  
4. **Motor Control:** Microcontroller sends PWM signals to motor driver to control speed and direction.  

- **line_following.ino:** Controls robot movement based on IR sensors.  
- **obstacle_avoidance.c:** Implements STM32 microcontroller logic for obstacle detection and avoidance.  
- **Fusion 360 files:** Can be opened and modified for custom chassis design.  
- **STL files:** Ready for 3D printing.  

---

##  Future Improvements

- Add **Bluetooth or Wi-Fi control** for remote operation.  
- Integrate **additional sensors** (e.g., IMU, camera) for autonomous navigation.  
- Improve **PID control** for smoother line-following.  
- Upgrade to **multi-functional robot** (maze-solving, object detection, mapping).

---




