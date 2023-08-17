#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

class CustomerType
{
    string cusid;
    string fname;
    string lname;
    string gender;
    string birthdate;
    string address;
    string tel;


public:
    void setCusid(string cid);
    void setFirstname(string fn);
    void setLastname(string ln);
    void setGender(string g);
    void setBirthdate(string bd);
    void setAddress(string addr);
    void setPhone(string telp);
    void setCustomer(string, string, string, string, string, string, string);
    void getCustomer(string&, string&, string&, string&, string&, string&, string&)const;
    void printCustomer()const;
    bool equalCustomer(const CustomerType&) const;
};
//create members function
    void CustomerType::setCusid(string cid)
    {
        cusid = cid;
    }
    void CustomerType::setFirstname(string fn)
    {
        fname = fn;
    }
    void CustomerType::setLastname(string ln)
    {
        lname = ln;
    }
    void CustomerType::setGender(string g)
    {
        gender = g;
    }
    void CustomerType::setBirthdate(string bd)
    {
        birthdate = bd;
    }
    void CustomerType::setAddress(string addr)
    {
        address = addr;
    }
    void CustomerType::setPhone(string telp)
    {
        tel = telp;
    }
    
    void CustomerType::setCustomer(string cid,string fn, string ln, string g, string bd, string addr, string telp)
    {
        cusid = cid;
        fname = fn;
        lname = ln;
        gender = g;
        birthdate = bd;
        address = addr;
        tel = telp;
    }

    void CustomerType::getCustomer(string &cid, string &fn, string &ln, string &g, string &bd, string &addr, string &telp) const
    {
        cid = cusid;
        fn = fname;
        ln = lname;
        g = gender;
        bd = birthdate;
        addr= address;
        telp = tel;
    }
    
    void CustomerType::printCustomer()const
    {
        cout << "Identification : " << cusid<<endl;
        cout << "First Name     : " << fname<<endl;
        cout << "Last Name      : " << lname<<endl;
        cout << "Gender         : " << gender<<endl;
        cout << "Birth Date     : " << birthdate<<endl;
        cout << "Address        : " <<address<<endl;
        cout << "Telephone      : " <<tel<<endl;
    }
    
    bool CustomerType::equalCustomer(const CustomerType &cus) const
    {
        return (cusid == cus.cusid);
    }

    int main()
    {
        CustomerType cust,c;
        bool check;
        cust.setCustomer("cus-001","Vath","Heng","Male","14=09=2003","Phnom Penh","010900664");
        c = cust;
        check = cust.equalCustomer(c);
        if (check) cout << "The same" <<endl;
        else cout << "NOT the same" <<endl;
        cout << "-------------------------------" <<endl;
        cust.printCustomer();
        return 0;
    }