#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <string>
using namespace std;

class Graphic {
protected:
	char symbol;
	int width, height;

public:
	Graphic(char, int, int);
	virtual ~Graphic();
	char getSymbol() const;
	int getWidth() const;
	int getHeight() const;
	void setSymbol(char);
	virtual void setWidth(int);
	virtual void setHeight(int);
	virtual void draw() const = 0;

	class IllegalDimension {
		private:
			string msg;
		public:
			IllegalDimension(string = "");
			string what() const;
	};
};

Graphic::Graphic(char s, int w, int h) : symbol(s), width(w), height(h)
{ }

Graphic::~Graphic()
{ }

char Graphic::getSymbol() const {
	return symbol;
}

int Graphic::getWidth() const {
	return width;
}

int Graphic::getHeight() const {
	return height;
}

void Graphic::setSymbol(char s) {
	this->symbol = s;
}

void Graphic::setWidth(int w) {
	if (w <= 0){
		throw IllegalDimension("Width must be positive!");
	}
	this->width = w;
}

void Graphic::setHeight(int h) {
	if (h <= 0){
		throw IllegalDimension("Height must be positive!");
	}
	this->height = h;
}

Graphic::IllegalDimension::IllegalDimension(string e) : msg(e)
{ }

string Graphic::IllegalDimension::what() const {
	return msg;
}

#endif
