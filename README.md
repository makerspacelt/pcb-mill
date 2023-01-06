# Project purpose
This project is for reviving PotoMat S42 PCB milling machine which is out of support (asked manufacturer). 

The documentation will be updated, in the mean time, progress will be reported in [timeline](timeline.md)

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
- [ ] Create upgrade plan
- [ ] Create user guide
- [ ] Add grbl repo as submodule. 
