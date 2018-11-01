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
	
	
	cout << "Geben Sie Ihr Speicherformat in Bits ein"<<endl;
	cin >> zsystem;
	char* array1= new char[zsystem];
	array1[zsystem-1] = '\0';
	
	int element = zsystem - 2;
	int i = zsystem-2;
	cout << "Geben Sie Ihre Dezimalzahl ein" << endl;
	cin >> dzahl;
	if (dzahl > 0) {
		memset(array1, '0', zsystem - 1 * sizeof(char));
		while (dzahl >= 1) {
			ergebnis = dzahl % 2;
			array1[i] = ergebnis + '0';
			i--;
			dzahl = dzahl / 2;
		}
		
	}
	
	else if (dzahl < 0) {
		memset(array1, '1', zsystem-1 * sizeof(char));
		dzahl = dzahl *(-1);
		while (dzahl >= 1) {
			ergebnis = dzahl % 2;
			if (ergebnis == 0) {
				ergebnis = 1;
			}
			else {
				ergebnis = 0;

			}

			array1[i] = ergebnis + '0';
			i--;
			dzahl = dzahl / 2;
		}
		while (element>=0) {
			if (array1[element] == '1') {
				array1[element] = '0';
				element--;

			}
			else if (array1[element] == '0') {
				array1[element] = '1';
				break;
			}
		
		}
		
		
	}
	
	cout << array1;

	system("pause");
	return 0;

}