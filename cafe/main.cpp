#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;

const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "password";
const string ITEMS_FILE = "items.txt";

struct Item {
    int number;
    string name;
    double price;
    string size;
};

struct Order {
    int itemNumber;
    int quantity;
};

vector<Item> items;
vector<Order> orders;

void loadItems() {
    ifstream inFile(ITEMS_FILE);

    if (inFile.is_open()) {
        int number;
        string name;
        double price;
        string size;

        while (inFile >> number && getline(inFile, name, '|') && inFile >> price >> size) {
            Item newItem = {number, name.substr(1), price, size};
            items.push_back(newItem);
        }

        inFile.close();
    }
}

void saveItems() {
    ofstream outFile(ITEMS_FILE);

    if (outFile.is_open()) {
        for (int i = 0; i < items.size(); i++) {
            outFile << items[i].number << " " << items[i].name << "|" << items[i].price << " " << items[i].size << endl;
        }

        outFile.close();
    }
}

void addItem() {
    int number;
    string name;
    double price;
    string size;

    cout << "Enter item number: ";
    cin >> number;
    cin.ignore();
    cout << "Enter item name: ";
    getline(cin, name);
    cout << "Enter item price: ";
    cin >> price;
    cout << "Enter item size (small/medium/large): ";
    cin >> size;

    Item newItem = {number, name, price, size};
    items.push_back(newItem);
    saveItems();

   cout<<"Item added successfully!"<<endl;
}

void deleteItem() {
   int number;

   cout<<"Enter item number to delete: ";
   cin>>number;

   for(int i=0;i<items.size();i++){
       if(items[i].number==number){
           items.erase(items.begin()+i);
           saveItems();
           cout<<"Item deleted successfully!"<<endl;
           return;
       }
   }

   cout<<"Sorry, we couldn't find the item you were looking for."<<endl;
}

void updateItem() {
   int number;
   string name;
   double price;
   string size;

   cout<<"Enter item number to update: ";
   cin>>number;

   for(int i=0;i<items.size();i++){
       if(items[i].number==number){
           cin.ignore();
           cout<<"Enter new item name: ";
           getline(cin,name);
           cout<<"Enter new item price: ";
           cin>>price;
           cout<<"Enter new item size (small/medium/large): ";
           cin>>size;

           items[i].name=name;
           items[i].price=price;
           items[i].size=size;

           saveItems();
           cout<<"Item updated successfully!"<<endl;
           return;
       }
   }

   cout<<"Sorry, we couldn't find the item you were looking for."<<endl;
}

void searchItem() {
   int number;

   cout<<"Enter item number to search: ";
   cin>>number;

   for(int i=0;i<items.size();i++){
       if(items[i].number==number){
           cout<<"Item found: "<<items[i].name<<", $"<<items[i].price<<", Number: "<<items[i].number<<", Size: "<<items[i].size<<endl;
           return;
       }
   }

   cout<<"Sorry, we couldn't find the item you were looking for."<<endl;
}

void showItems() {
   if(items.size()==0){
       cout<<"Sorry, there are no items available at the moment."<<endl;
       return;
   }

   cout<<"Items:"<<endl;
   for(int i=0;i<items.size();i++){
       cout<<items[i].name<<", $"<<items[i].price<<", Number: "<<items[i].number<<", Size: "<<items[i].size<<endl;
   }
}

void addOrder() {
    int number;
    int quantity;

    showItems();

    cout << "Enter item number to order: ";
    cin >> number;

    bool found = false;

    for (int i = 0; i < items.size(); i++) {
        if (items[i].number == number) {
            found = true;

            cout << "Enter quantity: ";
            cin >> quantity;

            Order newOrder = {number, quantity};
            orders.push_back(newOrder);

            cout << "Order added successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, we couldn't find the item you were looking for." << endl;
    }
}

void showOrders() {
    if (orders.size() == 0) {
        cout << "No orders have been placed yet." << endl;
        return;
    }

    double total = 0;

    cout << endl << "Receipt:" << endl;
    cout << "Item\t\tQuantity\tTotal" << endl;

    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < items.size(); j++) {
            if (items[j].number == orders[i].itemNumber) {
                double orderTotal = items[j].price * orders[i].quantity;
                total += orderTotal;

                cout << items[j].name << "" << orders[i].quantity << "$" << orderTotal << endl;
                break;
            }
        }
    }

    cout << endl << "Total: $" << total << endl;
}

void placeOrder() {
    int choice;

    while (true) {
        cout << endl
             << "Place Order" << endl
             << "1. Add Order" << endl
             << "2. Show Orders" << endl
             << "3. Checkout" << endl
             << "4. Cancel" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                showOrders();
                break;
            case 3:
                showOrders();
                orders.clear();
                cout<<endl<<"Thank you for your order!"<<endl;
                return;
            case 4:
                orders.clear();
                return;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }
}

bool adminLogin() {
   string enteredUsername;
   string enteredPassword="";
   char ch;

   cout<<"\t\tAdmin Login\n"<<endl
   <<"Enter your username: ";
   cin>>enteredUsername;
   cout<<"Enter your password: ";

   ch=_getch();
   while(ch!=13){
       enteredPassword+=ch;
       cout<<"*";
       ch=_getch();
   }

   if(enteredUsername==ADMIN_USERNAME && enteredPassword==ADMIN_PASSWORD){
       return true;
   }else{
       return false;
   }
}

int main() {
   loadItems();

   int choice;

   while(true){
       cout<<endl<<"Coffee Management System"<<endl<<"1. Admin Login"<<endl<<"2. Show Items"<<endl<<"3. Place Order"<<endl<<"4. Exit"<<endl<<"Enter your choice: ";
       cin>>choice;

       switch(choice){
           case 1:
               if(adminLogin()){
                   int adminChoice;

                   while(true){
                       cout<<endl<<"Admin Menu"<<endl<<"1. Add Item"<<endl<<"2. Delete Item"<<endl<<"3. Update Item"<<endl<<"4. Search Item"<<endl<<"5. Show Items"<<endl<<"6. Logout"<<endl<<"Enter your choice: ";
                       cin>>adminChoice;

                       switch(adminChoice){
                           case 1:
                               addItem();
                               break;
                           case 2:
                               deleteItem();
                               break;
                           case 3:
                               updateItem();
                               break;
                           case 4:
                               searchItem();
                               break;
                           case 5:
                               showItems();
                               break;
                           case 6:
                               cout<<"Logged out successfully!"<<endl;
                               break;
                           default:
                               cout<<"Invalid choice!"<<endl;
                       }

                       if(adminChoice==6){
                           break;
                       }
                   }
               }else{
                   cout<<"Invalid username or password!"<<endl;
               }
               break;
           case 2:
               showItems();
               break;
           case 3:
               placeOrder();
               break;
           case 4:
               cout<<"Thank you for using our system!"<<endl;
               return 0;
           default:
               cout<<"Invalid choice!"<<endl;
       }
   }

   return 0;
}
