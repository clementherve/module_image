#pragma once
#include <string>
#include "Pixel.h"

/**
* @brief      Classe 'image': contient les informations d'une image. Une image est représentée par un tableau de Pixel, et chaque pixel est représenté par les trois couleurs primaires : rouge, vert, bleu.
*/
class Image{

private:
Pixel* tab; // le tableau 1D de pixel [use new + delete]
unsigned int dimx, dimy; // les dimensions de l'image

public:


/**
 * @brief      Construit une image de dimension (0,0) mais n'alloue pas de mémoire sur le tas
 */
Image();



/**
 * @brief      Construit une image de dimension (dimensionX,dimensionY) et alloue de la mémoire sur le tas en conséquence
 *
 * @param[in]  dimensionX  La largeur de l'image
 * @param[in]  dimensionY  La hauteur de l'image
 */
Image(const unsigned int dimensionX, const unsigned int dimensionY);


/**
 * @brief      Détruit le tableau de pixel, met le pointeur à NULL et les dimensions de l'image à 0
 */
~Image();


/**
 * @brief      Renvoie le pixel de l'image présent aux coordonnées (x,y), et renvoie un pixel noir dans le cas contraire
 *
 * @param[in]  x     coordonnée x du pixel
 * @param[in]  y     coordonnée y du pixel
 *
 * @return     Le pixel correspondant
 */
Pixel& getPix(const unsigned int x, const unsigned int y) const;




/**
 * @brief      Modifie le pixel aux coordonnées (x,y) passées en paramètre en lui donnant la couleur "couleur"
 *
 * @param[in]  x        entier non signé
 * @param[in]  y        entier non signé
 * @param[in]  couleur  Pixel de couleur (r,g,b)
 */
void setPix(const unsigned int x, const unsigned int y, const Pixel &couleur);




/**
 * @brief      Dessine un rectangle dans l'image des dimensions passées en paramètres et de la couleur du pixel passé en paramètre
 *
 * @param[in]  Xmin     The xmin
 * @param[in]  Ymin     The ymin
 * @param[in]  Xmax     The xmax
 * @param[in]  Ymax     The ymax
 * @param[in]  couleur  The couleur
 */
void dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel &couleur);




/**
 * @brief      Efface l'image en remplissant le tableau par la couleur "couleur" passée en paramètre
 *
 * @param      couleur  la couleur [Pixel(r,g,b)] avec laquelle l'écran sera effacé
 */
void effacer(Pixel &couleur);








//
// @brief      Affiche l'image à l'écran
//
void afficher();






/**
 * @brief      Sauve l'image dans le répertoire data/
 *
 * @param[in]  filename  Le nom du fichier dans lequel sauvegarder l'image
 */
void sauver(const std::string& filename) const;







/**
 * @brief      Ouvre l'image dont le chemin est spécifié en paramètre et 
 *
 * @param[in]  filename  Le nom du fichier que l'on doit ouvrir
 */
void ouvrir(const std::string& filename);



/**
 * @brief      Affiche dans la console
 */
void afficherConsole();


/**
 * @brief      effectue des tests de régression sur la classe image
 */
void testRegression();

};
