#pragma once

#include "FiguraJugador.hpp"
#include "figuritasnpc.hpp"

#include <vector>
using std::vector;

class Juego {
private:
	vector<FiguritasNPC*> figuras;
	Jugador* jugador;
	int tramo;
	int playerColor;

public:
	Juego() {
		Random^ r = gcnew Random();
		jugador = new Jugador(10, 10, r->Next(0, 3));
		playerColor = 1;

		for (int i = 0; i < 3; i++) {
			figuras.push_back(new FiguritasNPC(
				r->Next(50, 300),
				r->Next(50, 300),
				r->Next(40, 85),
				r->Next(0, 3),
				false,	//Esto hay que cambiarlo para que compruebe si es igual al jugador
				1));
			_sleep(16);
		}
	}
	~Juego() {
		delete jugador;
		for (FiguritasNPC* figura : figuras) {
			delete figura;
		}
	}


	void DrawAll(Graphics^ g) {
		Random^ r = gcnew Random();
		//orden de dibujado: Figuras -> Jugador -> Minimapa -> UI

		Brush^ brocha = Brushes::Aqua;

		for (FiguritasNPC* figura : figuras) {
			figura->draw(g);
		}
		jugador->draw(g);
	}

	void Update(Graphics^ g) {

	}

	void KeyDown(Dir d) {

	}

	void keyUp(Dir d) {

	}
};

//compilame esta
