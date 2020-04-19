#include "p2Log.h"
#include "j1App.h"
#include "j1EasingAndSplines.h"
#include "..//Brofiler/Brofiler.h"

j1EasingAndSplines::j1EasingAndSplines() : j1Module()
{
	name.create("easing_splines");
}

// Destructor
j1EasingAndSplines::~j1EasingAndSplines()
{

}

SplineInfo::SplineInfo(int* position, const int &final_position, const float &duration, const Spline_Type &t) {

	// TODO 1: Create the constructor

}

bool SplineInfo::Update(float dt)
{

	BROFILER_CATEGORY("UPDATE SPLINE INFO", Profiler::Color::Bisque);

	bool ret = true;

	//Todo 2: Calculate time since spline start and save the value in FLOAT


	//Todo 3: Comprobate if the spline has finished using time_passed, to Update end we need to return false, look line 50 to know how it works
	
		//Todo 4: Make a switch for every case of spline and call its function, save the position (select three of one group to do the proof)


	return ret;
}

bool j1EasingAndSplines::Update(float dt)
{
	
	BROFILER_CATEGORY("Update splines", Profiler::Color::DarkKhaki);

	for (int i=0; i < easing_splines.size(); i++) {
		
		if (easing_splines[i] != nullptr) {
			
			if (!easing_splines[i]->Update(dt)) {
				
				delete(easing_splines[i]);
				easing_splines[i] = nullptr;

			}
		}
	}

	return true;

}

void j1EasingAndSplines::CreateSpline(int* i_pos, const int &f_pos, const float &duration, const Spline_Type &t)
{

	BROFILER_CATEGORY("SPLINE CREATE", Profiler::Color::Azure);

	SplineInfo* spline = new SplineInfo(i_pos, f_pos, duration, t);

	if (spline != nullptr) {

		easing_splines.push_back(spline);

	}

	else {

		LOG("Couldn't create the Spline...");

	}
		
}

int EaseFunctions::Ease(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	if (time_passed <= 0) return i_pos;
	if (time_passed >= duration) return i_pos + f_pos;
	else return f_pos * (time_passed / duration) + i_pos;
}

int EaseFunctions::EaseInQuad(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * (time_passed /= duration)*time_passed + i_pos;
}
int EaseFunctions::EaseOutQuad(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return -f_pos * (time_passed /= duration)*(time_passed-2) + i_pos;
}
int EaseFunctions::EaseInOutQuad(float &time_passed, int &i_pos, int &f_pos, float &duration) {

	if ((time_passed /= duration / 2) < 1) return f_pos / 2 * time_passed*time_passed + i_pos;
	return -f_pos / 2 * ((--time_passed)*(time_passed - 2) - 1) + i_pos;
}

int EaseFunctions::EaseInCubic(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * pow((time_passed / duration), 3) + i_pos;
}
int EaseFunctions::EaseOutCubic(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * (pow((time_passed / duration - 1), 3) + 1) + i_pos;
}
int EaseFunctions::EaseInOutCubic(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	if ((time_passed /= duration / 2) < 1)return f_pos / 2 * pow(time_passed, 3) + i_pos;
	return f_pos / 2 * (pow(time_passed - 2, 3) + 2) + i_pos;
}

int EaseFunctions::EaseInQuart(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * pow(time_passed / duration, 4) + i_pos;
}
int EaseFunctions::EaseOutQuart(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return -f_pos * (pow(time_passed / duration - 1, 4) - 1) + i_pos;
}
int EaseFunctions::EaseInOutQuart(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	if ((time_passed /= duration / 2) < 1)return f_pos / 2 * pow(time_passed, 4) + i_pos;
	return -f_pos / 2 * (pow(time_passed - 2, 4) - 2) + i_pos;
}

int EaseFunctions::EaseInQuint(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * pow(time_passed / duration, 5) + i_pos;
}
int EaseFunctions::EaseOutQuint(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * (pow(time_passed / duration - 1, 5) + 1) + i_pos;
}
int EaseFunctions::EaseInOutQuint(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	if ((time_passed /= duration / 2) < 1) return f_pos / 2 * pow(time_passed, 5) + i_pos;
	return f_pos / 2 * (pow(time_passed - 2, 5) + 2) + i_pos;
}

