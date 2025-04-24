# ArduEasy

ArduEasy is a beginner-friendly Arduino library that simplifies hardware interaction and non-blocking task management. It provides intuitive abstractions for common components like LEDs, buttons, motors, keypads, and time-based actions.

## ✨ Features

- Easy-to-use API for beginners
- Supports LEDs, buttons, motors, matrix keypads, and generic digital outputs and analog inputs 
- Non-blocking tasks (alternative to `delay()`)
- Lightweight and dependency-free
- Compatible with any Arduino board

## 📦 Installation

### Option 1 – Using Arduino IDE Library Manager

1. Open the Arduino IDE
2. Go to **Sketch > Include Library > Manage Libraries**
3. Search for **ArduEasy**
4. Click **Install**

### Option 2 – Manual Installation

1. Download the repository as a `.zip` file
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...**
3. Select the downloaded `.zip` file

## 🚀 How to Use

After installing the library, follow these steps to start using ArduEasy in your project:

### 1. Include the Library

At the top of your sketch, include the library header:

```cpp
#include <ArduEasy.h>
```

### 2. Create Component Objects
Use the available classes to create instances of the components you want to use. For example:

```cpp
Led led(13);            // LED on pin 13
Button btn(2);          // Button on pin 2
Motor motor(4, 5, 6);   // Motor using pins 4 and 5 for direction and 6 for enable
```

### 3. Configure Behavior in setup()
Define how each component should behave:

```cpp
void setup() {
  btn.onPress([]() { led.toggle(); }); // Toggle LED on button press
  motor.turnOn(100); // Start the motor
}
```
### 4. Keep Components Running in loop()
Call the ArduEasy loop to allow the library to manage time-based and reactive behavior:

```cpp
void loop() {
  ArduEasy::run();
}
```
>⚠️ You must call ArduEasy::run() continuously inside your loop() function.
It ensures that all registered components (like LEDs and buttons) update their state properly.

> ✅ You can combine multiple components easily. For example, you can trigger a motor when a button is held, or define actions that happen in sequence using the Actions class.

## 🔧 Basic Example

```cpp
#include <ArduEasy.h>

Led led(13);

void setup() {
  led.blink(); // Default: 500ms on, 500ms off
}

void loop() {
  ArduEasy::run(); // Keep components running
}
```
## 📚 Documentation

📖 Full documentation is coming soon!


## 🧪 Boards Tested

- ✅ Arduino Uno  