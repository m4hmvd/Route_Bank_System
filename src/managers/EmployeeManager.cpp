
#include "EmployeeManager.h"

#include "Client.h"
#include "Employee.h"
#include "Screens.h"

#include <iostream>
#include <string>

#include <chrono>
#include <iomanip>
#include <thread>
#include <windows.h>

using namespace std;



void handleEmployeeModule(const int consoleWidth)
{
  int index_of_employee;
  int e_id;
  string e_password;
  int employee_choice;

  int id;
  string name;
  string c_password;
  string n_password;
  double salary;
  double amount;
  clearScreen();
             do
            {
                clearScreen();
                printCentered("LOG IN AS EMPLOYEE", consoleWidth);
                printCentered("=================================", consoleWidth);
                cout << endl;
                cout << "ENTER YOUR ID: ";
                cin >> e_id;
                cout << endl;
                cout << "ENTER YOUR PASSWORD: ";
                cin >> e_password;
                cout << endl;
                if (search_employee(e_id) == -1)
                {
                setRedColor();
                cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
                setGoldColor();
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
                }
            else
            {
                index_of_employee = search_employee(e_id);
                if (allEmployees[index_of_employee].get_password() != e_password)
                {
                    setRedColor();
                    cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
                    setGoldColor();
                    this_thread::sleep_for(chrono::seconds(2));
                    clearScreen();
                }
                else
                {
                    do
                    {
                    clearScreen();
                    printCentered("/*  Employee Options  *\\ ", consoleWidth);
                    printCentered("=================================", consoleWidth);
                    cout << "(1)  Check Salary" << endl;
                    cout << "(2)  Activate Client" << endl;
                    cout << "(3)  Deactivate Client" << endl;
                    cout << "(4)  Change Password" << endl;
                    cout << "(5)  Change Client's Password" << endl;
                    cout << "(6)  Count Clients" << endl;
                    cout << "(7)  Check Client's Balance" << endl;
                    cout << "(8)  Add Client" << endl;
                    cout << "(9)  Search Client" << endl;
                    cout << "(10) List all Clients" << endl;
                    cout << "(11) View Profile" << endl;
                    cout << "(12) Return to Home Screen" << endl << endl;
                    cout << " ENTER YOUR WISH: ";
                    cin >> employee_choice;
                    cout << endl;
                    switch(employee_choice)
                    {
                    case 1:
                        {
                           clearScreen();
                           cout << "Your Salary is: " << allEmployees[index_of_employee].get_salary() << endl;
                           cout << "\nPress Enter to return to menu...";
                           cin.ignore();
                           cin.get();
                           break;
                        }
                    case 2:
                        {
                           clearScreen();
                           cout << "Enter the ID of the desired client: ";
                           cin >> id;
                           allEmployees[index_of_employee].activate_client(allClients[search_client(id)]);
                           cout << "\nPress Enter to return to menu...";
                           cin.ignore();
                           cin.get();
                           break;
                        }
                    case 3:
                        {
                           clearScreen();
                           cout << "Enter the ID of the desired client: ";
                           cin >> id;
                           allEmployees[index_of_employee].deactivate_client(allClients[search_client(id)]);
                           cout << "\nPress Enter to return to menu...";
                           cin.ignore();
                           cin.get();
                           break;
                        }
                    case 4:
                        {
                            clearScreen();
                            cout << "Enter the new desired password: ";
                            cin >> n_password;
                            allEmployees[index_of_employee].set_password(n_password);
                            if(Validate::validate_password(n_password))
                            {
                                setGreenColor();
                                cout << "Successfully! Your Password Updated :)" << endl;
                                setGoldColor();
                            }
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 5:
                        {
                            clearScreen();
                            cout << "Enter the ID of the desired client: ";
                            cin >> id;
                            cout << endl << "Enter his desired password: ";
                            cin >> n_password;
                            allEmployees[index_of_employee].update_client_password(allClients[search_client(id)] , n_password);
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;

                        }
                    case 6:
                        {
                            clearScreen();
                            cout << "Enter the ID of the desired client: ";
                            cin >> id;
                            cout << "Number of clients: " << allEmployees[index_of_employee].count_clients_till(allEmployees[index_of_employee].searchClient(id)) << endl;
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 7:
                        {
                            clearScreen();
                            cout << "Enter the ID of the desired client: ";
                            cin >> id;
                            allEmployees[index_of_employee].view_client_balance(allEmployees[index_of_employee].searchClient(id));
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 8:
                        {
                            clearScreen();
                            cout << "Enter the name of the desired client: ";
                            cin >> name;
                            if (Validate::validate_name(name))
                            {
                            cout << "Enter his password: ";
                            cin >> n_password;
                            if (Validate::validate_password(n_password))
                            {
                            cout << "Enter his balance: ";
                            cin >> amount;
                            if (amount >= 1500)
                            {
                                Client c(name,n_password,amount);
                                allEmployees[index_of_employee].addClient(c);
                            }
                            else
                            {
                                setRedColor();
                                cout << endl << "Balance must be >= 1500 :)" << endl;
                                setGoldColor();
                                this_thread::sleep_for(chrono::seconds(2));
                                clearScreen();
                            }
                            }
                            else
                            {
                                setRedColor();
                                cout << endl << "Invalid password, it should be from 8 to 20 characters..." << endl;
                                setGoldColor();
                                this_thread::sleep_for(chrono::seconds(2));
                                clearScreen();
                            }
                            }
                            else
                            {
                            setRedColor();
                            cout << endl << "Invalid name, it should be only 5 to 20 alphabetic characters only :)" << endl;
                            setGoldColor();
                            this_thread::sleep_for(chrono::seconds(2));
                            clearScreen();
                            }
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 9:
                        {
                            clearScreen();
                            cout << "Enter the ID of the desired client: ";
                            cin >> id;
                            Client* c = allEmployees[index_of_employee].searchClient(id);
                            setGreenColor();
                            cout << "Here is his profile: " << endl;
                            setGoldColor();
                            c->display();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 10:
                        {
                            clearScreen();
                            allEmployees[index_of_employee].listClient();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 11:
                        {
                            clearScreen();
                            allEmployees[index_of_employee].display();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 12:
                        {
                            clearScreen();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            clearScreen();
                            break;
                        }
                    default:
                        {
                           setRedColor();
                           cout << "INVALID CHOICE , PLEASE TRY AGAIN :)" << endl << endl;
                           setGoldColor();
                           this_thread::sleep_for(chrono::seconds(2));
                           clearScreen();
                           break;
                        }
                     }
                }
                while(employee_choice != 12);
                }


            }

            }
            while(search_employee(e_id) == -1  ||  (allEmployees[index_of_employee].get_password() != e_password)  );

}
