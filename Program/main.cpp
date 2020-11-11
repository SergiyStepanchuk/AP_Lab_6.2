#include <iostream>
#include <iomanip>
using namespace std;

void draw_line(int size, const char& c = '-') {
	for (--size; size >= 0; size--)
		cout << c;
	cout << endl;
}

int myrand(const int& min, const int& max) {
	return min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min;
}

void full_mass(int* mass, int size, const int* dia) { // сформувати масив;
	for (--size; size >= 0; size--)
		mass[size] = myrand(dia[0], dia[1]);
}

void draw_mass(const int* mass, int size, const int& c_space) {
	draw_line(size * c_space + 2);
	for (int i = 0; i < size; i++)
		cout << "|" << setw(c_space - 1) << mass[i];
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

double do_stuff(int* mass, int size) {
	unsigned int sum = 0, count = 0;
	for (--size; size >= 0; size--) 
		if (mass[size] % 2 == 0) {
			sum += size;
			count++;
		}
	return count > 0 ? sum / (double)count : 0;
}

// 2

void draw_line_2(const int &size, const char& c = '-') {
	cout << c;
	if (size > 1) {
		draw_line_2(size - 1, c);
		return;
	}
	
	cout << endl;
}

void full_mass_2(int* mass, int size_, const int* dia) { // сформувати масив;
	mass[size_] = myrand(dia[0], dia[1]);
	if (size_ > 0)
		full_mass_2(mass, size_ - 1, dia);
}

void draw_mass_2_2(const int* mass, const int& size_, const int& c_space) {
	cout << "|" << setw(c_space - 1) << mass[size_];
	if (size_ > 0)
		draw_mass_2_2(mass, size_ - 1, c_space);
}

void draw_mass_2(const int* mass, const int& size, const int& c_space) {
	draw_line(size * c_space + 2);
	draw_mass_2_2(mass, size - 1, c_space);
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

double do_stuff_2(int* mass,const int &size_, int count, int sum) {
	if (mass[size_] % 2 == 0) {
		sum += size_;
		count++;
	}

	return size_ > 0 ? 
		do_stuff_2(mass, size_ - 1, count, sum): 
		(count > 0 ? 
			sum / (double)count : 
			0);
}

void main() {
	srand(time(NULL));

	cout << "// 1 iteracia" << endl;

	const int c_space = 4; // кількість містя яке виділяєьбся на одну комірку массиву, при виводі в консоль
	int dia[2]; // діапазон 
	unsigned int n;
	cout << "n = "; cin >> n;
	cout << "dia start = "; cin >> dia[0];
	cout << "dia end = "; cin >> dia[1];

	int *mass = new int[n];

	full_mass(mass, n, dia);
	draw_mass(mass, n, c_space);
	cout << "middle " << do_stuff(mass, n) << endl;

	cout << "// 2 recursia" << endl;

	full_mass_2(mass, n-1, dia);
	draw_mass_2(mass, n, c_space);
	cout << "middle " << do_stuff_2(mass, n-1, 0, 0) << endl;

	delete[] mass;
}

