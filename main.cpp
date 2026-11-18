#include <iostream>
#include <string>
#include <stdexcept>
#include "myvector.h"
using namespace std;

int main() {
    cout << "MY CUSTOM VECTOR DEMO\n";
    cout << "----------------------\n\n";

    MyVector<int> numbers;

    cout << "Initial size: " << numbers.size() << endl;
    cout << "Initial capacity: " << numbers.capacity() << endl;

    cout << "\nAdding numbers...\n";

    for (int i = 1; i <= 6; i++) {
        numbers.push_back(i * 10); // 10-60 by 10

        cout << "Added " << i * 10
            << " | Size: " << numbers.size()
            << " | Capacity: " << numbers.capacity()
            << endl;
    }

    cout << "\nStored numbers:\n";

    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers.at(i) << " ";
    }

    cout << "\n\nTesting element modification...\n";
    numbers.at(0) = 100;
    cout << "First element: " << numbers.at(0) << endl;

    cout << "\nTesting invalid index...\n";

    try {
        cout << numbers.at(20) << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nTesting with strings...\n";

    MyVector<string> names;

    names.push_back("Alex");
    names.push_back("Jordan");
    names.push_back("Taylor");

    for (size_t i = 0; i < names.size(); i++) {
        cout << names.at(i) << endl;
    }

	cout << "PT 2. More Member Functions\n\n";

	MyVector<string> tools;

	tools.push_back("Hammer");
	tools.push_back("Screwdriver");
	tools.push_back("Drill");
	tools.push_back("Leaf Blower");
	tools.push_back("Wrench");

	cout << "Tools Vector:\n";
	for(int i = 0; i < tools.size(); i++)
	{
		cout << i+1 << ". " << tools.at(i) << "\n";
	}
	cout << "\nSize: " << tools.size();
	cout << "\nCapacity: " << tools.capacity();

	tools.pop_back();

	cout << "\n\nAfter pop_back:\n";

	cout << "Tools Vector:\n";
        for(int i = 0; i < tools.size(); i++)
        {
                cout << i+1 << ". " << tools.at(i) << "\n";
        }
        cout << "\nSize: " << tools.size();
        cout << "\nCapacity: " << tools.capacity();

	tools.clear();

	cout << "\n\nAfter Empty:\n";
        cout << "Tools Vector:\n";
        for(int i = 0; i < tools.size(); i++)
        {
                cout << i+1 << ". " << tools.at(i) << "\n";
        }
        cout << "\nSize: " << tools.size();
        cout << "\nCapacity: " << tools.capacity();

	tools.push_back("Oscillator");
	tools.push_back("Hacksaw");

        cout << "\n\nNew Tools Vector:\n";
        for(int i = 0; i < tools.size(); i++)
        {
                cout << i+1 << ". " << tools.at(i) << "\n";
        }
        cout << "\nSize: " << tools.size();
        cout << "\nCapacity: " << tools.capacity();

	cout << "\n\n";


    return 0;
}
