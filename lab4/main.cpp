#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

class Sphere {
protected:
    double radius;
public:
    Sphere(double r) : radius(r) {}

    double getVolume() const {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }

    double getSurfaceArea() const {
        return 4 * M_PI * pow(radius, 2);
    }

    virtual void displayInfo(ostream& os) const {
        os << "Sphere:\n";
        os << "  Radius: " << radius << endl;
        os << "  Volume: " << fixed << setprecision(2) << getVolume() << endl;
        os << "  Surface Area: " << fixed << setprecision(2) << getSurfaceArea() << endl;
    }
};

class Cube {
protected:
    double side;
public:
    Cube(double s) : side(s) {}

    double getVolume() const {
        return pow(side, 3);
    }

    double getSurfaceArea() const {
        return 6 * pow(side, 2);
    }

    virtual void displayInfo(ostream& os) const {
        os << "Cube:\n";
        os << "  Side Length: " << side << endl;
        os << "  Volume: " << fixed << setprecision(2) << getVolume() << endl;
        os << "  Surface Area: " << fixed << setprecision(2) << getSurfaceArea() << endl;
    }
};

class InscribedSphere : public Sphere, private Cube {
public:
    InscribedSphere(double sideLength)
        : Cube(sideLength), Sphere(sideLength / 2.0) {} 

    void displayInfo(ostream& os) const override {
        os << "Inscribed Sphere and Cube:\n";
        Cube::displayInfo(os);
        Sphere::displayInfo(os);
    }
};

int main() {

    double sideLength = 4.0;

    InscribedSphere shape(sideLength);

    ofstream outFile("shapes_info.txt");
    if (outFile.is_open()) {
        shape.displayInfo(outFile);
        cout << "Information about the shapes has been written to 'shapes_info.txt'.\n";
        outFile.close();
    }
    else {
        cerr << "Error: Could not open the file for writing.\n";
    }

    return 0;
}
