#include <iostream>
#include <cmath>

// Interface for printable objects
class Printable {
public:
    virtual void print() const = 0;
};

// Base class representing a geometric shape
class Shape : public Printable {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
};

// Derived class for a rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Calculate the area of the rectangle
    double area() const override {
        return length * width;
    }

    // Calculate the perimeter of the rectangle
    double perimeter() const override {
        return 2 * (length + width);
    }

    // Display information about the rectangle
    void display() const override {
        std::cout << "Rectangle: Length = " << length << ", Width = " << width << std::endl;
    }

    // Print details about the rectangle
    void print() const override {
        display();
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
    }
};

// Derived class for a circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Calculate the area of the circle
    double area() const override {
        return M_PI * radius * radius;
    }

    // Calculate the circumference of the circle
    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    // Display information about the circle
    void display() const override {
        std::cout << "Circle: Radius = " << radius << std::endl;
    }

    // Print details about the circle
    void print() const override {
        display();
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Circumference: " << perimeter() << std::endl;
    }
};

// Class representing a drawing with shapes
class Drawing : public Printable {
private:
    Shape* shapes[10];
    int count;

public:
    Drawing() : count(0) {}

    // Add a shape to the drawing
    void addShape(Shape* shape) {
        if (count < 10) {
            shapes[count++] = shape;
        } else {
            std::cout << "Drawing is full, cannot add more shapes." << std::endl;
        }
    }

    // Print details of all shapes in the drawing
    void print() const override {
        for (int i = 0; i < count; ++i) {
            shapes[i]->print();
            std::cout << std::endl;
        }
    }
};

int main() {
    Drawing drawing;

    char choice;
    do {
        std::cout << "Select a shape to add (R for Rectangle, C for Circle, Q to quit): ";
        std::cin >> choice;

        if (choice == 'R' || choice == 'r') {
            double length, width;
            std::cout << "Enter length and width of the rectangle: ";
            std::cin >> length >> width;
            Rectangle rect(length, width);
            drawing.addShape(&rect);
        } else if (choice == 'C' || choice == 'c') {
            double radius;
            std::cout << "Enter the radius of the circle: ";
            std::cin >> radius;
            Circle circle(radius);
            drawing.addShape(&circle);
        }
    } while (choice != 'Q' && choice != 'q');

    drawing.print();

    return 0;
}
