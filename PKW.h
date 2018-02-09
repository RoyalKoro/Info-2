#pragma once
#include "Fahrzeug.h"
class PKW :
	public Fahrzeug
{
	public:
		PKW();
		//PKW(const string sName, const double dMaxgeschwindigkeit, const double dVerbrauch) //Konstruktor mit Name, Maxgeschwindigkeit, Verbrauch
		PKW(const string sName, const double dMaxgeschwindigkeit, const double dVerbrauch, const double dTankvolumen = 55);//Konstruktor mit Name, Maxgeschwindigkeit, Verbrauch und Tankvolumen
		virtual ~PKW();//Destruktor
		virtual void vAbfertigung();//Abfertigungsschritt, aktualisiert die Informationen des PKW gemäß der Globalen Zeit
		virtual double dTanken(double dMenge = -1);//Tank den PKW um dMenge oder wenn kein Wert angegeben ist voll
		virtual void vAusgabe() const;//Gibt Informationen des PKW über die Textausgabe aus	
		virtual ostream& ostreamAusgabe(ostream& out) const;//Ausgabe über die Überladung des << Operators 
		virtual istream& istreamEingabe(istream& in);
		PKW& operator=(const PKW& PKWTemp);//Überladung des Zuweisungsoperators, kopiert PKWTemp
		virtual double dGeschwindigkeit() const;//Get-Funktion fuer p_dGeschwindigkeit
		virtual void vZeichnen(const Weg* pWeg) const;//Zeichnet ein PKW-Objekt auf einen Weg in der Grafikausgabe
	private:
		PKW(const PKW& cPKW);//Copykonstruktor
		double p_dVerbrauch;// Verbrauch des PKW
		double p_dTankinhalt;//Tankinhalt des PKW, die hälfte des Tankvolumens
		double p_dTankvolumen;//Tankvolumen des PKW, Standartwert 55, wenn nicht vom Konstruktor anders definiert
};

