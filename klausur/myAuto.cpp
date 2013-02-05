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
	fahr(risiko);
	int g=random(0,100,false);
	if(g<risiko) throw 1411;
	else{
		int res=(g*risiko)/50;
		if(res > 0){
			cout << "YAR HAR! " << res << "Euro wurden erbeutet!" << endl;
			geldbeutel+=res;	
		}
		else cout << "Gebracht hats nichts, aber immerhin stecken wir nicht im Knast..." << endl << endl;
	}
}

void myAuto::fahr(double kmh, double km){
	if(km<0) km=0;
	static int memory=0;
	for(int i=(int)km;i>0;i--){
		tankFuellung=tankFuellung-verbrauch*kmh;
		if(tankLeer()) throw 0;
		if(i%10 == 1){
			if(kmh>0 && kmh<50) cout<<"tucker\t";
			else if(kmh<100) 	cout<<"Wrumm!\t";
			else if(kmh<150) 	cout<<"WRUMM!\t";
			else {
				cout << "Auto putt... =( " << endl;
				throw 4411;	
			}
			memory++;
			if(memory%10 == 0){
				cout << "zeit zum schlafen..." << endl;
				random(1,1,true);
			}
			if(random(0,5,false)==4) unfall();
		}
	}
	tankFuellung=tankFuellung-verbrauch*kmh*(km-(int)km);
	if(tankLeer()) throw 0;
	kilometerstand+=km;
	cout << endl;
}

bool myAuto::istKaputt(){
	return (aussenspiegel||reifen||motorhaube||fenster);
}

void myAuto::unfall(){
	int k=random(1,4,false);
	switch (k){
		case 1 : aussenspiegel=true; cout << "Knacks, spiegel abgebrochen!\t"; break;
		case 2 : motorhaube=true; cout << "Wums, wo kam die Wand her?\t"; break;
		case 3 : reifen=true; cout << "PENG! Da ist ein Reifen geplatzt...\t"; break;
		case 4 : fenster=true; cout << "Klirr... Das war ein Fenster.\t"; break;
	}
	if(aussenspiegel&&motorhaube&&reifen&&fenster) throw 77;
}

void myAuto::tanken(const int liter){
	int fuell = liter;
	if(fuell==0) fuell=tankKapazitaet-tankFuellung;
	double preis=((double)random(85,125,false))/100;
	cout << endl << "Jetzt kostet der Sprit " << preis << "Euro" << endl
		<< "und du hast nur noch " << tankFuellung << "Liter im Tank" << endl;
	if (preis*fuell>0 && preis*fuell<geldbeutel){
		geldbeutel-=preis*fuell;
		tankFuellung+=fuell;
		cout << "erfolgreich aufgetankt =) fuer nur " << preis*fuell << "Euro" << endl;;
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
	aussenspiegel(false), motorhaube(false), reifen(false), fenster(false) {}

