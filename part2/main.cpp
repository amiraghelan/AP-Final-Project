#include <iostream>
#include <vector>


class Shape {
public:
    double density;

    Shape(double d) : density(d) {}

    virtual ~Shape() {}

    virtual double getVolume() const = 0;
    virtual double getSurfaceArea() const = 0;

    double getMass() const {
        return getVolume() * density;
    }
};


class Sphere : public Shape {
public:
    double radius;

    Sphere(double d, double r) : Shape(d), radius(r) {}

    double getVolume() const override {
        return (4 / 3) * 3.1415 * radius * radius * radius;
    }

    double getSurfaceArea() const override{
        return 4*3.1415*radius;
    }
};

class Cube : public Shape {
public:
    double A,B,C;

    Cube(double a,double b, double c, double _density) : Shape(_density), A(a),B(b),C(c) {}

    double getVolume() const override {
        return A*B*C;
    }

    double getSurfaceArea() const override{
        return 2*(A*B+A*C+C*B);
    }
};


class Device {
public:
    std::vector<Shape*> shapes;
    std::vector<Device*> devices;

    ~Device() {
        for (auto shape : shapes) {
            delete shape;
        }
        for (auto device : devices) {
            delete device;
        }
    }

    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void addDevice(Device* device) {
        devices.push_back(device);
    }

    double getTotalVolume() const {
        double totalVolume = 0.0;
        for (const auto& shape : shapes) {
            totalVolume += shape->getVolume();
        }
        for (const auto& device : devices) {
            totalVolume += device->getTotalVolume();
        }
        return totalVolume;
    }

    double getTotalSurfaceArea() const {
        double totalSurfaceArea = 0.0;
        for (const auto& shape : shapes) {
            totalSurfaceArea += shape->getSurfaceArea();
        }
        for (const auto& device : devices) {
            totalSurfaceArea += device->getTotalSurfaceArea();
        }
        return totalSurfaceArea;
    }

    double getTotalMass() const {
        double totalMass = 0.0;
        for (const auto& shape : shapes) {
            totalMass += shape->getMass();
        }
        for (const auto& device : devices) {
            totalMass += device->getTotalMass();
        }
        return totalMass;
    }
};




using namespace std;


int main() {

    Device* mainDevice = new Device();

    mainDevice->addShape(new Sphere(1.0, 3.0));
    mainDevice->addShape(new Cube(2.0,2,4, 2.0));

    Device* subDevice = new Device();
    subDevice->addShape(new Sphere(0.5, 1.0));
    subDevice->addShape(new Cube(1.5,3,4, 1.0));

    mainDevice->addDevice(subDevice);

    std::cout << "Total Volume: " << mainDevice->getTotalVolume() << std::endl;
    std::cout << "Total Mass: " << mainDevice->getTotalMass() << std::endl;
    std::cout << "Total Mass: " << mainDevice->getTotalSurfaceArea() << std::endl;



    return 0;
}
