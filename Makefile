# whitelist 
# not executed by make, you have to explicitely call them
.PHONY : all, clean, install


# compiler variables
Cflags = -ggdb -Wall
Clib = -lSDL2



all : bin/affichage.out bin/exemple.out bin/test.out



# exécutables
bin/affichage : obj/mainAffichage.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) $(Clib) obj/mainAffichage.o obj/Pixel.o obj/Image.o -o bin/affichage



bin/exemple : obj/mainExemple.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) $(Clib) obj/mainExemple.o obj/Pixel.o obj/Image.o -o bin/exemple


bin/test : obj/mainTest.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) $(Clib) obj/mainTest.o obj/Pixel.o obj/Image.o -o bin/test



# main
obj/mainAffichage.o : src/mainAffichage.cpp
	g++ $(Cflags) $(Clib) -c src/mainAffichage.cpp -o obj/mainAffichage.o


obj/mainExemple.o : src/mainExemple.cpp
	g++ $(Cflags) $(Clib) -c src/mainExemple.cpp -o obj/mainExemple.o


obj/mainTest.o : src/mainTest.cpp
	g++ $(Cflags) $(Clib) -c src/mainTest.cpp -o obj/mainTest.o



# classes de base
obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	g++ $(Cflags) -c src/Pixel.cpp -o obj/Pixel.o


obj/Image.o : src/Image.cpp src/Image.h src/Pixel.cpp src/Pixel.h
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
