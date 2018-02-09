#pragma once
#include "Fahrzeug.h"
#include "SimuClient.h"
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();//Standartkonstruktor
	Fahrrad(const string sName, const double dMaxgeschwindigkeit);//Konstruktor mit Zuweisung des Namens und der MaxGeschwindigkeit
	virtual ~Fahrrad();//Destruktor
	virtual double dGeschwindigkeit() const;//Liefert die aktuelle Geschwindigkeit des Fahrrads zurück
	virtual void vZeichnen(const Weg* pWeg) const;//Zeichnet ein Fahrrad-Objekt in der Grafikausgabe
};

