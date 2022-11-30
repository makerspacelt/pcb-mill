# TODO Add previous history



# 2022-11-30 BLDC controller

Took out BLDC controller for better acess. The schematic on the board is 
[MC33035DW](https://www.onsemi.com/pdf/datasheet/mc33035-d.pdf). The power supply for this is 26V. 

[33039](https://www.onsemi.com/pdf/datasheet/mc33039-d.pdf) - Closed loop controller. 
8 Pin should be for PWM control, which is VCC for that microchip. 

The pinout for the control connector is:



 -------------    ------------------
|  80V X     EN  GND  GND       |
|  80V 26V   X   PWM    GND     |
_______________________________

Ground is shorted to the frame. 

11 Error Amp Noninverting Input This input is normally connected to the speed set potentiometer.

7 Output Enable A logic high at this input causes the motor to run, while a low causes it to coast.


3 Fwd/Rev The Forward/Reverse Input is used to change the direction of motor rotation.

13 Error Amp Out/PWM Input This pin is available for compensation in closed loop applications.

23 Brake A logic low state at this input allows the motor to run, while a high state does not
allow motor operation a


Surasti VCC pinus biski nein. Galimai del dideliu kodiku. 


So [33039] controller is responsible for closed loop control. 