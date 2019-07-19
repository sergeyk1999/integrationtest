#include "Class.h"
#include <vector>
#include "integrator.h"
using namespace std;
double Class::GetTime()
{
	return time_;
}
double Class::GetX()
{
	return x_;
}
double Class::GetY()
{
	return y_;
}
void Class::SetTime(double time)
{
	time_ = time;
}
void Class::SetX(double x)
{
	x_ = x;
}
void Class::SetY(double y)
{
	y_ = y;
}
void Class::Move(vector <con*> list)
{
	Integrator* a = new Integrator();
	a->SetDelta(0.01);
	a->integration(list, time_);
	time_ += 1;

}
double Class::fx()
{
	return 5 * time_;
}
double Class::fy()
{
	return 3 * time_;
}
double Integrator::GetDelta()
{
	return delta_;
}
void Integrator::SetDelta(double delta)
{
	delta_ = delta;
}
void Integrator::integration(vector<con*> list, double time)
{
	double t = 0;
	for (t = 0; t < time; t += delta_)
	{
		for (auto i : list)
		{
			i->SetParametr_(i->GetParametr_() + (i->f_()) * delta_);
		}
	}
}
double Integrator::stepmaker(double f())
{
	return f() * delta_;
}