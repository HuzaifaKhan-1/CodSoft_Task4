#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

enum class Status {
    PENDING,
    COMPLETED
};

struct Task {
    string description;
    Status status;
    string category;
};

class ToDoListManager {
private:
    vector<Task> tasks;

public:
    void addTask() {
        Task newTask;
        cout << "Enter task description: ";
        getline(cin, newTask.description);
        cout << "Enter task category (e.g., Work, Personal): ";
        getline(cin, newTask.category);
        newTask.status = Status::PENDING;
        tasks.push_back(newTask);
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }
        cout << left << setw(5) << "ID" << setw(30) << "Description" << setw(20) << "Category" << setw(15) << "Status" << endl;
        cout << "-------------------------------------------------------------" << endl;
        int id = 1;
        for (const auto& task : tasks) {
            cout << left << setw(5) << id++ 
                 << setw(30) << task.description 
                 << setw(20) << task.category 
                 << setw(15) << (task.status == Status::PENDING ? "Pending" : "Completed") 
                 << endl;
        }
    }

    void markTaskAsCompleted() {
        int id;
        viewTasks();
        cout << "Enter task ID to mark as completed: ";
        cin >> id;
        cin.ignore();  // Clear the newline character from the input buffer
        if (id > 0 && id <= tasks.size()) {
            tasks[id - 1].status = Status::COMPLETED;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task ID!" << endl;
        }
    }

    void removeTask() {
        int id;
        viewTasks();
        cout << "Enter task ID to remove: ";
        cin >> id;
        cin.ignore();  // Clear the newline character from the input buffer
        if (id > 0 && id <= tasks.size()) {
            tasks.erase(tasks.begin() + id - 1);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task ID!" << endl;
        }
    }
};

int main() {
    ToDoListManager manager;
    int choice;

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                manager.addTask();
                break;
            case 2:
                manager.viewTasks();
                break;
            case 3:
                manager.markTaskAsCompleted();
                break;
            case 4:
                manager.removeTask();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
