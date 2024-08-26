//#include <iostream>
//using namespace std;
//struct Node
//{
//    int taskID;
//    string taskDescription;
//    Node* next;
//};
//class CircularQueue
//{
//    Node* front;
//    Node* rear;
//public:
//    CircularQueue()
//    {
//        front = NULL;
//        rear = NULL;
//    }
//    ~CircularQueue()
//    {
//        while (front != nullptr) 
//        {
//            Node* temp = front;
//            if (front == rear) //if there is a single node
//            {
//                delete front;
//                front = nullptr;
//                rear = nullptr;
//            }
            /*else 
            {
                front = front->next;
                delete temp;
            }*/
//        }
//    }
//
//    bool isEmpty() const 
//    {
//        return front == nullptr;
//    }
//
//    void insertTask(int taskID, const string& taskDescription) 
//    {
//        Node* newNode = new Node;
//        newNode->taskID = taskID;
//        newNode->taskDescription = taskDescription;
//        if (isEmpty()) 
//        {
//            front = newNode;
//        }
//        else 
//        {
//            rear->next = newNode;//because insertion is done at rear end
//        }
//        newNode->next = front;
//        rear = newNode;
//    }
//
//    void removeTask() 
//    {
//        if (isEmpty())
//        {
//            cout << "Task manager is empty. No task to remove." << endl;
//        }
//        else
//        {
//            Node* temp = front;
//            if (front == rear)
//            {
//                delete front;
//                front = nullptr;
//                rear = nullptr;
//            }
//            else 
//            {
//                front = front->next;
//                delete temp;
//                rear->next = front;
//            }
//        }
//    }
//
//    void displayTasks()
//    {
//        if (isEmpty())
//        {
//            cout << "Task manager is empty." << endl;
//        }
//        else 
//        {
//            Node* current = front;
//            cout << "Tasks in the task manager:" << endl;
//            do
//            {
//                cout << "Task ID: " << current->taskID << " - Description: " << current->taskDescription << endl;
//                current = current->next;
//            } while (current != front);//since it is circular it will traverse back to front
//        }
//    }
//};
//
//int main()
//{
//    CircularQueue taskManager;
//    taskManager.insertTask(1, "Schedule a meeting with board of directors");
//    taskManager.insertTask(2, "Give meeting minutes to the manager");
//    taskManager.insertTask(3, "Review code changes and provide feedback");
//    taskManager.displayTasks();
//    taskManager.removeTask();
//    cout << "Removed a task." << endl;
//    taskManager.displayTasks();
//    taskManager.removeTask();
//    taskManager.removeTask();
//    taskManager.removeTask(); // trying to dequeue from an empty task manager
//
//    return 0;
//}