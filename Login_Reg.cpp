#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check if username already exists
bool userExists(const string &username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) return true;
    }
    return false;
}

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    // Check if username exists
    if (userExists(username)) {
        cout << "Username already exists!!! Try another one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Validate password length
    if (password.length() < 5) {
        cout << "Password must be at least 5 characters long.\n";
        return;
    }

    // Store user credentials
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful! You can now log in.\n";
}

// Function to login a user
void loginUser() {
    string username, password, u, p;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "No users registered yet!!!\n";
        return;
    }

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login successful!! Welcome, " << username << ".\n";
    else
        cout << "Invalid username or password.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting..."; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
