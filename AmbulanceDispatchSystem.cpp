#include <iostream>
#include <string>
using namespace std;
struct Node //used a struct because all the data members are to be made public
{
    string patientName;
    int priority; // Higher value indicates higher priority this is ideal for ambulance system bacuse more severe cases need immediate priority
    Node* next;
};

class AmbulanceDispatchQueue
{
    Node* front;
    Node* rear;

public:
    AmbulanceDispatchQueue()
    {
        front = NULL;
        rear = NULL;
    }

    ~AmbulanceDispatchQueue() 
    {
        while (front != nullptr) 
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() const 
    {
        return front == nullptr;
    }

    void enqueue(const string& patientName, int priority)
    {
        Node* t1 = new Node;
        t1->patientName = patientName;
        t1->priority = priority;//now t1 node will have priority and name in it
        t1->next = nullptr;//because there will be no next node
        if (rear == nullptr) 
        {
            front = t1;
            rear = t1;
        }
        else 
        {
            rear->next = t1;
            rear = t1;
        }
    }

    void dequeue() 
    {
        if (isEmpty())
        {
            cout << "No emergency to dispatch." << endl;
        }
        else 
        {
            Node* temp = front;
            cout << "Ambulance is on it's way for the patient: " << temp->patientName << " whose priority is " << temp->priority << endl;//priority is also shown along with patient's name

            if (front == rear) 
            {
                rear = nullptr;
            }

            front = front->next;
            delete temp;
        }
    }

    void displayPendingEmergencies()
    {
        if (isEmpty()) 
        {
            cout << "There is no pending emergencies" << endl;
        }
        else
        {
            Node* current = front;
            cout << "The pending emergencies in the queue are" << endl;
            while (current != nullptr) {
                cout << "The patient " << current->patientName << " and the priority is" << current->priority << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    AmbulanceDispatchQueue dispatchQueue;

    dispatchQueue.enqueue("Gojo Satoru", 2); // Moderate priority
    dispatchQueue.enqueue("Park Jimin", 1); // High priority
    dispatchQueue.enqueue("Eren Yeager", 3); // Low priority

    dispatchQueue.displayPendingEmergencies();

    dispatchQueue.dequeue();
    dispatchQueue.dequeue();

    dispatchQueue.displayPendingEmergencies();

    return 0;
}
