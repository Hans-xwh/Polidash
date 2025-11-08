#pragma once

using namespace System::Drawing;

//Tipos de figura
enum Shapes {			//se puede llamar como Shapes(x), x siendo el numero de lados. las posiciones 0-2 quedan vacias.
	TRIANGULO	= 3,	
	CUADRADO	= 4,	
	PENTAGONO	= 5,	
	HEXAGONO	= 6,	
	HEPTAGONO	= 7,
	OCTAGONO	= 8,	
	NONAGONO	= 9,	
	DECAGONO	= 10,	
};

//El objetivo de esta clase es que sea base para jugador y los powers. Solo debe tener lo relacionado a colisiones y quizas dibujado
class Figura {
protected:
	int x, y;
	int speed;
	int size;		//todas las figuras son "cuadradas"
	Shapes shape;

public:
	Figura(int X, int Y, Shapes S = Shapes::TRIANGULO) {	//Default triangulo
		this->x = X;
		this->y = Y;
		speed = 5;
		size = 75;
		shape = S;
	}

	array<Point>^ damePuntos() {	//basado en la figura actual retorna los puntos convertidos a coordenadas globales
		if (shape < 3) {
			shape = TRIANGULO;	//evita dibujar poligonos invalidos
		}

		//Devuelve los puntos en el sentido contrario a las agujas del reloj
		if (shape == TRIANGULO) {
			array<Point>^ p = {
				Point(x + (size / 2), y),
				Point(x, y + (size)),
				Point(x + size, y + size)
			};
			return p;
		} 
		else if(shape == CUADRADO){
			array<Point>^ p = {
				Point(x,y),
				Point(x,y + size),
				Point(x + size, y + size),
				Point(x + size, y),
			};
			return p;
		}
		else if (shape == PENTAGONO) {
			array<Point>^ p = {
				Point(x + (size / 2),y),
				Point(x,y + (size / 2.5)),
				Point(x + (size / 4),y + size),
				Point(x + (size - size / 4),y + size),
				Point(x + size, y + (size / 2.5)),
			};
			return p;
		}
		else if (shape == HEXAGONO) {
			array<Point>^ p = {
				Point(x+(size/4), y),
				Point(x, y+(size/2)),
				Point(x+(size/4), y+size),
				Point(x+size-(size/4), y+size),
				Point(x+size, y + (size/2)),
				Point(x+size-(size/4), y)
			};
			return p;
		}
		else if (shape == HEPTAGONO) {
			array<Point>^ p = {
				Point(x + (size / 2), y),
				Point(x + (size / 6), y + (size / 4)),
				Point(x, y + (2 * size / 3)),
				Point(x + (size / 4), y + size),
				Point(x + size - (size / 4), y + size),
				Point(x + size, y + (2 * size / 3)),
				Point(x + size - (size / 6), y + (size / 4))
			};
			return p;
		}
		else if (shape == OCTAGONO) {
			array<Point>^ p = {
				Point(x+(size/3), y),
				Point(x, y+(size/3)),
				Point(x, y+ (2*size/3)),	//Podria ser (x, y + size - (size/2))
				Point(x+(size/3), y+size),
				Point(x+(2* size/3),y+size),
				Point(x+size, y+(2 * size/3)),
				Point(x+size, y+(size/3)),
				Point(x+(2*size/3),y)

			};
			return p;
		}
	}

	void draw(Graphics^ g) {
		shape = Shapes(8);		//Esta linea solo para pruebas, la forma no se debe fijar aqui

		array<Point>^ puntos = damePuntos();
		g->FillPolygon(Brushes::Aqua, puntos);
		g->DrawPolygon(Pens::Red, puntos);
	}
	
};
