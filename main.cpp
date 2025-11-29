#include "Airline.h"

using namespace::std;

void displayHeader();

void pressEnter();

void clearScreen(void);

int menu();

void cleanStandardInputStream(void);

int main(void){
    Airline airline;
    airline.flightsFromfile("flights.txt");
    airline.passengerFromfile("passengers.txt");

    Flight* primary = nullptr;

    displayHeader();
    while(1){
        int choice = menu();
        if(choice != 1 && primary == nullptr){
            cout<<"Please select a flight before selecting menu functions"<<endl;
            continue;
        }

        switch(choice){
            case 1:
                int flight_choice;
                airline.displayFlights();
                cout<<"Enter your choice: ";
                cin>> flight_choice;
                primary = airline.findFlightByIndex(flight_choice);
                pressEnter();
                continue;
            case 2:
                primary->displaySeatMap();
                pressEnter();
                continue;
            case 3:
                primary->displayPassengers();
                pressEnter();
                continue;
            case 4:
                primary->addPassenger();
                pressEnter();
                continue;
            case 5:
                primary->removePassenger();
                pressEnter();
                continue;
            case 6:
                while(1){
                    char s;
                    cout << "Do you want to save the data in the \\“flight_info.txt\\”? Please answer <Y or N> ";
                    cin >> s;
                    if(toupper(s) == 'Y' || toupper(s) == 'N') {
                        airline.saveData("flight_info.txt");
                        cout << "All the data in the passenger list were saved.";
                        break;
                    } 
                    cout << "Invalid option";   
                }
                continue;
            case 7:
                cout << "Program terminated.";
                exit(1);            
            default:
                cout<<"Please enter a valid option"<<endl;
                continue;
        }
    }      
    
}

void clearScreen(void)
{
    #ifdef UNIX
    system("clear");
    #else
    system("clr");
    #endif
}

void cleanStandardInputStream (void)
{
int leftover;
do {
leftover = cin.get();
} while (leftover !='\n' && leftover != EOF);
}


void displayHeader(){
    clearScreen();
    cout<<"Version 1.0"<<endl;
    cout<<"Term Project - Flight Managment Project in C++"<<endl;
    cout<<"Produced By: Kulvansh.J, Kuljot.J, Sarvesh.V"<<endl;
    cout<<"Year: 2025\n"<<endl;
    pressEnter();
}

void pressEnter(){
    cout<<"\n<<<Press Return to Continue>>>>\n"<<endl;
    cin.get();
}

int menu(){
    int choice = -1;
    clearScreen();
    cout << "Please select one the following options:\n\n";
    cout << "1. Display Flight Seat Map.\n";
    cout << "2. Display Passengers Information.\n";
    cout << "3. Add a New Passenger.\n";
    cout << "4. Remove an Existing Passenger\n";
    cout << "5. Save data\n";
    cout << "6. Quit. \n";
    cout << "\nEnter your choice: (1, 2, 3, 4, or 5) ";
    cin >> choice;
    cleanStandardInputStream();
    return choice;
}


