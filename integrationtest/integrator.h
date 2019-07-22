#pragma once

#include <vector>
#include <iostream>
#include <utility>
#include "Class.h"

using namespace std;
class Integrator
{
private:
	double delta_;
public:
	Integrator() = default;
	~Integrator() = default;
	void SetDelta(double delta);
	double GetDelta();
	void integration(vector <con*> list, double t_min, double t_max, Class* object);
	double stepmaker(Class* object, con* i, double ind, double dep);
};


