#include <SDL2/SDL.h>
#include <iostream>
// #include <stdlib.h>

// bool initialisation(SDL_Window* window, const int &width, const int &height){
	
// 	// on initialise SDL. SDL_InitSubSystem retourne 0 en cas de succès
// 	if(SDL_InitSubSystem(SDL_INIT_EVERYTHING) == 0){

// 		// on initialise la fenêtre
// 		// SDL_WINDOWPOS_UNDEFINED est utilisé pour spécifier où la fenêtre surgit à l'écran (balec)
// 		window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

// 		// si le pointeur est toujours null, il y a eu une erreur.
// 		if(window == NULL){
// 			std::cerr << "Erreur lors de la création de la fenêtre\n";
// 			std::cerr << SDL_GetError() << std::endl; // SDL_GetError affiche l'erreur exacte qui à causé le crash
// 			return false;
// 		}

// 		return true;
// 	} else {
// 		std::cerr << "Erreur lors de l'initialisation de SDL\n";
// 		std::cerr << SDL_GetError() << std::endl;
// 		return false;
// 	}
// }

int main(int argc, char* args[]){

	if(SDL_InitSubSystem(SDL_INIT_EVERYTHING) == 0){
		SDL_Window* window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 290, 290, SDL_WINDOW_SHOWN);
		if(window == NULL){
			std::cerr << "Erreur lors de la création de la fenêtre\n";
			std::cerr << SDL_GetError() << std::endl; // SDL_GetError affiche l'erreur exacte qui à causé le crash
		}


		SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF)); 


		SDL_UpdateWindowSurface(window);




		// 
		SDL_Delay(5000);
		SDL_DestroyWindow(window);
		SDL_Quit();

	} else {
		std::cerr << "Erreur lors de l'initialisation de SDL\n";
		std::cerr << SDL_GetError() << std::endl;
	}

	return 0;
}
