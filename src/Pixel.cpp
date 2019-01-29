#include <iostream>
#include "Pixel.h"


typedef unsigned char uchar;

/**
 * @brief      Initialise un pixel avec les valeurs (0, 0, 0)
 */
Pixel::Pixel():r(0), g(0), b(0){};




/**
 * @brief      Initialise un pixel avec les valeurs passées en paramètre
 *
 * @param[in]  nr    composante rouge du pixel
 * @param[in]  ng    composante verte du pixel
 * @param[in]  nb    composante bleu du pixel
 */
Pixel::Pixel(uchar nr, uchar ng, uchar nb):r(nr), g(ng), b(nb){};




/**
 * @brief      Accesseur de la composante rouge du pixel
 *
 * @return     la valeur de la composante rouge du pixel
 */
uchar Pixel::getRouge() const {
	return this -> r;
}




/**
 * @brief      Gets the vertical.
 *
 * @return     The vertical.
 */
uchar Pixel::getVert() const {
	return this -> g;
}





/**
 * @brief      Gets the bleu.
 *
 * @return     The bleu.
 */
uchar Pixel::getBleu() const {
	return this -> b;
}





/**
 * @brief      Sets the rouge.
 *
 * @param[in]  nr    { parameter_description }
 */
void Pixel::setRouge(uchar nr){
	if(nr >= 0 && nr <= 255){
		this -> r = nr;
	}
}





/**
 * @brief      Sets the vertical.
 *
 * @param[in]  nv    { parameter_description }
 */
void Pixel::setVert (uchar nv){
	if(nv >= 0 && nv <= 255){
		this -> g = nv;
	}
}





/**
 * @brief      Sets the bleu.
 *
 * @param[in]  nb    The number of
 */
void Pixel::setBleu (uchar nb){
	if(nb >= 0 && nb <= 255){
		this -> b = nb;
	}
}