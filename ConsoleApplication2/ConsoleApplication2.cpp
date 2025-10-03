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
    int chosenItems[maxPurchaseItems];
    int quantities[maxPurchaseItems];
	int purchaseItems;
	double subTotal=0, disCount=0, finalTotal=0;
	double disCountRate = 0.15; // 15% disCount
	
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
        cout << "\nHow many different items do you want to purchase (1-10)? ";
        cin >> purchaseItems;
        if (purchaseItems < 1 || purchaseItems > maxPurchaseItems) {
            cout << "Invalid number. Please enter between 1 and 10.\n";
        }
    } while (purchaseItems < 1 || purchaseItems > maxPurchaseItems);
	//End of validation

    // Collect user choices

    for (int i = 0; i < purchaseItems; i++) {

        int choice, qty;

        // Validate item choice

        do {

            cout << "\nEnter item number (1-8) for item " << (i + 1) << ": ";

            cin >> choice;

            if (choice < 1 || choice > maxItems) {

                cout << "Invalid item number! Please choose between 1 and 8.\n";

            }

        } while (choice < 1 || choice > maxItems);

        // Validate quantity

        do {

            cout << "Enter quantity for " << catalogue[choice - 1].name << ": ";

            cin >> qty;

            if (qty < 1) {

                cout << "Quantity must be at least 1.\n";

            }

        } while (qty < 1);

        chosenItems[i] = choice - 1;  // store index

        quantities[i] = qty;

    }

    // Calculate totals


    cout << "\n=== Purchase Summary for " << firstname << " " << lastname << " ===\n";

    for (int i = 0; i < purchaseItems; i++) {

        int idx = chosenItems[i];

        double cost = catalogue[idx].price * quantities[i];

        subTotal += cost;

        cout << left << setw(30) << catalogue[idx].name
            << "x" << quantities[i]
            << " = R" << fixed << setprecision(2) << cost << endl;

    }

    // Apply disCount if > 2000


    if (subTotal > 2000) {

        disCount = subTotal * disCountRate;

        finalTotal = subTotal - disCount;

    }

    cout << "\nSubtotal: R" << subTotal << endl;

    if (disCount > 0) {

        cout << "disCount (15%): R" << disCount << endl;

    }

    cout << "Final Total: R" << finalTotal << endl;




	cout << "\n \n";
	system("pause");
    return 0;
}
