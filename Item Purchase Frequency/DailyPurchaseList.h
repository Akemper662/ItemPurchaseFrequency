#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class DailyPurchaseList
{
private:
	ifstream inFS;
	ofstream outFS;
	map<string, int> itemFrequency;
	void ReadFile(string fileName);
	void WriteFile(string fileName);
	void PrintOneItem();
	void PrintAllItemsList();
	void PrintAllItemsGraph();
public:
	void ProcessInput();
};
