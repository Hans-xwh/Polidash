#pragma once

#include "FiguraJugador.hpp"
#include "figuritasnpc.hpp"

#include <vector>
using std::vector;

class Juego {
private:
	vector<FiguritasNPC*> figuras;
	Jugador* jugador;
	Figura* minifigura;
	int maxFiguras;
	int tramo;
	int transcurrido;
	int maxTiempo;
	int playerColor;
	int limitX, limitY;

public:
	Juego() {
		Random^ r = gcnew Random();
		jugador = new Jugador(700, 10, r->Next(0, 3));
		minifigura = new Figura(10, 10, 10, jugador->getColor());
		jugador->setSpeed(10);
		playerColor = 1;
		maxFiguras = 5;
		tramo = 2;
		transcurrido = 0;
		maxTiempo = 600;
		limitX = 800;
		limitY = 600;

		for (int i = 0; i < maxFiguras; i++) {
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

	//OriginalX, OriginalY, OriginalWidth, OriginalHeight, NewX, NewY, NewWidth, NewHeight
	void MiniFigInRange(int oX, int oY, int oW, int oH, int nX, int nY, int nW, int nH) {	//Esta funcion convierte coordenadas globales a locales basicamente, siendo el "parent" el cuadrado imaginario del tramo del minimapa.
		//Es hora de mapear en rango.
		minifigura->setX(nX + (float(oX) / float(oW)) * nW);
		minifigura->setY(nY + (float(oY) / float(oH)) * nH);
	}

	void DrawAll(Graphics^ g) {
		Random^ r = gcnew Random();
		//orden de dibujado: Figuras -> Jugador -> Minimapa -> UI

		switch (tramo) {
		case 1:
			g->Clear(Color::Lavender);
			break;
		case 2:
			g->Clear(Color::LightCyan);
			break;
		case 3:
			g->Clear(Color::LightGreen);
			break;
		}

		Brush^ brocha = Brushes::Aqua;

		for (FiguritasNPC* figura : figuras) {
			figura->draw(g);
		}
		jugador->draw(g);

		//Minimapa
		g->FillRectangle(Brushes::White, 978, 12, 289, 572);	//Minimapa bordes
		g->DrawRectangle(Pens::Black, 978, 12, 289, 572);

		switch (tramo) {
		case 1:
			g->FillRectangle(Brushes::Lavender, 1006, 21, 249, 60);

			MiniFigInRange(transcurrido, jugador->getY(),
				maxTiempo, g->VisibleClipBounds.Height,
				1006, 21, 249 - 10, 60);		//el -10 es para que no se salga del borde
			break;
		case 2:
			g->FillRectangle(Brushes::LightCyan, 1185, 87, 70, 354);

			MiniFigInRange(jugador->getX(), transcurrido,
				g->VisibleClipBounds.Width - (g->VisibleClipBounds.Width - 978), maxTiempo,
				1185, 87, 70, 354-10);
			break;
		}

		//bordes de todos, incluso inactivos
		g->DrawRectangle(Pens::Black, 1006, 21, 249, 60);	//Tramo 1
		g->DrawRectangle(Pens::Black, 1185,87,70,354);	//Tramo 2
		g->DrawRectangle(Pens::Black, 1006, 447,249,60 );	//Tramo 3

		minifigura->draw(g);
	}

	float Update(Graphics^ g) {
		Random^ r = gcnew Random();
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
					minifigura->setLados(jugador->getLados());
					if (jugador->getLados() > 10) {
						jugador->setLados(3);		//Aqui codigo de victoria instantanea
					}
				}
				else{
					jugador->SumaNum(-figura->getNum());
					jugador->setLados(jugador->getLados() - 1);
					minifigura->setLados(jugador->getLados());
				}

				delete figura;
				figuras.erase(figuras.begin() + i);
			}

			while (figuras.size() < maxFiguras) {
				figuras.push_back(new FiguritasNPC(
					r->Next(50, 300),
					r->Next(50, 300),
					r->Next(40, 85),
					r->Next(0, 3),
					false,	//Esto hay que cambiarlo para que compruebe si es igual al jugador
					1));
			}
		}

		transcurrido += 1;
		return (float(transcurrido) / float(maxTiempo)) * 100;
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
