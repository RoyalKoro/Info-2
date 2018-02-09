#include "Fahrzeug.h"
#include "Weg.h"
#include "FzgParken.h"
#include "FzgFahren.h"

Fahrzeug::Fahrzeug()
	:AktivesVO()
{
	vInitialisierung();

}

Fahrzeug::Fahrzeug(const string sName)
	:AktivesVO(sName)
{
	vInitialisierung();
}

Fahrzeug::Fahrzeug(const string sName, const double dMaxgeschwindigkeit)
	: AktivesVO(sName)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = dMaxgeschwindigkeit;
}

Fahrzeug::Fahrzeug(const Fahrzeug& Fzg)
{
}

Fahrzeug::~Fahrzeug()
{
}

void Fahrzeug::vAusgabe() const
{
	AktivesVO::vAusgabe();
	cout << setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(10) << p_dMaxGeschwindigkeit << " "
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(10) << dGeschwindigkeit() << " "
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(12) << p_dGesamtstrecke
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(12) << p_dAbschnittStrecke;
}

void Fahrzeug::vAbfertigung()
{
	if (dGlobaleZeit != p_dZeit) //Abfrage der letzen Abfertigungszeit damit nicht 2 mal in einem Zeitraum abgefertigt wird
	{
		double dZeit = dGlobaleZeit - p_dZeit; //Zeitunterschied zwischen lobaler Zeit und letzter Abfertigung
		p_dGesamtzeit += dZeit;//es wird die Zeitspanne seit der letzten Abfertigung zu der Gesamtzeit addiert	
		p_dZeit = dGlobaleZeit;	//Abfertigungszeitpunkt wird aktualisiert

		double dStrecke = 0;
		if (p_pVerhalten != 0)
		{
			dStrecke = p_pVerhalten->dStrecke(this, dZeit);  //Zurückgelegte Strecke seit dem letzten Abfertigungsschritt
		}
		p_dGesamtstrecke += dStrecke;//es wird die gefahrene Strecke seit der letzten Abfertigung zur Gesamtstrecke addiert
		p_dAbschnittStrecke += dStrecke; //es wird die gefahrene Strecke seit der letzten Abfertigung zur Abschnittsstrecke addiert

	}
}

double Fahrzeug::dTanken(double dMenge)//es haben nur PKW's Tank, also wird für Fahrräder und Objekte der Klasse Fahrzeug nicht getankt und 0 zurück gegeben, wird in PKW überschrieben
{
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit() const//PKW's und Objekte der Klasse Fahrzeug haben eine konstante Geschwindigkeit p_dMaxgeschwindigkeit, welche zurckgegeben wird. Wird in Fahrrad überschrieben
{
	return p_dMaxGeschwindigkeit;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& out) const//Lädt Ausgabeinformationen in den ostream out und gibt ihn wieder zurück
{
	AktivesVO::ostreamAusgabe(out)//Aufruf der OstreamAusghabe der Oberklasse 
		<< setprecision(2) << fixed//Auf 2 Nachkommastellen runden
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(10) << p_dMaxGeschwindigkeit << " "
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(10) << dGeschwindigkeit() << " "
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(12) << p_dGesamtstrecke
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(12) << p_dAbschnittStrecke;
	return out;
}

istream & Fahrzeug::istreamEingabe(istream & in)
{
	AktivesVO::istreamEingabe(in);
	in >> p_dMaxGeschwindigkeit;
	return in;
}

bool Fahrzeug::operator<(const Fahrzeug& Fzg) const
{
	return (this->p_dGesamtstrecke < Fzg.p_dGesamtstrecke);
}

bool Fahrzeug::operator>(const Fahrzeug& Fzg) const
{
	return (this->p_dGesamtstrecke > Fzg.p_dGesamtstrecke);
}
/*
bool Fahrzeug::operator==(const Fahrzeug& Fzg) const
{
return (this->p_dGesamtstrecke == Fzg.p_dGesamtstrecke);
}
*/
//Zuweisungsoperator, kopiert alle Informationen eines Fahrzeugs auf ein anderes Fahrzeug,
//ID ist anders da es ein anderes Objekt ist welches beim initialisieren eine eigene ID bekommen hat
Fahrzeug& Fahrzeug::operator=(const Fahrzeug& Fzg)
{
	AktivesVO::operator=(Fzg);
	p_dMaxGeschwindigkeit = Fzg.p_dMaxGeschwindigkeit;
	p_dGesamtstrecke = Fzg.p_dGesamtstrecke;
	p_dGesamtzeit = Fzg.p_dGesamtzeit;
	return *this;
}

void Fahrzeug::vNeueStrecke(Weg* pWeg)
{
	if (p_pVerhalten != 0)//Wenn ein Verhalten besteht soll dieses geloescht werden damit keine losen Zeiger zurueck bleiben
	{
		delete p_pVerhalten;
	}
	p_pVerhalten = new FzgFahren(pWeg);
	p_dAbschnittStrecke = 0;
	p_dZeit = dGlobaleZeit;
}

void Fahrzeug::vNeueStrecke(Weg* pWeg, double dStartzeitpunkt)
{
	if (p_pVerhalten != 0)//Wenn ein Verhalten besteht soll dieses geloescht werden damit keine losen Zeiger zurueck bleiben
	{
		delete p_pVerhalten;
	}
	p_pVerhalten = new FzgParken(pWeg, dStartzeitpunkt);
	p_dAbschnittStrecke = 0;
	p_dZeit = dGlobaleZeit;
}
double Fahrzeug::getAbschnittsStrecke() const
{
	return p_dAbschnittStrecke;
}

void Fahrzeug::vZeichnen(const Weg * pWeg) const
{
}

void Fahrzeug::vInitialisierung()
{
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtstrecke = 0;
	p_dGesamtzeit = 0;
	p_dAbschnittStrecke = 0;
	p_pVerhalten = 0;

}
