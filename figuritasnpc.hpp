#pragma once

#include "Figura.hpp"

using namespace System;
using namespace System::Drawing;

enum Tipo {
	PowerUp,
	PowerDown
};

class FiguritasNPC : public Figura
{

private:
	Dir direccion;
	Color colornpc;
	int value;
	int tramo;
	Tipo tipo;

public:
	FiguritasNPC(int X, int Y, Dir dir, Color c, Tipo t) : Figura(X, Y), direccion(dir), colornpc(c), tipo(t){
	colornpc = c;
	value = rand() % 5 + 1;

	}
};