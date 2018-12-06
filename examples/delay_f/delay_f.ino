/**
 * Example für die Verwendung der Funktion delay_f(), da diese mit der Verwendung von Funktionszeigern etwas schwieriger zu verstehen
 * ist
 * @author Dominik Authaler
 */

//Nicht vergessen: Die Library muss eingebunden werden!
#include "bot.h";

/*
 * Erzeugen des notwendigen Objekts, da die Library objektorientiert aufgebaut ist. Der wichtigste Unterschied zur bisherigen, nicht 
 * objektorientierten Programmierung, liegt darin, dass nun Methoden und Variablen zu Objekten zusammengefasst werden. Insbesondere
 * bedeutet dies, dass ihr die Methoden, welche in der Datei bot.h aufgelistet sind, nur auf einem Bot Objekt aufrufen könnt!  
 * Symbolisiert wird dies durch die Struktur "Objektname"."Methodenname" (vgl. Serial.begin(), ihr habt unbewusst die 
 * Objektorientierung die ganze Zeit schon verwendet ;-)). Bei unterem Aufruf ist das erste "bot" der Klassenname, das Zweite 
 * gibt den Namen des Objekts an (vgl. Erstellen von Variablen).
 */
bot bot;

//Dem Compiler die Grundstruktur der verwendeten Methoden klar machen --> lediglich Typen, Angabe von Variablennamen ist optional
//Man beachte, dass der Aufbau dem aus der Header-Datei folgt. Diese gibt vor, dass der Methode delay_f() eine Funktionszeiger auf
//eine void liefernde und uint64_t als Übergabeparamter annehmende Methode übergeben werden muss. 
void toTrigger(uint64_t);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Starte delay");
  //Die Übergabe des Funktionszeigers ist denkbar einfach, ihr schreibt einfach den Namen der Methode hin ;)
  bot.delay_f(500, toTrigger);
  Serial.println("Ende delay");

  //Als Vergleich, hier wird alles blockiert bis die Zeit abgelaufen ist!
  delay(500);
}

//Diese Methoden wollen wir während des Wartens mittels delay_f immer wieder aufrufen. Übergeben wird ihr von delay_f dabei
//die noch im delay verbleibende Zeit. Eine mögliche Anwendung wäre es also, hier in definierten Intervallen die 
//Ultraschallsensoren abzufragen. Dazu ist es dann noch notwendig, sich mit millis() die aktuelle Systemzeit zu besorgen
//und eventuell in einer globalen Variable zu speichern, wann das letzte Mal die Sensoren abgefragt wurden.
void toTrigger(uint64_t) {
    Serial.println("Triggered");
}

