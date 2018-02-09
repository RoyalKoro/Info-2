#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Kreuzung.h"
using namespace std;
class Welt
{
public:
	Welt();
	virtual ~Welt();
	void vEinlesen(istream& in);
	void vEinlesenMitGrafik(istream& in);
	void vSimulation();
	void vZeichnen();
	ostream& ostreamAusgabe(ostream& out) const;
private:
	list<Kreuzung*> p_pKreuzungen;
};
ostream& operator<<(ostream& out, const Welt& w);//Überladung des << Operators
