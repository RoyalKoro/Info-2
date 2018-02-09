#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Streckenende.h"
#include "Tankleer.h"


FzgFahren::FzgFahren(Weg* pWeg)
	:FzgVerhalten(pWeg)
{
}


FzgFahren::~FzgFahren()
{
}


double FzgFahren::dStrecke(Fahrzeug * pFahrzeug, double dZeit) const
{
	double dStrecke = pFahrzeug->dGeschwindigkeit() * dZeit;//Strecke die normal zurückgelegt werden würde		 
	if (p_pWeg->getLaenge() == pFahrzeug->getAbschnittsStrecke())
	{
		throw Streckenende(pFahrzeug, p_pWeg);//Ausnahme Streckenende, erstellt eine neue Fahrausnahme Streckenende und beendet die Funktion dStrecke, throw wird in der Abfertigung des Wegs aufgefangen
	}
	if (pFahrzeug->dGeschwindigkeit() == 0)
	{
		throw Tankleer(pFahrzeug, p_pWeg);
	}
	if (p_pWeg->getVirtuelleSchranke() < (pFahrzeug->getAbschnittsStrecke() + dStrecke))//Strecke die noch maximal auf dem Abschnitt zurückgelegt werden kann)
	{
		dStrecke = p_pWeg->getVirtuelleSchranke() - pFahrzeug->getAbschnittsStrecke();
	}
	else
	{
		p_pWeg->setvirtuelleSchranke(pFahrzeug->getAbschnittsStrecke() + dStrecke);
	}
	return dStrecke;
}

