#include "myAuto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int myAuto::random(int lowerbounds, int upperbounds, bool randomize){
	time_t t;
	if(randomize) {
		time(&t);
		srand((unsigned int)t);
	}
	return lowerbounds + std::rand() % (upperbounds - lowerbounds + 1);
} 

void myAuto::ueberfall(int risiko){
	cout << endl;
	if(risiko < 0 || risiko > 100) throw 1411;
	fahr(risiko+40,risiko/2);
	int g=random(0,100,false);
	if(g<polizeiAufmerksamkeit) throw 1411;
	else{
		int res=(g*risiko)/20-risiko;
		if(res > 0){
			cout << "YAR HAR! " << res << "Euro wurden erbeutet!" << endl;
			geldbeutel+=res;	
		}
		else cout << "Gebracht hats nichts, aber immerhin stecken wir nicht im Knast..." << endl << endl;
		polizeiAufmerksamkeit+=risiko/4;
		policeCheck();
	}
}

void myAuto::policeCheck(){
	if(polizeiAufmerksamkeit<20)		cout << "Die Polizei hat dich im Auge" << endl;
	else if(polizeiAufmerksamkeit<40)	cout << "Die ersten Cops kennen deinen Namen" << endl;
	else if(polizeiAufmerksamkeit<60)	cout << "Die Bullen fangen an dich zu besuchen" << endl;
	else if(polizeiAufmerksamkeit<80)	cout << "Achtung! Langsam wirds eng..." << endl;
	else if(polizeiAufmerksamkeit<100)	cout << "Es ist ein Wunder das du noch frei rumrennst" << endl;
	else if(polizeiAufmerksamkeit>=100) throw 101;
}

void myAuto::fahr(double kmh, double km){
	if(km<0) km=0;
	static int memory=0;
	for(int i=(int)km;i>0;i--){
		tankFuellung=tankFuellung-verbrauch*kmh;
		if(tankLeer()) throw 0;
		if(i%10 == 1){
			if(kmh>0 && kmh<50) cout<<"Tucker...\t";
			else if(kmh<100) 	cout<<"Wrumm!...\t";
			else if(kmh<150) 	cout<<"WRUMM!...\t";
			else {
				cout << "Auto putt... =( " << endl;
				throw 4411;	
			}
			memory++;
			if(memory%10 == 0){
				sleep();
			}
			if(random(0,50,false)==42) unfall();
		}
	}
	tankFuellung=tankFuellung-verbrauch*kmh*(km-(int)km);
	if(tankLeer()) throw 0;
	kilometerstand+=km;
	cout << endl;
}

void myAuto::sleep(){
	cout << " zeit zum Schlafen..." << endl;
	if(random(1,200,true)<polizeiAufmerksamkeit){
		throw 14112;
	}
	if(polizeiAufmerksamkeit>0){
		if(polizeiAufmerksamkeit>20) polizeiAufmerksamkeit-=8;
		else polizeiAufmerksamkeit-=4;
		cout << "Ein paar Cops vergessen dich." << endl;
		if(polizeiAufmerksamkeit<=0){
			polizeiAufmerksamkeit=0;
			cout << "Du bist von der Fahndungsliste runter!" << endl;
		} 
	}
}

bool myAuto::istKaputt(){
	return (aussenspiegel||reifen||motorhaube||fenster);
}

void myAuto::unfall(){
	int k=random(1,4,false);
	switch (k){
		case 1 : if(!aussenspiegel){
			aussenspiegel=true;
			cout << "Knacks, Spiegel abgebrochen!\t";
			break;
		}
		case 2 : if(!motorhaube){
			motorhaube=true;
			cout << "Wums, wo kam die Wand her?\t";
			break;
		}
		case 3 : if(!reifen){
			reifen=true;
			cout << "PENG! Da ist ein Reifen geplatzt...\t";
			break;
		}
		case 4 : if(!fenster){
			fenster=true;
			cout << "Klirr... Das war ein Fenster.\t";
			break;
		}
	}
	if(aussenspiegel&&motorhaube&&reifen&&fenster) throw 77;
}

void myAuto::tanken(const int liter){
	int fuell = liter;
	if(fuell==0) fuell=tankKapazitaet-tankFuellung;
	double preis=((double)random(85,125,false))/100;
	cout << endl << "Jetzt kostet der Sprit " << preis << "Euro" << endl
		<< "und du hast nur noch " << tankFuellung << "Liter im Tank" << endl;
	if (preis*fuell>=0 && preis*fuell<geldbeutel){
		geldbeutel-=preis*fuell;
		tankFuellung+=fuell;
		cout << "erfolgreich aufgetankt =) fuer " << preis*fuell << "Euro" << endl;;
		if(tankFuellung>tankKapazitaet){
			cout << "Auch wenn dabei " << tankFuellung-tankKapazitaet << " liter uebergelaufen sind" << endl;
			tankFuellung=tankKapazitaet;
		}
		cout << "Neue Tankfuellung ist: " << tankFuellung << endl;
	}
	else if(preis > 0)cout << "Ohne Knete kein Sprit Kindchen..." << endl;
}

void myAuto::reparier(){
	cout << endl << "Willkommen in der Autowerkstatt" << endl;
	if(aussenspiegel&&motorhaube&&reifen&&fenster) throw 77;
	int sum=0;
	if(aussenspiegel)sum += 10;
	if(motorhaube) sum+= 20;
	if(reifen) sum += 5;
	if(fenster) sum += 7;
	if(sum>geldbeutel) cout << "Sie haben leider nicht genuegend Geld =(" << endl
		<< "Sie braeuchten " << sum << "Euro, haben aber nur " << geldbeutel << endl;
	else{
		geldbeutel-=sum;
		cout << "Ihr Auto wurde repariert, die reparatur hat " << sum << "Euro gekostet" << endl;
	}
}

myAuto::myAuto() : kilometerstand(0), geldbeutel(50), verbrauch(0.003), tankKapazitaet(50), tankFuellung(tankKapazitaet),
	aussenspiegel(false), motorhaube(false), reifen(false), fenster(false), polizeiAufmerksamkeit(0) {
	random(1,1,true);
}

