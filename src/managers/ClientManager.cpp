#include "ClientManager.h"

#include "Client.h"
#include "FilesHelper.h"
#include "Screens.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

void handleClientModule(const int consoleWidth)
{
  int client_choice;
  int index_of_client;
  int c_id;
  string cli_password;

  int id;
  string name;
  string c_password;
  string n_password;
  double balance;
  double amount;
  int hour;
  int minute;
  int second;
  int loan_terms;
  clearScreen();
              do
            {
            cout << "(1) Log In" << endl;
            cout << " * Already you have an account" << endl;
            cout << "(2) Sign Up" << endl;
            cout << "** Don't have an account, Create new account" << endl;
            cout << "(3) Exit" << endl;
            cout << "ENTER YOUR WISH: ";
            cin >> client_choice;
            cout << endl;
            switch(client_choice)
            {
            case 1:
            {
            do
            {
                clearScreen();
                printCentered("LOG IN AS CLIENT", consoleWidth);
                printCentered("=================================", consoleWidth);
                cout << endl;
                cout << "ENTER YOUR ID: ";
                cin >> c_id;
                cout << endl;
                cout << "ENTER YOUR PASSWORD: ";
                cin >> cli_password;
                cout << endl;
                if (search_client(c_id) == -1)
                {
                setRedColor();
                cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
                setGoldColor();
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
                }
            else
            {
                index_of_client = search_client(c_id);
                if (allClients[index_of_client].get_password() != cli_password)
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
                    printCentered("/*  Client Options  *\\ ", consoleWidth);
                    printCentered("=================================", consoleWidth);
                    cout << "(1)  Deposit" << endl;
                    cout << "(2)  Withdraw" << endl;
                    cout << "(3)  Instant Transfer" << endl;
                    cout << "(4)  Scheduled Transfer" << endl;
                    cout << "(5)  Request Loan" << endl;
                    cout << "(6)  Change Password" << endl;
                    cout << "(7)  Check Balance" << endl;
                    cout << "(8)  Check Progress" << endl;
                    cout << "(9) Transactions History" << endl;
                    cout << "(10) Check Loan" << endl;
                    cout << "(11) View Profile" << endl;
                    cout << "(12) Return to Home Screen" << endl << endl;
                    cout << " ENTER YOUR WISH: ";
                    cin >> client_choice;
                    cout << endl;
                    switch(client_choice)
                    {
                    case 1:
                        {
                           clearScreen();
                           cout << "Enter the amount you want to deposit: ";
                           cin >> amount;
                           allClients[index_of_client].deposit(amount);
                           cout << "\nPress Enter to return to menu...";
                           cin.ignore();
                           cin.get();
                           break;
                        }
                    case 2:
                        {
                           clearScreen();
                           cout << "Enter the amount you want to withdraw: ";
                           cin >> amount;
                           allClients[index_of_client].withdraw(amount);
                           setGreenColor();
                           cout << "Successfully! " << amount << " is withdrawn from your balance" << endl << endl;
                           setGoldColor();
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
                           if (search_client(id) == -1)
                           {
                                setRedColor();
                                cout << "INVALID ID ... PLEASE TRY AGAIN :)" << endl;
                                setGoldColor();
                                this_thread::sleep_for(chrono::seconds(2));
                                clearScreen();
                           }
                           else
                           {
                               cout << "Enter the amount you want to transfer: ";
                               cin >> amount;
                               allClients[index_of_client].transfer_to(amount,allClients[search_client(id)]);
                               cout << "\nPress Enter to return to menu...";
                               cin.ignore();
                               cin.get();
                           }
                           break;
                        }
                    case 4:
                        {
                           clearScreen();
                           cout << "Enter the ID of the desired client: ";
                           cin >> id;
                           if (search_client(id) == -1)
                           {
                                setRedColor();
                                cout << "INVALID ID ... PLEASE TRY AGAIN :)" << endl;
                                setGoldColor();
                                this_thread::sleep_for(chrono::seconds(2));
                                clearScreen();
                           }
                           else
                           {
                               cout << "Enter the amount you want to transfer: ";
                               cin >> amount;
                               cout << endl << "Enter the desired hour: ";
                               cin >> hour;
                               cout << endl << "Enter the desired minute: ";
                               cin >> minute;
                               cout << endl << "Enter the desired second: ";
                               cin >> second;
                               cout << "\nAuto transfer scheduled at "
                               << setw(2) << setfill('0') << hour << ":"
                               << setw(2) << setfill('0') << minute << ":"
                               << setw(2) << setfill('0') << second << endl;

                               double c_balance = allClients[index_of_client].get_balance();

                               cout << "Waiting...\n";
                               while (true)
                                 {
                                     allClients[index_of_client].auto_transfer_at(hour,minute,second,amount,allClients[search_client(id)]);

                                     if (allClients[index_of_client].get_balance() < c_balance)
                                      break;
                                 }

                               cout << "\nPress Enter to return to menu...";
                               cin.ignore();
                               cin.get();

                            }
                            break;
                        }
                    case 5:
                        {
                            clearScreen();
                            cout << "1- You will earn 10000 LE and they will be added to your balance" << endl;
                            cout << "2- You will have a 1 year duration to pay this amount" << endl;
                            cout << "3- It's forbidden to do anything that leads to deactivate your account" << endl;
                            cout << "(1) agree  \t\t (2) disagree" << endl;
                            cout << "ENTER YOUR CHOICE: ";
                            cin >> loan_terms;
                            if(loan_terms >= 2)
                            {
                                setRedColor();
                                cout << "Sorry! The loan is not accepted :)" << endl;
                                setGoldColor();
                                this_thread::sleep_for(chrono::seconds(2));
                                clearScreen();
                           }
                           else
                           {
                               allClients[index_of_client].request_loan();
                               cout << "\nPress Enter to return to menu...";
                               cin.ignore();
                               cin.get();
                           }
                           break;

                        }
                    case 6:
                        {
                            clearScreen();
                            cout << "Enter Your Old Password: ";
                            cin >> c_password;
                            if (!allClients[index_of_client].verify_password(c_password))
                            {
                                setRedColor();
                                cout << "Sorry! This one is incorrect :)" << endl;
                                setGoldColor();
                                this_thread::sleep_for(chrono::seconds(2));
                                clearScreen();
                            }
                            else
                            {
                                cout << "Enter the new desired password: ";
                                cin >> n_password;
                                allClients[index_of_client].change_password(c_password,n_password);
                                cout << "\nPress Enter to return to menu...";
                                cin.ignore();
                                cin.get();
                            }
                            break;
                        }
                    case 7:
                        {
                            clearScreen();
                            allClients[index_of_client].check_balance();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 8:
                        {
                            clearScreen();
                            allClients[index_of_client].check_account_progress();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 9:
                        {
                            clearScreen();
                            allClients[index_of_client].show_transaction_history();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 10:
                        {
                            clearScreen();
                            cout << "Loans taken: " << allClients[index_of_client].get_loan() << endl;
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    case 11:
                        {
                            clearScreen();
                            allClients[index_of_client].display();
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
                        }
                     }
                }
                while(client_choice != 12);
                }


            }

            }
            while(search_client(c_id) == -1  ||  (allClients[index_of_client].get_password() != cli_password)  );

            break;
            }
            case 2:
                {
                    do
                    {
                    clearScreen();
                    printCentered("SIGN UP AS CLIENT", consoleWidth);
                    printCentered("=================================", consoleWidth);
                    cout << endl;
                    cout << "ENTER YOUR NAME: ";
                    cin >> name;
                    if(!Validate::validate_name(name))
                    {
                       setRedColor();
                       cout << endl << "Invalid name, it should be only 5 to 20 alphabetic characters only :)" << endl;
                       setGoldColor();
                       this_thread::sleep_for(chrono::seconds(2));
                       clearScreen();
                    }
                    else
                    {
                        cout << endl << "ENTER YOUR PASSWORD: ";
                        cin >> c_password;
                        if(!Validate::validate_password(c_password))
                        {
                            setRedColor();
                            cout << "Invalid password, it should be from 8 to 20 characters..." << endl;
                            setGoldColor();
                            this_thread::sleep_for(chrono::seconds(2));
                            clearScreen();
                        }
                        else
                        {
                            Client new_commer(name,c_password);
                            allClients.push_back(new_commer);
                            FilesHelper::saveClient(new_commer);
                            setGreenColor();
                            cout << "Successfully You have an account <3" << endl;
                            cout << "Close and Open the App again to Log in :)" << endl << endl;
                            setRedColor();
                            cout << "/*\t VERY IMPORTANT\t*\\" << endl;
                            setGreenColor();
                            cout << "To Activate your account, You should call the customer service" << endl;
                            cout << "To Ensure, your balance must be greater than or equal 1500" << endl;
                            setGoldColor();
                            cout << "\nPress Enter to return to menu...";
                            cin.ignore();
                            cin.get();
                            clearScreen();
                        }
                    }
                    }
                    while(!(Validate::validate_name(name) && Validate::validate_password(c_password)));
                    break;



                }
            case 3:
                {
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
                }
            }
            }
            while(client_choice > 3);


}
