
#ifndef VERKETTETESCHAFE_H
#define VERKETTETESCHAFE_H

#include "Schaf.h"

class VerketteteSchafe
{
private:
    SCHAF* head; // erstes Schaf in der Liste

public:

    VerketteteSchafe();

         /*
		//Die Funktion ist für das Anfügen von neuen Schafen (für die nächste Version)
		Rückgabetyp: void

		Formale Übergabeparameter:
		by value: Schaf *neuesSchaf
		by reference:
		*/
    void addSchaf(SCHAF* neuesSchaf);

    /*
//Die Funktion ist für das killen von Schafen
Rückgabetyp: void

Formale Übergabeparameter:
by value:
by reference: Schaf *ziel
*/
    void removeSchaf(SCHAF* ziel);

     /*
//Die Funktion ist für das zugreifen auf den Head der Linked list
Rückgabetyp: Schaf

Formale Übergabeparameter:
by value:
by reference:
*/
    SCHAF* getHead();

};

#endif
