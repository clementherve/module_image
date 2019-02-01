#pragma once


/**
* @brief      Classe 'pixel': contient les informations d'un pixel. Un pixel est composé de trois entiers positifs, compris entre 0 et 255: une composante Rouge, une composante verte et une composante bleu.
*/
class Pixel{

private:
unsigned char r, g, b;

public :



/**
* @brief      Initialise un pixel avec les valeurs (0, 0, 0)
*/
Pixel();
  



/**
 * @brief      Initialise un pixel avec les valeurs passées en paramètre
 *
 * @param[in]  nr    composante rouge du pixel
 * @param[in]  ng    composante verte du pixel
 * @param[in]  nb    composante bleu du pixel
 */
Pixel(unsigned char nr, unsigned char ng, unsigned char nb);






/**
 * @brief      Accesseur de la composante rouge du pixel
 *
 * @return     Retourne la valeur de la composante rouge du pixel (entier positif compris entre 0 et 255)
 */
unsigned char getRouge() const;







/**
 * @brief      Accesseur de la composante verte du pixel
 *
 * @return     Retourne la valeur de la composante verte du pixel (entier positif compris entre 0 et 255)
 */
unsigned char getVert() const;






/**
 * @brief      Accesseur de la composante bleu du pixel
 *
 * @return     Retourne la valeur de la composante bleu du pixel (entier positif compris entre 0 et 255)
 */
unsigned char getBleu() const;




/**
 * @brief      Donne la valeur passée en paramètre à la composante rouge du pixel
 *
 * @param[in]  nr    Entier (entre 0 et 255) représentant la composante rouge du pixel
 */
void setRouge(unsigned char nr);






/**
 * @brief      Donne la valeur passée en paramètre à la composante verte du pixel
 *
 * @param[in]  nr    Entier (entre 0 et 255) représentant la composante verte du pixel
 */
void setVert (unsigned char nv);







/**
 * @brief      Donne la valeur passée en paramètre à la composante bleu du pixel
 *
 * @param[in]  nr    Entier (entre 0 et 255) représentant la composante bleu du pixel
 */
void setBleu (unsigned char nb);
  


};