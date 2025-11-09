#pragma once

#include "Figura.hpp"

enum Tramo {
    t1 = 1,
    t2,
    t3
};

class Jugador : public Figura {

private:
    int tramo;

public:
	Jugador(int X, int Y, int C, int T = 1) : Figura(X, Y, 75, C, Shapes::TRIANGULO), tramo(T) {
        dx = dy = 0;

	}
    void mover(Dir tecla) {
        dx = 0; dy = 0;

        //t1 y t3 van al mismo lao
        switch (tramo) {
        case t1:
        case t3:
            dx = 0;
            if (tecla == ARRIBA) {
                dy = -1;
            }
            else if (tecla == ABAJO) {
                dy = 1;
            }
            break;
        case t2:
            dy = 0;
            if (tecla == IZQUIERDA) {
                dx = -1;
            }
            else if (tecla == DERECHA) {
                dx = 1;
            }
            break;
        }
    }

    void autoMove(int lx, int ly) {
        if (x + (dx * speed) > 0 && x + (dx * speed) + size < lx) {
            x += dx * speed;
        }
        if (y + (dy * speed) > 0 && y + (dy * speed) + size < ly) {
            y += dy * speed;
        }
    }

    void bounce() {
		dx = -dx;
		dy = -dy;
    }

	void setTramo(int T) { tramo = T; }

};

