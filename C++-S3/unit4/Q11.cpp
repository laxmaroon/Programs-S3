#include <iostream>
#include <cstring>

using namespace std;

struct student {
  string usn;
  string name;
  string branch;
  int sem;
  long phno;
  student *next;
};

student *head = NULL;

void insert_at_front(string usn, string name, string branch, int sem, long phno) {
  student *new_student = new student;
  new_student->usn = usn;
  new_student->name = name;
  new_student->branch = branch;
  new_student->sem = sem;
  new_student->phno = phno;
  new_student->next = head;
  head = new_student;
}

void delete_by_name(string name) {
  student *temp = head, *prev = NULL;
  if (temp != NULL && temp->name == name) {
    head = temp->next;
    delete temp;
    return;
  }
  while (temp != NULL && temp->name != name) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) return;
  prev->next = temp->next;
  delete temp;
}

void display_list() {
  student *temp = head;
  int count = 0;
  cout << "USN\tName\tBranch\tSem\tPhNo\n";
  while (temp != NULL) {
    cout << temp->usn << "\t" << temp->name << "\t" << temp->branch << "\t" << temp->sem << "\t" << temp->phno << endl;
    temp = temp->next;
    count++;
  }
  cout << "Number of nodes: " << count << endl;
}

int main() {
  int choice;
  string usn, name, branch;
  int sem;
  long phno;
  while (true) {
    cout << "1. Insert at front\n2. Delete by name\n3. Display list\n4. Exit\nEnter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter USN: ";
        cin >> usn;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter branch: ";
        cin >> branch;
        cout << "Enter sem: ";
        cin >> sem;
        cout << "Enter phone number: ";
        cin >> phno;
        insert_at_front(usn, name, branch, sem, phno);
        break;
      case 2:
        cout << "Enter name: ";
        cin >> name;
        delete_by_name(name);
        break;
      case 3:
        display_list();
        break;
      case 4:
        return 0;
      default:
        cout << "Invalid choice\n";
    }
  }
  return 0;
}
