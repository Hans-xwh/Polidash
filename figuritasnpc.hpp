#pragma once

#include "Figura.hpp"
#include <cstdlib>

using namespace System;
using namespace System::Drawing;

class FiguritasNPC : public Figura
{

private:
	int tramo;
 	bool isPowerUp;

public:
    FiguritasNPC(int X, int Y, int S, int C, bool powerUp, int tramo) : Figura(X, Y, S, C) {
        Random^ r = gcnew Random();
        isPowerUp = powerUp;
        this->tramo = tramo;
        numero = r->Next(1, 5);
        shape = Shapes(r->Next(3, 10));
        dx = 1; dy = 0;
        size = S;
    }

    void autoMove() override {
        /*switch (tramo) {
        case 1:
            dx = speed;
            dy = 0;
            break;
        case 2:
            dx = 0;
            dy = speed;
            break;
        case 3:
            dx = -speed;
            dy = 0;
            break;
        default:
            dx = speed;
            dy = 0;
            break;
        }*/
        x += dx * speed;
        y += dy * speed;
    }

    bool getIsPowerUp() { return isPowerUp;  }
    int getTramo() { return tramo; }

    bool fueraPantalla(Graphics^ g) {
        double ANCHO = g->ClipBounds.Width;
        double ALTO = g->ClipBounds.Height;

        return (x + size < 0 || x > ANCHO || y + size < 0 || y > ALTO);
    }

};