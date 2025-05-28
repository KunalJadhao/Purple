#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Work {
public:
    int ID;
    string worktitle;
    string description;
    int timegiven;
    string uploadedby;

    Work(int i, string w, string d, string u, int t)
        : ID(i), worktitle(w), description(d), uploadedby(u), timegiven(t) {}

    void show() {
        cout << "\n Work Details \n";
        cout << " ID: " << ID << endl;
        cout << " Work: " << worktitle << endl;
        cout << " Description: " << description << endl;
        cout << " Time Given: " << timegiven << " hours" << endl;
        cout << " Uploaded by: " << uploadedby << endl;
    }
};

class User {
public:
    string Name;
    string Email;
    string University;
    int Number;
    string Education;

    User(string name, string university, string email, int number, string education)
        : Name(name), University(university), Email(email), Number(number), Education(education) {}

    void show() {
        cout << "\n--- User Info ---\n";
        cout << " Name: " << Name << endl;
        cout << " Email: " << Email << endl;
        cout << " Education: " << Education << endl;
        cout << " University: " << University << endl;
        cout << " Phone Number: " << Number << endl;
    }
};

class PurpleLance {

    void inputWorkDetails() {
        int Id; 
        int time;
        string worktitle;
        string description; 
        string uploadedby;

        cout << "\nEnter Work Details:\n";
        cout << " ID: "; 
        cin >> Id;
        cin.ignore();
        cout << " Work title: "; 
        getline(cin, worktitle);
        cout << " Description: "; 
        getline(cin, description);
        cout << " Uploaded by: "; 
        getline(cin, uploadedby);
        cout << " Time given (hours): "; 
        cin >> time;
    }

    void inputUserDetails() {
        string name, email, university, education;
        int number;

        cout << "\n Enter User Details: \n";
        cin.ignore();
        cout << " Name: "; 
        getline(cin, name); 
        cout << " Email: "; 
        getline(cin, email);
        cout << " Education: "; 
        getline(cin, education);
        cout << " University: "; 
        getline(cin, university);
        cout << "User Registered Successfully!\n";
    }

public:
    void menu() {
        int choice;
        while (true) {
            cout << "\n--- PurpleLance ---\n"
                 << "1. Post Work\n"
                 << "2. Register User\n"
                 << "3. Exit\n"
                 << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: inputWorkDetails(); 
                break;
                case 2: inputUserDetails(); 
                break;
                case 3: cout << "Thank You!!\n"; 
                return;
                default: cout << "Invalid choice!\n";
            }
        }
    }
};

int main() {
    PurpleLance app;
    app.menu();
    return 0;
}
