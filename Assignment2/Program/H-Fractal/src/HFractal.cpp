/*
 * File: HFractal.cpp
 * ------------------
 * This program draws an H-fractal on the graphics window.int main() {
 */

#include "gwindow.h"

/* Function prototypes */

void drawHFractal(GWindow & gw, double x, double y, double size, int order);

/* Main program */

int main() {
   GWindow gw (600,400);
   gw.setColor("Black");
   gw.setExitOnClose(true);
   double xc = gw.getWidth() / 2;
   double yc = gw.getHeight() / 2;
   drawHFractal(gw, xc, yc, 100, 3);
   return 0;
}

/*
 * Function: drawHFractal
 * Usage: drawHFractal(gw, x, y, size, order);
 * -------------------------------------------
 * Draws a fractal diagram consisting of an H in which each additional
 * fractal layer draws half-size fractals at the four endpoints of each H.
 */

void drawHFractal(GWindow & gw, double x, double y, double size, int order) {
    //Using drawline method to draw the first big H
    gw.drawLine(x-size/2,y-size/2,x-size/2,y+size/2);
    gw.drawLine(x-size/2,y,x+size/2,y);
    gw.drawLine(x+size/2,y-size/2,x+size/2,y+size/2);
    if (order>0){
        // Using the four points to do the recursion steps
        drawHFractal(gw, x-size/2, y-size/2, size/2, order-1);
        drawHFractal(gw, x-size/2, y+size/2, size/2, order-1);
        drawHFractal(gw, x+size/2, y-size/2, size/2, order-1);
        drawHFractal(gw, x+size/2, y+size/2, size/2, order-1);
    }
}
   
