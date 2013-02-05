#include <iostream>
#include "myAuto.h"
using namespace std;

int main() {
	myAuto meinAuto;
	int input=0;
	try{
		while(input<8 && input >=0){
			if(input==0)
				cout <<  endl <<"MENU:" << endl
					 << "0\t" << "Ruft dieses Menue wieder auf" << endl
					 << "1\t" << "Fahren" << endl
					 << "2\t" << "Kilometerstand anzeigen" << endl
					 << "3\t" << "Geldstatus anzeigen" << endl
					 << "4\t" << "Laden ueberfallen" << endl
					 << "5\t" << "Tanken" << endl
					 << "6\t" << "Auto auf Schaeden ueberpruefen" << endl
					 << "7\t" << "In die Werkstatt fahren" << endl
					 << "8\t" << "Beenden" << endl;
			if(input==1){
				double a,b;
				cout << "Wie schnell? ";
				cin >> a;
				cout << "Wie weit? ";
				cin >> b;
				cout << endl;
				meinAuto.fahr(a,b);
			}
			if(input==2){
				cout << "Kilometerstand ist: " << meinAuto.getKilometerstand() << endl;
			}
			if(input==3){
				cout << "Du hast noch " << meinAuto.getGeldbeutel() << "Euro" << endl;
			}
			if(input==4){
				double risk;
				cout << "Wie risikoreich (0-100%) moechtest du vorgehen?";
				cin >> risk;
				meinAuto.ueberfall(risk);
			}
			if(input==5){
				int liter;
				cout << "Wie viel moechtest du tanken? (Mit 0 tankst du voll)" << endl;
				cin >> liter;
				meinAuto.tanken(liter);
			}
			if(input==6){
				if(meinAuto.istKaputt()) cout << "Ja, es wird Zeit fuer die Werkstatt..." << endl;
				else cout << "Das Auto sieht super aus!" << endl;
			}
			if(input==7){
				meinAuto.reparier();
			}
			cin >> input;	
		}
	} catch(int err){
		if (err==0){
			cout << "Mwahahahaha, mitten auf der Straße stehen geblieben?" << endl;
			return 0;	
		}
		if (err==1411){
			cout << "Wilkommen im Gefaengnis!" << endl << "\tGame Over!";
			return 0;
		}
		if(err==4411){
			cout << "Sieht aus als würde dein Auto explodieren..." << endl << "Goettliche Gerechtigkeit und sowas" << endl;
			return 0;
		}
		if(err==77){
			cout << "Das sieht nach nem Kaputtem Auto aus =D, VERSAGER!" << endl;
			return 0;
		}
	}
	/*
		meinAuto.fahr(45.3);
		cout << "kilometerstand ist: " << meinAuto.getKilometerstand() << endl;
		cout << "Zeit fuer RISIKO: UEBERFALL!!!" << endl;
		meinAuto.ueberfall(50);
		meinAuto.fahr(145.3,100);
		cout << "Kilometerstand ist: " << meinAuto.getKilometerstand() << endl;
		cout << "und wir haben noch " << meinAuto.getGeldbeutel() << "Euro im Beutel" << endl;
		meinAuto.volltanken();
	*/
}
