// Librairies externes
#include <iostream>
#include <cassert>
#include <SDL2/SDL.h>

#include <fstream>


// Header de Image.h
#include "Image.h"


// 
// Constructeur par défaut de la classe: initialise dimx et dimy à 0
// ce constructeur n'alloue pas de pixel
// 
Image::Image(): dimx(0), dimy(0){
    this -> tab = NULL;
    this -> noir = new Pixel(0, 0, 0);
}


// 



// Constructeur de la classe: initialise dimx et dimy (après vérification)
// puis alloue le tableau de pixel dans le tas (image noire)
Image::Image(const unsigned int dimensionX, const unsigned int dimensionY){



    if(dimensionX > 0 && dimensionY > 0 && dimensionX < 500 && dimensionY < 500){
        
        this -> dimx = dimensionX;
        this -> dimy = dimensionY;

        
    } else {

        this -> dimx = 1;
        this -> dimy = 1;

    }

    const unsigned int dim = (this -> dimx)*(this -> dimy);

    assert(dimx > 0 && dimx < 1000);
    assert(dimy > 0 && dimy < 1000);
    assert(dim > 0);

    this -> tab = new Pixel[dim];
    this -> noir = new Pixel(0, 0, 0);
}





// Destructeur de la classe: déallocation de la mémoire du tableau de pixels
// et mise à jour des champs dimx et dimy à 0
Image::~Image(){
    delete[] this -> tab;
    delete this -> noir;
    this -> noir = NULL;
    this -> tab = NULL;
    this -> dimx = 0;
    this -> dimy = 0;
}



// Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
// la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
Pixel& Image::getPix(const unsigned int x, const unsigned int y) const{

    if(x >= 0 && y >= 0 && x < this -> dimx && y < this -> dimy){

        assert(x >= 0);
        assert(y >= 0);
        assert(y < this->dimx);
        assert(y < this->dimy);

        return this -> tab[y * this->dimx + x];
    } else {
        return *(this -> noir); // ABORT MISSION, I REPEAT, ABORT MISSION!
    }
}






// Mutateur : modifie le pixel de coordonnées (x,y)
void Image::setPix(const unsigned int x, const unsigned int y, const Pixel &couleur){

	if(x >= 0 && y >= 0 && x < this -> dimx && y < this -> dimy){

        assert(x >= 0);
        assert(y >= 0);
        assert(y < this->dimx);
        assert(y < this->dimy);

		this -> tab[y * (this->dimx) + x] = couleur;
	}
}



// Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
void Image::dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel &couleur){
    


    if(Xmin >= 0 && Ymin >= 0 && Xmin < Xmax && Ymin < Ymax){

        assert(Xmin >= 0);
        assert(Ymin >= 0);
        assert(Xmin < Xmax);
        assert(Ymin < Ymax);

        int nbCasesX = Xmax - Xmin + 1;
        int nbCasesY = Ymax - Ymin + 1;
        int X;
        int Y = Ymin;
        for (int i = 0; i < nbCasesY; i++){
            X = Xmin;
            for (int j = 0; j < nbCasesX; j++){
                this -> setPix(X, Y, couleur);
                X = X + 1;
            }
            Y = Y + 1;
        }

    }



}



// 
void Image::effacer(Pixel &couleur){
    dessinerRectangle(0, 0, this->dimx-1, this->dimy-1, couleur);
}




bool Image::init_fenetre(SDL_Window* &fenetre, SDL_Renderer* &rendu){

    // on force le pointeur a etre nul 
    // (il n'est pas sensé valoir autre chose a ce stade)
    fenetre = NULL;
    rendu = NULL;

    // la fonction d'initialisation renvoit 0 si tout s'est bien passé
    if(SDL_InitSubSystem(SDL_INIT_VIDEO) == 0){
        fenetre = SDL_CreateWindow(
                "Module Image", 
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                200, 
                200, 
                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

        

        // si Create Window a planté, a un pointeur qui est NULL
        if(fenetre == NULL){
            return false;
        } else {
            rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_SOFTWARE);
            return true;
        }

    } else {
        return false;
    }
}



