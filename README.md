1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software)
2. Download this repository
3. Open the Arduino IDE
   1. File -> Open -> Locate your downloaded repository and select the "SolenoidPERcode" .ino file inside of the SolenoidPERcode folder.
   2. Plug in your arduino uno using a usb2.0 connector to your computer.
   3. Install the Adafruit Motor Shield V2 library through the library manager of the arduino IDE. [Documentation](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/install-software)
      1. In the top ribbon of the arduino IDE click Sketch -> Include Library -> Manage Libraries...
      2. In opened screen for Manage Libraires, in the search bar in the top right type in "Adafruit Motor Shield V2", could also search "adafruit motor".
      3. Click the Install button next to the option of the library that is by Adafruit.
      4. Restart the arduino IDE
   4. Click the "Select Board" dropdown menu and select the arduino uno. If you do not see it present then your board has not been successfully connected to the computer.
   5. Click the checkmark button at the top left of the arduino IDE to verify there are no errors in your sketch.
   6. Click the right arrow button at the top left of the Arduino IDE to upload the code to the arduino uno.

Note: The arduino uno motor shield v2 was used in addition to just the arduino uno. A button is also hooked up to the arduino uno to initiate the sequence. A basic introduction to using the shield can be found [here](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/overview).
