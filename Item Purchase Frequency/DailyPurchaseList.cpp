#include <iostream>
#include "DailyPurchaseList.h"
using namespace std;

void DailyPurchaseList::ReadFile(string fileName) {
	string item;

	try {
		inFS.open(fileName);
		if (!inFS.is_open()) { throw ""; }
		else {
			while (true) {
				inFS >> item;
				if (itemFrequency.count(item) < 1) {
					itemFrequency.emplace(item, 1);
				}
				else {
					itemFrequency.at(item)++;
				}
				if (inFS.eof()) { break; }
			}
		}
	}
	catch (...) {
		cout << "Failed to read open file." << endl;
	}
}

void DailyPurchaseList::WriteFile(string fileName) {
	try {
		outFS.open(fileName);
		if (!outFS.is_open()) { throw ""; }
		else {
			for (const auto& key : itemFrequency) {
				outFS << key.first << " " << key.second << endl;
			}
		}
	}
	catch (...) {
		cout << "Failed to write open file." << endl;
	}
}

void DailyPurchaseList::ProcessInput() {
	ReadFile("PurchaseList.txt");
	WriteFile("frequency.dat");

	int temp;

	try {
		cin >> temp;
		if (cin.fail()) {
			throw "";
		}
		else {
			switch (temp) {
			case 1:
				this->PrintOneItem();
				break;
			case 2:
				this->PrintAllItemsList();
				break;
			case 3:
				this->PrintAllItemsGraph();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout << "Invalid option" << endl;
				break;
			}
		}
	}
	catch (...) {
		cout << "Wrong input. Please enter one integer\n";
		cin.clear();
		cin.ignore(256, '\n');   // ignore the line change
	}
}

void DailyPurchaseList::PrintOneItem() {
	string item;

	cout << "\nEnter item name" << endl;
	try {
		cin >> item;
		if (cin.fail()) { throw ""; }
		else {
			if (itemFrequency.count(item) > 0) {
				cout << "\n" << item << " " << itemFrequency.at(item) << endl;
			}
			else {
				cout << "Item not found\n" << endl;
			}
		}
	}
	catch (...) {
		cout << "Print output error." << endl;
	}

}

void DailyPurchaseList::PrintAllItemsList() {
	for (const auto& key : itemFrequency) {
		cout << "\n" << key.first << " " << key.second << endl;
	}
}

void DailyPurchaseList::PrintAllItemsGraph() {
	for (const auto& key : itemFrequency) {
		cout << "\n" << key.first << " ";
		int i = 0;
		while (i < key.second) {
			cout << "*";
			i++;
		}
		cout << endl;
	}
}
