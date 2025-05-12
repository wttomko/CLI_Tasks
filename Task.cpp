#include <iostream>
#include <string>
#include "json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;


class Task {
    private:
        int id;
        string description;
        bool isCompleted;

    public:
        Task(string description){
            ifstream file("Tasks.json");
            json j;
            file >> j;
            this->id = j.size() + 1; // Simple ID generation based on size of JSON array
            
            this->description = description;
            this->isCompleted = false;
            

            json newTask = {
                {"id", this->id},
                {"description", this->description},
                {"isCompleted", this->isCompleted}
            };
            j.push_back(newTask);
            ofstream outFile("Tasks.json");
            outFile << j.dump(4);
        }

        void markAsCompleted() {
            this->isCompleted = true;
        }

        void markAsIncomplete() {
            this->isCompleted = false;
        }

        int getId() {
            return this->id;
        }

        string getDescription() {
            return this->description;
        }

        bool getIsCompleted() {
            return this->isCompleted;
        }

        json toJson() {
            json j;
            j["id"] = this->id;
            j["description"] = this->description;
            j["isCompleted"] = this->isCompleted;
            return j;
        }
};

void printTasks(){
    string blue = "\033[34m";
    string red = "\033[31m";
    string reset = "\033[0m";
    ifstream file("Tasks.json");
    json j;
    file >> j;
    for (auto& task : j) {
        if (task["isCompleted"] == true) {
            cout << blue << "[" << task["id"] << "] " << task["description"] << reset << endl;
        } else {
            cout << red << "[" << task["id"] << "] " << task["description"] << reset << endl;
        }
    }
}

void removeTask(int id) {
    ifstream file("Tasks.json");
    json j;
    file >> j;
    for (auto it = j.begin(); it != j.end(); ++it) {
        if ((*it)["id"] == id) {
            j.erase(it);
            break;
        }
    }

    // Update IDs of remaining tasks
    for (int i = 0; i < j.size(); ++i) {
        j[i]["id"] = i + 1; // Reassign IDs starting from 1
    }

    ofstream outFile("Tasks.json");
    outFile << j.dump(4);
}

int main() {
    // Initialize the JSON file if it doesn't exist
    ifstream file("Tasks.json");
    if (!file) {
        ofstream outFile("Tasks.json");
        outFile << "[]";
    } else {
        // code to read the file and check if it's empty
        json j;
        file >> j;
        if (j.empty()) {
            ofstream outFile("Tasks.json");
            outFile << "[]";
        }
    }

    string choice;
    while (choice != "Q"){
        cout << "\033[2J\033[1;1H"; 
        cout << "Task Manager" << endl;
        cout << "==================================" << endl;
        cout << "\033[34mComplete\033[0m :: \033[31mIncomplete\033[0m" << endl;
        cout << "==================================" << endl;
        printTasks();
        cout << "==================================" << endl;
        cout << "[1] Add Task" << endl;
        cout << "[2] [TASK NUMBER] Remove Task" << endl;
        cout << "[3] [TASK NUMBER] Mark Task as Completed" << endl;
        cout << "[4] [TASK NUMBER] Mark Task as Incomplete" << endl;
        cout << "[5] Clear all Tasks" << endl;
        cout << "[6] Exit" << endl;
        cout << "==================================" << endl;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice[0]) {
            case '1': {
                string description;
                cout << "Enter task description: ";
                getline(cin, description);
                Task newTask(description);
                break;
            }
            case '2': {
                int id;
                if (choice.length() < 2) {
                    cout << "Please enter a task number: ";
                    cin >> choice;
                    cin.ignore();
                    id = choice[0] - '0';
                } else if (choice.length() == 2) {
                    id = choice[1] - '0';
                } else if (choice.length() == 3) {
                    id = stoi(choice.substr(choice.length() - 2));
                }

                removeTask(id);
                break;
            }
            case '3': {
                int id;
                if (choice.length() < 2) {
                    cout << "Please enter a task number: ";
                    cin >> choice;
                    cin.ignore();
                    id = choice[0] - '0';
                } else if (choice.length() == 2) {
                    id = choice[1] - '0';
                } else if (choice.length() == 3) {
                    id = stoi(choice.substr(choice.length() - 2));
                }
                ifstream file("Tasks.json");
                json j;
                file >> j;
                for (auto& task : j) {
                    if (task["id"] == id) {
                        task["isCompleted"] = true;
                        break;
                    }
                }
                ofstream outFile("Tasks.json");
                outFile << j.dump(4);
                break;
            }
            case '4': {
                int id;
                if (choice.length() < 2) {
                    cout << "Please enter a task number: ";
                    cin >> choice;
                    cin.ignore();
                    id = choice[0] - '0';
                } else if (choice.length() == 2) {
                    id = choice[1] - '0';
                } else if (choice.length() == 3) {
                    id = stoi(choice.substr(choice.length() - 2));
                }
                ifstream file("Tasks.json");
                json j;
                file >> j;
                for (auto& task : j) {
                    if (task["id"] == id) {
                        task["isCompleted"] = false;
                        break;
                    }
                }
                ofstream outFile("Tasks.json");
                outFile << j.dump(4);
                break;
            }
            case '5': {
                ofstream outFile("Tasks.json");
                outFile << "[]";
                break;
            }
            case '6':
            case 'Q':
            case 'q':
            default:
                break; // Exit the loop
        }

    }
    return 0;
}
