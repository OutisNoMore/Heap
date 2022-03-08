#ifndef PIXEL_H_
#define PIXEL_H_

#include <iostream>

/***********************************************************
* Class pixel
*_________________________________________________________
* This is a custom data type that stores the rgb color
* of a pixel. The distance of the pixel from black is 
* calculated and used to roughly estimate how dark of 
* a shade the color is.
*_________________________________________________________
* INPUTS
*   _red (int)    // IN - red value of color
*   _green (int)  // IN - green value of color
*   _blue (int)   // IN - blue value of color
*   _name (std::string) // IN - color name
*
* POST-CONDITIONS
*   Distance between color and black is calculated.
***********************************************************/
class pixel{
private:
  int _red;   // IN - red value of color
  int _green; // IN - green value of color
  int _blue;  // IN - blue value of color
  double _distance; // IN - measures distance from black (0, 0, 0)
  std::string _color; // IN - common name of color

public:
  /******************************
   ** CONSTRUCTOR & DESTRUCTOR **
   ******************************/

  pixel(): _red(0), _green(0), _blue(0), _distance(0.0), _color("NULL"){};

  pixel(int r, int g, int b, std::string color);

  /***************
   ** ACCESSORS **
   ***************/
  bool operator<(const pixel& p);
  bool operator>(const pixel& p);

/**********************************************************
 *
 * ACCESSOR operator<<(std::ostream& os, const pixel& p);
 *_________________________________________________________
 * This function receives a reference to a stream output
 * operator and a reference to a pixel. The name of the
 * color of the pixel is output.
 *_________________________________________________________
 * PRE-CONDITIONS
 *  os (std::ostream&) // IN - reference to stream output
 *   p (pixel&) // IN - reference to pixel to compare with
 *
 * POST-CONDITIONS
 *   This function will return the name of the
 *   color of the pixel.
 ***********************************************************/
  friend std::ostream& operator<<(std::ostream& os, const pixel& p){
    os << "(" << p._color << ")";
    return os;
  }
};


#endif
