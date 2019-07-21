#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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
	void Move(Class* object);
	void SetX(double x);
	void SetY(double y);
	double GetTime();
	double GetX();
	double GetY();
	double fx(double ind,double dep);
	double fy(double ind,double dep);
};
typedef void(Class::* setter)(double parametr);
typedef double (Class::* getter)();
typedef double (Class::* f)(double ind,double dep);
class con
{
public:
	setter SetParametr_=0;
	getter GetParametr_=0;
	f f_=0;
	con() = default;
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
	void integration(vector <con*> list, double time,Class* object);
	double stepmaker(Class* object,con* i,double ind,double dep);
};