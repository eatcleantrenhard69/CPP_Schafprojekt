#ifndef SCHAF_H
#define SCHAF_H


class SCHAF
{
	private:
	int iMageninhalt; //Mageninhalt der Schafe
	int ixPos; //Xposition
	int iyPos; //YPosition
	int iID; //ID des Schaf




	public:
		SCHAF *next; //Verkettende Schafe für linked list.
		SCHAF();
		SCHAF(int iX, int iY, int iBlumen, int iId);
		~SCHAF();

		//get Methoden
		int getXPos() { return ixPos; }
		int getYPos() { return iyPos; }
		int getMageninhalt() { return iMageninhalt; }
		int getID() { return iID; }

		void Caloric_Deficit(int iBewegungskosten); //Bewegungskosten ist ein Parameter Q
		/*
		//Die Funktion reduziert die Blumen im Magen um eingabewert

		Rückgabetyp: int

		Formale Übergabeparameter:
		by value:
				  Bewegungskosten q //
		by reference:
		*/
		void getBlumen(int iAnzahl);
		/*
		//Die Funktion schreibt Schafen den Blumen zu

		Rückgabetyp: none

		Formale Übergabeparameter:
		by value: iAnzahl //Anzahl der Blumen.
		by reference:
		*/
		void schaf_bewegen(int iN);
		/*
		//Die Funktion bewegt das Schaf in eine zufällige Richtung um ein Feld

		Rückgabetyp: --

		Formale Übergabeparameter:
		by value: iN //Feldgrößße
		by reference:
		*/

};

#endif // SCHAF_H
