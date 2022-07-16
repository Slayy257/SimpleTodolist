#include <iostream>
#include <Windows.h>
#include "component/task.h"

// task manager

void showTasks() {
    for (int i = 0; i < Task::get_lenght(); i++) {
        std::pair<std::string, taskState> pair = Task::get_task(i);
        std::string done = pair.second == taskState::Done ? "Done" : "Not done";

        if (i == 0) {
            std::cout << "--------------------------------------------------------------------\n";
            std::cout << "| " << i + 1 << ". " << pair.first << " ( " << done.c_str() << " )\n";
        }
        else if (i == Task::get_lenght() - 1) {
            std::cout << "| " << i + 1 << ". " << pair.first << " ( " << done.c_str() << " )\n";
            std::cout << "--------------------------------------------------------------------\n";
        }
        else {
            std::cout << "| " << i + 1 << ". " << pair.first << " ( " << done.c_str() << " )\n";
        }
    }
}

void add_task() {
    system("cls");

    std::cout << "Enter task name: ";

    std::string taskName;
    std::getline(std::cin, taskName);

    Task::add_task(taskName);
}

void set_done_task() {
    system("cls");

    showTasks();

    std::cout << "\nEnter task number: ";

    int input;
    std::cin >> input;
    input -= 1;


    Task::set_task_state(input, taskState::Done);
}

void remove_done_task() {
    for (int i = 0; i < Task::get_lenght(); i++) {
        if (Task::get_task(i).second == taskState::Done) {
            Task::remove_task(i);
        }
    }
}

void showMenu() {
    showTasks();

    std::cout << "\n[1] Add task";
    std::cout << "\n[2] Set task done";
    std::cout << "\n[3] Remove done task";

    std::cout << "\nEnter option: ";

    // get input from user
    int input;
    std::cin >> input;
    std::cin.ignore();

    switch (input)
    {
    case 1: { add_task(); break; }
    case 2: { set_done_task(); break; }
    case 3: { remove_done_task(); break; }
    default:
        std::cout << "\n\nInvalid Option";
        Sleep(2000);
        break;
    }

    system("cls");
}

int main()
{
    Task::add_task("linge");
    Task::add_task("vesselle");
    Task::add_task("bin");
    Task::add_task("baleyeuse");

    while (true) {
        showMenu();
    }

    return 0;
}