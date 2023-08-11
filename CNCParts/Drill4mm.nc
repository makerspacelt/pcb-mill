(Drill4mm)
(Machine)
(  vendor: ProtoMat S42 Mod)
(  description: Generic 3-axis)
(T2  D=4 CR=0 TAPER=118deg - ZMIN=-10.202 - drill)
G90 G94
G17
G21
G28 G91 Z0
G90

(Drill3)
T2 M6
S7277 M3
G54
G0 X8.165 Y-25
Z15
Z5
Z4
G1 Z-10.202 F436.6
G0 Z5
Y22
Z4
G1 Z-10.202 F436.6
G0 Z5
Z15
G28 G91 Z0
G90
G28 G91 X0 Y0
G90
M5
M30
