#include <iostream>
#include <string>
using namespace std;

struct NameType 
{
  string firstname;
  string middlename;
  string lastname;
};

struct DateType 
{
  int day;
  int month;
  int year;
};

struct ContactType 
{
  string email;
  string phone;
  string fax;
};

struct AddressType 
{
  string houseno;
  string streetno;
  string commune;
  string district;
  string province;
};

class EmployeeType
{
private:
  int emp;
  NameType name;
  string gender;
  DateType birthdate;
  ContactType contact;
  AddressType address;
public:
  EmployeeType() 
  {
    emp = 0;
    name = {"", "", ""};
    gender = "";
    birthdate = {0, 0, 0};
    contact = {"", "", ""};
    address = {"", "", "", "", ""};
  }

  EmployeeType(int e, NameType n, string g, DateType b, ContactType c, AddressType a) 
  {
    emp = e;
    name = n;
    gender = g;
    birthdate = b;
    contact = c;
    address = a;
  }

  int getEmp() { return emp; }
  void setEmp(int e) { emp = e; }

  NameType getName() { return name; }
  void setName(NameType n) { name = n; }

  string getGender() { return gender; }
  void setGender(string g) { gender = g; }

  DateType getBirthdate() { return birthdate; }
  void setBirthdate(DateType b) { birthdate = b; }

  ContactType getContact() { return contact; }
  void setContact(ContactType c) { contact = c; }

  AddressType getAddress() { return address; }
  void setAddress(AddressType a) { address = a; }

  void showInfo() 
  {
    cout << "Employee ID: " << emp << endl;
    cout << "Name: " << name.lastname << " " << name.middlename << " " << name.firstname << endl;
    cout << "Gender: " << gender << endl;
    cout << "Birthdate: " << birthdate.day << "/" << birthdate.month << "/" << birthdate.year << endl;
    cout << "Contact Information:\nEmail: " << contact.email << "\nPhone: " << contact.phone 
		 << "\nFacility: " << contact.fax << endl;
    cout << "Address:\nHouse Number: " << address.houseno << "\nStreet Number: " << address.streetno 
		 << "\nCommune: " << address.commune << "\nDistrict: " << address.district << "\nProvince: " 
		 << address.province << endl;
  }
};

int main() 
{
  
  EmployeeType emp1(1, {"Heng", "Akphy", "vath"}, "Male", {14, 9, 2003},
  						  {"Vathheng@me.com", "010900664", "IT"}, 
						  {"168", "St-132z.", "3", "Terk Lahork1", "Phnom Penh"});
  emp1.showInfo();

  return 0;
}