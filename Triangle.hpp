#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Graphic.hpp"
#include <iostream>

class Triangle : public Graphic {
    public:
        Triangle(char, int, int);
        virtual ~Triangle();
        virtual void setWidth(int) override;
        virtual void setHeight(int) override;
        virtual void draw() const override;
};

Triangle::Triangle(char s, int w, int h)
: Graphic(s, w, h) {
	if (w < h){
		throw IllegalDimension("Width must be the same as height for a triangle!");
	}
	if (w > h){
		throw IllegalDimension("Height must be the same as width for a triangle!");
	}
	if (w <= 0){
		throw IllegalDimension("Width must be positive!");
	}
	if (h <= 0){
		throw IllegalDimension("Height must be positive!");
	}
}

Triangle::~Triangle(){

}

void Triangle::draw() const {
	cout << "Triangle: " << endl;
	for (int i = height; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			cout << symbol;
		}
		cout << endl;
	}
	cout << endl;
}

void Triangle::setHeight(int h) {
	if (h <= 0){
		throw IllegalDimension("Height must be positive!");
	}
	height = h;
	width = h;
}

void Triangle::setWidth(int w) {
	if (w <= 0){
		throw IllegalDimension("Width must be positive!");
	}
	height = w;
	width = w;
}

#endif