void Image::ajoute_pixel(SDL_Renderer* &rendu, const unsigned int x, const unsigned int y, const Pixel &pix){
    

    // donne une nouvelle couleur avec laquelle dessiner
    SDL_SetRenderDrawColor(rendu, pix.getRouge(), pix.getVert(), pix.getBleu(), 255);
    
    // draw here
    SDL_RenderDrawPoint(rendu, x, y);

}



void Image::boucle_fenetre(SDL_Window* &fenetre, SDL_Renderer* &rendu){

    bool is_running = true;
    SDL_Event e;

    float scale = 1.0;
    int xSize, ySize;

    while(is_running){

        // gère les évenements
        while(SDL_PollEvent(&e)){

            if(e.type == SDL_QUIT){
                is_running = false;
            } else if(e.type == SDL_KEYDOWN){
                
                std::string letter = SDL_GetKeyName(e.key.keysym.sym);

                if(letter == "T"){
                    // std::cout << scale << std::endl;
                    if(scale < 20.0){
                        scale += 0.1;
                    }
                    SDL_RenderSetScale(rendu, scale, scale);
                } else if(letter == "G"){
                    if(scale > 0.1){
                        scale -= 0.1;
                        SDL_RenderSetScale(rendu, scale, scale);
                    }
                }

                
            }

        } // fin de la gestion des évènements



        // specifie un arriere plan
        //specifie une couleur d'arriere plan (rgba)
        SDL_SetRenderDrawColor(rendu, 50, 50, 50, 255);
        // nettoie l'ecran avec la couleur specifiee au dessus
        SDL_RenderClear(rendu);

        
        SDL_GetWindowSize(fenetre, &xSize, &ySize);
        // generation du rendu
        for(unsigned int i=0; i<this->dimx; i++){
            for(unsigned int j=0; j<this->dimy; j++){
                ajoute_pixel(rendu, i + (xSize - dimx*scale)/(2*scale), j + (ySize - dimy*scale)/(2*scale), getPix(i, j));
            }
        }


        // affiche
        // update the screen
        SDL_RenderPresent(rendu);
    }

}





void Image::detruire_fenetre(SDL_Window* &fenetre, SDL_Renderer* &rendu){

    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);

    rendu = NULL;
    fenetre = NULL;

    SDL_Quit();
}






// 
void Image::afficher(){


    SDL_Window* fenetre = NULL;
    SDL_Renderer* rendu = NULL;

    if(init_fenetre(fenetre, rendu)){
        boucle_fenetre(fenetre, rendu);
        detruire_fenetre(fenetre, rendu);
    }

}





void Image::sauver(const std::string& filename) const {
    
    std::ofstream fichier(filename.c_str());
    
    // assert(fichier.is_open());

    if(fichier.is_open()){

        fichier << "P3\n";
        fichier << this->dimx << " " << this->dimy << "\n";
        fichier << "255\n";

        for(unsigned int y=0; y<this->dimy; y++){
            
            for(unsigned int x=0; x<this->dimx; x++){
                Pixel& pix = getPix(x,y); // permet d'éviter d'accéder 3 fois au pixel, on y accède une fois, et ensuite on travaille sur une référence (pix)
                fichier << (unsigned int) pix.getRouge() << " " << (unsigned int) pix.getVert() << " " << (unsigned int) pix.getBleu() << " ";
            }

        }

        std::cout << "Sauvegarde de l'image " << filename << " ... OK\n";
        fichier.close();

    }
}





