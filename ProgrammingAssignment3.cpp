/*
 * CSC/CIS-5-47991/47992 Program Logic Using C++ Spring 2023
 *
 * STUDENT:    Austin De La Cruz
 * ASSIGNMENT: Programming Assignment 3
 * DUE DATE:   05/24/2023
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

/*
 * Name: ID/PW Database
 * Description: A program to manage a password database of user IDs and passwords.
 */

struct User 
{
    string username;
    string password;
};

const int optionCount = 4;
const string options[] = {"Change", "Lookup", "Save", "Exit"};

enum OptionType {CHANGE, LOOKUP, SAVE, EXIT};

OptionType getOptionType(const string& choice) 
{
    if (choice == "Change") 
    {
        return CHANGE;
    } 
    else if (choice == "Lookup") 
    {
        return LOOKUP;
    } 
    else if (choice == "Save") 
    {
        return SAVE;
    } 
    else if (choice == "Exit") 
    {
        return EXIT;
    } else 
    {
        return EXIT; 
    }
}

int main() 
{
    string dbFile;
    cout << "Enter the name of password database: ";
    getline(cin, dbFile);

    ifstream file(dbFile);
    if (!file.is_open()) 
    {
        cout << "Database file not found." << endl;
        return 1;
    }

    int entryCount = 0;
    file >> entryCount;

    // DB ID/PW pair
    string dbUsername, dbPassword;
    file >> dbUsername >> dbPassword;

    // database
    User db;
    db.username = dbUsername;
    db.password = dbPassword;
    User* users = new User[entryCount];
    users[0] = db;

    // Read the rest of the ID and PW 
    for (int i = 1; i < entryCount; i++) 
    {
        string username, password;
        file >> username >> password;
        users[i].username = username;
        users[i].password = password;
    }

    file.close();

    // DB login
    string inputUsername, inputPassword;
    cout << "Enter your username: ";
    getline(cin, inputUsername);
    cout << "Enter your password: ";
    getline(cin, inputPassword);

    if (inputUsername == db.username && inputPassword == db.password) 
    {
        while (true) 
        {
            cout << "\nSelect an option:" << endl;
            for (int i = 0; i < optionCount; i++) 
            {
                cout << options[i] << endl;
            }
            cout << "Option? ";

            string choice;
            getline(cin, choice);

            OptionType option = getOptionType(choice);

            switch (option) 
            {
                case CHANGE: 
                {
                    string changeUsername, newPassword;
                    cout << "Enter ID to change: ";
                    getline(cin, changeUsername);

                    bool found = false;
                    for (int i = 0; i < entryCount; i++) 
                    {
                        if (users[i].username == changeUsername) 
                        {
                            cout << "Enter new password: ";
                            getline(cin, newPassword);
                            users[i].password = newPassword;
                            cout << "Entry saved." << endl;
                            found = true;
                            break;
                        }
                    }

                    if (!found) 
                    {
                        cout << "Username '" << changeUsername << "' not found." << endl;
                    }

                    break;
                }
                case LOOKUP: 
                {
                    string lookupUsername;
                    cout << "ID to lookup: ";
                    getline(cin, lookupUsername);

                    bool found = false;
                    for (int i = 0; i < entryCount; i++) 
                    {
                        if (users[i].username == lookupUsername) 
                        {
                            cout << "Password: " << users[i].password << endl;
                            found = true;
                            break;
                        }
                    }

                    if (!found) 
                    {
                        cout << "'" << lookupUsername << "' not found." << endl;
                    }

                    break;
                }
                case SAVE: 
                {
                    ofstream outFile(dbFile);
                    if (!outFile.is_open()) 
                    {
                        cout << "Error saving the database." << endl;
                        return 1;
                    }

                    outFile << entryCount << endl;
                    outFile << db.username << " " << db.password << endl;

                    for (int i = 1; i < entryCount; i++) 
                    {
                        outFile << users[i].username << " " << users[i].password << endl;
                    }

                    outFile.close();
                    cout << "DB updated." << endl;

                    break;
                }
                case EXIT: 
                {
                    delete[] users;
                    return 0;
                }
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        }
    } else 
    {
        cout << "Incorrect username or password." << endl;
        delete[] users;
        return 1;
    }
}