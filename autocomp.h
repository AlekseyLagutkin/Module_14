#pragma once
#include  <iostream>
#include <string>
#define alfa 26

using namespace std;

struct trienode
{
	trienode* children[alfa];   //Массив указателей
	bool eow;   //Признак конца слова
};
trienode* newnod(void);   //Создание нового узла
void insnod(trienode* root, string key);   //Добавление узла
string autoc(trienode* root, string key);   //Автовсавка
void out(trienode* root, string key);   //Вывод слова по ключу

