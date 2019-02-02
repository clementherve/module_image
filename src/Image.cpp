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
    this->tab = NULL;
}






// Constructeur de la classe: initialise dimx et dimy (après vérification)
// puis alloue le tableau de pixel dans le tas (image noire)
Image::Image(const unsigned int dimensionX, const unsigned int dimensionY){


    assert(dimensionX >= 0);
    assert(dimensionY >= 0);


    if(dimensionX >= 0 && dimensionY >= 0){
        this -> dimx = dimensionX;
        this -> dimy = dimensionY;

        
    } else {
        this -> dimx = 0;
        this -> dimy = 0;
    }

    const unsigned int dim = dimensionX*dimensionY;
    this -> tab = new Pixel[dim];
}





// Destructeur de la classe: déallocation de la mémoire du tableau de pixels
// et mise à jour des champs dimx et dimy à 0
Image::~Image(){
    delete[] this -> tab;
    this -> tab = NULL;
    this -> dimx = 0;
    this -> dimy = 0;
}



// Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
// la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
Pixel& Image::getPix(const unsigned int x, const unsigned int y) const{

    assert(x >= 0);
    assert(y >= 0);
    assert(y <= this->dimx);
    assert(y <= this->dimy);

    if(x >= 0 && y >= 0 && x < this -> dimx && y < this -> dimy){
        return this -> tab[y * this->dimx + x];
    } else {
        return this -> tab[0]; // wtf am i supposed to do ???????
    }
}




// Mutateur : modifie le pixel de coordonnées (x,y)
void Image::setPix(const unsigned int x, const unsigned int y, const Pixel &couleur){

    assert(x >= 0);
    assert(y >= 0);
    assert(y <= this->dimx);
    assert(y <= this->dimy);

	if(x >= 0 && y >= 0 && x < this -> dimx && y < this -> dimy){
		this -> tab[y * (this->dimx) + x] = couleur;
	}
}



// Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
void Image::dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel &couleur){
    
    assert(Xmin >= 0);
    assert(Ymin >= 0);
    assert(Xmin <= Xmax);
    assert(Ymin <= Ymax);


    int nbCasesX = Xmax - Xmin + 1;
    int nbCasesY = Ymax - Ymin + 1;
    int X;
    int Y = Ymin;
    for (int i = 0; i < nbCasesY; i++){
        X = Xmin;
        for (int j = 0; j < nbCasesX; j++){
            this->setPix(X, Y, couleur);
            X = X + 1;
        }
        Y = Y + 1;
    }
}



// 
void Image::effacer(Pixel &couleur){
    dessinerRectangle(0, 0, this->dimx-1, this->dimy-1, couleur);
}




