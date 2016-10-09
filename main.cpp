// Author: Maciej Ruszczyk

#include "Constans.h"
#include <iostream>

string numberToWord(string);

int main()
{
	string tekst;

	while(true)
	{
		getline(cin, tekst);

		if (tekst == "") 
			break;

		numberToWord(tekst);

		cout << numberToWord(tekst)<< endl;
	}

	return 0;
}

string numberToWord(string tekst) {
	bool x;
	int ile;
	size_t calosc, reszta;
	string Result="";

	if (tekst[0] - 48 == 0) {
		return "zero";
	}

	while (tekst.size()>0){
		x = false;
		calosc = (tekst.size() - 1) / 3;
		reszta = (tekst.size() - 1) % 3;


		if (reszta == 2){
			Result += Setki[tekst[0]-48] + " ";

			if (tekst[1] - 48 >= 2 && tekst[1] - 48 <= 9)
				Result += Dziesiatki[tekst[1] - 48] + " ";

			if (tekst[1] - 48 == 1){
				Result += Dziesiatki_11[tekst[2] - 48] + " ";

				x = true;
			}

			if (!x)
				Result += Jednosci[tekst[2] - 48] + " ";

			ile = 3;
		}
		else if (reszta == 1){
			if (tekst[0] - 48 >= 2 && tekst[0] - 48 <= 9) {
				Result += Dziesiatki[tekst[0] - 48] + " ";
			}

			if (tekst[0] - 48 == 1){
				Result += Dziesiatki_11[tekst[1] - 48] + " ";
				x = true;
			}

			if (!x) {
				Result += Jednosci[tekst[1] - 48] + " ";
			}
			ile = 2;
		}
		else if (reszta == 0){
			Result += Jednosci[tekst[0] - 48] + " ";
			ile = 1;
		}


		if (tekst[0] != '0' || tekst[1] != '0' || tekst[2] != '0') 
			Result += Przedrostki[calosc] + " ";

		tekst.erase(0, ile);
	}
	return Result;
}
