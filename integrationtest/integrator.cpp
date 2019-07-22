#include "integrator.h"
double Integrator::GetDelta()
{
	return delta_;
}
void Integrator::SetDelta(double delta)
{
	delta_ = delta;
}
void Integrator::integration(vector<con*> list,double t_min, double t_max, Class* object)
{

	for (double t=t_min; t < t_max; t += delta_)
	{
		for (auto i : list)
		{
			(object->*(i->SetParametr_))((object->*(i->GetParametr_))() + stepmaker(object, i, t, (object->*(i->GetParametr_))()));
		}
	}
}
double Integrator::stepmaker(Class* object, con* i, double ind, double dep)
{
	double k1 = delta_ * ((object->*(i->f_))(ind, dep));
	double k2 = delta_ * ((object->*(i->f_))(ind + delta_ / 2, dep + k1 / 2));
	double k3 = delta_ * ((object->*(i->f_))(ind + delta_ / 2, dep + k2 / 2));
	double k4 = delta_ * ((object->*(i->f_))(ind + delta_, dep + k3));
	//cout << k1 << " " << k2 << " " << k3 << " " << k4 << endl;
	double res = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	//printf("delta=%lf\n", res);
	return res;
}