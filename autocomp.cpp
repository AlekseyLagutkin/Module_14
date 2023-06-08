#include "autocomp.h"
#include <string>

using namespace std;

trienode* newnod(void)   //Создание нового узла
{
	trienode* node = new trienode;
	for (int i = 0; i < alfa; ++i)
	{
		node->children[i] = nullptr;
	}
	node->eow = false;   
	return node;
}

void insnod(trienode* root, string key)   //Добавление слова в дерево
{
	trienode* node = root;
	trienode* nnode = nullptr;   //Новый узел
	for (int i = 0; i < key.length(); ++i)   //Проверка наличия ключевого слова в дереве
	{
		int j = key[i] - 'A';
		if (node->children[j] == nullptr)   //Если буквы нет, создаем новый узел
		{
			nnode = newnod();   
			node->children[j] = nnode;   
			node = nnode;
		}
		else
		{
			node = node->children[j];    //Если буква есть, переходим на следующий узел
		}
		if (i == key.length() - 1)    //Присваиваем признаку конца слова последнего узла True
		{
			node->eow = true;
		}
	}
	//cout << node->eow << endl;
}
string autoc(trienode* root, string key)   //Автовсавка
{
	trienode* node = root;
	char str[10];   //Массив для хранения слова
	int i;
	int j;
	for (i = 0; i < key.length(); ++i)   //Проверка наличия ключевого слова в дереве
	{
		j = key[i] - 'A';
		if (node->children[j] == nullptr)
		{
			cout << "Нет такой буквы в этом слове" << endl;
			break;
		}
		str[i] = key[i];
		node = node->children[j];
	}
	if (i == key.length())   //Если ключ найден, выводим все слово
	{
		while (node->eow == false)
		{
			for (int k = 0; k < alfa; ++k)   //Идем по алфавиту
			{
				if (node->children[k] != nullptr)   //Записываем первую найденную букву в массив
				{
					str[i] = 'A' + k;
					node = node->children[k];
					break;
				}
			}
			++i;
		}
		for (j = 0; j < i; ++j)
		{
			cout << str[j];   //Выводим все слово на экран
		}
	}
	str[i] = '\0';
	return str;
}
void out(trienode* root, string key)   //Вывод слова на экран по ключу
{
	trienode* node = root;
	char str[10];
	for (int i = 0; i < key.length(); ++i)
	{
		int j = key[i] - 'A';
		if (node->children[j] == nullptr)
		{
			cout << "Нет такой буквы в этом слове" << endl;
			break;
		}
		str[i] = key[i];
		cout << str[i];
		node = node->children[j];
	}
	cout << endl;
}