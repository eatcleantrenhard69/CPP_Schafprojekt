#include "verketteSchafe.h"

VerketteteSchafe::VerketteteSchafe() {
	head = nullptr;
}
void VerketteteSchafe::addSchaf(SCHAF *neuesSchaf)
{
	neuesSchaf ->next = head;
	head = neuesSchaf;
}
void VerketteteSchafe::removeSchaf(SCHAF* ziel)
{
	if (head == ziel)
	{
		head = head->next;
	}
	else
	{
		SCHAF *aktuell = head;
	while (aktuell->next != nullptr && aktuell->next != ziel)
	{
		aktuell = aktuell->next;
	}
	if (aktuell->next == ziel) {
        aktuell->next = ziel->next;
    }
    else {

    }
	}

}
SCHAF* VerketteteSchafe::getHead()
{
	return head;
}
