/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIII <BR>
 * Versuch 6: Satndard Template Library - STL
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include<fstream>

#include "Student.h"


//void pop_front(std::vector<Student> &v)
//{
//	if (v.size() > 0) {
//		v.erase(v.begin());
//	}
//}

int main()
{
	std::vector<Student> studentenListe;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
		studentenListe.push_back(Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1"));
		studentenListe.push_back(Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23"));
		studentenListe.push_back(Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55"));
		studentenListe.push_back(Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12"));
		studentenListe.push_back(Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9"));
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement hinten entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
			      << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
			      << "(5): Datenelement Loeschen" << std::endl
			      << "(6): Datenelement vorne hinzufuegen" << std::endl
			      << "(7): Datenelement vorne Loeschen" << std::endl
			      << "(8): Daten aus einer Datei einlesen"<<std::endl
			      << "(9): Daten in eine Datei sichern" << std::endl

                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

					studentenListe.push_back(Student(matNr, name, geburtstag, adresse));
                }
                break;

            // Datenelement hinten entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                       
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
						(studentenListe.back()).ausgabe();
						studentenListe.pop_back();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
					std::vector<Student>::const_iterator it;
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
					for (it = studentenListe.begin(); it != studentenListe.end(); it++)
					{
						it->ausgabe();
					}
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

				//Datenbank rueckwaerts ausgeben
			case '4':
				if (!studentenListe.empty())
				{
					std::vector<Student>::const_reverse_iterator revit;
					std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
					for (revit = studentenListe.rbegin(); revit != studentenListe.rend(); revit++)
					{
						revit->ausgabe();
					}
				}
				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}
				break;

				//Elemente loeschen
			case '5':
				if (!studentenListe.empty())
				{
					bool result = false;
					std::vector<Student>::const_iterator it;
					unsigned int matNum;
					std::cout << "Die zu loeschenede Matrikelnummeer eingeben: " << std::endl;
					std::cin >> matNum;

					for (it = studentenListe.begin(); it <= studentenListe.end(); it++)
					{
						if (it->getMatNr() == matNum)
						{
							result = true;
							std::cout << "Der Student wurde geloescht:" << std::endl;
							it->ausgabe();
							studentenListe.erase(it);
							break;
						}

						else
						{
							if (result)
							{
								std::cout << "Die Matrikelnummer existiert nicht!" << std::endl;
							}

						}
					}
				}

				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}
				break;

				// Datenelement vorne hinzufuegen
			case '6':
			{
				std::vector<Student>::const_iterator it;
				unsigned int matNr = 0;
				std::string name = "";
				std::string geburtstag = "";
				std::string adresse = "";

				std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
				getline(std::cin, name);    // ganze Zeile einselen inklusive aller Leerzeichen

				std::cout << "Geburtsdatum: ";
				getline(std::cin, geburtstag);

				std::cout << "Adresse: ";
				getline(std::cin, adresse);

				std::cout << "Matrikelnummer: ";
				std::cin >> matNr;
				std::cin.ignore(10, '\n');


				it = studentenListe.begin();
				studentenListe.insert(it, Student(matNr, name, geburtstag, adresse));

			}
			break;

			//Datenelement vorne Loeschen
			case '7':
			{
				if (!studentenListe.empty())
				{
					std::vector<Student>::const_iterator it;
					std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
					it= studentenListe.begin();
					it->ausgabe();
					studentenListe.erase(it);
				}
				else
				{
					std::cout << "Die Liste ist leer!\n";
				}
			}
			break;

			//Daten aus einer Datei einlesen
			case'8':
			{   
				unsigned int matNr = 0;
			    std::string name = "";
			    std::string geburtstag = "";
			    std::string adresse = "";
				
				//Erstellen eines Objekts der Klasse ifstream 
				//Kurzform,die Datei wird beim Erstellen des Objekts direkt geöffnet 

				std::ifstream eingabe("studenten.txt"); 

                //DatenausderDateilesen 

				eingabe >> matNr;
				eingabe.ignore(1, '\n');
				std::getline(eingabe, name);
				std::getline(eingabe, geburtstag);
				std::getline(eingabe, adresse);
			
				//AusgabederDatenaufdemBildschirm 

				std::cout << matNr << std::endl;
				std::cout << name << std::endl;
				std::cout << geburtstag << std::endl;
				std::cout << adresse << std::endl;

				//Dateiwirdautomatischgeschlossen
			
				return 0;
			}
			break;

			//Daten in eine Datei sichern
			case'9':
			{  
				unsigned int matNr = 0;
			   std::string name = "";
			   std::string geburtstag = "";
			   std::string adresse = "";

				//Erstellen eines Objekts der Klasse ofstream 

				std::ofstream ausgabe;

				//Öffnen einer Datei,in die geschrieben werden soll ausgabe.open("studenten.txt"); 
				//Daten in die Datei schreiben 

				ausgabe << matNr << std::endl;
				ausgabe << name << std::endl;
				ausgabe << geburtstag << std::endl;
				ausgabe << adresse << std::endl;
				//Schließen der Datei 

				ausgabe.close();
			
					
				return 0;
			
			}
			break;


            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
