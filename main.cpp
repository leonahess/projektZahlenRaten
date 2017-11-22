#include <iostream>

const char* UNIX_CLEAR_COMMAND = "clear";
const char* WINDOWS_CLEAR_COMMAND = "cls";
const char* CLEAR_COMMAND = UNIX_CLEAR_COMMAND;
const char* UNIX_PAUSE_COMMAND = "read -n1 -r -p \"-- Press any key to continue --\"";
const char* WINDOWS_PAUSE_COMMAND = "pause";
const char* PAUSE_COMMAND = UNIX_PAUSE_COMMAND;
using namespace std;

int main() {
  char ende;
  int eingabeA, eingabeB, zaehler;
  START:cout << "~~~~~~~~~~~~~~~~~~~~~" << endl << "Ratespiel - Partner A" << endl << "~~~~~~~~~~~~~~~~~~~~~" << endl;

  do {
    cout << "Bitte eine Zahl von 1 bis 100 eingeben." << endl;

    while(!(cin >> eingabeA)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Bitte nur Zahlen eingeben!" << endl << "Bitte eine Zahl von 1 bis 100 eingeben." << endl;
    }

  } while (eingabeA < 1 || eingabeA > 100);

  cout << "\nPartner B kann nun starten." << endl;
  system(PAUSE_COMMAND);
  system(CLEAR_COMMAND);


  cout << "~~~~~~~~~~~~~~~~~~~~~" << endl << "Ratespiel - Partner B" << endl << "~~~~~~~~~~~~~~~~~~~~~" << endl;
  zaehler = 0;
  do {
    cout << "Bitte gib eine Zahl von 1 bis 100 ein, um, die Zahl deines Partners zu erraten." << endl;
    while(!(cin >> eingabeB)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      zaehler = zaehler + 1;
      cout << "Bitte nur Zahlen eingeben! Versuch: " << zaehler << endl << "\nBitte eine Zahl von 1 bis 100 eingeben." << endl;
    }
    zaehler = zaehler + 1;

    if (eingabeA > eingabeB) {
      cout << "Die eingegebene Zahl ist zu klein. Versuch: " << zaehler<< endl;
    } else if (eingabeA < eingabeB) {
      cout << "Die eingegebene Zahl ist zu groß. Versuch: " << zaehler << endl;
    } else {
      cout << "Yeah! Die Zahl " << eingabeA << " wurde erraten! Benötigte Versuche: " << zaehler << endl;
    }
  } while (eingabeA != eingabeB);

  do {
    cout << "Möchtest du: 'q' - Das Programm beenden oder 'n' - ein neues Spiel starten?" << endl;
    cin >> ende;

    if (ende == 'q') {
      cout << "Spiel wird beendet..." << endl;
      return 0;
    } else if (ende == 'n') {
      system(CLEAR_COMMAND);
      goto START;
    } else {
      cout << "Bitte gib entweder q oder n ein!" << endl;
    }
  } while (ende != 'q' || ende != 'n');
}