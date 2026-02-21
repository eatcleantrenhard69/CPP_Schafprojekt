#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "VerketteSchafe.h"
#include "Feld.h"
#include "Schaf.h"

int main()
{
	int iN;                 			// Feldgröße
    int iStartBlumen;       			// Blumen im Magen zu Beginn
    int iWachsendeBlumen;   			// Wieviele Blumen wachsen auf einem Feld?
    int iFelderaufdenenBlumenwachsen;   //Auf wievielen Feldern wachsen blumen
    int iBewegungskosten;   			//Kosten pro Schritt
    FELD Spielfeld;  					//Spielfeld
    int iI; 							//Laufvariable
    int iXpos; 							//PositionX
    int iYpos; 							//PositionY
    int iRunde = 1; 					//Runde der Simulation
	bool simulationLauft = true; 		//Simulation läuft?

	std::cout << "BITTE NUR EINZELNE GANZZAHLEN EINGEBEN. NICHTS AUSSER EINZELNE GANZZAHLEN \n";
	std::cout << "Gib die Anzahl der Blumen auf einem Feld an.";
	std::cin >> iWachsendeBlumen;

	std::cout << "Gib die insgesamten Felder an auf denen Blumen wachsen";
	std::cin >> iFelderaufdenenBlumenwachsen;

	std::cout << "Bewegungskosten";
	std::cin >> iBewegungskosten;

	std::cout << "Feldgröße";
	std::cin >> iN;

	std::cout << "iStartblumen?";
	std::cin >> iStartBlumen;

	//
	Spielfeld.Feld_erstellen(iN);

	//
	VerketteteSchafe Schafgruppe;

	//
	for(iI = 0; iI< 4; iI++)
	{
		iXpos = rand() % iN; //Zufällige Pos
		iYpos = rand() % iN; //Zufällige Pos
		SCHAF * neuesSchaf = new SCHAF(iXpos, iYpos, iStartBlumen, iI);
		Schafgruppe.addSchaf(neuesSchaf);
		std::cout << "Schaf ID " << iI + 1 << " erstellt bei (" << iXpos << ", " << iYpos << "). Startblumen: " << iStartBlumen << std::endl;
	}
	//)
	while(simulationLauft == true && Schafgruppe.getHead() != nullptr)
	{
		std::cout << "\n================================================" << std::endl;
        std::cout << "RUNDE " << iRunde << " STARTET:" << std::endl;
        std::cout << "================================================" << std::endl;

		Spielfeld.SpreadFlowers(iFelderaufdenenBlumenwachsen, iWachsendeBlumen);
		SCHAF *aktuellesSchaf = Schafgruppe.getHead();
		while(aktuellesSchaf != nullptr)
		{

			SCHAF *naechstesSchaf = aktuellesSchaf->next;
			aktuellesSchaf->schaf_bewegen(iN);
			aktuellesSchaf->Caloric_Deficit(iBewegungskosten);


			if(aktuellesSchaf->getMageninhalt() <=0)
			{
				std::cout << "ID " << aktuellesSchaf->getID() << " ist GESTORBEN. ";

				Schafgruppe.removeSchaf(aktuellesSchaf); // Aus der Liste entfernen
                delete aktuellesSchaf;
			}
			aktuellesSchaf = naechstesSchaf;
		}
		if(Schafgruppe.getHead()!= nullptr)
		{
			Spielfeld.feld_verwalten(Schafgruppe);
		}
		iRunde++;
	}



}
//Schafe krieren und id anzahl der Schafe und dann in Feld die IDS vergleichen wenn mehrere Schafe auf
//einem Feld und dann Magenanzahl und dann werden daraufhin wieder funktionen aufgerufen.
