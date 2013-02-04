#include "hanoi.hpp"
#include <chrono>
#include <thread>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <allegro.h>

using namespace std;

unsigned	moves = 0,
			calls = 0,
			interval = 0,
			n = 0;
bool		accelerando = false;
tower_c		one(1),
			two(2),
			three(3);
BITMAP		*buffer = NULL;

void init_allegro() {

	allegro_init();
	install_keyboard();

	set_color_depth(desktop_color_depth());
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, scrx,scry, 0, 0);

	buffer = create_bitmap(SCREEN_W,SCREEN_H);

}

void draw() {

	unsigned spacing = SCREEN_W/4;

	one.draw(spacing);
	two.draw(spacing);
	three.draw(spacing);

	draw_sprite(buffer, screen, SCREEN_H, SCREEN_W); // Draw the buffer to the screen
    draw_sprite(screen, buffer, 0, 0);
    unsigned percent_done = (moves / (pow(2,n) - 1)) * 255;
    clear_to_color(buffer, makecol(percent_done, percent_done, percent_done)); // Clear the contents of the buffer bitmap

}

void solve(tower_c &source, tower_c &temp, tower_c &dest, unsigned discs) {
	if(!discs) return;

	if(debug) cout << "MOVING" << endl;

	//solve by recursively calling function
	solve(source, dest, temp, discs-1);
	dest.push(source.pop());
	++moves;
	if(accelerando) interval -= interval / (pow(2,n) - 1);	//decrement interval by (interval/total moves)

	draw();
	this_thread::sleep_for(chrono::milliseconds(interval));

	solve(temp, source, dest, discs-1);

	++calls;
}

int main() {

	cout << "How many disks would you like to play with?\n> ";
	cin >> n;
	cin.ignore();

	for(unsigned i = n; i != 0; --i) {
		one.push(i);
	}


	cout << "\nHow fast would you like the game to go? Available tempi are:\n\n";
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
	cout << "TURBO\n";
	cout << "\n> ";

	string input;
	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), ::tolower);

	if(input == "a piacere")
		cout << "> ",					cin >> interval;
	else if(input == "tempo giusto")	interval = 75;
	else if(input == "larghissimo")		interval = 19;
	else if(input == "grave")			interval = 30;
	else if(input == "lento")			interval = 43;
	else if(input == "largo")			interval = 48;
	else if(input == "larghetto")		interval = 53;
	else if(input == "adagio")			interval = 60;
	else if(input == "adagietto")		interval = 67;
	else if(input == "andante moderato")interval = 70;
	else if(input == "andante")			interval = 75;
	else if(input == "andantino")		interval = 80;
	else if(input == "marcia moderato")	interval = 84;
	else if(input == "moderato")		interval = 90;
	else if(input == "allegretto")		interval = 105;
	else if(input == "allegro")			interval = 120;
	else if(input == "vivace")			interval = 138;
	else if(input == "vivacissimo")		interval = 145;
	else if(input == "allegrissimo")	interval = 163;
	else if(input == "presto")			interval = 170;
	else if(input == "prestissimo")		interval = 180;
	else if(input == "turbo")			interval = 1;
	else
		cout << "Unrecognised input, defaulting to Tempo giusto\n", interval = 75;

	interval = 60000/interval;	//convert from BPM to ms
	if(input == "turbo") interval = 0;


	char accel;
	cout << "\nEnable Accelerando? (gets faster over time) [y/n, defulat 'n']:\n> ";
	cin >> accel;

	if(tolower(accel) == 'y')
		accelerando = true;
	else
		accelerando = false;

	if(debug) cout << "\n\n" << one.discs << '\t' << two.discs << '\t' << three.discs << '\n';

	init_allegro();

	draw();

	solve(one, two, three, n);
	textout_centre_ex(screen, font, "Press ESC to exit",
					 SCREEN_W/2, 20,
					 makecol(0,0,0), makecol(255,255,255));
	while(!key[KEY_ESC]);

	if(debug) cout << "\n\n" << one.discs << '\t' << two.discs << '\t' << three.discs << '\n';
	cout <<"\n\nIt took " << calls << " recursive calls to move the discs " << moves << " times.\n";
	system("pause");


	return 0;
}
END_OF_MAIN()
