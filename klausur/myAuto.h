#ifndef MEIN_AUTO_IST_TOLL
#define MEIN_AUTO_IST_TOLL
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class myAuto{
	public:
		int getKilometerstand();
		int getGeldbeutel();
		void fahr(double);
		void fahr(double, double);
		bool istKaputt();
		void unfall();
		bool tankLeer();
		int tankfuellung();
		void tanken(int);
		void volltanken();
		void reparier();
		myAuto();
		myAuto(const myAuto&);
		myAuto(double, double, double, double, double, bool, bool, bool, bool, double);
		void ueberfall(int);
		int getPolizeigefahr();
		string save();
		myAuto& klau();
	private:
		double kilometerstand;
		double geldbeutel;
		double verbrauch;
		double tankKapazitaet;
		double tankFuellung;
		bool aussenspiegel;
		bool motorhaube;
		bool reifen;
		bool fenster;
		int random(int,int,bool);
		double polizeiAufmerksamkeit;
		void sleep();
		void policeCheck();
};

inline int myAuto::getPolizeigefahr(){
	return polizeiAufmerksamkeit;
}

inline int myAuto::getGeldbeutel(){
	return geldbeutel;
}

inline void myAuto::fahr(double kmh){
	fahr(kmh,1);
}

inline bool myAuto::tankLeer(){
	return tankfuellung()<=0;
}

inline int myAuto::tankfuellung(){
	return tankFuellung;
}

inline int myAuto::getKilometerstand(){
	return (int) kilometerstand;
}

inline void myAuto::volltanken(){
	tanken(0);
}
#endif

