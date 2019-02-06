#include "Image.h"
 
int main(int argc, char** argv) {



   Image caribou(500, 500);
   caribou.ouvrir("./data/caribou2.ppm");
   caribou.afficher();
   // TEST
   // Image image3(4, 4);

   // Pixel rose (255, 128, 255);
   // image3.dessinerRectangle(1, 1, 2, 2, rose);

   // image3.afficherConsole();
   // image3.sauver("./data/image3.ppm");


   // Image image4;
   // image4.ouvrir("./data/image3.ppm");
   // image4.afficherConsole();

   // Pixel rose (255, 128, 255);
   // image2.dessinerRectangle(0, 0, 2, 2, rose);
   // image2.afficherConsole();
   // FIN TEST


   // Pixel orange (255, 128, 0);
   // Pixel rose (255, 128, 255);
   // Pixel bleu (0, 128, 255);

   // Image image1 (64,48);
   // image1.effacer(orange);
   // image1.dessinerRectangle(10, 5, 25, 10, rose);
   // image1.setPix(2,2,rose);
   // image1.sauver("./data/image1.ppm");
   // image1.afficher(); // memory leaks
 
   // Image image2;
   // image2.ouvrir("./data/image1.ppm");
   // image2.dessinerRectangle(5, 5, 15, 10, bleu);
   // image2.dessinerRectangle(25, 25, 35, 45, bleu);
   // image2.sauver("./data/image2.ppm");
   // image2.afficherConsole();
   

   return 0;    
}