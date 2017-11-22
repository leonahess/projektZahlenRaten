#include <iostream>
using namespace std;
const char* UNIX_CLEAR_COMMAND = "clear";
const char* WINDOWS_CLEAR_COMMAND = "cls";
const char* CLEAR_COMMAND = UNIX_CLEAR_COMMAND;
const char* UNIX_PAUSE_COMMAND = "read -n1 -r -p \"-- Press any key to continue --\"";
const char* WINDOWS_PAUSE_COMMAND = "pause";
const char* PAUSE_COMMAND = UNIX_PAUSE_COMMAND;


int main() {
    int zahl;
    char ende;

    START:
    cout << "**********************" << endl << "Ratespiel - Partner A" << endl << "**********************" << endl;
    do {

        cout << "Bitte geben Sie eine Zahl von 1 bis 100 ein: ";

        while (!(cin >> zahl)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bitte geben Sie eine Zahl von 1 bis 100 ein: ";
        }

    } while (zahl < 1 || zahl > 100);

    cout << endl << "B muss jetzt die " << zahl << " erraten." << endl;
    cout << "Partner B kann nun starten" << endl;

    system(PAUSE_COMMAND);
    system(CLEAR_COMMAND);

    cout << "**********************" << endl << "Ratespiel - Partner B" << endl << "**********************" << endl;

    int rateZahl, zaehler;
    zaehler = 0;
    do {

        cout << "Bitte geben Sie eine Zahl von 1 und 100 ein" << endl;

        while (!(cin >> rateZahl)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            zaehler = zaehler + 1;
            cout << "Bitte geben Sie eine Zahl von 1 bis 100 ein: " << endl << "Versuch: " << zaehler << endl;
        }
        zaehler = zaehler + 1;

        if (rateZahl < zahl) {
            cout << "Die eingegebene Zahl ist zu klein. Versuch: " << zaehler << endl;
        } else if (rateZahl > zahl) {
            cout << "Die eingegebene Zahl ist zu groß. Versuch: " << zaehler << endl;
        } else {
            cout << "Yeah! Du hast die Zahl " << zahl << " erraten." << endl << "Gebrauchte Versuche: " << zaehler
                 << endl;
        }


    } while (zahl != rateZahl);


    do{
    cout << "Möchstest du: 'q' - Das Programm beenden oder 'n' - ein neues Spiel starten?" << endl;
    cin >> ende;

    if (ende == 'q') {
        cout << "Spiel wird beendet ..." << endl;
        return 0;
    } else if (ende == 'n') {
        system(CLEAR_COMMAND);
        goto START;
    } else {
        cout << "Bitte entweder 'q' oder 'n' ein!" << endl;
    }

    }while(ende != 'n' || ende != 'q');

}