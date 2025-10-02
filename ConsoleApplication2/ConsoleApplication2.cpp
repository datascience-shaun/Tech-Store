#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Item {
    int number;
    string name;
    double price;
};

int main() {
	// Variable declarations
    string firstname, lastname;
	const int maxItems = 8;
	const int maxPurchaseItems = 10;
	int purchaseItems;

	// User input for name
    cout << "Enter Firstname: ";
    cin >> firstname;
    cout << "Enter Lastname: ";
    cin >> lastname;

    // Create catalogue as an array of structs
    Item catalogue[maxItems] = {
        {1, "Wireless Mouse", 150.00},
        {2, "Bluetooth Speaker", 250.00},
        {3, "USB Flash Drive", 100.00},
        {4, "Gaming Keyboard", 500.00},
        {5, "Noise-Cancelling Headphones", 750.00},
        {6, "Smartwatch", 1200.00},
        {7, "External Hard Drive", 1000.00},
        {8, "Portable Charger", 300.00}
    };
	//End of catalogue creation


    // Display catalogue
    cout << "\nTech Store Catalogue:\n";
    cout << "---------------------------------------------\n";
    cout << left << setw(5) << "No" << setw(30) << "Item" << "Price\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < maxItems; i++) {
        cout << left << setw(5) << catalogue[i].number
            << setw(30) << catalogue[i].name
            << "R" << catalogue[i].price << endl;
    }
	//End of catalogue display


	// Validate number of items to purchase
    do {
        cout << "Enter the number of items you want to purchase (1-10): ";
        cin >> purchaseItems;

        if (purchaseItems < 1 || purchaseItems > maxPurchaseItems) {
            cout << "Invalid number of items. Please enter a number between 1 and 10.\n";
        }
    } while (purchaseItems < 1 || purchaseItems > maxPurchaseItems);
	//End of validation
    return 0;
}
