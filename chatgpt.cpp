#include <iostream>
#include <vector>

class ToDoList {
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string &task) {
        tasks.push_back(task);
        std::cout << "Task added: " << task << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display." << std::endl;
            return;
        }
        
        std::cout << " Tasks: " << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
            
        }
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            std::cout << "Task deleted: " << tasks[index] << std::endl;
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    std::cout << "\t\t\t\t    +--------------------------------------+    "  <<std:: endl;
    std::cout << "\t\t\t\t    ¦    Welcome to the C++ ToDo List      ¦    " <<std:: endl;
    std::cout << "\t\t\t\t    +--------------------------------------+    " << std::endl;
    std::cout<<std::endl;

    while (true) {
   	std::cout<<std::endl;
    std::cout << "\nChoose an option:" << std::endl;
    std::cout << "1. Add Task\n2. View Tasks\n3. Delete Task\n4. Quit" << std::endl;
    std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string task;
                std::cout << "Enter task: ";
                std::cin.ignore();  // Clear the input buffer
                std::getline(std::cin, task);
                todo.addTask(task);
                break;
            }
            case 2:
                todo.viewTasks();
                break;
            case 3: {
                int index;
                std::cout << "Enter task index to delete: ";
                std::cin >> index;
                todo.deleteTask(index - 1);  // Adjust index for 0-based vector
                break;
            }
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    }

    return 0;
}

