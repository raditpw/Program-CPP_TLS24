#include <iostream>
#include <cstdlib> // Required for the system() function
using namespace std;

// Function to clear the screen (Windows)
void clrscreen() {
    system("cls");  // Windows command to clear the screen
}

// Function to display the menu and return the user's choice
int displayMenu() {
    int choice;
    cout << "\nWater Intake Tracker\n";
    cout << "1. Log water intake\n";
    cout << "2. Check total intake\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function to log water intake
void logWater(int &totalIntake) {
    int water;
    cout << "Enter the amount of water (in ml): ";
    cin >> water;
    totalIntake += water;
    cout << "You've added " << water << " ml to your daily intake.\n";
}

// Function to check total intake and provide feedback
void checkIntake(int totalIntake) {
    int goal = 2000; // 2000 ml (2 liters) daily goal
    cout << "Your total water intake today is: " << totalIntake << " ml.\n";
    if (totalIntake >= goal) {
        cout << "Congratulations! You've reached your daily water goal.\n";
    } else {
        cout << "Keep going! You need " << 2000 - totalIntake << " ml more to reach your goal.\n";
    }
}

int main() {
    int totalIntake = 0; // Keeps track of total water intake
    int choice;

    // Main program loop
    while (true) {
        choice = displayMenu();
        clrscreen();  // Clear the screen after each menu option is selected

        if (choice == 1) {
            logWater(totalIntake);
        } else if (choice == 2) {
            checkIntake(totalIntake);
        } else if (choice == 3) {
            cout << "Exiting the program. Stay hydrated!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

        // Pause for a moment to let the user see the result, then clear the screen
        cout << "\nPress Enter to continue...";
        cin.ignore(); // Ignores previous newline from the last input
        cin.get(); // Waits for Enter key
        clrscreen();  // Clears screen before displaying the menu again
    }

    return 0;
}

