#include "Image.h"
 
int main() {
   Pixel orange (255, 128, 0);
   Pixel rose (255, 128, 255);
   Pixel bleu (0, 128, 255);
 
   Image image1 (64,48);
   image1.effacer(orange);
   image1.dessinerRectangle(10, 5, 25, 10, rose);
   image1.setPix(2,2,rose);
   image1.sauver("./data/image1.ppm");
 
   Image image2;
   image2.ouvrir("./data/image1.ppm");
   image2.dessinerRectangle(5, 5, 15, 10, bleu);
   image2.dessinerRectangle(25, 25, 35, 45, bleu);
   image2.sauver("./data/image2.ppm");
 
   return 0;    
}