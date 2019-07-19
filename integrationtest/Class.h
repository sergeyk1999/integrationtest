#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class con
{
public:
	void (*SetParametr_)(double parametr);
	double (*GetParametr_)();
	double (*f_)();
	con() = default;
};
class Class
{
private:
	double time_;
	double x_;
	double y_;
public:
	Class() = default;
	~Class() = default;
	void SetTime(double time);
	void Move(vector <con*> list);
	void SetX(double x);
	void SetY(double y);
	double GetTime();
	double GetX();
	double GetY();
	double fx();
	double fy();
};
class Integrator
{
private:
	double delta_;
public:
	Integrator() = default;
	~Integrator() = default;
	void SetDelta(double delta);
	double GetDelta();
	void integration(vector <con*> list, double time);
	double stepmaker(double f());
};