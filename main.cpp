#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>

using namespace std;

struct osoba{
	string imie,nazwisko,status,wiek;
};
class program{
	vector <struct osoba> spis;
	public:
		ifstream wejscie;
		ofstream wyjscie;
		program();
		~program();
		
	void sprawdzPlik();
	void wczytywanie();
	void sprawdzanie();
	void zapis();
};
program::program(){
	wejscie.open("wejscie.txt");
	wyjscie.open("wyjscie.txt");
	wyjscie<<"["<<endl;
}
program::~program(){
	wyjscie<<"]";
	wejscie.close();
	wyjscie.close();
	
}
void program::sprawdzPlik(){
	if(wejscie.good()&&wyjscie.good()){}
	else cout<<"blad";
}
void program::wczytywanie(){
	struct osoba wprowadzenie;
	while(!wejscie.eof()){
		wejscie>>wprowadzenie.wiek>>wprowadzenie.imie>>wprowadzenie.nazwisko;
		spis.push_back(wprowadzenie);
	
	}
}
void program::zapis(){
	for(vector<struct osoba>::iterator it = spis.begin(); it != spis.end(); ++it){
		wyjscie<<"{\"imie\":"+it->imie+",""\"nazwisko\":"+it->nazwisko+",""\"wiek\":"+it->wiek+",""\"status\":"+it->status+"},"<<endl;
	}
}
void program::sprawdzanie(){
	regex poprawne("[A-Z][a-z]+");
	for(vector<struct osoba>::iterator it = spis.begin(); it != spis.end(); ++it){
		if(regex_match(it->imie,poprawne)){
			it->status = "OK";
		}
		else{
			it->status = "error";
		}
	}
}
int main() {
	program p1;
	p1.sprawdzPlik();
	p1.wczytywanie();
	p1.sprawdzanie();
	p1.zapis();
	return 0;
}
