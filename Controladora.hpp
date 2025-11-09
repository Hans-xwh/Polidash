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
		jugador = new Jugador(700, 10, r->Next(0, 3));
		jugador->setSpeed(10);
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
		//primero hay que mover todo
		jugador->autoMove();
		
		for (FiguritasNPC* figura : figuras) {
			figura->autoMove();
		}

		//luego comprobar colisiones
		for (int i = 0; i < figuras.size(); i++) {
			FiguritasNPC* figura = figuras[i];
			Rectangle playerCollider = jugador->getRect();

			if (playerCollider.IntersectsWith(figura->getRect())) {	//si el jugador intersecta con la figura
				if(figura->getColor() == jugador->getColor()){
					jugador->SumaNum(figura->getNum());
					jugador->setLados(jugador->getLados() + 1);
					if (jugador->getLados() > 10) {
						jugador->setLados(3);		//Aqui codigo de victoria instantanea
					}
				}
				else{
					jugador->SumaNum(-figura->getNum());
					_sleep(100);
					jugador->setLados(jugador->getLados() - 1);
				}

				delete figura;
				figuras.erase(figuras.begin() + i);
			}
		}
	}

	void KeyDown(Dir d) {
		switch (d) {
		case ARRIBA:
			jugador->mover(ARRIBA);
			break;
		case ABAJO:
			jugador->mover(ABAJO);
			break;
		case IZQUIERDA:
			jugador->mover(IZQUIERDA);
			break;
		case DERECHA:
			jugador->mover(DERECHA);
			break;
		}
	}

	void keyUp(Dir d) {
		jugador->mover(NADA);
	}
};

//compilame esta
