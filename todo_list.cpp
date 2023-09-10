#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Task {
    string description;
    bool done;

    Task(const string& desc) : description(desc), done(false) {}
};

void AddTask(vector<Task>& t, const string& desc) {
    t.push_back(Task(desc));
    cout << "Task added: " << desc <<endl;
}


void ViewTasks(const vector<Task>& tasks) {
    cout << "Task List:" <<endl;
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].done) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending] ";
        }
        cout << tasks[i].description <<endl;
    }
}

void DeleteTask(vector<Task>& tasks, int Index) {
    if (Index >= 1 && Index <= (tasks.size())) {
        cout << "Task Deleted: " << tasks[Index - 1].description << endl;
        tasks.erase(tasks.begin() + Index - 1);
    } else {
        cout << "Enter a valid Number." <<endl;
    }
}

void MarkCompleted(vector<Task>& tasks, int Index) {
    if (Index >= 1 && Index <= (tasks.size())) {
        tasks[Index - 1].done = true;
        cout << "Task marked as completed: " << tasks[Index - 1].description <<endl;
    } else {
        cout << "Invalid task number." <<endl;
    }
}

int main() {
    vector<Task> tasks;
    string desc; 

    while (true) {
        cout << "\t\t\t                 Welcome To-Do List!!!             " <<endl;
        cout << "1. Add Task" <<endl;
        cout << "2. View Tasks" <<endl;
        cout << "3. Mark Task as Completed" <<endl;
        cout << "4. Delete Task" <<endl;
        cout << "5. Quit" <<endl<<endl;

        int number;
        cout << "Enter your choice(1/2/3/4/5): ";
        cin >> number;

        switch (number) {
            case 1:
                cin.ignore();
                cout << "Enter task to be added: ";
                getline(cin, desc);
                AddTask(tasks, desc);
                break;
            case 2:
                ViewTasks(tasks);
                break;
            case 3:
                int taskIndex;
                cout << "Enter the task number to be marked as completed: ";
                cin >> taskIndex;
                MarkCompleted(tasks, taskIndex);
                break;
            case 4:
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                DeleteTask(tasks, taskIndex);
                break;
            case 5:
                cout << "Thanks for Using,Bye!!!" <<endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." <<endl;
        }
    }

    return 0;
}

