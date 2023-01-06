In this document, planned upgrades and reasons should be documented.


# Adding Z axis
## Current status
Currently Z axis is actuated by solenoid and a spring. The actual depth is regulated using a screw ![screw](../images/heightscrew.png). When solenoid is powered, the head will move down. And when it is off, spring will move it up. The pin used to drive it is Z+ endstop. 
## Why upgrade is needed
As it is just solenoid, it does not really have a way to set a custom height. The height is only regulated by a screw. So in drilling operations, you would need to re-adjust the screw. Single operation at a time. This will become really tedious over time and if you wanted to make something other than PCBs, you are stuck. So logical solution would be adding Z axis, which would allow you to even CNC other parts and have your tool sitting in single height, thus making the drilling and milling at same time possible. CNC shield already has required stuff to make it happen, only problem is how.
## Procedure of an upgrade
1. Unmount solenoid
2. Take measurements and model tool head.
3. Model stepper holder.
4. Model threadnut holder.
5. Model endstop? 
6. Make and assemble mechanical components
7. Wire stepper and endstop through guide belt and connect to CNC shield. 
8. Upgrade firmware. I would say best option would be try just using stock, as it supposed to work straight away with  3 axies.
9. Done! Tests :D

# Connect endstops in series
## Current status
Only X min and Y max are connected. CNC shield is using min and max connected in parallel. 
## Why
If we want extra security, we should have min max so if some inexperienced user decides to over do it, it would hard stop, protecting the device.
## How
Just connect them in series. That is about it. You may need to add aditional stuff for signal filtering, as there are quite long wires.

# Upgrade spindle
## Current status
Spindle is about 200W, and 32k RPM. If we want to mill aluminium, we would need more powerfull and slower spindle.
## How
A possibility is to use old spindle from previous CNC machine, it is 2kW and already has quite a lot of things mounted. So we would just need to dissasemble old spindle and mount new one. Aditional things may be needed to manufacture for it to fit and function. 