#include <iostream>     // std::cout, std::endl
#pragma warning (disable:4996)
using namespace std;

//chyba miałoby sens robienie drugej klasy jakby bylo wiecej elementow do przekazania a nie tylko jeden string.

typedef struct _lista {
	int modul; //to co bede wstawiac do listy
	_lista *next;
}lista;

void usun(lista *head);
void sortuj(lista*head) {
	lista *temp = head->next;
	lista *help = head->next->next;
	//for (temp = head->next; temp != NULL; temp = temp->next)
	//{
	//	for (help = temp; help != NULL; help = help->next)
	//	{
	//		if (help->modul > temp->modul) {
	//			int key = help->modul;
	//			help->modul = temp->modul;
	//			temp->modul = key;
	//			//break;
	//		}
	//	}
	//}
	while (temp)
	{
		//help = temp->next;
		while (help)
		{
			if (help->modul > temp->modul)
			{
				int key = help->modul;
				help->modul = temp->modul;
				temp->modul = key;
			}
			help = help->next;
		}
		temp = temp->next;
	}
}

void dodaj_poczatek(lista *head, int wstawiana) {
	lista *nowy = new lista;
	nowy->modul = wstawiana;
	int counter = 0;

	lista *temp = head->next;
	if (head->next == NULL)
	{
		head->next = nowy;
		nowy->next = NULL;
	}
	else if (head->next && head->next->next == NULL)
	{
		if (nowy->modul >= head->next->modul)
		{
			nowy->next = head->next;
			head->next = nowy;
		}
		else
		{
			nowy->next = NULL;
			head->next->next = nowy;
		}
	}
	else
	{
		lista *next_temp = head->next->next;
		while (next_temp != NULL)
		{
			counter++;
			if (counter == 1)
			{
				if (nowy->modul >= temp->modul)
				{
					nowy->next = temp;
					head->next = nowy;
					break;
				}
				else if (nowy->modul >= next_temp->modul)
				{
					temp->next = nowy;
					nowy->next = next_temp;
					break;
				}
				
			}
			else if (counter > 1)
			{
				if (nowy->modul >= next_temp->modul)
				{
					temp->next = nowy;
					nowy->next = next_temp;
					break;
				}
			}
			temp = temp->next;
			next_temp = next_temp->next;
			if (next_temp == NULL) {
				if (nowy->modul < temp->modul)
				{
					temp->next = nowy;
					nowy->next = NULL;
					break;
				}
			}
			
			
		}
	}
}


//taki bubble sort na liście
//for (int i = 0; i < 3; i++)
//{
//	if (nowy->modul < temp->modul) {
//		cout << "yhm\n";
//		//lista *help= new lista;
//		/*
//		cout << nowy->modul;
//		cout << temp->modul;*/
//		head->next = temp;
//		temp->next = nowy;
//		nowy->next = head->next->next->next;
//		head = head->next;
//		//cout << nowy->modul;
//		//cout << temp->modul;
//	}
//}




void usun_pierwszy(lista *head) {
	if (head->next == NULL) {
		cout << "na" << endl;
		return;
	}
	cout << head->next->modul << endl;

	lista *temp;
	temp = head->next;

	head->next = head->next->next;

	delete temp;

}

void dodaj_koniec(lista *head, int wstawiana) {
	lista *ost = new lista;
	ost->next = NULL;
	ost->modul = wstawiana;
	if (head->next == NULL)
		head->next = ost;
	else {
		lista *temp = head->next;

		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = ost;
	}
}

void usun_ostatni(lista *head) {
	if (head->next == NULL)
		return;
	else if (head->next->next == NULL) {
		delete head->next;
		head->next = NULL;
	}
	else {
		lista *temp = head->next;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}
}

void merge(lista *head1, lista *head2) {
	//lista *newhead = NULL;
	lista* temp = NULL;
	temp = head2->next;
	while (temp != NULL) {
		dodaj_poczatek(head1, temp->modul);
		temp = temp->next;
	}
	head2->next = NULL;
	//usun(head2);
	//return head2;
}

void increase(int co, int naco, lista *head) {
	lista*temp = head->next;
	bool gowno = false;
	if (head->next == NULL)
	{
		cout << "na" << endl;
	}
	else {
		while (temp)
		{
			if (temp->modul == co)
			{
				temp->modul = naco;
				gowno = true;
				break;
			}
			temp = temp->next;
		}
		if (gowno)
		{
			sortuj(head);
		}
		else cout << "na" << endl;
	}

}

void wyswietl(lista *head) {

	lista *temp = head->next;
	while (temp != NULL) {
		cout << temp->modul << endl;
		temp = temp->next;
	}
}

void usun(lista *head) {

	//head = head->next;
	//cout << head->next->modul;
	while (head->next != NULL) {
		lista *temp = head->next;
		head = head->next;
		temp = nullptr;
	}
}

int rozmiar_listy(lista *head) {
	int rozmiar = 0;

	while (head->next != NULL)
	{
		head = head->next;
		rozmiar++;
	}
	return rozmiar;
}

int main() {

	lista* tab = new lista[1000];
	for (int i = 0; i < 1000; i++) {
		tab[i].next = NULL;
	}


	int ile = 0;
	char litera;
	scanf(" %d", &ile);
	//scanf_s("%c", &litera);
	while (ile != 0)
	{
		scanf(" %c", &litera);
		switch (litera)
		{
		case 'a':
			int wartosc;
			int nrgrupy;
			scanf(" %d", &nrgrupy);
			scanf(" %d", &wartosc);
			//tab[nrgrupy].next = NULL;
			dodaj_poczatek(&tab[nrgrupy], wartosc);
			break;
		case 'e':
			int grupa;
			scanf(" %d", &grupa);
			usun_pierwszy(&tab[grupa]);
			break;
		case 'm':
			int gr1;
			int gr2;
			scanf(" %d %d", &gr1, &gr2);
			merge(&tab[gr1], &tab[gr2]);
			break;
		case 'i':
			int group;
			int v1;
			int v2;
			scanf(" %d %d %d", &group, &v1, &v2);
			increase(v1, v2, &tab[group]);
			//cout << "na" << endl;
			break;
			//case 'p':
			//	int gr;
			//	scanf(" %d", &gr);
			//	wyswietl(&tab[gr]);
		default:
			break;
		}
		ile--;
	}


	return 0;
}