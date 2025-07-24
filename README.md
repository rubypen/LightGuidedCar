---

# 🚗 Light-Guided Autonomous Car

**Solo Embedded Systems Project | Arduino, C++, Sensors, 3D Printing, Hardware Integration**

A compact, self-navigating vehicle programmed in Arduino C++ that autonomously moves toward light sources while avoiding obstacles. Designed and built end-to-end with limited hardware components and a custom 3D-printed chassis, showcasing strong embedded programming and systems engineering skills.

---

## 🧠 What I Built

- Developed embedded control software using Arduino to process light sensor data and steer motors toward brighter areas
- Integrated an ultrasonic distance sensor to detect and avoid obstacles in real time
- Programmed LEDs to provide visual feedback and status indicators
- Iteratively tuned sensor thresholds and motor commands to ensure smooth, responsive navigation
- Executed full hardware assembly including 3D-printed chassis and creative use of off-the-shelf materials (deodorant roller front wheel, rubber stopper rear wheels)

---

## 🛠️ Hardware Overview

- **Chassis**: Custom 3D-printed base with a deodorant roller serving as a low-friction front wheel
- **Drive System**: Two DC motors powering rubber stopper rear wheels
- **Sensors & Electronics**:
    - Two analog light sensors for detecting light intensity
    - Ultrasonic distance sensor for obstacle detection
    - LEDs for system status and aesthetics
    - Arduino Uno microcontroller for logic and control
- **Wiring & Circuitry**:
    
    Designed and implemented an **optimal wiring layout** using mini breadboards to organize connections clearly and compactly.
    
    Minimized cable length and interference by routing wires carefully, improving signal integrity and maintainability.
    
    The wiring setup enabled easy debugging and future hardware expansion.
    

---

## ⚙️ Core Features

- Autonomous navigation guided by real-time light intensity measurements
- Obstacle detection and avoidance using ultrasonic sensing
- Efficient motor control via PWM signals mapped from sensor inputs
- Minimalist hardware design operating within strict constraints (two motors, limited wheel options)
- Integrated software-hardware system ensuring reliable and smooth operation

---

## 🔧 Software Highlights

- Utilized Arduino's `analogRead()` to continuously monitor sensor data
- Mapped sensor values to motor speeds with PWM using `analogWrite()`
- Implemented a lightweight control loop balancing responsiveness and stability
- Developed manual tuning procedures to optimize behavior under varying environmental conditions

---

This project reflects my ability to design and implement embedded systems that tightly integrate software and hardware. It highlights hands-on problem solving, iterative development, and practical application of engineering principles in constrained environments.
