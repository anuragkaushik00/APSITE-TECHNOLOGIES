#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Task {
public:
    Task(const string& desc) : description(desc), completed(false) {}

    void markAsCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }

private:
    string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getDescription() 
                 << " [" << (tasks[i].isCompleted() ? "Completed" : "Pending") << "]" << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].markAsCompleted();
            cout << "Task " << index << " marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task " << index << " removed from the list." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

private:
    vector<Task> tasks;
};

void clearInput() {
    cin.clear(); // Clear the error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover characters in the input buffer
}

int main() {
    ToDoList todoList;
    int choice;
    string description;
    size_t index;

    while (true) {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover newline character

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                todoList.addTask(description);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                if (cin.fail()) {
                    clearInput();
                    cout << "Invalid task number." << endl;
                    break;
                }
                todoList.markTaskAsCompleted(index);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> index;
                if (cin.fail()) {
                    clearInput();
                    cout << "Invalid task number." << endl;
                    break;
                }
                todoList.removeTask(index);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
