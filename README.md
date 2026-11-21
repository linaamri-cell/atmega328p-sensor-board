# my-first-PCB

2-layer board based on the ATmega328P, designed in KiCad. Runs at 3.3 V with an 8 MHz crystal.

## Specs
- MCU: ATmega328P, 8 MHz crystal
- Power: VBUS input, 3.3 V from an AZ1117-3.3 regulator
- 2 LEDs (power + user LED on PD2), reset button

## Connectors
- **J3**: 6-pin serial header (FTDI) for uploading code
- **J1**: 6-pin AVR ISP
- **J4**: 4-pin sensor port (VBUS, DATA, GND), intended for a DHT-type sensor
- **J2**: 4-pin I2C port (SDA, SCL)

## Design highlights
- Two ways to program: serial header with auto-reset (100 nF on RESET) and AVR ISP
- On-board 3.3 V regulation (AZ1117-3.3) with 10 µF input/output caps
- Expansion ports: 1-wire sensor (J4) and I2C (J2)
- Hand-solder-friendly footprints: 0805 passives, 2.54 mm headers

## Files
- `gerbers/`: Gerber and drill files, ready for fabrication

## Status
Hardware complete: board fabricated, assembled and working.
Firmware bring-up in progress: LED, serial, then DHT sensor.

## Tools
KiCad 10, Arduino IDE
