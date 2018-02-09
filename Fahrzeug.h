#pragma once

#include "AktivesVO.h"
#include "FzgVerhalten.h"
#include "SimuClient.h"

class Weg;//Weg wird bekannt gemacht

class Fahrzeug :
	public AktivesVO
{
	public:
		Fahrzeug(); //Standartkonstruktor
		Fahrzeug(const string sName);//Konstruktor mit Namensübergabe
		Fahrzeug(const string sName, const double dMaxgeschwindigkeit);//Konstruktor mit Namensübergabe und MaxGeschwindigkeit
		virtual ~Fahrzeug();//Destruktor
		virtual void vAusgabe() const; //gibt Fahrzeugspezifische Informationen über die Textausgabe aus
		virtual void vAbfertigung();//Abfertigungsschritt, aktualisiert Fahrzeugspezifische Informationen gemäß der Globalen Zeit
		virtual double dTanken(double dMenge = -1);//Tankt das Fahrzeug
		virtual double dGeschwindigkeit() const;// gibt die aktuelle Geschwindigkeit des Fahrzeugs zurück
		virtual ostream& ostreamAusgabe(ostream& out) const;//Ausgabe über die Überladung des << Operators
		virtual istream& istreamEingabe(istream& in);
		bool operator<(const Fahrzeug& Fzg) const;//Überladung des < Operators, vergleicht die gefahrene Strecke von zwei Fahrzeugen
		bool operator>(const Fahrzeug& Fzg) const;//Überladung des > Operators, vergleicht die gefahrene Strecke von zwei Fahrzeugen
		Fahrzeug& operator=(const Fahrzeug& Fzg);//Überladung des Zuweisungsoperators, kopiert Objekte und weißt eine neue ID zu
												 //bool operator==(const Fahrzeug& Fzg) const;//Überladung des == Operators, vergleicht die gefahrene Strecke von zwei Fahrzeugen
		void vNeueStrecke(Weg* pWeg);//Setzt das _Fahrzeug auf einen neuen Weg
		void vNeueStrecke(Weg * pWeg, double dStartzeitpunkt);//Überladung der Funktion, gibt zusätzlich einen Startzeitpunkt an zu dem das Fahrzeug los fahren soll
		double getAbschnittsStrecke() const;//Get-Funktion für p_dAbschnittsStrecke
		virtual void vZeichnen(const Weg* pWeg) const;//Macht in Fahrzeug nichts, wird in beiden Unterklassen überschrieben

	private:
		Fahrzeug(const Fahrzeug& Fzg);//Copykonstruktor des Fahrzeugs, auf private damit er nicht zufällig benutzt wird
		void vInitialisierung(); // Initialisiert Membervariablen auf 0 oder "" und setzt die ID

	protected:
		double p_dMaxGeschwindigkeit; //Maximale GGeschwindigkeit des Fahrzeugs
		double p_dGesamtstrecke; //Gesamt gefahrene Strecke des Fahrzeugs
		double p_dGesamtzeit; //Gesamtfahrzeit des Fahrzeugs
		double p_dAbschnittStrecke; //zurückgelegte Strecke auf dem aktuellen Abschnitt
		FzgVerhalten* p_pVerhalten;//Legt das Verhalten auf einem Weg fest, 
};

