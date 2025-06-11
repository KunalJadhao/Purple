#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person { // Base Class or the Parent class
protected:
    string name;
    string email;
    long phone;  // Changed from int to long to accommodate larger phone numbers

public:
    // Constructor
    Person(string n, string e, long p) : name(n), email(e), phone(p) {}
    virtual void showDetails() = 0; // pure virtual function
    virtual ~Person() {} // Virtual Destructor
};

class User : public Person { // Inheritance
    string university;
    string education;

public:
    User(string n, string u, string e, long p, string ed)
        : Person(n, e, p), university(u), education(ed) {}

    void showDetails() override { // override function
        cout << "\n--- FreeLancer ---\n"
             << "Name: " << name << "\n"
             << "Email: " << email << "\n"
             << "University: " << university << "\n"
             << "Education: " << education << "\n"
             << "Phone: " << phone << endl;
    }
};

class Client : public Person {
    string company;
    string role;

public:
    Client(string n, string e, long p, string c, string r)
        : Person(n, e, p), company(c), role(r) {}

    void showDetails() override {  // override function
        cout << "\n--- Client ---\n"
             << "Name: " << name << "\n"
             << "Email: " << email << "\n"
             << "Company: " << company << "\n"
             << "Role: " << role << "\n"
             << "Phone: " << phone << endl;
    }
};

struct Work {
    int id;
    string title;
    string description;  // Structure to show a work
    int hours;
    string author;
    int rating = 0; 

    void show() {
        cout << "\n--- Work ---\n"
             << "ID: " << id << "\n"
             << "Title: " << title << "\n"
             << "Description: " << description << "\n"
             << "Hours: " << hours << "\n"
             << "Author: " << author << "\n"
             << "Rating: " << (rating ? to_string(rating) + "/5" : "Not rated yet") << endl;
    }
};

class PurpleLance {
    vector<Work> works; // Storing all works

    Work getWorkInput() {
        Work w;
        cout << "\nEnter work details:\n";
        cout << "ID: ";
        cin >> w.id;
        cin.ignore();
        cout << "Title: ";
        getline(cin, w.title);
        cout << "Description: ";
        getline(cin, w.description);
        cout << "Author: ";
        getline(cin, w.author);
        cout << "Hours: ";
        cin >> w.hours;
        works.push_back(w); // Storing the new work
        return w;
    }

    User getUserInput() {
        string name;
        string university;
        string email; 
        string education;
        long phone;  // Changed to long

        cin.ignore();
        cout << "\nEnter user details:\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Email: ";
        getline(cin, email);
        cout << "University: ";
        getline(cin, university);
        cout << "Education: ";
        getline(cin, education);
        cout << "Phone: ";
        cin >> phone;

        return User(name, university, email, phone, education);
    }

    Client getClientInput() {
        string name, email, company, role;
        long phone;  // Changed to long

        cin.ignore();
        cout << "\nEnter client details:\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Email: ";
        getline(cin, email);
        cout << "Company: ";
        getline(cin, company);
        cout << "Role: ";
        getline(cin, role);
        cout << "Phone: ";
        cin >> phone;

        return Client(name, email, phone, company, role);  
    }

    void rateWork() { // function to rate the work using the conditional statements
        if (works.empty()) {
            cout << "No works available to rate!\n";
            return;
        }

        cout << "\nAvailable Works:\n";
        for (const auto& work : works) {
            cout << "ID: " << work.id << " - " << work.title << endl;
        }

        int workId;
        cout << "Enter Work ID to rate: ";
        cin >> workId;

        auto it = find_if(works.begin(), works.end(), 
            [workId](const Work& w) { return w.id == workId; });

        if (it == works.end()) {
            cout << "Work ID not found!\n";
            return;
        }

        int rating;
        cout << "Enter rating (1-5): ";
        cin >> rating;

        while (rating < 1 || rating > 5) {
            cout << "Invalid rating! Please enter between 1-5: ";
            cin >> rating;
        }

        it->rating = rating;
        cout << "Rating saved successfully for work '" << it->title << "'\n";
    }

public:
    void run() {
        while (true) {
            cout << "---- PurpleLance ----" << endl;
            
            cout << "\n1. Post Work\n"
                 << "2. Add User\n"
                 << "3. Add Client\n"
                 << "4. Rate Work\n"
                 << "5. Exit\n"
                 << "Choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    Work w = getWorkInput();
                    w.show();
                    break;
                }
                case 2: {
                    User u = getUserInput();
                    u.showDetails();
                    break;
                }
                case 3: {
                    Client c = getClientInput();
                    c.showDetails();
                    break;
                }
                case 4: {
                    rateWork();
                    break;
                }
                case 5:
                    cout << "Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }
};

int main() {
    PurpleLance system;
    system.run();
    return 0;
}
