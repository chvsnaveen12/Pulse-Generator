# Pulse-Generator
Pulse generator for the 8-bit cmos computer

## Wiring
| Arduino Pin | Connection |
| :--------   | :-------   |
|   d12       | LCD rs     |
|   d11       | LCD en     |
|   d3        | LCD d4     |
|   d4        | LCD d5     |
|   d5        | LCD d6     |
|   d6        | LCD d7     |
|   A1        | Encoder A  |
|   A2        | Encoder B  |
|   A0        | Encoder SW |
|   d10       | Menu Button|
|   d2        | Pulse Out  |

Menu button has to be hooked up in an active low configuration.
If you want to change direction of the encoder, just swap Encoder A and Encoder B.

## Usage 
Press the Menu button to cycle through the 4 modes. [Youtube Video](https://www.youtube.com/watch?v=3lUOrzv3epo)

### Single step mode
Press the encoder button to send out a pulse.

### Multi step mode
Select how many pulses you want to generate, and then press the encoder button to send out that many pulses.

### Delay mode millis
Select the delay between a state transition of the pulse, in milliseconds. Then press the encoder button to start the pulse generation.
To stop, press the encoder button again. If the delay is too high and the pulses are being generated, the encoder might stop responding.
Just stop the pusles, change the delay, and start again.

### Delay mode micros
Works just like the above function but the delay between state transitions is in microseconds.

