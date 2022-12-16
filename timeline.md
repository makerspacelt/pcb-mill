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

It seems that motor is 80V not 26 V... But we will see how it goes. 


# Motor pinout

UP MOTOR

CONNECTOR

A B C 5V G HA HB HC

# 2022-12-02
Good Friday. So next two steps I want to do today, is to figure out how to connect and control spindle and Z axis in CNC shield. After this we can proceed to rest of the wiring. Possibly I may connect Y endstops too today. 

## Configuring Z axis
https://openbuilds.com/threads/using-a-solenoid-on-an-arduino-cnc-shield-and-gcode.9966/
```
wire it to the Coolant Enable pin and control it with  
M8 to turn it on (equiv to Z down)  
M9 to turn it off (equiv to Z up)
```

Well this is simplier than I thought. NOw see if I can configure that in flatcam.

Ok, so there is a way without any mods to flatcam. As well... it did not have a setting. 
https://github.com/gnea/grbl/issues/640
```
doesn't matter where it comes from, the z-direction pin gets set or cleared with all the other direction pins in line 324 of stepper.c

`DIRECTION_PORT = (DIRECTION_PORT & ~DIRECTION_MASK) | (st.dir_outbits & DIRECTION_MASK);`

replace it with some thing like:

`DIRECTION_PORT = (DIRECTION_PORT & ~((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT))) | (st.dir_outbits & ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)));`

`if(st.step_outbits & (1<<Z_STEP_BIT)) DIRECTION_PORT = (DIRECTION_PORT & ~((1<<Z_DIRECTION_BIT))) | (st.dir_outbits & ((1<<Z_DIRECTION_BIT)));`
```

So i will modify the repo source for this. 
https://github.com/gnea/grbl/wiki/Compiling-Grbl
Zipped modified lib and included it . Upload completed.



## How to control
`git clone https://github.com/kliment/Printrun.git`
use this app.

FOund even better 
https://cnc.js.org/
https://create.arduino.cc/projecthub/Arnov_Sharma_makes/setting-up-grbl-on-arduino-uno-along-cncjs-dc02d9


## Preparing SPindle.
Tried to connect spindle with figured out schematics, but onfortunatelly no spinning occured. Only on shutdown short spin was there. So we decided to replace the controller. 

Managed to connect cheap controller and start spindle. Nominal voltage seems to be 36 V.
Spindle startup voltage is 30V, any lower and it will not start. Though if you start and drop to 26V, it will still spin. To not make it more complicated, 35V was routed from stock PSU.

[Datasheet for the spindle](https://crossic.com/wp-content/uploads/2022/02/JYQD-V7.5E-English-2.pdf)

## 2022-12-14
We were routing most of the cables, connected endstops (tested Y axis, seemed to be fine), removed old cables. What still left is to make adapter board for connecting extended spindle cables with controller. And then tests tests tests.

Needed to invert axies
Use $3=00000110 mask


Also endstops are connected parallel on shield so
 #define LIMITS_TWO_SWITCHES_ON_AXES 
 needed



 22.73 250
 100

 Anyway, still failing to home and use swithces properly. https://github.com/gnea/grbl/issues/788
 Though did calibrate steps. And solenoid seems to work fine too.

 # 2022-12-16
 Disconnected Y limit switches from the PSU, and connected straight. Using only one switch now. If want to use two, you need to connect in series. Wires already prepared.

 Managed to run homing. Also started to set up work PC.