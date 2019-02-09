#include "Image.h"
 


 // Effectue les tests de regression
int main() {
   Image monImage(4, 4);

   Pixel pix(5, 6, 7);
   monImage.dessinerRectangle(0, 0, 2, 2, pix);
   monImage.testRegression();
   return 0;
}