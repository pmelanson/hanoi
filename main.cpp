#include "hanoi.hpp"
#include <chrono>
#include <thread>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

unsigned	moves = 0,
			interval = 0,
			n = 0;
bool		accelerando = false;
tower_c		one,
			two,
			three;

void draw() {

	int i = 0;
	cout << "\033[2J\033[H";
	while(i != n) {
		cout	<< one[i] << '\t'
				<< two[i] << '\t'
				<< three[i] << '\n';
		++i;
	}
	cout << endl;
}

void solve(tower_c &source, tower_c &temp, tower_c &dest, unsigned discs) {
	if(!discs) return;

	if(debug) cout << "MOVING" << endl;

	//solve by recursively calling function
	solve(source, dest, temp, discs-1);
	dest.push(source.pop());
	++moves;
	if(accelerando) interval -= interval / (pow(2,n) - 1);	//decrement interval by (interval/moves)d

	draw();
	this_thread::sleep_for(chrono::milliseconds(interval));

	solve(temp, source, dest, discs-1);
}

int main() {

	cout << "How many disks would you like to play with?\n> ";
	cin >> n;
	cin.ignore();


	for(unsigned i = n; i != 0; --i) {
		one.push(i);
	}


	cout << "How fast would you like the game to go? Available tempi are\n";
	cout << "A piacere (enter BPM)\n";
	cout << "Tempo giusto (default tempo)\n";
	cout << "Larghissimo\n";
	cout << "Grave\n";
	cout << "Lento\n";
	cout << "Largo\n";
	cout << "Larghetto\n";
	cout << "Adagio\n";
	cout << "Adagietto\n";
	cout << "Andanto moderato\n";
	cout << "Andante\n";
	cout << "Andantino\n";
	cout << "Marcia moderato\n";
	cout << "Moderato\n";
	cout << "Allegretto\n";
	cout << "Allegro\n";
	cout << "Vivace\n";
	cout << "Viacissimo\n";
	cout << "Allegrissimo\n";
	cout << "Presto\n";
	cout << "Prestissimo\n";
	cout << "> ";

	string input;
	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), ::tolower);

	if(input == "a piacere")
		cout << "> ", cin >> interval;
	else if(input == "tempo giusto")
		interval = 75;
	else if(input == "larghissimo")
		interval = 19;
	else if(input == "grave")
		interval = 30;
	else if(input == "lento")
		interval = 43;
	else if(input == "largo")
		interval = 48;
	else if(input == "larghetto")
		interval = 53;
	else if(input == "adagio")
		interval = 60;
	else if(input == "adagietto")
		interval = 67;
	else if(input == "andante moderato")
		interval = 70;
	else if(input == "andante")
		interval = 75;
	else if(input == "andantino")
		interval = 80;
	else if(input == "marcia moderato")
		interval = 84;
	else if(input == "moderato")
		interval = 90;
	else if(input == "allegretto")
		interval = 105;
	else if(input == "allegro")
		interval = 120;
	else if(input == "vivace")
		interval = 138;
	else if(input == "vivacissimo")
		interval = 145;
	else if(input == "allegrissimo")
		interval = 163;
	else if(input == "presto")
		interval = 170;
	else if(input == "prestissimo")
		interval = 180;
	else
		cout << "Bad input, defaulting to Tempo giusto\n", interval = 75;

	interval = 60000/interval;	//convert from BPM to ms


	cout << "Enable Accelerando? (gets faster with time, default 'n') (y/n)\n> ";
	char accel;
	cin >> accel;

	if(tolower(accel) == 'y')
		accelerando = true;
	else
		accelerando = false;



	draw();
	cout << "Press ENTER to continue";
	cin.ignore();
	cin.ignore();

	solve(one, two, three, n);


	cout << moves << " moves taken\n";
	system("pause");


	return 0;
}
