#include "AdminManager.h"

#include "Admin.h"
#include "Employee.h"
#include "Screens.h"

#include <iostream>
#include <string>


#include <chrono>
#include <iomanip>
#include <thread>
#include <windows.h>

using namespace std;

void handleAdminModule(const int consoleWidth)
{
  int index_of_admin;
  int a_id;
  string a_password;
  int admin_choice;

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
                printCentered("LOG IN AS ADMIN", consoleWidth);
                printCentered("=================================", consoleWidth);
                cout << endl;
                cout << "ENTER YOUR ID: ";
                cin >> a_id;
                cout << endl;
                cout << "ENTER YOUR PASSWORD: ";
                cin >> a_password;
                cout << endl;
                if (search_admin(a_id) == -1)
                {
                setRedColor();
                cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
                setGoldColor();
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
                }
            else
            {
                index_of_admin = search_admin(a_id);
                if (allAdmins[index_of_admin].get_password() != a_password)
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
                    printCentered("/*  Admin Options  *\\ ", consoleWidth);
                    printCentered("=================================", consoleWidth);
                    cout << "(1)  See System Statistics" << endl;
                    cout << "(2)  Risk Assessment" << endl;
                    cout << "(3)  Increase Employee's Salary" << endl;
                    cout << "(4)  Change Password" << endl;
                    cout << "(5)  Decrease Employee's Salary" << endl;
                    cout << "(6)  Add Employee" << endl;
                    cout << "(7)  Search Employees" << endl;
                    cout << "(8)  List all Employees" << endl;
                    cout << "(9)  View Profile" << endl;
                    cout << "(10) Return to Home Screen" << endl << endl;
                    cout << " ENTER YOUR WISH: ";
                    cin >> admin_choice;
                    cout << endl;
                    switch(admin_choice)
                    {
                    case 1:
                        {
                           clearScreen();
                           cout << "till which client ... Enter his ID: ";
                           cin>>id;
                           if (search_client(id) != -1)
                           {
                           int temp = id;
                           cout << endl << "till which employee ... Enter his ID: ";
                           cin >> id;
                           if (search_employee(id) != -1)
                           {
                              allAdmins[index_of_admin].see_system_statistics_till(allAdmins[index_of_admin].searchClient(temp)
                                                                                   ,allAdmins[index_of_admin].searchEmployee(id));
                           }
                           else
                           {
                                setRedColor();
                                cout << endl << "ERROR! Invalid Employee's ID" << endl;
                                setGoldColor();
                                this_thread::sleep_for(chrono::seconds(2));
                                clearScreen();
                           }
                           }
                           else
                           {
                                setRedColor();
                                cout << endl << "ERROR! Invalid Client's ID" << endl;
                                setGoldColor();
                                this_thread::sleep_for(chrono::seconds(2));
                                clearScreen();
                           }
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
                           allAdmins[index_of_admin].risk_assessment(allClients[search_client(id)]);
                           cout << "\nPress Enter to return to menu...";
                           cin.ignore();
                           cin.get();
                           break;
                        }
                    case 3:
                        {
                           clearScreen();
                           cout << "Enter the ID of the desired employee: ";
                           cin >> id;
                           cout << endl << "Enter the desired amount: ";
                           cin >> amount;
                           allAdmins[index_of_admin].increase_salary(allEmployees[search_employee(id)] , amount);
                           setGreenColor();
                           cout << "Successfully Increased :)" << endl;
                           setGoldColor();
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
                            allAdmins[index_of_admin].set_password(n_password);
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
                            cout << "Enter the ID of the desired employee: ";
                            cin >> id;
                            cout << endl << "Enter the desired amount: ";
                            cin >> amount;
                            allAdmins[index_of_admin].decrease_salary(allEmployees[search_employee(id)] , amount);
                            setGreenColor();
                            cout << "Successfully Decreased :)" << endl;
                            setGoldColor();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;

                        }
                    case 6:
                        {
                            clearScreen();
                            cout << "Enter the name of the desired employee: ";
                            cin >> name;
                            if (Validate::validate_name(name))
                            {
                            cout << "Enter his password: ";
                            cin >> n_password;
                            if (Validate::validate_password(n_password))
                            {
                            cout << "Enter his salary: ";
                            cin >> amount;
                            if (amount >= 5000)
                            {
                                Employee e(name,n_password,amount);
                                allAdmins[index_of_admin].addEmployee(e);
                            }
                            else
                            {
                                setRedColor();
                                cout << endl << "Salary must be >= 5000 :)" << endl;
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
                    case 7:
                        {
                            clearScreen();
                            cout << "Enter the ID of the desired employee: ";
                            cin >> id;
                            Employee* e = allAdmins[index_of_admin].searchEmployee(id);
                            setGreenColor();
                            cout << "Here is his profile: " << endl;
                            setGoldColor();
                            e->display();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 8:
                        {
                            clearScreen();
                            allAdmins[index_of_admin].listEmployee();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 9:
                        {
                            clearScreen();
                            allAdmins[index_of_admin].display();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 10:
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
                while(admin_choice != 10);
                }


            }

            }
            while(search_admin(a_id) == -1  ||  (allAdmins[index_of_admin].get_password() != a_password)  );
}