// 
void Image::ouvrir(const std::string& filename) {
    
    std::ifstream fichier(filename.c_str());
    
    // assert(fichier.is_open());

    if(fichier.is_open()){

        unsigned int nr, ng, nb;
        std::string mot;
        
        this -> dimx = 0;
        this -> dimy = 0;
        
        fichier >> mot >> this->dimx >> this->dimy >> mot;

        std::cout << this->dimx << "; " << this->dimy << "\n";

        assert(this->dimx > 0 && this->dimy > 0);
        
        if (tab != NULL){
            delete [] tab;
        }

        this->tab = new Pixel[this->dimx*this->dimy];
        
        for(unsigned int y = 0; y < this->dimy; y++){

            for(unsigned int x = 0; x < this->dimx; x++){
                fichier >> nr >> ng >> nb;
                Pixel pixy((unsigned int) nr, (unsigned int) ng, (unsigned int) nb);
                setPix(x, y, pixy);
            }

        }
        
        fichier.close();
        std::cout << "Lecture de l'image " << filename << " ... OK\n";

    }
}






void Image::afficherConsole(){
    std::cout << this->dimx << " " << this->dimy << "\n";
    for(unsigned int y=0; y<this->dimy; y++) {
        for(unsigned int x=0; x<this->dimx; x++) {
            Pixel& pix = this->getPix(x,y);
            std::cout << (int) pix.getRouge() << " " << (int) pix.getVert() << " " << (int) pix.getBleu() << "|";
        }
        std::cout << "\n";
    }
}




