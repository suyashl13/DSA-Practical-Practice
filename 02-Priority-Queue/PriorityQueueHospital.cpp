#include <iostream>
#include <string>

#define SIZE 10

#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1

using namespace std;

struct q_element
{
    char p_name[50];
    int priority;
};

q_element patient_queue[SIZE];
int rear, front = -1;

void enqueue(q_element element)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue is full.";
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
            patient_queue[rear] = element;
        }
        else
        {
            int insert_index;
            for (int i = rear; i >= front; i--)
            {
                if (element.priority > patient_queue[i].priority)
                {
                    patient_queue[i + 1] = patient_queue[i];
                }
                else
                {
                    insert_index = i;
                    break;
                }
            }
            patient_queue[insert_index + 1] = element;
            rear++;
        }
    }
}

void dequeue()
{
    if (rear == -1)
    {
        cout << "Queue is empty.";
        return;
    }

    cout << "DEQUEUE : " << patient_queue[front].p_name;
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        cout << patient_queue[i].p_name << " " << patient_queue[i].priority << " | ";
    }
}

int main(int argc, char const *argv[])
{
    int option;
    q_element patient = q_element{};

    while (true)
    {
        cout << "*** Menu ***" << endl
             << "------------" << endl;
        cout << "1. Add Patient to Queue." << endl
             << "2. Dequeue a Patient form Queue." << endl
             << "3. Display Queue" << endl
             << "4. Exit" << endl << endl;

        cout << "Enter your choice : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter the name of patient : ";
            cin >> patient.p_name;

            cout << "Enter Priority (1,5,10) : ";
            cin >> patient.priority;

            enqueue(patient);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}
