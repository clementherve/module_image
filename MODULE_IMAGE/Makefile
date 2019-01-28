# whitelist 
# not executed by make, you have to explicitely call them
.PHONY : all, clean, install


# compiler variables
Cname = g++
Cflags = -ggdb -Wall
# Clib = -lSDL2
Clib = 



all : bin/affichage.out bin/exemple.out bin/test.out



# exécutables
bin/affichage.out : obj/mainAffichage.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) $(Clib) obj/mainAffichage.o obj/Pixel.o obj/Image.o -o bin/affichage.out



bin/exemple.out : obj/mainExemple.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) $(Clib) obj/mainExemple.o obj/Pixel.o obj/Image.o -o bin/exemple.out


bin/test.out : obj/mainTest.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) $(Clib) obj/mainTest.o obj/Pixel.o obj/Image.o -o bin/test.out



# main
obj/mainAffichage.o : src/mainAffichage.cpp
	g++ $(Cflags) $(Clib) -c src/mainAffichage.cpp -o obj/mainAffichage.o


obj/mainExemple.o : mainExemple.cpp
	g++ $(Cflags) $(Clib) -c src/mainExemple.cpp -o obj/mainExemple.o


obj/mainTest.o : mainTest.cpp
	g++ $(Cflags) $(Clib) -c src/mainTest.cpp -o obj/mainTest.o



# classes de base
obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	g++ $(Cflags) -c src/Pixel.cpp -o obj/Pixel.o


obj/Image.o : src/Image.cpp src/Image.h
	g++ $(Cflags) $(Clib) -c src/Image.cpp -o obj/Image.o



# Installe la lib SDL2
install : 
	sudo apt-get install libsdl2-dev   
	sudo apt-get install libsdl2-image-dev
	sudo apt-get install libsdl2-ttf-dev
	sudo apt-get install libsdl2-mixer-dev


# Enlève les fichiers intermédiaires
clean : 
	rm -f $(objDir)/*.o
	rm -f $(binDir)/*.out
