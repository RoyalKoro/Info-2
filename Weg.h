#pragma once
#include "AktivesVO.h"
#include "LazyListe.h"
#include <list>

class Fahrzeug;//Fahrzeug wird bekannt gemacht
class Kreuzung;
class Weg : public AktivesVO //Stellt einen Weg dar auf dem Fahrzeuge fahren koennen
{

public:
	typedef enum //Neuer Datentyp fuer die Geschwindigkeitsbegrenzung auf dem Weg
	{
		Innerorts = 50,
		Landstrasse = 100,
		Autobahn = -1
	}
	Begrenzung;
	Weg();//Standartkonstrukor
	Weg(const string sName, const double dLaenge, const Begrenzung eLimit = Autobahn, bool bUeberholverbot = true);//Konsruktor mit Zuweisung des Namen, der Laenge und des Geschwindigkeitslimits
	virtual ~Weg();//Desruktor
	virtual void vAbfertigung();//Fertigt alle Fahrzeuge auf dem Weg ab
	virtual ostream& ostreamAusgabe(ostream& out) const; //Ausgabefunktion ueber den Steam-Operator
	virtual istream& istreamEingabe(istream& in);
	double getLaenge() const;//Get-Funktion fuer p_dLaenge
	void vAnnahme(Fahrzeug* pFahrzeug);//fuegt ein fahrendes Fahrzeug der Liste hinzu
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeitpunkt);//Ueberladung, fuegt ein parkendes Fahrzeug mit einem Startzeitpunkt der Liste hinzu
	void vAbgabe(Fahrzeug* pFahrzeug);//loescht ein Fahrzeug aus der Liset wenn dieses den Weg verlässt
	void vTankleer(Fahrzeug* pFahrzeug);
	Begrenzung getLimit() const;//Get-Funktion fuer p_eLimit
	double getVirtuelleSchranke() const;
	void setvirtuelleSchranke(double dSchranke);
	void setRueckweg(Weg* pWeg);
	Weg* getRueckweg() const;
	void vZeichnen() const;
	Kreuzung* getKreuzung() const;
	void setKreuzung(Kreuzung* pKreuzung);
private:
	double p_dLaenge;
	//list<Fahrzeug*> p_pFahrzeuge;
	LazyListe<Fahrzeug*> p_pFahrzeuge;//Speichert Zeiger auf Fahrzeuge die auf dem Weg fahren
	Begrenzung p_eLimit;//Geschwindigkeitslimit auf dem Weg
	bool p_bUeberholverbot;
	double p_dVirtuelleSchranke;
	Weg* p_pRueckweg;
	Kreuzung* p_pKreuzung;

};

