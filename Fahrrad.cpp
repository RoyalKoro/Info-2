#include "Fahrrad.h"



Fahrrad::Fahrrad():Fahrzeug()
{
}

Fahrrad::Fahrrad(const string sName, const double dMaxgeschwindigkeit): Fahrzeug(sName, dMaxgeschwindigkeit)
{
}


Fahrrad::~Fahrrad()
{
}


double Fahrrad::dGeschwindigkeit() const
{
	int iHilfe = (int)p_dGesamtstrecke / 20;//Cast auf int, pro gefahrene 20km
	double dGeschwindigkeit = pow(0.9, iHilfe) * p_dMaxGeschwindigkeit;//0.9^pro gefahrene 20km multipliziert mit der Maxgeschwindigkeit um das langsamer werden der Fahrradfahrer zu simulieren
	if (dGeschwindigkeit < 12) //Geschwindigkeit soll minimal 12km/h betragen
	{
		dGeschwindigkeit = 12;
	}
	return dGeschwindigkeit;// Rückgabe der Geschwindigkeit
}

void Fahrrad::vZeichnen(const Weg * pWeg) const
{
	bZeichneFahrrad(p_sName, pWeg->getName(), p_dAbschnittStrecke / pWeg->getLaenge(), dGeschwindigkeit());//p_dAbschnittStrecke / pWeg->getLaenge() gibt den Anteil des Weg an welches schon gefahren wurde
}
