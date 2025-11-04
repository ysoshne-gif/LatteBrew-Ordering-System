#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure for coffee items
struct Coffee {
    string name;
    double price;
    int stock;
};

int main() {
    const int MENU_SIZE = 5;
    Coffee menu[MENU_SIZE] = {
        {"Espresso", 90.00, 10},
        {"Cappuccino", 110.00, 8},
        {"Latte", 120.00, 12},
        {"Caramel Macchiato", 130.00, 6},
        {"Mocha", 125.00, 10}
    };

    double total = 0.0;
    int choice, qty;
    char again;

    cout << "===============================" << endl;
    cout << "   WELCOME TO LATTE BREW CAFE  " << endl;
    cout << "===============================" << endl;

    do {
        cout << "\nMenu:" << endl;
        cout << "--------------------------------" << endl;
        cout << left << setw(5) << "No" << setw(20) << "Coffee" << setw(10) << "Price" << "Stock" << endl;
        cout << "--------------------------------" << endl;

        for (int i = 0; i < MENU_SIZE; i++) {
            cout << left << setw(5) << (i + 1)
                 << setw(20) << menu[i].name
                 << setw(10) << menu[i].price
                 << menu[i].stock << endl;
        }

        cout << "\nEnter the number of your choice: ";
        cin >> choice;

        if (choice < 1 || choice > MENU_SIZE) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> qty;

        if (qty <= 0) {
            cout << "Invalid quantity.\n";
            continue;
        }

        if (qty > menu[choice - 1].stock) {
            cout << "Sorry, not enough stock available.\n";
            continue;
        }

        double subtotal = menu[choice - 1].price * qty;
        total += subtotal;
        menu[choice - 1].stock -= qty;

        cout << "\nYou ordered " << qty << " x " << menu[choice - 1].name;
        cout << " = ₱" << subtotal << endl;
        cout << "Current total: ₱" << total << endl;

        cout << "\nWould you like to order another item? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    cout << "\n===============================" << endl;
    cout << "       ORDER SUMMARY" << endl;
    cout << "===============================" << endl;
    cout << "Total Amount Due: ₱" << total << endl;
    cout << "Thank you for ordering at LATTE BREW! ☕" << endl;

    return 0;
}
