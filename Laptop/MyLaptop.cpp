#include <iostream>
#include <string>
using namespace std;

class HDD
{
	string brand;
	float capacity;
	short rpm;
public:
	HDD();
	HDD(const char* brand,float cap, short rpm);
	void Show();
};
HDD::HDD()
{
	brand = "Western Digital";
	capacity = 1000;
	rpm = 5200;
}
HDD::HDD(const char* brand,float cap, short rpm)
{
	this->brand = brand;
	capacity = cap;
	this->rpm = rpm;
}
void HDD::Show()
{
	cout << "Brand - " << brand << endl;
	cout << "Capacity - " << capacity << endl;
	cout << "RPM - " << rpm << endl;
}

class RAM {
	string brand;
	float size;
	float speed;

public:
	RAM();
	RAM(const char* brand, float size, float speed);
	void Show();
};
RAM::RAM()
{
	this->brand = "Corsar";
	this->size = 8;
	this->speed = 3200;
}
RAM::RAM(const char* brand, float size, float speed)
{
	this->brand = brand;
	this->size = size;
	this->speed = speed;
}
void RAM::Show()
{
	cout << "Brand - " << brand << endl;
	cout << "Size - " << size << endl;
	cout << "Speed - " << speed << endl;
}

class Videocard {
	string title;
	string brand;

public:
	Videocard();
	Videocard(const char*, const char*);
	void Show();
	
};
Videocard::Videocard()
{
	title = "GTX 1060";
	brand = "NVIDIA";
}
Videocard::Videocard(const char* name, const char* brand)
{
	title = name;
	this->brand = brand;
}
void Videocard::Show()
{
	cout << "Title - " << title << endl;
	cout << "Brand - " << brand << endl;
}

class CPU{

	string brand;
	string title;

public:
	CPU();
	CPU(const char*, const char*);
	void Show();
};
CPU::CPU()
{
	brand = "AMD";
	title = "Ryzen 2600";
}
CPU::CPU(const char* brand, const char* title)
{
	this->brand = brand;
	this->title = title;
}
void CPU::Show()
{
	cout << "Brand - " << brand << endl;
	cout << "Title - " << title << endl;
}

class Keyboard
{
	string brand;
	string language;
	unsigned int keys;

public:
	Keyboard();
	Keyboard(const char*, const char*, unsigned int);
	void Show();
};
Keyboard::Keyboard()
{
	brand = "Logitech";
	language = "English";
	keys = 108;
}
Keyboard::Keyboard(const char* brand, const char* language, unsigned int keys)
{
	this->brand = brand;
	this->language = language;
	this->keys = keys;
}
void Keyboard::Show()
{
	cout << "Brand - " << brand << endl;
	cout << "Language - " << language << endl;
	cout << "Keys - " << keys << endl;
}

class Printer
{
	string brand;
	int printing_speed;
public:
	Printer();
	Printer(const char*, int);
	void Show();

};
Printer::Printer()
{
	brand = "IBM";
	printing_speed = 100;
}
Printer::Printer(const char* brand, int printing_speed)
{
	this->brand = brand;
	this->printing_speed = printing_speed;
}
void Printer::Show()
{
	cout << "Brand - " << brand << endl;
	cout << "Printing speed - " << printing_speed << endl;
}

class Laptop
{
	string title;

	HDD HDD1;
	RAM RAM1;
	Videocard Videocard1;
	CPU CPU1;
	Keyboard Keyboard1;

	Printer* printer;

public:
	Laptop();
	Laptop(const char* title);
	Laptop(Printer* obj, const char* title);
	void Print();

};
Laptop::Laptop()
{
	title = "N/A";
	printer = nullptr;
}
Laptop::Laptop(const char* title)
{
	this->title = title;
	printer = nullptr;
}
Laptop::Laptop(Printer* obj, const char* title)
{
	printer = obj;
	this->title = title;
}
void Laptop::Print()
{
	cout << "Laptop Title - " << title << endl;
	cout << "----HDD----" << endl;
	HDD1.Show();
	cout << "----RAM----" << endl;
	RAM1.Show();
	cout << "----Videocard----" << endl;
	Videocard1.Show();
	cout << "----CPU----" << endl;
	CPU1.Show();
	cout << "----Keyboard----" << endl;
	Keyboard1.Show();
	if (printer != nullptr) {
		cout << "----Printer----" << endl;
		printer->Show();
	}


}

int main() {

	Printer printer1;
	Laptop* laptop1 = new Laptop(&printer1,"Lenovo");

	laptop1->Print();

	delete laptop1;
	cout << endl << endl;

	Laptop newLaptop(&printer1, "Hello!");

	newLaptop.Print();

	return 0;
}


