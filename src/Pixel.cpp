#include <iostream>
#include "Pixel.h"



/**
 * @brief      Initialise un pixel avec les valeurs (0, 0, 0)
 */
Pixel::Pixel():r(0), g(0), b(0){
	std::cout << "[PIXEL] noir initialise\n";
};




/**
 * @brief      Initialise un pixel avec les valeurs passées en paramètre
 *
 * @param[in]  nr    composante rouge du pixel
 * @param[in]  ng    composante verte du pixel
 * @param[in]  nb    composante bleu du pixel
 */
Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb):r(nr), g(ng), b(nb){
	std::cout << "[PIXEL] initialise\n";
};




/**
 * @brief      Accesseur de la composante rouge du pixel
 *
 * @return     la valeur de la composante rouge du pixel
 */
unsigned char Pixel::getRouge() const {
	return this -> r;
}




/**
 * @brief      Gets the vertical.
 *
 * @return     The vertical.
 */
unsigned char Pixel::getVert() const {
	return this -> g;
}





/**
 * @brief      Gets the bleu.
 *
 * @return     The bleu.
 */
unsigned char Pixel::getBleu() const {
	return this -> b;
}





/**
 * @brief      Sets the rouge.
 *
 * @param[in]  nr    { parameter_description }
 */
void Pixel::setRouge(unsigned char nr){
	if(nr >= 0 && nr <= 255){
		this -> r = nr;
	}
}





/**
 * @brief      Sets the vertical.
 *
 * @param[in]  nv    { parameter_description }
 */
void Pixel::setVert (unsigned char nv){
	if(nv >= 0 && nv <= 255){
		this -> g = nv;
	}
}





/**
 * @brief      Sets the bleu.
 *
 * @param[in]  nb    The number of
 */
void Pixel::setBleu (unsigned char nb){
	if(nb >= 0 && nb <= 255){
		this -> b = nb;
	}
}