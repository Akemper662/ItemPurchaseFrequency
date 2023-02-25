// 7-3 Project -- Aaron Kemper -- 2/18/2023

#include <iostream>
#include <string>
#include "DailyPurchaseList.h"
using namespace std;

void DisplayMenu() {
    cout << "**************************************************" << endl;
    cout << "**********        CORNER  GROCER        **********" << endl;
    cout << "**********    Item Purchase Frequency   **********" << endl;
    cout << "**************************************************" << endl;
    cout << "**********             MENU             **********" << endl;
    cout << "**************************************************" << endl;
    cout << "**  1) Display specific item                    **" << endl;
    cout << "**  2) Display all items                        **" << endl;
    cout << "**  3) Display all items as histogram           **" << endl;
    cout << "**  4) Quit                                     **" << endl;
    cout << "**************************************************" << endl;
}



int main()
{
    DailyPurchaseList MyFile;

    while (true) {
        DisplayMenu();
        MyFile.ProcessInput();
    }
}