// a mettre en privé !!!
bool Image::init_fenetre(SDL_Window* &fenetre){

    // on force le pointeur a etre nul 
    // (il n'est pas sensé valoir autre chose a ce stade)
    fenetre = NULL;


    // la fonction d'initialisation renvoit 0 si tout s'est bien passé
    if(SDL_InitSubSystem(SDL_INIT_EVERYTHING) == 0){
        fenetre = SDL_CreateWindow(
                "Module Image", 
                SDL_WINDOWPOS_UNDEFINED, 
                SDL_WINDOWPOS_UNDEFINED, 
                200, 
                200, 
                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

        
        // si Create Window a planté, a un pointeur qui est NULL
        if(fenetre == NULL){
            return false;
        } else {
            return true;
        }

    } else {
        return false;
    }
}



void Image::boucle_fenetre(){

    bool is_running = true;
    SDL_Event e;

    while(is_running){

        while(SDL_PollEvent(&e)){

            if(e.type == SDL_QUIT){
                is_running = false;
            } else if(e.type == SDL_KEYDOWN){
                
                std::string letter = SDL_GetKeyName(e.key.keysym.sym);

                if(letter == "T"){
                    SDL_Log("T");
                } else if(letter == "G"){
                    SDL_Log("G");
                }

                
            }

        }

    }

}



// a mettre en privé !
void Image::detruire_fenetre(SDL_Window* &fenetre){
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}



// 
void Image::afficher(){


    SDL_Window* fenetre = NULL;

    if(init_fenetre(fenetre)){
        std::cout << "fenetre initialisee !\n";


        boucle_fenetre();

        // cette partie est à remplacer par la boucle de gestion d'evenements
        // SDL_Surface* screenSurface = SDL_GetWindowSurface(fenetre);
        // SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF)); 
        // SDL_UpdateWindowSurface(fenetre);
        // SDL_Delay(5000);



        detruire_fenetre(fenetre);
    } else {
        std::cout << "il y a eu un probleme !\n";
    }   
     // SDL goes here

}





// 
void Image::sauver(const std::string& filename) const {
    
    std::ofstream fichier(filename.c_str());
    
    assert(fichier.is_open()); // a remplacer par if(is_open()) ???
    
    fichier << "P3\n";
    fichier << this->dimx << " " << this->dimy << "\n";
    fichier << "255\n";

    for(unsigned int y=0; y<this->dimy; y++){
        
        for(unsigned int x=0; x<this->dimx; x++){
            Pixel& pix = getPix(x,y); // permet d'éviter d'accéder 3 fois au pixel, on y accède une fois, et ensuite on travaille sur une référence (pix)
            fichier << pix.getRouge() << " " << pix.getVert() << " " << pix.getBleu() << " ";
        }

    }


    std::cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}





// 
void Image::ouvrir(const std::string& filename) {
    
    std::ifstream fichier(filename.c_str());
    
    assert(fichier.is_open());
    
    unsigned char r, g, b;
    std::string mot;
    
    this -> dimx = 0;
    this -> dimy = 0;
    
    fichier >> mot >> this->dimx >> this->dimy >> mot;

    std::cout << this->dimx << "; " << this->dimy << "\n";
    
    assert(this->dimx > 0 && this->dimy > 0);
    
    if (tab != NULL){
        delete [] tab;
    }

    tab = new Pixel[this->dimx*this->dimy];
    
    for(unsigned int y=0; y < this->dimy; ++y){
        for(unsigned int x=0; x < this->dimx; ++x){
            fichier >> r >> b >> g;

            std::cout << "(" << x << "," << y << ") = " << (int) r << " " << (int) g << " " << (int) b << "\n";

            (this -> getPix(x,y)).setRouge(r);
            (this -> getPix(x,y)).setVert(g);
            (this -> getPix(x,y)).setBleu(b);
        }
    }
    
    fichier.close();
    std::cout << "Lecture de l'image " << filename << " ... OK\n";
}






// ok
void Image::afficherConsole(){
    std::cout << this->dimx << " " << this->dimy << "\n";
    for(unsigned int y=0; y<this->dimy; y++) {
        for(unsigned int x=0; x<this->dimx; x++) {
            Pixel& pix = this->getPix(x,y);
            std::cout << "[" << (int) pix.getRouge() << " " << (int) pix.getVert() << " " << (int) pix.getBleu() << "]";
        }
        std::cout << "\n";
    }
}




// Effectue une série de tests vérifiant que le module fonctionne et
// que les données membres de l'objet sont conformes
void Image::testRegression(){

    // un pixel utilisé dans les tests
   /* Pixel pixy(5, 5, 5);
    Image* img = NULL;


    std::cout << "[TEST 1] - negatively sized image ==> ";
    img = new Image(-1, 1);
    std::cout << "ok\n";
    
    std::cout << "[TEST 2] - set pix(2, 2) on negatively sized image ==> ";
    img -> setPix(2, 2, pixy);
    std::cout << "ok\n";

    std::cout << "[TEST 3] - draw oversized rectangle ==> ";
    img -> dessinerRectangle(0,0,3,3,pixy);
    std::cout << "ok\n";


    delete img;
    img = NULL;




    std::cout << "[TEST 1] - null sized image ==> ";
    img = new Image(0, 0);
    std::cout << "ok\n";

    
    std::cout << "[TEST 2] - set pix(2, 2) on null sized image ==> ";
    img -> setPix(2, 2, pixy);
    std::cout << "ok\n";


    std::cout << "[TEST 3] - draw oversized rectangle ==> ";
    img -> dessinerRectangle(0,0,3,3,pixy);
    std::cout << "ok\n";

    delete img;
    img = NULL;




    std::cout << "[TEST 1] - default constructor image ==> ";
    img = new Image;
    std::cout << "ok\n";

    
    std::cout << "[TEST 2] - set pix(2, 2) on default image ==> ";
    img -> setPix(2, 2, pixy);
    std::cout << "ok\n";


    std::cout << "[TEST 3] - draw oversized rectangle ==> ";
    img -> dessinerRectangle(0,0,3,3,pixy);
    std::cout << "ok\n";

    delete img;
    img = NULL;*/
}