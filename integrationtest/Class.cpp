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
void Class::Move(Class* object)
{
	con* x = new con();
	x->f_ = &Class::fx;//from here
	x->GetParametr_ = &Class::GetX;
	x->SetParametr_ = &Class::SetX;
	con* y = new con();
	y->f_ = &Class::fy;//from here
	y->GetParametr_ = &Class::GetY;
	y->SetParametr_ = &Class::SetY;
	//to here
	//printf("%lf\n", (object->*(x->GetParametr_))());
	//(object->*(x->SetParametr_))(1.);
	//printf("%lf\n", (object->*(x->GetParametr_))());
	vector <con*> list;
	list.push_back(x);
	//list.push_back(y);
	Integrator* a = new Integrator();
	a->SetDelta(0.1);
	a->integration(list, 0.5,object);
	time_ += a->GetDelta();
	//cout << "x1=" << object->GetX() << "x2=" << GetX() << "x3=" << (object->*(x->GetParametr_))() << endl;
	a->~Integrator();
}
double Class::fx(double ind,double dep)
{
	return ind + dep;
}
double Class::fy(double ind,double dep)
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
void Integrator::integration(vector<con*> list, double time,Class* object)
{
	double t = 0;

	for (t = 0; t < time; t += delta_)
	{
		for (auto i : list)
		{
			cout << (object->*(i->GetParametr_))() << endl;
			(object->*(i->SetParametr_))((object->*(i->GetParametr_))() + stepmaker(object, i,t, (object->*(i->GetParametr_))()));
		}
	}
}
double Integrator::stepmaker(Class* object,con* i,double ind,double dep)
{
	double k1 = delta_ * ((object->*(i->f_))(ind, dep));
	double k2 = delta_ * ((object->*(i->f_))(ind + delta_ / 2, dep + k1 / 2));
	double k3 = delta_ * ((object->*(i->f_))(ind + delta_ / 2, dep + k2 / 2));
	double k4 = delta_ * ((object->*(i->f_))(ind + delta_, dep + k3));
	//cout << k1 << " " << k2 << " " << k3 << " " << k4 << endl;
	double res = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	printf("delta=%lf\n", res);
	return res;
}