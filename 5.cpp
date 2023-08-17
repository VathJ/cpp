#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct EmployeeType
{
  string name;
  string position;
  double salary;
};

class EmployeeListType
{
private:
  vector<EmployeeType> vector;
  int length;
  int size;
public:
  EmployeeListType(int s)
  {
    length = 0;
    size = s;
  }

  void addItem(EmployeeType e)
  {
    if (length < size)
	{
      vector.push_back(e);
      length++;
      cout << "Employee added\n";
    }
	 else {
      cout << "Error: List is full\n";
    }
  }


  void deleteItem(int index)
  {
    if (index >= 0 && index < length)
	{
      vector.erase(vector.begin() + index);
      length--;
      cout << "** Employee deleted\n";
    }
	else {
      cout << "Error: Invalid index.\n";
    }
  }


  void updateItem(EmployeeType e)
  {
    bool found = false;
    for (int i = 0; i < length; i++)
	{
      if (vector[i].name == e.name)
	  {
        vector[i] = e;
        found = true;
        cout << "** Employee updated.\n";
        break;
      }
    }
    if (!found) {
      cout << "Error: Employee no found\n";
    }
  }

  void printList() const
  {
    if (length == 0)
	{
      cout << "List is empty.\n";
    }
	else
	{
      cout << "\nEmployee List:\n";
      for (int i = 0; i < length; i++)
	  {
        cout << "Name: " << vector[i].name << endl;
        cout << "Position: " << vector[i].position << endl;
        cout << "Salary: $" << vector[i].salary << endl;
        cout << endl;
      }
    }
  }
};

int main()
{

  EmployeeListType list(3);

  EmployeeType e1 = {"Vath", "Manager", 1000.0};
  list.addItem(e1);

  EmployeeType e2 = {"Thida", "Manager Assistant", 500.0};
  list.addItem(e2);

  EmployeeType e3 = {"Rith", "Sale", 300.0};
  list.addItem(e3);

  list.printList();

  list.deleteItem(1);

  EmployeeType e4 = {"CheaVey", "Support", 10000.0};
  list.updateItem(e4);

  list.printList();

  return 0;
}
