#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
using namespace std;



    struct Ticket{
        // Variables for Ticket details
        char name[30];
        char id[5];
        char movi[10];
        int duration;
        int price;
        int time;
    };
        char name[30];
        char id[5];
        char movi[10];
        int duration;
        int price;
        int time;
        
        
        // Utility functions
        void waitForEnter(void){
            cout<<"\n\n\n Enter for Back \n\n";
            cin.get();
            cin.get();
        }

        // Functions to perform desired actions
        void listTickets(void){
            system("cls");
            FILE *file;
            file= fopen("anika.txt", "r");
            cout<<"\n name  id  movi\n";
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &movi[0], &duration, &price, &time)!= EOF)
                cout<<"\n"<<name<<"\t"<<id<<"\t"<<movi;
            fclose(file);
            waitForEnter();
        }

        void showDetails(void){
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"Enter Ticket id: ";
            cin>>checkId;
            file= fopen("anika.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &movi[0], &duration, &price, &time)!=EOF)
                if(strcmp(checkId,id)==0){
                    cout<<"\nname: "<<name;
                    cout<<"\nid: "<<id;
                    cout<<"\nmovi: "<<movi;
                    cout<<"\nduration: "<<duration;
                    cout<<"\nprice: "<<price;
                    cout<<"\ntime: "<<time;
                }
            fclose(file);
            waitForEnter();
        }

        void editExisting(void){
            system("cls");
            char checkId[5];
            cout<<"Enter Ticket id: ";
            cin>>checkId;
            char newmovi[10];
            cout<<"Enter new movi: ";
            cin>>newmovi;
            int newprice;
            cout<<"Enter new price: ";
            cin>>newprice;
            FILE *file, *tmpfile;
            file= fopen("anika.txt", "r");
            tmpfile= fopen("tmp.txt", "w");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &movi[0], &duration, &price, &time)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tmpfile, "%s %s %s %d %d %d \n", name, id, newmovi, duration, newprice, time );
                else
                    fprintf(tmpfile, "%s %s %s %d %d %d \n", name, id, movi, duration, price, time );
            }
            fclose(file);
            fclose(tmpfile);
            int isRemoved= remove("anika.txt");
            int isRenamed= rename("tmp.txt", "anika.txt");
            waitForEnter();
        }

        void addNewTicket(void){
            system("cls");
            cout<<"\n Enter Name: ";
            cin>>name;
            cout<<"\n Enter Ticket ID: ";
            cin>>id;
            cout<<"\n Enter movi Name: ";
            cin>>movi;
            cout<<"\n Enter Movi duration: ";
            cin>>duration;
            cout<<"\n Enter Ticket price: ";
            cin>>price;
            cout<<"\n Enter show time: ";
            cin>>time;

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("anika.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, movi, duration, price, time );
                fclose(file);
                cout<<"\nNew Ticket has been added to anikabase\n";
            }
            else
                addNewTicket();
            waitForEnter();
        }

        void deleteTicketDetails(void){
            system("cls");
            char checkId[5];
            cout<<"Enter Ticket id: ";
            cin>>checkId;
            char ch;
            cout<<"Enter 'y' to confirm deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tmpfile;
                file= fopen("anika.txt", "r");
                tmpfile= fopen("tmp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &movi[0], &duration, &price, &time)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tmpfile, "%s %s %s %d %d %d \n", name, id, movi, duration, price, time );
                fclose(file);
                fclose(tmpfile);
                int isRemoved= remove("anika.txt");
                int isRenamed= rename("tmp.txt", "anika.txt");
                cout<<"\nDeletion Successful\n";
                waitForEnter();
            }
            else
                deleteTicketDetails();
        }

int main()
{
	int choice;

    do{
	cout << "Enter The choice:\n\n";
	cout << "1. Display Ticket list	\n";
	cout << "2. Show Individual ticket information\n";
	cout << "3. Update ticket details\n";
	cout << "4. Add new Ticket\n";
	cout << "5. delete Ticket\n";
	cout << "5. Exit\n";
	
    cout << "\n\nEnter your choice:";
    cin >> choice;
        switch(choice){

        case 1: listTickets();
        break;
        case 2: showDetails();
        break;
        case 3: editExisting();
        break;
        case 4: addNewTicket();
        break;
		case 5:	deleteTicketDetails();
        break;
		case 6: cout << "\nExit!";
        break;
        default: cout << "\nWrong Choice!! Try Again!!";
        }
    }while(choice != 6);
    return 0;
	return 0;
}
