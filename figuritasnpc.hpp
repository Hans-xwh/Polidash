#pragma once

#include "Figura.hpp"
#include <cstdlib>

using namespace System;
using namespace System::Drawing;

class FiguritasNPC : public Figura
{

private:
	Color colornpc;
	int value;
	int tramo;
 	bool isPowerUp;

public:
	FiguritasNPC(int X, int Y, Color c, bool powerUp, int tramo) : Figura(X, Y), colornpc(c), isPowerUp(powerUp), tramo(tramo){

	value = rand() % 5 + 1;
	shape = Shapes(rand() % 8 + 3);
	dx = dy = 0;

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

    void draw(Graphics^ g) {
        array<Point>^ puntos = damePuntos();
        SolidBrush^ solid = gcnew SolidBrush(colornpc);
        g->FillPolygon(solid, puntos);
        g->DrawPolygon(Pens::Black, puntos);
    }

    int getValue() { return value; }
    bool getIsPowerUp() { return isPowerUp;  }
    Color getColornpc() { return colornpc;  }
    int getTramo() { return tramo; }

    bool fueraPantalla(Graphics^ g) {
        double ANCHO = g->ClipBounds.Width;
        double ALTO = g->ClipBounds.Height;

        return (x + size < 0 || x > ANCHO || y + size < 0 || y > ALTO);
    }

};