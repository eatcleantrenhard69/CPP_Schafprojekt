#ifndef FELD_H
#define FELD_H

#include "../VerketteSchafe.h"
class FELD
{
	private:
		int iN; //Feldgröße
		int **paiFeld;

	public:
		FELD();
		~FELD();
		/*
// Die Funktion durchläuft jedes Feld und führt basierend auf der Schafanzahl die Interaktionslogik aus:
// Schafcount=1: Fressen der Blumen. Schafcount>1: Kampf um die Blumen (stärkstes Schaf gewinnt).

Rückgabetyp: int also return 0

Formale Übergabeparameter:
by value:
by reference: VerketteteSchafe &VerketteteSchafe (Die Liste der Schafe, deren Mageninhalt sich ändert)
*/
		int feld_verwalten(VerketteteSchafe &VerketteteSchafe);

		/*
//Die Funktion erstellt ein Feld basierend auf den Eingabeparametern

Rückgabetyp: int

Formale Übergabeparameter:
by value: int iParam //Feldgröße aber variabel, deswegen unter neuem Namen und mit This als Zugriffshilfsmittel weil mein Feld
//Konstruktor das automatisch auf einen Wert setzt
by reference:
*/
		void Feld_erstellen(int iN);

				/*
// Die Funktion lässt 'iBlumenanzahl' (o) Blumen auf 'iBlumenanzahlfeld' (m) zufälligen Feldern wachsen.

Rückgabetyp: void

Formale Übergabeparameter:
by value: int iBlumenanzahlfeld (m: Anzahl der Felder, auf denen Blumen wachsen)
          int iBlumenanzahl (o: Menge der Blumen, die pro Feld hinzukommen)
by reference:
*/
		void SpreadFlowers(int Blumenanzahlfeld, int iBlumenanzahl);

};

#endif // SCHAF_H