int EaseFunctions::EaseInSine(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * (1 - cos(time_passed / duration * (PI / 2))) + i_pos;
}
int EaseFunctions::EaseOutSine(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * sin(time_passed / duration * (PI / 2)) + i_pos;
}
int EaseFunctions::EaseInOutSine(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos / 2 * (1 - cos(PI*time_passed / duration)) + i_pos;
}

int EaseFunctions::EaseInExpo(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * pow(2, 10 * (time_passed / duration - 1)) + i_pos;
}
int EaseFunctions::EaseOutExpo(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * (-pow(2, -10 * time_passed / duration) + 1) + i_pos;
}
int EaseFunctions::EaseInOutExpo(float &time_passed, int &i_pos, int &f_pos, float &duration)
{

	if ((time_passed /= duration / 2) < 1)	return f_pos / 2 * pow(2, 10 * (time_passed - 1)) + i_pos;
	return f_pos / 2 * (-pow(2, -10 * --time_passed) + 2) + i_pos;

}

int EaseFunctions::EaseInCirc(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return f_pos * (1 - sqrt(1 - (time_passed /= duration)*time_passed)) + i_pos;
}
int EaseFunctions::EaseOutCirc(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	return  f_pos * sqrt(1 - (time_passed = time_passed / duration - 1)*time_passed) + i_pos;
}
int EaseFunctions::EaseInOutCirc(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	if ((time_passed /= duration / 2) < 1) return f_pos / 2 * (1 - sqrt(1 - time_passed * time_passed)) + i_pos;
	return f_pos / 2 * (sqrt(1 - (time_passed -= 2)*time_passed) + 1) + i_pos;
}

int EaseFunctions::EaseOutBounce(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	if ((time_passed /= duration) < (1 / 2.75)) {
		return f_pos * (7.5625*time_passed*time_passed) + i_pos;
	}
	else if (time_passed < (2 / 2.75)) {
		return f_pos * (7.5625*(time_passed -= (1.5 / 2.75))*time_passed + .75) + i_pos;
	}
	else if (time_passed < (2.5 / 2.75)) {
		return f_pos * (7.5625*(time_passed -= (2.25 / 2.75))*time_passed + .9375) + i_pos;
	}
	else {
		return f_pos * (7.5625*(time_passed -= (2.625 / 2.75))*time_passed + .984375) + i_pos;
	}

}

int EaseFunctions::EaseInBack(float &time_passed, int &i_pos, int &f_pos, float &duration)
{
	float s = 1.70158;
	return f_pos * (time_passed /= duration)*time_passed*((s + 1)*time_passed - s) + i_pos;

}
int EaseFunctions::EaseOutBack(float &time_passed, int &i_pos, int &f_pos, float &duration)
{

	float s = 1.70158;
	return f_pos * ((time_passed = time_passed / duration - 1)*time_passed*((s + 1)*time_passed + s) + 1) + i_pos;

}
int EaseFunctions::EaseInOutBack(float &time_passed, int &i_pos, int &f_pos, float &duration)
{

	float s = 1.70158;
	if ((time_passed /= duration / 2) < 1) return f_pos / 2 * (time_passed*time_passed*(((s *= (1.525)) + 1)*time_passed - s)) + i_pos;
	return f_pos / 2 * ((time_passed -= 2)*time_passed*(((s *= (1.525)) + 1)*time_passed + s) + 2) + i_pos;

}

int EaseFunctions::EaseOutElastic(float &time_passed, int &i_pos, int &f_pos, float &duration)
{

	if ((time_passed /= duration) == 1) {
		return i_pos + f_pos;
	}
	else {
		return (f_pos*pow(2, -10 * time_passed) * sin((time_passed*duration - ((duration * 0.3) / 4))*(2 * 3.14) / (duration * 0.3)) + f_pos + i_pos);
	}

}

bool j1EasingAndSplines::CleanUp()
{
	LOG("Freeing scene");

	for (int i = 0; i < easing_splines.size(); i++) {

		if (easing_splines[i] != nullptr) {

			delete(easing_splines[i]);
			easing_splines[i] = nullptr;


		}
	}

	return true;

}

