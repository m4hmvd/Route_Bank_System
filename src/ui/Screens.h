#pragma once

#include <string>

void runapp();

// Shared UI / console helpers
void printCentered(std::string text, int width);
void clearScreen();
void setGoldColor();
void setRedColor();
void setGreenColor();
void setBlueColor();
void resetColor();

// Shared search helpers
int search_client(int id);
int search_employee(int id);
int search_admin(int id);


void showSplashScreen(int consoleWidth);
void handleExitModule(const int consoleWidth);
void showMainMenu(short &module, const int consoleWidth);
