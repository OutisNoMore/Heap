#include "Pixel.h"

/**********************************************************
 *
 * CONSTRUCTOR pixel
 *_________________________________________________________
 * This constructor receives rgb values and the name of
 * the color.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need pre-defined values:
 *    r (int) // IN - red value of color
 *    g (int) // IN - green value of color
 *    b (int) // IN - blue value of color
 *    color (Std::string) // IN - name of color
 *
 * POST-CONDITIONS
 *   This function will set all data to the given values.
 *   The distance of the color from black is also calculated.
 ***********************************************************/
  pixel::pixel(int r, int g, int b, std::string color){
    _red = r;
    _green = g;
    _blue = b;
    _distance = r*r + g*g + b*b;
    _color = color;
  } 

  /***************
   ** ACCESSORS **
   ***************/

/**********************************************************
 *
 * ACCESSOR operator<(const pixel& p);
 *_________________________________________________________
 * This function receives a reference to a pixel and
 * compares the distances. True is returned if the calling
 * pixel is darker.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   p (pixel&) // IN - reference to pixel to compare with
 *
 * POST-CONDITIONS
 *   This function will return true if the calling pixel is
 *   closer to black, or darker than the other pixel.
 ***********************************************************/
  bool pixel::operator<(const pixel& p){
    return this->_distance < p._distance;
  }

  
/**********************************************************
 *
 * ACCESSOR operator>(const pixel& p);
 *_________________________________________________________
 * This function receives a reference to a pixel and
 * compares the distances. True is returned if the calling
 * pixel is lighter.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   p (pixel&) // IN - reference to pixel to compare with
 *
 * POST-CONDITIONS
 *   This function will return true if the calling pixel is
 *   farther to black, or lighter than the other pixel.
 ***********************************************************/
  bool pixel::operator>(const pixel& p){
    return this->_distance > p._distance;
  }  


