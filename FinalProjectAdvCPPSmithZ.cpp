// FinalProjectAdvCPPSmithZ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
#include <string>


using namespace std;

class Customer {
    string name,
        address,
        city,
        state,
        zip,
        telephone,
        lastPayment;
    double balance;
public:
    string getName() { return name; }
    string getAddress() { return address; }
    string getCity() { return city; }
    string getState() { return state; }
    string getZip() { return zip; }
    string getTelephone() { return telephone; }
    string getLastPayment() { return lastPayment; }
    double getBalance() { return balance; }

    void setName(string n) { name = n; }
    void setAddress(string n) { address = n; }
    void setCity(string n) { city = n; }
    void setState(string n) { state = n; }
    void setZip(string n) { zip = n; }
    void setTelephone(string n) { telephone = n; }
    void setLastPayment(string n) { lastPayment = n; }

    void setBalance(double b) { balance = b; }

    void readData(ifstream& inFile);

    void writeData(fstream& outFile);

    Customer(string name = "", string address = "", string city = "", string state = "", string zip = "", string telephone = "", string lastPayment = "", double balance = 0);
    /*
    void displayData() {
        cout << "\nName: " << name;
        cout << "\nAddress: " << address << ", " << city << ", " << state << " " << zip;
        cout << "\nPhone: " << telephone;
        cout << "\nDate of last payment: " << lastPayment;
        cout << "\nCurrent balance: " << balance;
    }
    */
};

Customer::Customer(string name, string address, string city, string state, string zip, string telephone, string lastPayment, double balance) {
    this->name = name;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->telephone = telephone;
    this->lastPayment = lastPayment;
    this->balance = balance;
}

void Customer::writeData(fstream& outFile) {
    int nameLength = name.length();
    outFile << "\nName: ";
    outFile.write(name.data(), nameLength);
    
    int addressLength = address.length();
    int cityLength = city.length();
    int stateLength = state.length();
    int zipLength = zip.length();
    outFile << "\nAddress: ";
    outFile.write(address.data(), addressLength);
    outFile << ", ";
    outFile.write(city.data(), cityLength);
    outFile << ", ";
    outFile.write(state.data(), stateLength);
    outFile << " ";
    outFile.write(zip.data(), zipLength);

    int telephoneLength = telephone.length();
    outFile << "\nTelephone: ";
    outFile.write(telephone.data(), telephoneLength);

    int dateOfPaymentLength = lastPayment.length();
    outFile << "\nDate of last payment: ";
    outFile.write(lastPayment.data(), dateOfPaymentLength);

    outFile << "\nCurrent balance: $" << balance;
}

//void enterRecord();

int main()
{
    fstream file("customers.txt", ios::in | ios::out);
    if (file.fail()) {
        cout << "error opening file.";
        return 1;
    }

    int menuChoice = 7;
    while (menuChoice != 6) {
        cout << "\n1) Enter a new record into the file";
        cout << "\n2) Search for a record to display";
        cout << "\n3) Search for a record to delete";
        cout << "\n4) Search for a record to change";
        cout << "\n5) Display entire collect of records";
        cout << "\n6) Exit\n";

        cin >> menuChoice;

        if (menuChoice == 1) {
            string name, address, city, state, zip, telephone, lastPayment;
            double balance = 0;
            do {
                cout << "\nPlease enter a name: ";
                cin >> name;
                cout << "\nPlease enter a street address: ";
                cin >> address;
                cout << "\nPlease enter a city: ";
                cin >> city;
                cout << "\nPlease enter a state: ";
                cin >> state;
                cout << "\nPlease enter a zipcode: ";
                cin >> zip;
                cout << "\nPlease enter a telephone number: ";
                cin >> telephone;
                cout << "\nPlease enter the date of the last payment: ";
                cin >> lastPayment;
                cout << "\nPlease enter the customer balance: ";
                cin >> balance;
            } while (name.empty() || address.empty() || city.empty() || state.empty() || zip.empty() || telephone.empty() || balance < 0);

            Customer newCustomer = Customer(name, address, city, state, zip, telephone, lastPayment, balance);

            newCustomer.writeData(file);
        }
    }
}

//void enterRecord() { }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
