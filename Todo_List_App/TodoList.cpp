#include <iostream>
#include <string>
#include <vector>
#include <limits> // Include for std::numeric_limits
using namespace std;

class Task {
private:
    string taskName;
    bool completed;

public:
    Task(const string& taskName) : taskName(taskName), completed(false) {}

    string getTask() const {
        return taskName;
    }

    bool isCompleted() const {
        return completed;
    }

    void markCompleted() {
        completed = true;
    }

    void markUncompleted() {
        completed = false;
    }
};

class TodoManager {
private:
    vector<Task> myTasks;

public:
    void addTask(const string& taskName) {
        myTasks.push_back(Task(taskName));
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < myTasks.size()) {
            myTasks.erase(myTasks.begin() + taskIndex);
        }
    }

    void listTasks() const {
        if (myTasks.empty()) {
            cout << "No tasks in the To-Do List." << endl;
        } 
        else {
            cout << "Tasks in the To-Do List:" << endl;
            for (size_t i = 0; i < myTasks.size(); i++) {
                cout << i + 1 << ". " << myTasks[i].getTask();
                if (myTasks[i].isCompleted()) {
                    cout << " - Completed";
                }
                cout << endl;
                
            }
        }
            
        
    }

    void markComplete(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < myTasks.size()) {
            myTasks[taskIndex].markCompleted();
        }
    }

    void markTaskIncomplete(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < myTasks.size()) {
            myTasks[taskIndex].markUncompleted();
        }
    }
};

int main() {
    TodoManager todoList;
    string taskName;
    int taskIndex;
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== To-Do List Manager ===" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. List Tasks" << endl;
        cout << "4. Mark Task as Complete" << endl;
        cout << "5. Mark Task as Incomplete" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Task Name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                getline(cin, taskName);
                todoList.addTask(taskName);
                cout << "Task Added Successfully" << endl;
                break;
            case 2:
                cout << "Enter Task Index To Remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex - 1);
                cout << "Task Removed Successfully" << endl;
                break;
            case 3:
                todoList.listTasks();
                break;
            case 4:
                cout << "Enter Task Index To Mark Completed: ";
                cin >> taskIndex;
                todoList.markComplete(taskIndex - 1);
                cout << "Task Marked as Completed Successfully" << endl;
                break;
            case 5:
                cout << "Enter Task Index To Mark Incomplete: ";
                cin >> taskIndex;
                todoList.markTaskIncomplete(taskIndex - 1);
                cout << "Task Marked as Incomplete Successfully" << endl;
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }

        
    }

    return 0;
}
