#include <stdlib.h> // needed for NULL
#include <iostream>
#include <cassert>

#include "Image.h"


// Constructeur par défaut de la classe: initialise dimx et dimy à 0
// ce constructeur n'alloue pas de pixel
Image::Image(): dimx(0), dimy(0){};



// Constructeur de la classe: initialise dimx et dimy (après vérification)
// puis alloue le tableau de pixel dans le tas (image noire)
Image::Image(unsigned int dimensionX, unsigned int dimensionY){
    this -> dimx = dimensionX;
    this -> dimy = dimensionY;
    std::cout << this->dimx;
    this -> tab = new Pixel[(this -> dimx) * (this -> dimy)];
}



// Destructeur de la classe: déallocation de la mémoire du tableau de pixels
// et mise à jour des champs dimx et dimy à 0
Image::~Image(){
    delete[] this -> tab;
    this -> tab = NULL;
}



// Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
// la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
Pixel Image::getPix(unsigned int x, unsigned int y){
    if(x >= 0 && y >= 0 && x <= this -> dimx && y <= this -> dimy){
        return this -> tab[y * this->dimx + x];
    } else {
    	return this -> tab[0]; // permet de résoudre le warning
    }
}



// Mutateur : modifie le pixel de coordonnées (x,y)
void Image::setPix(unsigned int x, unsigned int y, const Pixel &couleur){

    assert(x >= 0);
    assert(y >= 0);
    assert(y <= this->dimx);
    assert(y <= this->dimy);

	if(x >= 0 && y >= 0 && x <= this -> dimx && y <= this -> dimy){
		this -> tab[y * (this->dimx) + x] = couleur;
	}
}



// Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel &couleur) const {
    int nbCasesX = Xmax - Xmin + 1;
    int nbCasesY = Ymax - Ymin + 1;
    int X;
    int Y = Ymin;
    for (int i = 0; i < nbCasesY; i++){
        X = Xmin;
        for (int j = 0; j < nbCasesX; j++){
            this.setPix(X, Y, couleur);
            X = X + 1;
        }
        Y = Y + 1;
    }
}



// Efface l'image en la remplissant de la couleur en paramètre
// (en appelant dessinerRectangle avec le bon rectangle)
void Image::effacer(Pixel &couleur){
    dessinerRectangle(0, 0, this->dimx-1, this->dimy-1, couleur);
}




//
// @brief      { function_description }
//
void Image::afficher(){

}


// 
void Image::sauver(char* chemin){
	
}



// Effectue une série de tests vérifiant que le module fonctionne et
// que les données membres de l'objet sont conformes
void Image::testRegression(){

    // test constructeur
    // std::cout << "testReg\n";
    // Image* img = new Image(2, 3);
    // delete img;
    // img = NULL;

}