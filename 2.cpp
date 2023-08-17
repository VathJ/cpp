#include <iostream>
#include <string>
using namespace std;

struct NameType {
    string firstname;
    string middlename;
    string lastname;
};

struct DataType {
    int day;
    int month;
    int year;
};

struct ContactType {
    string email;
    string phone;
    string fax;
};

struct AddressType {
    string houseno;
    string streetno;
    string commune;
    string district;
    string province;
};

int main() {
    // Example usage of the structs
    NameType name = {"Heng", "Akphy", "Vath"};
    DataType date = {14, 9, 2003};
    ContactType contact = {"Vathheng@me.com", "010900664", "855"};
    AddressType address = {"164No", "132z","Terk Lahork1", "Phnom Penh", "Cambodia"};

    cout << "Name: " << name.firstname << " " << name.middlename << " " << name.lastname << endl;
    cout << "Date: " << date.day << "/" << date.month << "/" << date.year << endl;
    cout << "Contact: " << contact.email << ", " << contact.phone << ", " << contact.fax << endl;
    cout << "Address: " <<address.houseno << ", " << address.streetno << ", " << address.commune << ", " << address.district << ", " << address.province << endl;

    return 0;
}
