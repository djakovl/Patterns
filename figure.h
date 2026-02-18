#pragma once
#include <cmath>
#define PI 3.1415926

using namespace std;


class Figure
{
public:
	virtual ~Figure() = default;
	virtual double area() const = 0;
	virtual double square() const = 0;

};

class SquareFig : public Figure
{
	double a;
public:
	explicit SquareFig(double side) : a(side) {}
	double area() const override {
		return a * 4;
	}
	double square() const override {
		return a * a;
	}
};


class RoundFig : public Figure
{
	double r;
public:
	explicit RoundFig(double radius) : r(radius) {}
	double area() const override {
		return 2* r* PI;
	}
	double square() const override {
		return r * PI * r;
	}
};


class TriangleFig : public Figure
{
	double a, b, c;
public:
	explicit TriangleFig(double side_a, double side_b, double side_c) : a(side_a), b(side_b), c(side_c) {}
	double area() const override {
		return a + b + c;
	}
	double square() const override {
		double p = area() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};
