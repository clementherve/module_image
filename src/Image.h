#pragma once

#include <SDL2/SDL.h>  
#include <string>
#include "Pixel.h"

/**
* @brief      Classe 'image': contient les informations d'une image. Une image est représentée par un tableau de Pixel, et chaque pixel est représenté par les trois couleurs primaires : rouge, vert, bleu.
*/
class Image{




private:
Pixel* tab; // le tableau 1D de pixel [use new + delete]
Pixel* noir; // un pixel noir renvoye dans les cas extremes
unsigned int dimx, dimy; // les dimensions de l'image








/**
 * @brief      Initialise une fenetre passée en référence
 *
 * @param      fenetre Un pointeur sur l'objet fenetre
 *
 * @return     True si tout c'est bien passé, false si il y a eu un problème
 */
bool init_fenetre(SDL_Window* &fenetre, SDL_Renderer* &rendu);







/**
 * @brief      ajoute un pixel dans le rendu de l'image (n'affiche rien )
 *
 * @param      rendu  Le rendu de l'image qui sera affiché
 * @param[in]  x      la coordonnée horizontale du pixel sur le rendu
 * @param[in]  y      la coordonnée verticale du pixel sur le rendu
 * @param[in]  pix    la couleur du pixel, encodée par la classe Pixel
 */
void ajoute_pixel(SDL_Renderer* &rendu, const unsigned int x, const unsigned int y, const Pixel &pix);






/**
 * @brief      Génère la boucle d'affichage et de gestion des évènements claviers
 *
 * @param      rendu  le rendu à afficher à l'écran
 */
void boucle_fenetre(SDL_Window* &fenetre, SDL_Renderer* &rendu);






/**
 * @brief      Détruit les objets fenetre et rendu, libère la mémoire
 *
 * @param      fenetre  une référence sur l'objet fenetre
 *
 * @param      rendu  une référence sur l'objet rendu
 */
void detruire_fenetre(SDL_Window* &fenetre, SDL_Renderer* &rendu);




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
 * @param[in]  Xmin     la plus petite coordonnée horizontale
 * @param[in]  Ymin     la plus petite coordonnée verticale
 * @param[in]  Xmax     la plus grande coordonnée horizontale
 * @param[in]  Ymax     la plus grande coordonnée verticale
 * @param[in]  couleur  une couleur encodée par un pixel
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
 * @brief      Affiche dans la console le contenu de l'image stockée en mémoire
 */
void afficherConsole();







/**
 * @brief      effectue des tests de régression sur la classe image
 */
void testRegression();

};
