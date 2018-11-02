#include <iostream>
#include <string>
using namespace std;
#include <algorithm>

int main() {
	/*
	//Von Dezimal in die beliebige Zahlsystem konvertieren
	int z;
	int b;
	int v;
	//maximal 32 Stellen für int-Zeichen
	char zieldarstellung[33];
	
	zieldarstellung[32] = '\0';
	memset(zieldarstellung, '0', 32 * sizeof(char));
	
	cin >> z;
	cin >> b;
	int i = 31;
	while (z >= 1) {
		v = z % b;
		if (v <= 9) {
			zieldarstellung[i] = v +'0';
		}
		else if (v==10){
			v = 'A';
			zieldarstellung[i] = v;
		}
		else if (v == 11) {
			v = 'B';
			zieldarstellung[i] = v;
		}
		else if (v == 12) {
			v = 'C';
			zieldarstellung[i] = v;
		}
		else if (v == 13) {
			v = 'D';
			zieldarstellung[i] = v;
		}
		else if (v == 14) {
			v = 'E';
			zieldarstellung[i] = v;
		}
		else if (v == 15) {
			v = 'F';
			zieldarstellung[i] = v;
		}

		
		cout << zieldarstellung[i];
		i--;

		z = z / b;
		}
		
	cout << endl << zieldarstellung << endl;
	
	*/
	
	int dzahl;
	int ergebnis;
	int zsystem;
	bool h=true;
	
	cout << "Geben Sie Ihr Speicherformat  ein"<<endl;
	cin >> zsystem;
	zsystem = zsystem * 8;
	char* array1= new char[zsystem+1];
	array1[zsystem] = '\0';
	
	int element = zsystem - 1;
	int i = zsystem-1;
	cout << "Geben Sie Ihre Dezimalzahl ein" << endl;
	cin >> dzahl;
		memset(array1, '0', zsystem - 1 * sizeof(char));
	if (dzahl > 0) {
		while (dzahl >= 1) {
			ergebnis = dzahl % 2;
			array1[i] = ergebnis + '0';
			i--;
			dzahl = dzahl / 2;
		}
		
	}
	
	else if (dzahl < 0) {
		h = false;
		dzahl = dzahl * (-1);
		while (dzahl >0) {
			ergebnis = dzahl % 2;
			array1[i] = ergebnis + '0';
			dzahl = dzahl / 2;
			i--;
		}
		
		while (element >= 0) {
			
			if (array1[element] == '1') {
				element--;
				while (element >= 0) {

					if (array1[element] == '0') {
						array1[element] = '1';
					}
					else {
						array1[element] = '0';
					}
					element--;


				}
			}
			 
			else if (array1[element] == '0') {
				element--;
			}
			

			
		}
	}

	if (h==true && array1[0]=='1' ) {
		cout << "Fehler – Resultat gälte als negative Zahl!";

	}
	else {
		cout << array1;
	}
	system("pause");
	return 0;

}