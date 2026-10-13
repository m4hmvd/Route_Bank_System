#include "Screens.h"
#include "AdminManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"

#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "FilesHelper.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>
#include <windows.h>

using namespace std;




void printCentered(string text, int width)
{
    int padding = (width - text.length()) / 2;
    if (padding > 0)
        cout << string(padding, ' ');
    cout << text << endl;
}

// Clear screen
void clearScreen()
{
    system("cls");
}

// Set console color (gold-ish = bright yellow)
void setGoldColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void setRedColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
}


void setGreenColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void setBlueColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

// Reset to default color
void resetColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


int search_client(int id)
{
    if (allClients.empty())
    {
        cout << "No clients loaded. Creating default admin...\n";
        return -1;
    }
    for (int i = 0; i < allClients.size(); i++)
        {
        if (allClients[i].get_id() == id)
        {
            return i;
        }
    }
    return -1;
}

int search_employee(int id)
{
    if (allEmployees.empty())
    {
        cout << "No employees loaded.\n";
        return -1;
    }
    for (int i = 0; i < allEmployees.size(); i++)
        {
        if (allEmployees[i].get_id() == id)
        {
            return i;
        }
    }
    return -1;
}

int search_admin(int id)
{
    if (allAdmins.empty())
    {
        cout << "No admins loaded.\n";
        return -1;
    }

    for (int i = 0; i < allAdmins.size(); i++)
        {
        if (allAdmins[i].get_id() == id)
        {
            return i;
        }
    }
    return -1;
}


void showSplashScreen(int consoleWidth)
{
    clearScreen();
    setGoldColor();

    cout << string(4, '\n');

    printCentered("===============================================", consoleWidth);

    printCentered("", consoleWidth);

    // Big EGB with stars
    printCentered("@@@@@@   @@@@@@    @@@@@@@@", consoleWidth);
    printCentered("@@       @         @@    @@", consoleWidth);
    printCentered("@@@@@@   @  @@@@   @@@@@@@@ ", consoleWidth);
    printCentered("@@       @     @   @@    @@", consoleWidth);
    printCentered("@@@@@@   @@@@@@@   @@@@@@@@", consoleWidth);

    cout << endl;


    printCentered("EGYPT GLOBAL BANK", consoleWidth);
    cout << endl;


    printCentered("Empowering Your Future, Globally.", consoleWidth);

    printCentered("===============================================", consoleWidth);

    cout << string(3, '\n');

    this_thread::sleep_for(chrono::seconds(2));



    printCentered("System Loading...", consoleWidth);


    this_thread::sleep_for(chrono::seconds(3));

    cout << endl;
    clearScreen();
}


void handleExitModule(const int consoleWidth)
{
                clearScreen();
            printCentered("===============================================", consoleWidth);
            cout << endl << endl;
            printCentered("@@@@@    @@@@@   @@@@@@     @   @    @@@@@    @    @     @@@@@@   @@@@@   @@@@@   @    @", consoleWidth);
            printCentered("@@       @       @          @   @    @   @    @    @     @@       @   @   @   @   @    @", consoleWidth);
            printCentered(" @@@@    @@@@@   @@@@         @      @   @    @    @       @@@@   @   @   @   @   @@   @", consoleWidth);
            printCentered("   @@    @       @            @      @   @    @    @         @@   @   @   @   @   @  @ @", consoleWidth);
            printCentered("@@@@@    @@@@@   @@@@@@       @      @@@@@    @@@@@@      @@@@@   @@@@@   @@@@@   @   @@", consoleWidth);
            cout << endl << endl;
            printCentered("===============================================", consoleWidth);

            this_thread::sleep_for(chrono::seconds(2));



            printCentered("Thanks For Your Time", consoleWidth);
}


void showMainMenu(short &module, const int consoleWidth) {
  printCentered("WELCOME TO EGB BANK", consoleWidth);
  printCentered("=================================", consoleWidth);
  printCentered("APP MODULES", consoleWidth);
  printCentered("===============", consoleWidth);
  cout << endl;
  cout << "(1) Client Module" << endl;
  cout << "(2) Employee Module" << endl;
  cout << "(3) Admin Module" << endl;
  cout << "(4) Exit" << endl << endl;
  cout << "ENTER YOUR DESIRED MODULE: ";
  cin >> module;
  cout << endl;
  switch (module) {
  case 1: {
    handleClientModule(consoleWidth);
    break;
  }
  case 2: {
    handleEmployeeModule(consoleWidth);
    break;
  }
  case 3: {
    handleAdminModule(consoleWidth);
    break;
  }
  case 4: {
    handleExitModule(consoleWidth);
    break;
  }
  default: {
    setRedColor();
    cout << "INVALID CHOICE , PLEASE TRY AGAIN :)" << endl << endl;
    setGoldColor();
    clearScreen();
  }
  }
}

void runapp() {
  FilesHelper::getClients();
  FilesHelper::getEmployees();
  FilesHelper::getAdmins();
  const int consoleWidth = 100;

  showSplashScreen(consoleWidth);

  short module;
  do {
    showMainMenu(module, consoleWidth);
  } while (module != 4);


}
