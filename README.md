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
# Flatcam

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
