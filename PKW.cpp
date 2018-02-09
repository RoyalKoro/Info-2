#include "PKW.h"

PKW::PKW()
{
}
/*
PKW::PKW(const string sName, const double dMaxgeschwindigkeit, const double dVerbrauch)
:Fahrzeug(sName, dMaxgeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(55), p_dTankinhalt(55/2)
{

}
*/
PKW::PKW(const string sName, const double dMaxgeschwindigkeit, const double dVerbrauch, double dTankvolumen)
	: Fahrzeug(sName, dMaxgeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen), p_dTankinhalt(dTankvolumen / 2)
{
}


PKW::~PKW()
{
}

void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)//wenn der Tank leer ist wird der Bearbeitungsschritt übersprungen und nur die Abfertigungszeit aktualisiert 
	{
		double dStrecke = p_dGesamtstrecke;// Hilfsvariable zum zwischenspeichern der alten Gesamtstrecke 
		Fahrzeug::vAbfertigung();
		p_dTankinhalt -= p_dVerbrauch / 100 * (p_dGesamtstrecke - dStrecke);//zieht dem Tankinhalt den Verbrauch seit dem letzten Abfertigungsschritt ab
		if (p_dTankinhalt < 0)//Tankinhalt darf nicht kleiner als 0 werden
		{
			p_dTankinhalt = 0;
		}
	}
	else
	{
		double dZeit = dGlobaleZeit - p_dZeit;
		p_dZeit = dGlobaleZeit;
		p_pVerhalten->dStrecke(this, dZeit);
	}
}

double PKW::dTanken(double dMenge)
{
	if (p_dTankinhalt != p_dTankvolumen)//wenn das der Tank voll ist wird dMenge = 0, da nicht getankt wird
	{
		if (dMenge != -1 && (dMenge + p_dTankinhalt) < p_dTankvolumen)//Wenn nicht voll getankt werden soll und die Menge nicht größer als der verfügbare Platz im Tank ist
		{
			p_dTankinhalt += dMenge;
		}
		else
		{
			dMenge = p_dTankvolumen - p_dTankinhalt;//Tankt voll und weißt die Differenz zwischen Tankvolumen und Tankinhalt dMenge zu  
			p_dTankinhalt = p_dTankvolumen;
		}
	}
	else
	{
		dMenge = 0.0;
	}
	return dMenge;//Rückgabe der Menge die getankt wurde

}

void PKW::vAusgabe() const//ruft die Ausgabe der Klasse Fahrzeug auf und gibt der Verbrauch und den Tankinhalt zusätzlich auf
{
	Fahrzeug::vAusgabe();
	cout << setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::right) << "  " << setw(12) << p_dVerbrauch
		<< resetiosflags(ios::left) << setiosflags(ios::right) << " " << setw(12) << p_dTankinhalt;
}

ostream& PKW::ostreamAusgabe(ostream& out) const//ruft die Ausgabe der Klasse Fahrzeug über die Überladung des Operators auf und gibt den Verbrauch und den Tankinhalt zusätzlich aus
{
	Fahrzeug::ostreamAusgabe(out) << setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::right) << "  " << setw(12) << p_dVerbrauch
		<< resetiosflags(ios::left) << setiosflags(ios::right) << " " << setw(12) << p_dTankinhalt;
	return out;
}

istream & PKW::istreamEingabe(istream & in)
{
	Fahrzeug::istreamEingabe(in);
	in >> p_dVerbrauch;
	in >> p_dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
	return in;
}

PKW & PKW::operator=(const PKW& PKWTemp)//Kopie eines PKW, ruft die Fahrzeugzuweisung auf und erweitert mit PKW spezifischen Informationen
{
	Fahrzeug::operator=(PKWTemp);
	p_dVerbrauch = PKWTemp.p_dVerbrauch;
	p_dTankinhalt = PKWTemp.p_dTankinhalt;
	p_dTankvolumen = PKWTemp.p_dTankvolumen;
	return *this;
}

double PKW::dGeschwindigkeit() const
{
	if (p_dTankinhalt == 0)
	{
		return 0;
	}
	if (p_pVerhalten != 0 && p_pVerhalten->dLimit() < p_dMaxGeschwindigkeit && p_pVerhalten->dLimit() != -1)//Gibt das Limit des Wegs zurueck wenn es keine Autobahn ist und das Limit kleiner ist als die Maxgeschwindigkeit des Fahrzeugs, ansonsten die Maxgeschwindiigkeit
	{
		return p_pVerhalten->dLimit();
	}
	else
	{
		return p_dMaxGeschwindigkeit;
	}
}

void PKW::vZeichnen(const Weg * pWeg) const
{
	bZeichnePKW(p_sName, pWeg->getName(), p_dAbschnittStrecke / pWeg->getLaenge(), dGeschwindigkeit(), p_dTankinhalt); //p_dAbschnittStrecke / pWeg->getLaenge() gibt den Anteil des Weg an welches schon gefahren wurde
}

