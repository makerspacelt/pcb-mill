# Project purpose
This project is for reviving PotoMat S42 PCB milling machine which is out of support (asked manufacturer). 

The documentation will be updated, in the mean time, progress will be reported in [timeline](timeline.md)
And the future plans in [[Planned upgrades]]

# Supported platforms
linux
# Setup workstation
1.  Install docker and docker compose on your system [Docker instalation instructions](https://docs.docker.com/get-docker/)
2. Clone this repository.
3. Open CMD in workstation directory.
4. Type `docker-compose up -d`

This should start [Cncjs] server at (http://localhost:8000), and [Flatcam] desktop application. If you ever close [Flatcam], run the same command again and it should re-open. 

If you need to you can set this up on system startup, but this will not be covered here. 

# Cncjs
## Introduction
Web based application for controlling, configuring and running the machine with gcode. [Cncjs docs](https://cnc.js.org/docs/)
## Configuring machine
### Inner GRBL settings
You can use embedded terminal window to use [GRBL configuration commands](https://github.com/gnea/grbl/blob/master/doc/markdown/settings.md) . **CAUTION. NO SETTING BACKUP YET MADE :D** . Otherwise reflashing firmware is needed to make it permanent. 
[MSG:'$H'|'$X' to unlock]
$0=10 (Step pulse time, microseconds)
$1=25 (Step idle delay, milliseconds)
$2=0 (Step pulse invert, mask)
$3=0 (Step direction invert, mask)
$4=0 (Invert step enable pin, boolean)
$5=1 (Invert limit pins, boolean)
$6=0 (Invert probe pin, boolean)
$10=19 (Status report options, mask)
$11=0.010 (Junction deviation, millimeters)
$12=0.002 (Arc tolerance, millimeters)
$13=0 (Report in inches, boolean)
$20=0 (Soft limits enable, boolean)
$21=0 (Hard limits enable, boolean)
$22=1 (Homing cycle enable, boolean)
$23=11 (Homing direction invert, mask)
$24=25.000 (Homing locate feed rate, mm/min)
$25=500.000 (Homing search seek rate, mm/min)
$26=250 (Homing switch debounce delay, milliseconds)
$27=1.000 (Homing switch pull-off distance, millimeters)
$30=2000 (Maximum spindle speed, RPM)
$31=0 (Minimum spindle speed, RPM)
$32=0 (Laser-mode enable, boolean)
$100=1100.000 (X-axis travel resolution, step/mm)
$101=1100.000 (Y-axis travel resolution, step/mm)
$102=250.000 (Z-axis travel resolution, step/mm)
$110=500.000 (X-axis maximum rate, mm/min)
$111=500.000 (Y-axis maximum rate, mm/min)
$112=500.000 (Z-axis maximum rate, mm/min)
$120=10.000 (X-axis acceleration, mm/sec^2)
$121=10.000 (Y-axis acceleration, mm/sec^2)
$122=10.000 (Z-axis acceleration, mm/sec^2)
$130=250.000 (X-axis maximum travel, millimeters)
$131=200.000 (Y-axis maximum travel, millimeters)
$132=200.000 (Z-axis maximum travel, millimeters)
ok
### Machine limits
TODO
# Flatcam
## Introduction
Desktop app to generate instructions for milling pcbs or lasercutting. More in [Flatcam docs](http://flatcam.org/).
## A quirk
Unfortunatelly support on this is a bit patchy, as new version is being developed, and thus the set up was not really fixed. This is why a [fork](https://github.com/AntumArk/Flatcam) is used and old flatcam version ( functions perfectly fine). What is basically done, is the dependencies were fixed and install script was automated using docker. 
## Feed speed
TODO
## Dwell
TODO
## Spindle speed
TODO
# TODO
- [x] - Figure out spindle wiring.
- [x] - Connect spindle to CNC shield.
- [x] - Create control schematic for solenoid (use original board as example)
- [x] - Figure out how to control solenoid with CNC shield
- [x] - Connect Y endstops
- [x] - Configure XY axies
- [x] - Configure spindle
- [x] - Configure solenoid as Z axis
- [x] - First test.
- [ ] Create machine schematics
- [x] Create setup guide
- [x] Create upgrade plan
- [ ] Create user guide
- [x] Add grbl repo as submodule. 
