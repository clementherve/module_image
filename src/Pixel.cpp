#include <iostream>
#include <cassert>
#include "Pixel.h"



// Constructeur par défaut de la classe: initialise le pixel à la couleur noire
Pixel::Pixel():r(0), g(0), b(0){};




// Constructeur de la classe: initialise r,g,b avec les paramètres 
Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb){
	if(nr >= 0 && nr <= 255 && ng >= 0 && ng <= 255 && nb >= 0 && nb <= 255){
		assert(nr >= 0 && nr <= 255);
		assert(ng >= 0 && ng <= 255);
		assert(nb >= 0 && nb <= 255);
		this -> r = nr;
		this -> g = ng;
		this -> b = nb;
	} else {
		this -> r = 0;
		this -> g = 0;
		this -> b = 0;
	}
};


// 


// Accesseur : récupère la composante rouge du pixel
unsigned char Pixel::getRouge() const {
	return this -> r;
}




// Accesseur : récupère la composante verte du pixel
unsigned char Pixel::getVert() const {
	return this -> g;
}




// Accesseur : récupère la composante bleue du pixel
unsigned char Pixel::getBleu() const {
	return this -> b;
}





// Mutateur : modifie la composante rouge du pixel
void Pixel::setRouge(unsigned char nr){
	if(nr >= 0 && nr <= 255){
		assert(nr >= 0 && nr <= 255);
		this -> r = nr;
	}
}




// Mutateur : modifie la composante verte du pixel
void Pixel::setVert (unsigned char nv){
	if(nv >= 0 && nv <= 255){
		assert(nv >= 0 && nv <= 255);
		this -> g = nv;
	}
}




// Mutateur : modifie la composante bleue du pixel
void Pixel::setBleu (unsigned char nb){
	if(nb >= 0 && nb <= 255){
		assert(nb >= 0 && nb <= 255);
		this -> b = nb;
	}
}