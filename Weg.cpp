#include "Weg.h"
#include "Fahrzeug.h"
#include "FahrAusnahme.h"



Weg::Weg():AktivesVO()
{
}

Weg::Weg(const string sName, const double dLaenge, const Begrenzung eLimit, bool bUeberholverbot)
	: AktivesVO(sName), p_dLaenge(dLaenge), p_eLimit(eLimit), p_bUeberholverbot(bUeberholverbot)
{
}


Weg::~Weg()
{
}

void Weg::vAbfertigung()
{
	p_dVirtuelleSchranke = p_dLaenge;
	p_pFahrzeuge.vAktualisieren();
	for (LazyListe<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)//Durchlauf der Liste
	{
		try
		{
			(*it)->vAbfertigung();
		}
		catch (FahrAusnahme& e)//Fahrausnahme wird aufgefangen
		{
			e.vBearbeiten();
		}

	}
	p_pFahrzeuge.vAktualisieren();
	p_dZeit = dGlobaleZeit;
}

ostream& Weg::ostreamAusgabe(ostream& out) const
{
	AktivesVO::ostreamAusgabe(out)
		<< setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(12) << p_dLaenge
		<< resetiosflags(ios::right) << " ( ";
	for (list<Fahrzeug*>::const_iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it)
	{
		out << (*it)->getName() << " ";
	}
	out << ")";
	return out;
}

istream & Weg::istreamEingabe(istream & in)
{
	AktivesVO::istreamEingabe(in);
	return in;
}

double Weg::getLaenge() const
{
	return p_dLaenge;
}

void Weg::vAnnahme(Fahrzeug * pFahrzeug)
{
	pFahrzeug->vNeueStrecke(this);
	p_pFahrzeuge.push_back(pFahrzeug);//Fahrende Fahrzeuge am Ende hinzufuegen
}

void Weg::vAnnahme(Fahrzeug * pFahrzeug, double dStartzeitpunkt)
{
	pFahrzeug->vNeueStrecke(this, dStartzeitpunkt);
	p_pFahrzeuge.push_front(pFahrzeug);//Parkende Fahrzeuge am Anfang hinzufuegen
}

void Weg::vAbgabe(Fahrzeug * pFahrzeug)
{
	for (LazyListe<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it)
	{
		if ((*it) == pFahrzeug)
		{
			p_pFahrzeuge.erase(it);//loescht das Fahrzeug aus der Liste wenn es das gleiche wie das gesuchte ist
			break;
		}
	}
}

void Weg::vTankleer(Fahrzeug * pFahrzeug)
{
	for (LazyListe<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it)
	{
		if ((*it) == pFahrzeug)
		{
			p_pFahrzeuge.erase(it);//loescht das Fahrzeug aus der Liste wenn es das gleiche wie das gesuchte ist
			break;
		}
	}
	p_pFahrzeuge.push_back(pFahrzeug);
}

Weg::Begrenzung Weg::getLimit() const
{
	return p_eLimit;
}

double Weg::getVirtuelleSchranke() const
{
	if (p_bUeberholverbot == true)
	{
		return p_dVirtuelleSchranke;
	}
	return p_dLaenge;
}

void Weg::setvirtuelleSchranke(double dSchranke)
{
	p_dVirtuelleSchranke = dSchranke;
}

void Weg::setRueckweg(Weg * pWeg)
{
	p_pRueckweg = pWeg;
}

void Weg::vZeichnen() const
{
	for (LazyListe<Fahrzeug*>::const_iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it)
	{
		(*it)->vZeichnen(this);
	}
}

Kreuzung * Weg::getKreuzung() const
{
	return p_pKreuzung;
}

void Weg::setKreuzung(Kreuzung * pKreuzung)
{
	p_pKreuzung = pKreuzung;
}

Weg* Weg::getRueckweg() const
{
	return p_pRueckweg;
}


