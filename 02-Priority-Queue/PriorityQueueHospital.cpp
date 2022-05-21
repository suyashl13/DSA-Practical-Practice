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

int main(int argc, char const *argv[])
{
    enqueue(q_element{"A", SERIOUS});
    enqueue(q_element{"B", NONSERIOUS});
    enqueue(q_element{"C", CHECKUP});
    enqueue(q_element{"C", CHECKUP});
    enqueue(q_element{"C", CHECKUP});
    enqueue(q_element{"S", SERIOUS});
    enqueue(q_element{"S", SERIOUS});
    enqueue(q_element{"S", SERIOUS});
    enqueue(q_element{"S", SERIOUS});

    for (int i = front; i <= rear; i++)
    {
        cout << patient_queue[i].p_name << " " << patient_queue[i].priority << endl;
    }

    return 0;
}
