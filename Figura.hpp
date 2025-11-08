#pragma once

using namespace System::Drawing;

//Direcciones
enum Dir {
	ARRIBA,
	ABAJO,
	IZQUIERDA,
	DERECHA,
};

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
	int dx, dy;
	int speed;	//Quiza no se usa
	int size;		//todas las figuras son "cuadradas"
	int numero;
	Shapes shape;

public:
	Figura(int X, int Y, int T=200, Shapes S = Shapes::TRIANGULO) {	//Default triangulo de 200
		this->x = X;
		this->y = Y;
		speed = 5;
		size = T;
		shape = S;
		numero = 0;
	}

	array<Point>^ damePuntos() {	//basado en la figura actual retorna los puntos convertidos a coordenadas globales
		if (shape < 3 || shape>10) {
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
		else if (shape == NONAGONO) {
			array<Point>^ p = {
				Point(x + (size / 2),y),
				Point(x + (size / 5), y + (size / 6)),
				Point(x, y + (size / 2)),
				Point(x + (size / 8), y + (size / 1.25)),
				Point(x + (size / 3), y + size),
				Point(x + size - (size / 3), y + size),
				Point(x + size - (size / 8), y + ( size / 1.25)),
				Point(x + size, y + (size / 2)),
				Point(x + size - (size / 5), y + (size / 6))
			};
			return p;
		}
		else if (shape == DECAGONO){
			array<Point>^ p = {
				Point(x+(size/2), y),
				Point(x+(size/5),y+(size/8)),
				Point(x, y+(size/2.75)),
				Point(x, y + size -(size/2.75)),
				Point(x + (size/5), y+size-(size/8)),
				Point(x+ (size/2), y+size),
				Point(x+ size-(size/5), y + size-(size/8)),
				Point(x + size, y + size - (size / 2.75)),
				Point(x + size, y + (size / 2.75)),
				Point(x + size - (size / 5), y + (size / 8)),
			};
			return p;
		}
	}

	void draw(Graphics^ g) {
		//shape = Shapes(10);		//Esta linea solo para pruebas, la forma no se debe fijar aqui

		array<Point>^ puntos = damePuntos();
		g->FillPolygon(Brushes::Aqua, puntos);
		g->DrawPolygon(Pens::Red, puntos);

		//Numero interior
		if (numero >= 0) {
			g->DrawString(numero.ToString(), gcnew Font("Arial", size / 8), Brushes::Black, Rectangle(x + (size/2)-(size/10), y + (size / 2)- (size / 10), size / 8, size / 8 + 10));
		}
	}

	virtual void autoMove() {
		//codigo de movimiento automatico ahora,
	}

	void setSpeed(int s) { speed = s; }
	void setDx(int DX) { dx = DX; }
	void setDy(int DY) { dy = DY; }
	void setSize(int S) { size = S; }
	void setNumero(int N) { numero = N; }
	void SumaNum(int N) { numero += N; }
	

	int getX() {return x;}
	int getY() { return y; }
	int getNum() { return numero; }

	Rectangle getRect() {
		return Rectangle(x, y, size, size);
	}

};
