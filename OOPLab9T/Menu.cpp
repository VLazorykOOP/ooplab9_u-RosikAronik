#include <iostream>
void task1();
void task2();
int main() {
    int choice;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1.Task1" << std::endl;
        std::cout << "2.Task2" << std::endl;
        std::cout << "3.Leave" << std::endl;

        std::cout << "Enter option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        default:
            std::cout << "Wrong imput" << std::endl;
            break;
        }
        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}