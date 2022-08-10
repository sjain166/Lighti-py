# Lighti-py
Music Visualizer using WS2812B LED strips and Arduino UNO

![connection](https://user-images.githubusercontent.com/85589093/184040390-8d0fb4d7-d4d6-49ff-a113-6a8c5356cc9f.png)

## Setting up Arduino UNO

1. Connecting the Sound Module to the UNO with [VCC - > GND || GND -> 5v || OUT -> PIN28].
2. Connecting the WS2812B to the UNO with [5v -> 5v || DIN -> PIN2 || GND -> GND].
3. Using a External Power Sully for better current suppply for the LED strips.

## Setting Up the ARDUINO IDE

1. Import the AdaFruit-NeoPixel Library
2. Set the Correct COM Port
3. Set the BAUD Rate to 115200

## The Final Run

1. Connect the UNO to PC
2. Turn on the External Power Supply
3. Download the visualizer.ino
4. Open the File and upload the Code.

### Optional 
To make it look like a visualizer I created a 15X15 matrix using Fusion360 and printed using CR10 3D-Printer. 
Folded the LED strips to match the matrix leaving 5 pixel gap at every fold.
Which Looks like this :-


