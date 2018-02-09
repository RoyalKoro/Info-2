#include "FzgParken.h"
#include "Fahrzeug.h"
#include "Losfahren.h"

FzgParken::FzgParken(Weg * pWeg, double dStartzeitpunkt)
	:FzgVerhalten(pWeg), p_dStartzeitpunkt(dStartzeitpunkt)
{
}

FzgParken::~FzgParken()
{
}

double FzgParken::dStrecke(Fahrzeug * pFahrzeug, double dZeit) const
{
	if (p_dStartzeitpunkt <= dGlobaleZeit)// Startzeitpunkt wird erreicht
	{
		throw Losfahren(pFahrzeug, p_pWeg);//erstellt eine Fahrausnahme Losfahren und beendet dStrecke, throw wird in der Abfertigung des Wegs aufgefangen
	}
	else
	{
		return 0.0;
	}
}


