# whitelist 
# not executed by make, you have to explicitely call them
.PHONY : all, clean, install, test


# compiler variables
Cflags = -ggdb -Wall
# Clib = 
Clib = -L/usr/include/ -lSDL2main -lSDL2


test : 
	g++ -Wall sdl_test.cpp $(Clib)



all : bin/affichage.out bin/exemple.out bin/test.out



# exécutables
bin/affichage : obj/mainAffichage.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) obj/mainAffichage.o obj/Pixel.o obj/Image.o -o bin/affichage



bin/exemple : obj/mainExemple.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) obj/mainExemple.o obj/Pixel.o obj/Image.o -o bin/exemple $(Clib)


bin/test : obj/mainTest.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) obj/mainTest.o obj/Pixel.o obj/Image.o -o bin/test $(Clib)



# main
obj/mainAffichage.o : src/mainAffichage.cpp
	g++ $(Cflags) -c src/mainAffichage.cpp -o obj/mainAffichage.o $(Clib)


obj/mainExemple.o : src/mainExemple.cpp
	g++ $(Cflags) -c src/mainExemple.cpp -o obj/mainExemple.o $(Clib)


obj/mainTest.o : src/mainTest.cpp
	g++ $(Cflags) -c src/mainTest.cpp -o obj/mainTest.o $(Clib)



# classes de base
obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	g++ -c src/Pixel.cpp -o obj/Pixel.o $(Clib)


obj/Image.o : src/Image.cpp src/Image.h src/Pixel.cpp src/Pixel.h
	g++ $(Cflags) -c src/Image.cpp -o obj/Image.o $(Clib)



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
