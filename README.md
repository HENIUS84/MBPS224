# MBPS224
This is program of supporting firmware for Mictrocontroller Based Power Supply project called MBPS224.

Device consists of two main parts:
- Main Board (ATmega128),
- Power Supply Module ATmega32).

The responsibilities of Main Board are:
- communication with power supply module over isolated I2C bus,
- measurements visualization,
- setting parameters of power supply modules,
- communication with PC.

The responsibilities of Power Supply Module are:
- voltage and current regulation,
- temperature measurement of voltage regulator,
- voltage and current measurements,
- communication with Main Board by isolated I2C bus.
