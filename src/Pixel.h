#pragma once


/**
 * @brief      Classe 'pixel': contient les informations d'un pixel
 */
class Pixel{

private:
    unsigned char r, g, b;
    
public :



    // Constructeur par défaut de la classe: initialise le pixel à la couleur noire
    Pixel();

    // Constructeur de la classe: initialise r,g,b avec les paramètres   
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb);

    // Accesseur : récupère la composante rouge du pixel
    unsigned char getRouge() const;

    // Accesseur : récupère la composante verte du pixel
    unsigned char getVert() const;

    // Accesseur : récupère la composante bleue du pixel
    unsigned char getBleu() const;

    // Mutateur : modifie la composante rouge du pixel
    void setRouge(unsigned char nr);

    // Mutateur : modifie la composante verte du pixel
    void setVert (unsigned char nv);

    // Mutateur : modifie la composante bleue du pixel
    void setBleu (unsigned char nb);
      
};