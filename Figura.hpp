#pragma once


using namespace System::Drawing;

//El objetivo de esta clase es que sea base para jugador y los powers. Solo debe tener lo relacionado a colisiones y quizas dibujado
class Figura {
protected:
	int x, y;
	int speed;
	int width, heigth;

public:
	Figura(int X, int Y) {
		this->x = X;
		this->y = Y;
		speed = 5;
		width = heigth = 10;
	}

	void draw(Graphics^ g) {
		array<Point>^ puntos = {
			Point(x+5,y),
			Point(x,y+10),
			Point(x+10,y+10),
		};
		g->FillPolygon(Brushes::Blue, puntos);
	}
	
};
