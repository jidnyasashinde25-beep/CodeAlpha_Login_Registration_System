#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Check if username already exists
bool userExists(string username)
{
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            return true;
        }
    }
    return false;
}

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    if (userExists(username))
    {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string user, pass;
    bool found = false;

    cout << "\n===== USER LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass)
    {
        if (user == username && pass == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login Successful! Welcome " << username << " 🎉\n";
    else
        cout << "Invalid Username or Password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== LOGIN SYSTEM ==========\n";
        cout << "1. Register User\n";
        cout << "2. Login User\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
