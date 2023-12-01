#include "Graphic.hpp"
#include "MyVector.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

#include <cstdlib>
#include <iostream>
#include <new>

/******************************************************************************
 * 																			  *
 * 					Jeremy Bridgeman & Austin Huang							  *
 * 																			  *
 ******************************************************************************/

using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

template <typename T>
void printVector(MyVector<T>&);

void testOne();
void testTwo();
void testThree();
void testFour();

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls four test suites on the `MyVector`
 * class template.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer that signals the exit code to the operating system (OS)
*******************************************************************************/

int main() {
    // call the test suites
    testOne();
    testTwo();
    testThree();
    testFour();

    // terminate
    return 0;
}

/*******************************************************************************
 * Description:
 * Prints out the elements inside `vec`. Assumes the type `T` overloads the `<<`
 * insertion operator.
 *
 * Input:
 * vec - a reference to a `MyVector<T>` object
 *
 * Output:
 * N/A
*******************************************************************************/

template <typename T>
void printVector(MyVector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

/*******************************************************************************
 * Description:
 * Tries various legal and illegal operations on a `MyVector<int>` object.
 *
 * Input:
 * N/A
 *
 * Output:
 * N/A
*******************************************************************************/

void testOne() {
    // create an empty vector
    MyVector<int> vec1;

    // confirm the size is 0
    cout << "vec1 size: " << vec1.size() << endl;

    // try an illegal operation
    try {
        cout << vec1.front() << endl;
    }
    catch (MyVector<int>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try another illegal operation
    try {
        cout << vec1.back() << endl;
    }
    catch (MyVector<int>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try another illegal operation
    try {
        cout << vec1[0] << endl;
    }
    catch (MyVector<int>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try another illegal operation
    try {
        cout << vec1.find(9) << endl;
    }
    catch (MyVector<int>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try another illegal operation
    try {
        vec1.remove(-4);
    }
    catch (MyVector<int>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try to add an item
    try {
        vec1.add(15);
    }
    catch (bad_alloc& e) {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    // confirm the size is now 1
    cout << "vec1 size: " << vec1.size() << endl;

    // try legal operations
    try {
        cout << "vec1 front: " << vec1.front() << endl;
        cout << "vec1 back: " << vec1.back() << endl;
        printVector(vec1);
    }
    catch (MyVector<int>::VectorError& e) {
        cout << e.what() << endl;
    }
}

/*******************************************************************************
 * Description:
 * Tries various legal and illegal operations on a `MyVector<char>` object.
 *
 * Input:
 * N/A
 *
 * Output:
 * N/A
*******************************************************************************/

void testTwo() {
    // create a vector with starting size 5
    MyVector<char> vec2(5);

    // confirm the size is 5
    cout << "vec2 size: " << vec2.size() << endl;

    // try to initialize the vector and print it
    try {
        for (int i = 0; i < vec2.size(); i++) {
            vec2[i] = static_cast<char>(i + 97);
        }
        printVector(vec2);
    }
    catch (MyVector<char>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try an illegal operation
    try {
        cout << vec2[13] << endl;
    }
    catch (MyVector<char>::VectorError& e) {
        cout << e.what() << endl;
    }

    // create another vector by copying from the first vector
    MyVector<char> vec3(vec2);

    // try to print it to confirm the elements were copied over
    try {
        printVector(vec3);
    }
    catch (MyVector<char>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try to add elements and print again
    try {
        for (int i = 5; i < 10; i++) {
            vec3.add(static_cast<char>(i + 97));
        }
        printVector(vec3);
    }
    catch (MyVector<char>::VectorError& e) {
        cout << e.what() << endl;
    }

    // confirm the new size is 10
    cout << "vec3 size: " << vec3.size() << endl;

    // try an illegal operation
    try {
        cout << vec3.find('q') << endl;
    }
    catch (MyVector<char>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try to find a legal item
    try {
        cout << "Index of item d is " << vec3.find('d') << endl;
    }
    catch (MyVector<char>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try to remove the front and back of the vector, then print
    try {
        vec3.remove(vec3.front());
        vec3.remove(vec3.back());
        printVector(vec3);
    }
    catch (MyVector<char>::VectorError& e) {
        cout << e.what() << endl;
    }

    // try to reset the vector
    try {
        vec3.reset();
    }
    catch (MyVector<char>::VectorError& e) {
        cout << e.what() << endl;
    }

    // confirm the size is now 0
    cout << "vec3 size: " << vec3.size() << endl;
}

/*******************************************************************************
 * Description:
 * Tests if the `=` assignment operator overload works for `MyVector<double>`
 * objects.
 *
 * Input:
 * N/A
 *
 * Output:
 * N/A
*******************************************************************************/

void testThree() {
    // create a dynamic vector with starting size 5
    // place elements inside the vector and print
    MyVector<double>* vec4 = new MyVector<double>(5);
    (*vec4)[0] = 9.8;
    (*vec4)[1] = 0.078;
    (*vec4)[2] = -4.0;
    (*vec4)[3] = 354.96;
    (*vec4)[4] = 1.1111;
    printVector(*vec4);

    // create a second vector with starting size 7
    // place elements inside the vector and print
    MyVector<double> vec5(7);
    vec5[0] = 3.5;
    vec5[2] = -2.2;
    vec5[4] = 4.4;
    vec5[5] = -5.5;
    vec5[1] = 1.1;
    printVector(vec5);

    // call the overload for the assignment operator
    *vec4 = vec5;

    // print both vectors to verify they have the same elements
    printVector(*vec4);
    printVector(vec5);

    // change each vector
    vec4->add(4.1847);
    vec5.remove(3.5);

    // print both vectors again to verify they have different outputs
    printVector(*vec4);
    printVector(vec5);

    // release dynamic memory
    delete vec4;
    vec4 = nullptr;
}

/*******************************************************************************
 * Description:
 * Tests if the `Graphic` family of classes were implemented correctly by using
 * a polymorphic `MyVector` object.
 *
 * Input:
 * N/A
 *
 * Output:
 * N/A
*******************************************************************************/

void testFour() {
    // create a polymorphic vector of 4 graphics
    MyVector<Graphic*> vec6(4);
    vec6[0] = new Rectangle('*', 8, 4);
    vec6[1] = new Rectangle('-', 3, 10);
    vec6[2] = new Triangle('.', 5, 5);
    vec6[3] = new Triangle('+', 7, 7);

    // draw the graphics inside the vector
    cout << endl;
    for (int i = 0; i < vec6.size(); i++) {
        vec6[i]->draw();
    }

    // try illegal dimensions
    try {
        vec6[0]->setWidth(0);
    }
    catch (const Graphic::IllegalDimension& e) {
        cout << e.what() << endl;
    }
    try {
        vec6[1]->setHeight(-9);
    }
    catch (const Graphic::IllegalDimension& e) {
        cout << e.what() << endl;
    }
    try {
        vec6[2]->setWidth(0);
    }
    catch (const Graphic::IllegalDimension& e) {
        cout << e.what() << endl;
    }
    try {
        vec6[3]->setHeight(-9);
    }
    catch (const Graphic::IllegalDimension& e) {
        cout << e.what() << endl;
    }
    try {
        vec6[2]->setHeight(3);
    }
    catch (const Graphic::IllegalDimension& e) {
        cout << e.what() << endl;
    }

    // try illegal dimensions in the constructor
    try {
        vec6.add(new Rectangle('?', 4, 0));
    }
    catch (const Graphic::IllegalDimension& e) {
        cout << e.what() << endl;
    }
    try {
        vec6.add(new Triangle('?', 5, 7));
    }
    catch (const Graphic::IllegalDimension& e) {
        cout << e.what() << endl;
    }

    // release dynamic memory
    for (int i = 0; i < vec6.size(); i++) {
        delete vec6[i];
    }
}





