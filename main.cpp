
#include <iostream>
#include <string>
using namespace std;
#define MAX 10
//Employee salary management

class Employee
{
public:
    int m = 0, s = 0, w = 0;
    int postion;
    Employee(string name, int year) : m_strName(name), m_nYear(year) {} //constructor
    virtual ~Employee() {}
    string GetName() const
    {
        return m_strName;
    } //Get the name
    int GetYear() const
    {
        return m_nYear;
    }                            //Get working years
    virtual int GetSalary() = 0; //Get salary
    void Edisplay()
    {
        cout << "Employee Name       : " << m_strName << endl;
        cout << "Employee Experience : " << m_nYear << " Years" << endl;
    }

protected:
    string m_strName;
    int m_nYear;
};
class Supervisor : public Employee
{
public:
    Supervisor(string name, int year) : Employee(name, year)
    {
        postion = 1;
        s++;
    }
    ~Supervisor() {}
    virtual int GetSalary() { return 14000; }
    void Sdisplay()
    {
        cout << "Employee Postion Supervisor" << endl;
        Edisplay();
        cout << "Employee Salary              :" << GetSalary() << endl;
    }
};

class Workers : public Employee
{
protected:
    Supervisor *super = new Supervisor("Rahim ", 2);

public:
    Workers(string name, int year) : Employee(name, year)
    {
        postion = 0;
        w++;
    }
    ~Workers() {}
    virtual int GetSalary() { return 12000; }

    Supervisor get()
    {
        return *super;
    }
    void set(Supervisor *s)
    {
        super = s;
    }
    void Wdisplay()
    {
        cout << "Employee Postion Worker" << endl;
        Edisplay();
        cout << "Employee Salary              :" << GetSalary() << endl;
        cout << "Supervisor Detail" << endl;
        super->Sdisplay();
    }
};

class Manager : public Employee
{
public:
    Manager(string name, int year) : Employee(name, year)
    {
        postion = 2;
        m++;
    }
    ~Manager() {}
    virtual int GetSalary() { return 13000; }
    void Mdisplay()
    {
        cout << "Employee Postion Manager" << endl;
        Edisplay();
        cout << "Employee Salary              :" << GetSalary() << endl;
    }
};

class Node
{
public:
    Employee *data = new Workers("a", 0); 
    Node *next;
};
void push(Node **head_ref, Employee *new_data) // linked list function 
{

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void deleteNode(Node **head_ref, Employee *emp) // linked list function
{

    // Store head node
    Node *temp = *head_ref;
    Node *prev = NULL;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data->GetName() == emp->GetName())
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }

    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
    while (temp != NULL && temp->data->GetName() != emp->GetName())
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    delete temp;
}

// Class for stack
class stack
{
    int SIZE = 5;
    Employee *employee[5]; // total number of employee could be 5; 
    int top;
    int capacity;

public:
    stack(int size = 3); // constructor
    // destructor
    Employee *key;

    void push(Employee *emp);
    Employee *pop();

    int size();
    bool isEmpty();
    bool isFull();
    void display();
    void search();
};

// Constructor to initialize stack
stack::stack(int size)
{
    SIZE = size;
    capacity = size;
    top = -1;
}

// Utility function to add an element x in the stack
void stack::push(Employee *emp)
{
    

    
    employee[++top] = emp;
}

// Utility function to pop top element from the stack
Employee *stack::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
      
    }

    // decrease stack size by 1 and (optionally) return the popped element
    return employee[top--];
}

// Utility function to return the size of the stack
int stack::size()
{
    return top + 1;
}

// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
    return top == -1; // or return size() == 0;
}

// Utility function to check if the stack is full or not
bool stack::isFull()
{
    return top == capacity - 1; // or return size() == capacity;
}
void stack::search()
{
    string name;
    cout << "Enter worker name " << endl;
    cin >> name;
    int i;
    for (i = 0; i <= top; i++)
        if (employee[i]->GetName() == name)
        {
            key = employee[i];
        }
}
void stack::display()
{
    int i = 0;
    while (i <= top)
    {

        cout << "Worker  num is #" << (i + 1) << endl;
        employee[i]->Edisplay();
        cout << "Salary : " << employee[i]->GetSalary() << endl;

        i++;
    } // or return size() == capacity;
}

int menu()
{
    int choice;
    cout<<"---------------------MENU--------------------------------------"<<endl;
    cout << "Please select your choice : " << endl;
    cout << "Select 1 to see all the employee" << endl;
    cout << "Select 2 to see all the workers " << endl;
    cout << "Select 3 to search a worker by name" << endl;
    cout << "Select 4  to add a worker" << endl;
    cout << "Select 5 to give medical leave a worker" << endl;
    cout <<"Select 6 to reduce a worker " << endl;
    cout << "Enter your choice " << endl;
    cin >> choice;
    return choice;
}
void list()
{

    Node *head = NULL;

    head = new Node();
// ageh theke banaye rkhsi
    Employee *emo = new Workers("1", 1);
    Employee *emo1 = new Workers("Ayaz Rahman", 1);
    Employee *emo2 = new Workers("David", 1);
    Employee *emo3 = new Workers("Silvia", 1);
    Employee *emo4 = new Workers("Akib", 1);
    Employee *emo5 = new Manager("Emon", 1);
    Employee *emo6 = new Supervisor("Morshed", 1);
    Employee *emo7 = new Supervisor("Rashed", 1);
// list ey dhukai
   
    push(&head, emo1);
    push(&head, emo2);
    push(&head, emo3);
    push(&head, emo4);
    push(&head, emo5);
    push(&head, emo6);
    push(&head, emo7);
    stack empl(5);

   
    cout << "------------------------------Company detail----------------------" << endl;

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data->postion == 0)
        {
            empl.push(temp->data);
        }
        temp = temp->next;

        if (empl.isFull())
        {
            cout << "Worker list is full" << endl;
            cout << "Sorry !! We have to delete the latest worker !!" << endl;
            break;
        }
    }

    int c = menu();
    while (c <= 6)
    {

        if (c == 1)
        {
            int i = 0;
            temp = head;

            while (temp->next != NULL)
            {
                i++;
                cout << "Employee #" << i << endl;
                temp->data->Edisplay();
                temp = temp->next;
            }
        }

        if (c == 2)
        {

            cout << "**************WokerList*******************" << endl;
            empl.display();
        }
        if (c == 3)
        {
            empl.search();
            empl.key->Edisplay();
        }
        if (c == 4)
        {
            string name;
            int year;
            cout << "enter worker name :";
            cin >> name;
            cout << "Enter Worker experience :";
            cin >> year;

            Employee *emo = new Workers(name, year);

            push(&head, emo);
            empl.push(emo);

            cout << emo->GetName() << " is added " << endl;
        }
        if (c == 5)
        {
            empl.search();
            empl.key->Edisplay();
            deleteNode(&head, empl.key);
            cout << empl.key->GetName() << "- Medical Leave Approved !!" << endl;
            cout << "Check the employee list " << endl;
        }
         if (c == 6)
        {
            Employee* e=empl.pop();
            cout << e->GetName() << " is sacked" << endl;
             deleteNode(&head, e);
            
        }
        c = menu();
    }
}

int main() //The main function is only for debugging, the specific can be improved
{
    list();

    system("pause");
    return 0;
}
