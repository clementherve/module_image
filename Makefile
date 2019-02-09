# Indique à make de ne pas exécuter clean sauf mention contraire
.PHONY : clean


# variables, pour la flexibilité.
# Pour compiler sans debug, enlever -ggdb
# Clib contient la librairie SDL pour l'affichage graphique
Cflags = -ggdb -Wall
Clib = -L/usr/include/ -lSDL2main -lSDL2


# Construit tous les main
all : bin/affichage bin/exemple bin/test




# exécutables
bin/affichage : obj/mainAffichage.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) obj/mainAffichage.o obj/Pixel.o obj/Image.o -o bin/affichage $(Clib)


bin/exemple : obj/mainExemple.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) obj/mainExemple.o obj/Pixel.o obj/Image.o -o bin/exemple $(Clib)


bin/test : obj/mainTest.o obj/Pixel.o obj/Image.o
	g++ $(Cflags) obj/mainTest.o obj/Pixel.o obj/Image.o -o bin/test $(Clib)



# Les différents main exigés
obj/mainAffichage.o : src/mainAffichage.cpp src/Image.h src/Pixel.h
	g++ $(Cflags) -c src/mainAffichage.cpp -o obj/mainAffichage.o $(Clib)


obj/mainExemple.o : src/mainExemple.cpp src/Image.h src/Pixel.h
	g++ $(Cflags) -c src/mainExemple.cpp -o obj/mainExemple.o $(Clib)


obj/mainTest.o : src/mainTest.cpp src/Image.h src/Pixel.h
	g++ $(Cflags) -c src/mainTest.cpp -o obj/mainTest.o $(Clib)





# Les classes de base
obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	g++ $(Cflags) -c src/Pixel.cpp -o obj/Pixel.o $(Clib)


obj/Image.o : src/Image.cpp src/Image.h src/Pixel.h
	g++ $(Cflags) -c src/Image.cpp -o obj/Image.o $(Clib)




# Enlève les fichiers intermédiaires
clean : 
	rm -f obj/* bin/*