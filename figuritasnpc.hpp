#pragma once

#include "Figura.hpp"
#include <cstdlib>

using namespace System;
using namespace System::Drawing;

class FiguritasNPC : public Figura
{

private:
	int value;
	int tramo;
 	bool isPowerUp;

public:
    FiguritasNPC(int X, int Y,int S, bool powerUp, int tramo) : Figura(X, Y, S){
        Random^ r = gcnew Random();
        isPowerUp = powerUp;
        this->tramo = tramo;
        value = r->Next(0, 9);
        shape = Shapes(r->Next(3, 10));
	    dx = dy = 0;
        size = S;
	}

    void autoMove() override {
         switch (tramo) {
        case 1:
            dx = speed;
            dy = 0;
            break;
        case 2:
            dx = 0;
            dy = -speed;
            break;
        case 3:
            dx = -speed;
            dy = 0;
            break;
        default:
            dx = speed;
            dy = 0;
            break;
         }
        x += dx;
        y += dy;
    }

    /*void draw(Graphics^ g) {    //No me implementes otra funcion draw, no es necesaria. *Emoji calavera*
        array<Point>^ puntos = damePuntos();
        SolidBrush^ solid = gcnew SolidBrush();
        g->FillPolygon(solid, puntos);
        g->DrawPolygon(Pens::Black, puntos);
    }*/

    int getValue() { return value; }
    bool getIsPowerUp() { return isPowerUp;  }
    int getTramo() { return tramo; }

    bool fueraPantalla(Graphics^ g) {
        double ANCHO = g->ClipBounds.Width;
        double ALTO = g->ClipBounds.Height;

        return (x + size < 0 || x > ANCHO || y + size < 0 || y > ALTO);
    }

};