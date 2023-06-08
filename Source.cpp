#include <iostream>
#include "autocomp.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	trienode* tr = newnod();
	char a = 0;
	string str;
	insnod(tr, "VASYA");
	insnod(tr, "LENA");
	insnod(tr, "VALERA");
	insnod(tr, "MARUSYA");
	insnod(tr, "PETYA");
	insnod(tr, "ANFISA");
	insnod(tr, "GENA");
	insnod(tr, "KOLYA");
	insnod(tr, "OLYA");
	insnod(tr, "KESHA");
	insnod(tr, "BORYA");
	insnod(tr, "DASHA");
	insnod(tr, "EGOR");
	insnod(tr, "IRA");
	insnod(tr, "NASTYA");
	insnod(tr, "ROMA");
	insnod(tr, "SASHA");
	insnod(tr, "TANYA");
	insnod(tr, "FEDYA");

	cout << "Начните ввод имени прописными латинскими буквами (A-Z) и нажмите ввод для автовсавки, или нажмите 0 для выхода : "<< endl;
	while (str != "0")
	{
		cin >> str;
		if (str >= "A" && str <= "Z")
		{
			autoc(tr, str);
		}
		else
		{
			cout << "Неверный ввод" << endl;
		}
	}
	return 0;
}