// Effectue une série de tests vérifiant que le module fonctionne et
// que les données membres de l'objet sont conformes
void Image::testRegression(){

    // un pixel utilisé dans les tests
    Pixel pixy(5, 5, 5); // pixy normal
    
    // Pixel depressedPixy(-5, -5, -5); //pixy negatif (depressed)
    // Pixel excitedPixy(400, 400, 400); //pixy positif (excited)

    Pixel garbage(3, 67, 200);
    Image* img = NULL;


    std::cout << "[TEST 1]\n";
    std::cout << "img = new Image(-1, 1)\n";
    img = new Image(-1, 1);
    
    // setpix (normal)
    std::cout << "setpix(2, 2)\n";
    img -> setPix(2, 2, pixy);

    std::cout << "setpix(-2, 2)\n";
    img -> setPix(-2, 2, pixy);

    std::cout << "setpix(-2, -2)\n";
    img -> setPix(-2, -2, pixy);


    // // setpix (excited)
    // std::cout << "setpix(2, 2)\n";
    // img -> setPix(2, 2, excitedPixy);

    // std::cout << "setpix(-2, 2)\n";
    // img -> setPix(-2, 2, excitedPixy);

    // std::cout << "setpix(-2, -2)\n";
    // img -> setPix(-2, -2, excitedPixy);


    // // setpix (depressed)
    // std::cout << "setpix(2, 2)\n";
    // img -> setPix(2, 2, depressedPixy);

    // std::cout << "setpix(-2, 2)\n";
    // img -> setPix(-2, 2, depressedPixy);

    // std::cout << "setpix(-2, -2)\n";
    // img -> setPix(-2, -2, depressedPixy);


    // getpix
    std::cout << "getpix(2, 2)\n";
    garbage = img -> getPix(2, 2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";

    std::cout << "getpix(-2, 2)\n";
    garbage = img -> getPix(-2, 2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";


    std::cout << "getpix(-2, -2)\n";
    garbage = img -> getPix(-2, -2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";



    // dessinerRectangle
    std::cout << "dessinerRectangle(0,0,3,3, pixel)\n";
    img -> dessinerRectangle(0,0,3,3,pixy);

    std::cout << "dessinerRectangle(-1,-1,3,3, pixel)\n";
    img -> dessinerRectangle(-1,-1,3,3,pixy);

    std::cout << "dessinerRectangle(5,5,3,3, pixel)\n";
    img -> dessinerRectangle(5,5,3,3,pixy);

    std::cout << "dessinerRectangle(-5,-5,-3,-3, pixel)\n";
    img -> dessinerRectangle(-5,-5,-3,-3,pixy);

    std::cout << "dessinerRectangle(0,0,0,0, pixel)\n";
    img -> dessinerRectangle(0,0,0,0,pixy);


    std::cout << "==>ok\n[FIN TEST 1]\n";
    // freeeeee
    delete img;
    img = NULL;


    std::cout << "\n=================================\n\n";



    std::cout << "[TEST 2]\n";
    std::cout << "img = new Image(-1, -1)\n";
    img = new Image(-1, -1);
    

    // setpix
    std::cout << "setpix(2, 2)\n";
    img -> setPix(2, 2, pixy);

    std::cout << "setpix(-2, 2)\n";
    img -> setPix(-2, 2, pixy);

    std::cout << "setpix(-2, -2)\n";
    img -> setPix(-2, -2, pixy);


    // // setpix (excited)
    // std::cout << "setpix(2, 2)\n";
    // img -> setPix(2, 2, excitedPixy);

    // std::cout << "setpix(-2, 2)\n";
    // img -> setPix(-2, 2, excitedPixy);

    // std::cout << "setpix(-2, -2)\n";
    // img -> setPix(-2, -2, excitedPixy);


    // // setpix (depressed)
    // std::cout << "setpix(2, 2)\n";
    // img -> setPix(2, 2, depressedPixy);

    // std::cout << "setpix(-2, 2)\n";
    // img -> setPix(-2, 2, depressedPixy);

    // std::cout << "setpix(-2, -2)\n";
    // img -> setPix(-2, -2, depressedPixy);


    // getpix
    std::cout << "getpix(2, 2)\n";
    garbage = img -> getPix(2, 2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";

    std::cout << "getpix(-2, 2)\n";
    garbage = img -> getPix(-2, 2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";


    std::cout << "getpix(-2, -2)\n";
    garbage = img -> getPix(-2, -2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";



    // dessinerRectangle
    std::cout << "dessinerRectangle(0,0,3,3, pixel)\n";
    img -> dessinerRectangle(0,0,3,3,pixy);

    std::cout << "dessinerRectangle(-1,-1,3,3, pixel)\n";
    img -> dessinerRectangle(-1,-1,3,3,pixy);

    std::cout << "dessinerRectangle(5,5,3,3, pixel)\n";
    img -> dessinerRectangle(5,5,3,3,pixy);

    std::cout << "dessinerRectangle(-5,-5,-3,-3, pixel)\n";
    img -> dessinerRectangle(-5,-5,-3,-3,pixy);

    std::cout << "dessinerRectangle(0,0,0,0, pixel)\n";
    img -> dessinerRectangle(0,0,0,0,pixy);



    std::cout << "==>ok\n[FIN TEST 2]\n";
    // freeee !!
    delete img;
    img = NULL;


    std::cout << "\n=================================\n\n";

    std::cout << "[TEST 3]\n";
    std::cout << "img = new Image\n";
    img = new Image;
    

    // setpix
    std::cout << "setpix(2, 2)\n";
    img -> setPix(2, 2, pixy);

    std::cout << "setpix(-2, 2)\n";
    img -> setPix(-2, 2, pixy);

    std::cout << "setpix(-2, -2)\n";
    img -> setPix(-2, -2, pixy);


    // // setpix (excited)
    // std::cout << "setpix(2, 2)\n";
    // img -> setPix(2, 2, excitedPixy);

    // std::cout << "setpix(-2, 2)\n";
    // img -> setPix(-2, 2, excitedPixy);

    // std::cout << "setpix(-2, -2)\n";
    // img -> setPix(-2, -2, excitedPixy);


    // // setpix (depressed)
    // std::cout << "setpix(2, 2)\n";
    // img -> setPix(2, 2, depressedPixy);

    // std::cout << "setpix(-2, 2)\n";
    // img -> setPix(-2, 2, depressedPixy);

    // std::cout << "setpix(-2, -2)\n";
    // img -> setPix(-2, -2, depressedPixy);



    // getpix
    std::cout << "getpix(2, 2)\n";
    garbage = img -> getPix(2, 2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";

    std::cout << "getpix(-2, 2)\n";
    garbage = img -> getPix(-2, 2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";


    std::cout << "getpix(-2, -2)\n";
    garbage = img -> getPix(-2, -2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";



    // dessinerRectangle
    std::cout << "dessinerRectangle(0,0,3,3, pixel)\n";
    img -> dessinerRectangle(0,0,3,3,pixy);

    std::cout << "dessinerRectangle(-1,-1,3,3, pixel)\n";
    img -> dessinerRectangle(-1,-1,3,3,pixy);

    std::cout << "dessinerRectangle(5,5,3,3, pixel)\n";
    img -> dessinerRectangle(5,5,3,3,pixy);

    std::cout << "dessinerRectangle(-5,-5,-3,-3, pixel)\n";
    img -> dessinerRectangle(-5,-5,-3,-3,pixy);

    std::cout << "dessinerRectangle(0,0,0,0, pixel)\n";
    img -> dessinerRectangle(0,0,0,0,pixy);



    std::cout << "==>ok\n[FIN TEST 3]\n";
    // freeee !!
    delete img;
    img = NULL;


    std::cout << "\n=================================\n\n";


    std::cout << "[TEST 4]\n";
    std::cout << "img = new Image(0,0)\n";
    img = new Image(0, 0);
    
    // setpix
    std::cout << "setpix(2, 2)\n";
    img -> setPix(2, 2, pixy);

    std::cout << "setpix(-2, 2)\n";
    img -> setPix(-2, 2, pixy);

    std::cout << "setpix(-2, -2)\n";
    img -> setPix(-2, -2, pixy);


    // // setpix (excited)
    // std::cout << "setpix(2, 2)\n";
    // img -> setPix(2, 2, excitedPixy);

    // std::cout << "setpix(-2, 2)\n";
    // img -> setPix(-2, 2, excitedPixy);

    // std::cout << "setpix(-2, -2)\n";
    // img -> setPix(-2, -2, excitedPixy);


    // // setpix (depressed)
    // std::cout << "setpix(2, 2)\n";
    // img -> setPix(2, 2, depressedPixy);

    // std::cout << "setpix(-2, 2)\n";
    // img -> setPix(-2, 2, depressedPixy);

    // std::cout << "setpix(-2, -2)\n";
    // img -> setPix(-2, -2, depressedPixy);

    // getpix
    std::cout << "getpix(2, 2)\n";
    garbage = img -> getPix(2, 2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";

    std::cout << "getpix(-2, 2)\n";
    garbage = img -> getPix(-2, 2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";


    std::cout << "getpix(-2, -2)\n";
    garbage = img -> getPix(-2, -2);
    std::cout << "> " << (int) garbage.getRouge() << "," << (int) garbage.getVert() << "," << (int) garbage.getBleu() << "\n";


    // dessinerRectangle
    std::cout << "dessinerRectangle(0,0,3,3, pixel)\n";
    img -> dessinerRectangle(0,0,3,3,pixy);

    std::cout << "dessinerRectangle(-1,-1,3,3, pixel)\n";
    img -> dessinerRectangle(-1,-1,3,3,pixy);

    std::cout << "dessinerRectangle(5,5,3,3, pixel)\n";
    img -> dessinerRectangle(5,5,3,3,pixy);

    std::cout << "dessinerRectangle(-5,-5,-3,-3, pixel)\n";
    img -> dessinerRectangle(-5,-5,-3,-3,pixy);

    std::cout << "dessinerRectangle(0,0,0,0, pixel)\n";
    img -> dessinerRectangle(0,0,0,0,pixy);


    std::cout << "==>ok\n[FIN TEST 4]\n";
    // freeeeee
    delete img;
    img = NULL;


}