(Drill3mm)
(Machine)
(  vendor: ProtoMat S42 Mod)
(  description: Generic 3-axis)
(T3  D=0.3 CR=0 TAPER=118deg - ZMIN=-10.09 - drill)
G90 G94
G17
G21
G28 G91 Z0
G90

(Drill2)
T3 M6
S12000 M3
G54
G0 X7.5 Y1.536
Z15
Z5
Z0.5
G1 Z-10.09 F54
G0 Z5
X-7.5
Z0.5
G1 Z-10.09 F54
G0 Z5
Y31.763
Z0.5
G1 Z-10.09 F54
G0 Z5
X7.5
Z0.5
G1 Z-10.09 F54
G0 Z5
X-7.665 Y-10
Z4
G1 Z-10.09 F54
G0 Z5
Y-5.25
Z4
G1 Z-10.09 F54
G0 Z5
Z15
G28 G91 Z0
G90
G28 G91 X0 Y0
G90
M5
M30
