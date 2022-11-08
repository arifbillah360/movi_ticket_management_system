#include <bits/stdc++.h>

#define max 20
using namespace std;

struct Ticket {
	string name;
	long int code;
	string Movi_Name;
	int price;
	int date;
};

int num;


Ticket tic[max], ttic[max],
	sorttic[max], sorttic1[max];

void build()
{
	cout << "Maximum Number can be "
		<< max << "\n";

	cout << "Enter the number of "
		<< "Number required: ";
	cin >> num;

	cout << "Enter the data:\n";

	for (int i = 0; i < num; i++) {
		cout << "Customer Name ";
		cin >> tic[i].name;

		cout << "Ticket ID ";
		cin >> tic[i].code;

		cout << "Movi Name ";
		cin >> tic[i].Movi_Name;

		cout << "price ";
		cin >> tic[i].price;

		cout << "date ";
		cin >> tic[i].date;
	}

}

// Function to insert the data into
// given data type
void insert()
{
	if (num < max) {
		int i = num;
		num++;

		cout << "Enter the information \n";

		cout << "Customer Name ";
		cin >> tic[i].name;

		cout << "Ticket ID ";
		cin >> tic[i].code;

		cout << "Movi Name ";
		cin >> tic[i].Movi_Name;

		cout << "price ";
		cin >> tic[i].price;

		cout << "date ";
		cin >> tic[i].date;
	}
	else {
		cout << "Ticket Table Full\n";
	}

}

// Function to delete record at index i
void deleteIndex(int i)
{
	for (int j = i; j < num - 1; j++) {
		tic[j].name = tic[j + 1].name;
		tic[j].code = tic[j + 1].code;
		tic[j].Movi_Name
			= tic[j + 1].Movi_Name;
		tic[j].price = tic[j + 1].price;
		tic[j].date = tic[j + 1].date;
	}
	return;
}

// Function to delete record
void deleteRecord()
{
	cout << "Enter the Ticket ID "
		<< "to Delete Record";

	int code;

	cin >> code;
	for (int i = 0; i < num; i++) {
		if (tic[i].code == code) {
			deleteIndex(i);
			num--;
			break;
		}
	}
}

void searchRecord()
{
	cout << "Enter the Ticket"
		<< " ID to Search Record";

	int code;
	cin >> code;

	for (int i = 0; i < num; i++) {

		// If the data is found
		if (tic[i].code == code) {
			cout << "Customer Name "
				<< tic[i].name << "\n";

			cout << "Ticket ID "
				<< tic[i].code << "\n";

			cout << "Movi Name "
				<< tic[i].Movi_Name << "\n";

			cout << "price "
				<< tic[i].price << "\n";

			cout << "date "
				<< tic[i].date << "\n";
			break;
		}
	}

}
// Ticket display
void Display()
{
	for(int i=0; i<20; i++ ){
	if (tic[i].code != 0) {
			cout << "Ticket information \n";
			cout << " #Name: ";
			cout << tic[i].name;

			cout << " #Ticket_ID: ";
			cout << tic[i].code;

			cout << " #Movi_Name: ";
			cout << tic[i].Movi_Name;

			cout << " #price ";
			cout << tic[i].price;

			cout << " #date; ";
			cout << tic[i].date;

			continue;
		}
	}
}

// Driver Code
int main()
{
	cout << "Enter The choice:\n\n";
	cout << "1. Build Table	\n";
	cout << "2. Insert a data\n";
	cout << "3. Delete data\n";
	cout << "4. Search a data\n";
	cout << "5. Display Information\n";
	cout << "5. Exit\n";

	int choice;
    do{
    cout << "\n\nEnter the choice:";
    cin >> choice;
        switch(choice){

        case 1: build();
        break;
        case 2: insert();
        break;
        case 3: deleteRecord();
        break;
        case 4: searchRecord();
        break;
		case 5:	Display();
        break;
		case 6: cout << "\nExit!";
        break;
        default: cout << "\nWrong Choice!!";
        }
    }while(choice != 6);
    return 0;
	return 0;
}
