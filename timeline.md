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

 # 2022-12-25
 Preparing workstation dockercompose. [CNCJS](https://github.com/cncjs/cncjs) had one set up, so I just configured that in compose file. 

 Yeah the problem is that python container seems to open well.. python on start. I do not want that. 
 Instead of using python container, i just switch to ubuntu and install python... Oh well. Lets hope it works.Switched to alpine to reduce size.  Nevermind... setup file is for ubuntu only. So nope. Redo... 
 Ok, now it says that sudo not found... Installed sudo package. Another problem, requires user input in selecting timezone and region. [No interactive zones](https://stackoverflow.com/questions/53079135/how-can-i-pass-arguments-or-bypass-it-in-docker-build-process) . That fixed prompts. But still need to remove easy_install line. Then next error is fixed using [Downgrade vispy](https://bitbucket.org/jpcgt/flatcam/issues/538/ubuntu-fail-to-run-from-source)

Next error:
```
root@ba43b2a95795:/usr/src/app# python3 FlatCAM.py 
/usr/local/lib/python3.10/dist-packages/vispy/visuals/graphs/layouts/networkx_layout.py:10: UserWarning: Networkx not found, please install network to use its layouts
  warnings.warn(
qt.qpa.xcb: could not connect to display 
qt.qpa.plugin: Could not load the Qt platform plugin "xcb" in "" even though it was found.
This application failed to start because no Qt platform plugin could be initialized. Reinstalling the application may fix this problem.

Available platform plugins are: eglfs, linuxfb, minimal, minimalegl, offscreen, vnc, wayland-egl, wayland, wayland-xcomposite-egl, wayland-xcomposite-glx, webgl, xcb.

Aborted (core dumped)
```
[Running GUI in docker](https://www.howtogeek.com/devops/how-to-run-gui-applications-in-a-docker-container/)


 Other problem, that i need somehow execute flatcam so it would open within container, but I could see it on host machine. It has something to do with entrypoint. When you run the container, it will start your selected executable. 
 ## Todo
 - Load machine profile from file. There is an option to run with -c argument giving the file. 
 - Set up flatcam.
    Sort of done... Made a script instead of docker. As I still need to learn how to use display when app is running inside container. 

# 2022-12-29
Flatcam is up and running in docker. Same with CNCJS. Just do `docker-compose up` and everything will be up. Open cncjs in (http://localhost:8000).

# 2022-12-31
Finally started whole machine. Connected workshop vacuum to machine, to pull the base plate closer. Had to clean the vacuum first... There were a problem of trying to adjust the height of the drill, figured out that you need to turn a screw on a side:
![[Pasted image 20230106152902.png]]
It has a really weird bit. You need to use small steel strip. After that, ran some tests with 0.1 mm engraving bit. ![[IMG_20221231_223333.jpg]]
![[IMG_20221231_221200.jpg]]![[IMG_20221231_221203.jpg]]
Results well... are something. Depth is still too big, so more tuning needed. Though I also tried it on aluminium with 0.5 mm bit.
![[IMG_20221231_225819.jpg]]![[IMG_20221231_230227.jpg]]
![[IMG_20221231_231920.jpg]]
As the bit had 4 wings, the outer edge seem to be not clear. A single blade drill bit should be used. Otherwise, pretty good results. 
# 2023-01-06
Updating documentation, plans. 