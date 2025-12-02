//main.cpp

#include "Airline.h"

using namespace std;

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
            if(choice == 7){
                cout << "Program terminated.";
                exit(1);
            }
            cout<<"Please select a flight before selecting menu functions"<<endl;
            continue;
        }

        switch(choice){
            case 1:
            clearScreen();
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

void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int menu(){
    int choice = -1;
    cout << "Please select one the following options:\n\n";
    cout << "1. Select a Flight.\n";
    cout << "2. Display Flight Seat Map.\n";
    cout << "3. Display Passengers Information.\n";
    cout << "4. Add a New Passenger.\n";
    cout << "5. Remove an Existing Passenger\n";
    cout << "6. Save data\n";
    cout << "7. Quit. \n";
    cout << "\nEnter your choice (1-7): ";
    cin >> choice;
    cleanStandardInputStream();
    return choice;
}


