#pragma once

#include "FiguraJugador.hpp"
#include "figuritasnpc.hpp"


#include <vector>

using std::vector;
using namespace System::Drawing;

class Juego {
private:
	vector<FiguritasNPC*> figuras;
	Jugador* jugador;
	Figura* minifigura;
	int maxFiguras;
	int tramo;
	int transcurrido;
	int maxTiempo;
	int autoCurrent, autoMax;
	int figurasPlayerColor;
	int limitX, limitY;

public:
	Juego() {
		Random^ r = gcnew Random();
		jugador = new Jugador(40, 10, r->Next(0, 3));
		minifigura = new Figura(10, 10, 10, jugador->getColor());
		jugador->setSpeed(10);
		figurasPlayerColor = 0;
		maxFiguras = 5;
		tramo = 1;
		jugador->setTramo(tramo);
		transcurrido = 0;
		maxTiempo = 600;
		autoCurrent = autoMax = 0;
		limitX = 980;
		limitY = 593;

		for (int i = 0; i < maxFiguras; i++) {
			/*FiguritasNPC* f = new FiguritasNPC(
				-r->Next(10,200),
				r->Next(50, 300),
				r->Next(40, 85),
				r->Next(0, 3),
				false,	//Esto hay que cambiarlo para que compruebe si es igual al jugador
				1);
			figuras.push_back(f);
			if (f->getColor() == jugador->getColor()) {
				figurasPlayerColor++;
			}
			if (tramo != 3 && jugador->getLados() >= 9) {
				while (f->getColor() == jugador->getColor()) {
					f->setColor(r->Next(0, 3));
				}
			}*/
			figuras.push_back(generaFigura());
			_sleep(16);
		}
	}
	~Juego() {
		delete minifigura;
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

	FiguritasNPC* generaFigura() { //retorna una figura apropiada para el tramo actual
		Random^ r = gcnew Random();
		FiguritasNPC* f;

		switch (tramo) {
		case 1:
			f = new FiguritasNPC(
				r->Next(limitX, limitX+100),
				r->Next(50, 500),
				r->Next(40, 85),
				r->Next(0, 3),
				false,	//Esto hay que cambiarlo para que compruebe si es igual al jugador
				1);
			f->setDx(-1);
			f->setDy(0);
			break;
		case 2:
			f = new FiguritasNPC(
				r->Next(10, limitX-85),
				limitY + r->Next(10, 75),
				r->Next(40, 85),
				r->Next(0, 3),
				false,	//Esto hay que cambiarlo para que compruebe si es igual al jugador
				1);
			f->setDx(0);
			f->setDy(-1);
			break;
		case 3:
			f = new FiguritasNPC(
				-75,
				r->Next(50, 300),
				r->Next(40, 85),
				r->Next(0, 3),
				false,	//Esto hay que cambiarlo para que compruebe si es igual al jugador
				1);
			f->setDx(1);
			f->setDy(0);
			break;
		default:
			f = new FiguritasNPC(
				-75,
				r->Next(50, 300),
				r->Next(40, 85),
				r->Next(0, 3),
				false,	//Esto hay que cambiarlo para que compruebe si es igual al jugador
				1);
			break;
		}		

		//Hay que cuidar que no sea del mismo color que el jugador si se han alcanzado 9 lados 
		if (f->getColor() == jugador->getColor()) {
			figurasPlayerColor++;
		}

		if (tramo != 3 && figurasPlayerColor + jugador->getLados() > 9) {
			while (f->getColor() == jugador->getColor()) {
				f->setColor(r->Next(0, 3));
			}
			figurasPlayerColor--;
		}

		f->setSpeed(r->Next(5, 10));
		return f;
	}

	void cambioTramo() {
		Random^ r = gcnew Random();
		tramo++;

		jugador->setTramo(tramo);
		if (tramo == 2) {
			jugador->setX(limitX / 2);
			jugador->setY(40);
		}
		else {
			jugador->setX(limitX - 150);
			jugador->setY(limitY / 2);
		}
		transcurrido = 0;
		//Limpiar figuras y regenerar
		for (FiguritasNPC* figura : figuras) {
			delete figura;
		}
		figuras.clear();
		figurasPlayerColor = 0;

		while (figuras.size() < maxFiguras) {
			figuras.push_back(generaFigura());
			_sleep(16);
		}

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
				1006, 21, 249 - 10, 60-5);		//el -10 es para que no se salga del borde
			break;

		case 2:
			g->FillRectangle(Brushes::LightCyan, 1185, 87, 70, 354);

			MiniFigInRange(jugador->getX(), transcurrido,
				g->VisibleClipBounds.Width - (g->VisibleClipBounds.Width - 978), maxTiempo,	//Se tiene que tener en cuenta el offset por la interfaz
				1185, 87, 70-7, 354-10);
			break;

		case 3:
			g->FillRectangle(Brushes::LightGreen, 1006, 447, 249, 60);

			MiniFigInRange(maxTiempo - transcurrido, jugador->getY(),
				maxTiempo, g->VisibleClipBounds.Height,
				1006, 447, 249-10, 60-5);
			break;
		}

		//bordes de todos, incluso inactivos
		g->DrawRectangle(Pens::Black, 1006, 21, 249, 60);	//Tramo 1
		g->DrawRectangle(Pens::Black, 1185,87,70,354);	//Tramo 2
		g->DrawRectangle(Pens::Black, 1006, 447,249,60 );	//Tramo 3

		minifigura->draw(g);
	}

	int Update(Graphics^ g) {
		Random^ r = gcnew Random();

		if (tramo > 3) {
			return 2;	//Derrota
		};

		//primero hay que mover todo

		jugador->autoMove(limitX, limitY);
		
		for (int i = 0; i < figuras.size(); i++) {
			FiguritasNPC* figura = figuras[i];
			figura->autoMove();

			//comprobar si se sale de pantalla
			
			if (tramo == 3 && figura->getX() > 980) {
				if (figura->getColor() == jugador->getColor()) figurasPlayerColor--;
				delete figura;
				figuras.erase(figuras.begin() + i);
			}
			else if(tramo == 2 && figura->getY() < -10 - figura->getSize()){
				if (figura->getColor() == jugador->getColor()) figurasPlayerColor--;
				delete figura;
				figuras.erase(figuras.begin() + i);
			}
			else if (tramo == 1 && figura->getX() + figura->getSize() < 0) {
				if (figura->getColor() == jugador->getColor()) figurasPlayerColor--;
				delete figura;
				figuras.erase(figuras.begin() + i);
			}

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
					if (jugador->getLados() >= 10) {
						return 1;		//victoria
					}
				}
				else{
					jugador->SumaNum(-figura->getNum());
					jugador->setLados(jugador->getLados() - 1);
					minifigura->setLados(jugador->getLados());
				}

				if(figura->getColor() == jugador->getColor()){
					figurasPlayerColor--;
				}
				delete figura;
				figuras.erase(figuras.begin() + i);
				i--;
			}
		}

		while (figuras.size() < maxFiguras) {
			figuras.push_back(generaFigura());
		}

		transcurrido += 1;
		if (transcurrido >= maxTiempo) cambioTramo();

		//return (float(transcurrido) / float(maxTiempo)) * 100;
		return 0;	//continua
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
