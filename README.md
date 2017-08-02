# arduino-echo
Simple program to test USB-to-TTL on Arduino's. Arduino receives a message (8bit char encoding assumed) and repeats it back to predefined Serial connection (by default on same connection it had received a message).

This simple yet highly configurable 'utility' helps you debug certain bottlenecks in your arduino-to-PC communication, especially when USB (as serial comm) is not an option. Tested with 30m UTP cable using 3 wires (RX, TX, GND),  baudrates between 300 and 2000000 (2Mbps), using chinese Arduino (CH340G) as USB-to-TTL (by putting RESET pin to LOW), as well as FTDI TTL-232R. Both were working fine as long as you don't fill up Arduinos buffer (often 64 Bytes; 64 chars). No errors during transmission were encoutered, even when stressed out (an hour of transmitting).

In case of overflowing buffer, text sent to Arduino will simply be trucated to 64Bytes (often showing only first 64 chars).

Arduino sketch if configurable to use software serial, as well as repeating a message to another serial device (currently intended only for testing purpouses). In future, this could be used as serial repeater.

Use with Arduino IDEs serial monitor, as putty (and other command-line serial utilityes) sends message as char-by-char instead of whole message, resulting in line breaks after (almost) every character. This is intended, but in future should be configurable. 
