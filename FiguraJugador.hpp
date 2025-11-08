#pragma once

#include "Figura.hpp"
enum Tramo {
    t1 = 1,
    t2,
    t3
};

class Jugador : public Figura {

private:
    Tramo t;

public:
	Jugador(int X, int Y, Tramo tInicial = t1) : Figura(X, Y, 50, Shapes::TRIANGULO), t(tInicial) {

        dx = dy = 0;

	}
    void mover(Dir tecla) {
        dx = 0; dy = 0;

        //t1 y t3 van al mismo lao
        switch (t) {
        case t1:
        case t3:
            if (tecla == ARRIBA) {
                dy = -speed;
            }
            else if (tecla == ABAJO) {
                dy = speed;
            }
            break;
        case t2:
            if (tecla == IZQUIERDA) {
                dx = -speed;
            }
            else if (tecla == DERECHA) {
                dx = speed;
            }
            break;
        }
    }

    void autoMove() override {
        x += dx;
        y += dy;
    }

};

