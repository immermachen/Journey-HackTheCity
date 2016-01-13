----------------Capture function from:----------------------
config:D:\StructuredLightOpenCV\procamtools-v1\source\calibrate\options.ini


run in vs2013; 

mkdir D:\data                  for startcapture: one time for one pair image. 
camera1: 0-00.bmp,0-01.bmp
camera2: 1-00.bmp,1-01.bmp


----------------Global Config----------------------
copy [D:\Journey-HackTheCity\decoded and options.ini] to [D:\Journey-HackTheCity\procamtools-v1\Release\]

config: D:\Journey-HackTheCity\procamtools-v1\Release\decoded\0options.ini
config: D:\Journey-HackTheCity\procamtools-v1\Release\decoded\1options.ini


----------------Decode function from:----------------------
config: D:\Journey-HackTheCity\procamtools-v1\Release\options.ini

mkdir D:\Journey-HackTheCity\procamtools-v1\Release\decoded

run in command: 
decoder.exe 

use D:\data
camera1: 0-00.bmp,0-01.bmp
camera2: 1-00.bmp,1-01.bmp

save decoded data in:  D:\Journey-HackTheCity\procamtools-v1\Release\decoded

----------------Calibration function from:----------------------
config: D:\Journey-HackTheCity\procamtools-v1\Release\decoded\0options.ini (1options.ini)

run in command: 
calibrator.exe 0:  for camera left, and see inlines number, if small change the vertical_center = 0.55 in 0options.ini until inlines is larger.=
calibrator.exe 1:  for camera right

Note: vertical_center = 0.55 is difficult thing, sometimes with or without light are different value for same position, for camera 1. 

----------------triangulate function from:----------------------
config: D:\Journey-HackTheCity\procamtools-v1\Release\decoded\0options.ini (1options.ini)

run in command: 
triangulate.exe 1 10   ;the first 1 can be arbitrary letter. 10: angle. 

output: D:\Journey-HackTheCity\procamtools-v1\Release\decoded\0mesh.fly (1mesh.fly)



