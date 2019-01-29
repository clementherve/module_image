#include <stdlib.h> // needed for NULL
#include <iostream>

#include "Image.h"


// Constructeur par défaut de la classe: initialise dimx et dimy à 0
// ce constructeur n'alloue pas de pixel
Image::Image(): dimx(0), dimy(0){
	std::cout << "[IMAGE] 0*0 initialisee\n";
};



// Constructeur de la classe: initialise dimx et dimy (après vérification)
// puis alloue le tableau de pixel dans le tas (image noire)
Image::Image(unsigned int dimensionX, unsigned int dimensionY){
	std::cout << "[IMAGE] "<<dimensionX<<"*"<<dimensionY<<" initialisee\n";
    this -> dimx = dimensionX;
    this -> dimy = dimensionY;
    this -> tab = new Pixel[(this -> dimx) * (this -> dimy)];
}



// Destructeur de la classe: déallocation de la mémoire du tableau de pixels
// et mise à jour des champs dimx et dimy à 0
Image::~Image(){
	std::cout << "image detruite\n";
    delete[] this -> tab;
    this -> tab = NULL;
}



// Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
// la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
Pixel Image::getPix(unsigned int x, unsigned int y) const {
    if(x >= 0 && y >= 0 && x <= this -> dimx && y <= this -> dimy){
        return this -> tab[y * this->dimx + x];
    } else {
    	return this -> tab[0]; // permet de résoudre le warning
    }
}



// Mutateur : modifie le pixel de coordonnées (x,y)
void Image::setPix(unsigned x, unsigned y, Pixel &couleur){
	std::cout << "[SETPIX]\n";
	if(x >= 0 && y >= 0 && x <= this -> dimx && y <= this -> dimy){
		this -> tab[y * (this->dimx) + x] = couleur;
	}
}



// Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel &couleur){

}



// Efface l'image en la remplissant de la couleur en paramètre
// (en appelant dessinerRectangle avec le bon rectangle)
void Image::effacer(Pixel &couleur){

}



// 
void Image::afficher(){

}


// 
void Image::sauver(char* chemin){
	
}



// Effectue une série de tests vérifiant que le module fonctionne et
// que les données membres de l'objet sont conformes
void Image::testRegression(){ // const ??

}