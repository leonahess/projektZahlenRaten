 # Projektaufgabe
 Erstelle eine C++ Konsolenanwendung für ein Zahlenspiel, welches von zwei Partner gespielt werden kann.
 Dabei soll von Partner A eine ganzzahlige Ziffer zwischen 1 und 100 eingeben und durch Partner B erraten werden.
 
 Nach erfolgreicher Eingabe einer zu erratenden Ziffer seitens Partner A soll der bisherige Inhalt in der Konsole gelöscht werden und der Ratespaß für Partner B gestartet werden.
 
 Die Anwendung soll die Eingaben von Partner B auswerten und jeweils Informationen über seinen Versuch ausgeben. Hierbei soll die Ausgabe entweder die Informationen geben, dass die eingegebene Ziffer größer oder kleiner als die gesuchte Zaahl von Partner A ist.
 
 Sämtliche Versuche von Partner B sollen über eine Schleife mitgezählt werden.  
 
 # Fehlerüberprüfung
 Um den Ratespaß tatsächlich zu garantieren, muss die Eingabe zu Beginn von Partner A überprüft werden. Die Eingabe muss sich wirklich in der Spanne von 1 und 100 befinden. Ist die Eingabe ungültig oder nicht unter dieser Bedingung, soll die Eingabe immer wieder wiederholt werden, bis die Ziffer tatsächlich korrekt ist.
 
 # Demonstration
 Das zu erfüllende Endergebnis steht als kompilierte .exe-Anwendung ebenfalls auf unserer Kurswebseite unter Materialien (Datum der aktuellen Kurseinheit) zum Ausprobieren zur Verfügung.
 
 #Konsole leeren/Press any key to continue
 Bevor Partner B die Zahl erraten kann, muss die Konsole für ihn zunächst geleert werden, damit er die Eingabe von Partner A nicht sieht. Ebenfalls muss der Start per Tastendruck erst bestätigt werden. Hierbei gibt es Unterschiede zwischen den auszuführenden Betriebssystemen.
 
 Um eine möglichst einheitliche Lösung zu garantieren, kann der der nachfolgende Code vor dem Hauptprogramm main() definiert werden.
 
 Je nach Plattform muss jeweils die nachfolgende markierte Zeile durch das richtige Präfix (UNIX_ für Linux oder WINDOWS_ für Windows) ersetzt werden.

 ```c++
using namespace std;
const char* UNIX_CLEAR_COMMAND = "clear";
const char* WINDOWS_CLEAR_COMMAND = "cls";
const char* CLEAR_COMMAND = UNIX_CLEAR_COMMAND;
const char* UNIX_PAUSE_COMMAND = "read -n1 -r -p \"-- Press any key to continue --\"";
const char* WINDOWS_PAUSE_COMMAND = "pause";
const char* PAUSE_COMMAND = UNIX_PAUSE_COMMAND;
```
Der Aufruf der „Konsole leeren“-Funktion erfolgt im Hauptprogramm dann jeweils über die Zeile
```c++
system(CLEAR_COMMAND);
```
Und der Aufruf der „Press any key to continue“-Funktion erfolgt nachträglich über die Zeile
```c++
system(PAUSE_COMMAND);
```
