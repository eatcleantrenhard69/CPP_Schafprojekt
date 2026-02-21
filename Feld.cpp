#include "Feld.h"
#include "VerketteSchafe.h"
#include "Schaf.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


FELD::FELD()
{
    iN = 64;
}
FELD::~FELD()
{
    if(paiFeld != NULL)
    {
        for (int i=0; i<iN; i++)
        {
            delete [] paiFeld[i];
        }
        delete [] paiFeld;
    }
    std::cout << "Feld ist zerstört";
}


/*
//Die Funktion erstellt ein Feld basierend auf den Eingabeparametern

Rückgabetyp: int

Formale Übergabeparameter:
by value: n Größe
by reference:
*/
void FELD::Feld_erstellen(int iN_param)
{
    //Die Klassenvariable iN muss auf den gewünschten Wert gesetzt werden, hab einfach im StandardKonstrukor
    //64 als Beispiel wert genommen.
    this->iN = iN_param;

    // Variablendeklaration
    int iLauf;

    // Nun wird das Array mit dem neuen, korrekten Wert erstellt
    paiFeld = new int*[this->iN];

    for(iLauf = 0; iLauf < this->iN; iLauf++)
    {
        paiFeld[iLauf] = new int[this->iN] {0};
    }
}
void FELD::SpreadFlowers(int iBlumenanzahlfeld, int iBlumenanzahl)
{
    //variablen
    int iL; //laufvariable
    int iX; //Xpos
    int iY; //Ypos

    for(iL=0; iL<iBlumenanzahlfeld; iL++)
    {
        iX = rand() % iN;  //Von 0 bis N-1
        iY = rand() % iN;  //Von 0 bis N-1
        paiFeld[iX][iY] = paiFeld[iX][iY] + iBlumenanzahl;
    }
}

int FELD::feld_verwalten(VerketteteSchafe &VerketteteSchafe)
{
    int iI;//lauf
    int iJ;//lauf
    for(iI=0; iI<iN; iI++)
    {
        for(iJ=0; iJ<iN; iJ++)
        {
            // Wenn auf dem Feld Blumen sind (oder Schafe zum Fressen/Kämpfen anwesend sind)
            // Wir müssen die Schleife durchgehen, auch wenn keine Blumen da sind,
            int iSchafcount = 0;
            SCHAF *starkstesSchaf = nullptr; // Wird sowohl für Fressen als auch für Kampf verwendet
            int iMaxinhalt = 0;             // Niedriger Startwert für den Mageninhalt

            SCHAF *aktuellesSchaf = VerketteteSchafe.getHead();

            //Schafe auf einem Feld zählen
            while(aktuellesSchaf != nullptr)
            {
                if(aktuellesSchaf ->getXPos() == iI && aktuellesSchaf->getYPos() == iJ)
                {
                    iSchafcount++;

                    // Finde das stärkere Schaf oder zuerst gesuchte bei Gleichstand
                    if(aktuellesSchaf->getMageninhalt() > iMaxinhalt)
                    {
                        iMaxinhalt = aktuellesSchaf->getMageninhalt();
                        starkstesSchaf = aktuellesSchaf; // Speichert den Pointer zum stärksten Schaf
                    }
                }
                aktuellesSchaf = aktuellesSchaf->next;
            }

            //Wenn ein Schaf auf dem Feld ist dann frisst das Schaf
            if(iSchafcount == 1)
            {
                if(paiFeld[iI][iJ] >= 1)
                {

                    starkstesSchaf->getBlumen(paiFeld[iI][iJ]);

                    std::cout << "Fressen: Schaf ID " << starkstesSchaf->getID() << " frisst " << paiFeld[iI][iJ] << " Blumen bei (" << iI << ", " << iJ << ")." << std::endl;
                    paiFeld[iI][iJ] = 0; // Feld leeren
                }
            }


            // Wenn mehrere Schafe da sind dann kämpfen die
            else if (iSchafcount > 1)
            {
                if(starkstesSchaf != nullptr) // Sicherheitscheck
                {
                    if (paiFeld[iI][iJ] > 0) {
                        // Der Gewinner erhält alle Blumen des Feldes
                        starkstesSchaf->getBlumen(paiFeld[iI][iJ]);
                        std::cout << "KAMPF: Schaf ID " << starkstesSchaf->getID() << " gewinnt " << paiFeld[iI][iJ] << " Blumen bei (" << iI << ", " << iJ << ")." << std::endl;
                    }
                    else {
                        std::cout << "KAMPF: Schaf ID " << starkstesSchaf->getID() << " ist der staerkste, aber es gibt keine Blumen zu gewinnen." << std::endl;
                    }

                    // Das Feld wird in jedem Fall geleert (da die Blumen gefressen wurden)
                    paiFeld[iI][iJ] = 0;
                }
            }

        }
    }
    return 0;
}











