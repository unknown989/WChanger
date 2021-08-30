# WChanger
the most simplest window wallpaper changer
## Build
* Clone : ``git clone https://github.com/unknown989/WChanger.git``
* If you are using MinGW follow these steps if not link the files in [Linking](#Linking) with your IDE compiler
* Compile the file as an object ``g++.exe -Wall -g -municode  -c main.cpp -o main.o``
* Link the object with the additiobal libraries ``g++.exe  -o WChanger.exe main.o   -lgdi32 -luser32 -lkernel32 -lcomctl32 -lcomdlg32``

## Linking
* ``gdi32``
* ``user32``
* ``kernel32``
* ``comctl32``
* ``comdlg32``

## Contact
Check my github account for the contact methods ,and do let me know if there's a bug
