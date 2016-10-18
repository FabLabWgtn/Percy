G21 ;metric values
G90 ;absolute positioning
M82 ;set extruder to absolute mode
M107 ;start with the fan off
G28 Z F30; Home Axis
G28 X Y F30; Home Y X
G92 E0 ;zero the extruded length
M117 Cleaning...;Put Cleaning message on screen
G4 P5000 ; wait 5 seconds for nozzle length to stabilize
G92 E0 ; reset extruder
M117 Printing...;Put printing message on LCD screen
