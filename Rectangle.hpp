#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include "Graphic.hpp"

class Rectangle : public Graphic {
    public:
        Rectangle(char, int, int);
        virtual ~Rectangle();
        virtual void draw() const override;
};

Rectangle::Rectangle(char s, int w, int h)
: Graphic(s, w, h) {
	if (w <= 0){
		throw IllegalDimension("Width must be positive!");
	}
	if (h <= 0){
		throw IllegalDimension("Height must be positive!");
	}
}

Rectangle::~Rectangle(){

}

void Rectangle::draw() const{
	cout << "Rectangle: " << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << symbol;
		}
		cout << endl;
	}
	cout << endl;
}

#endif


