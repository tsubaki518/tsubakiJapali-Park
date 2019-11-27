#pragma once
#include <time.h>


class Animation {
protected:
	int count = 0;
public:
	bool Draw(){}
};

class StartAnimation:public Animation {
private:
	 clock_t start, end;
public:
	void Init();
	bool Draw();
};

class GoalAnimation :public Animation {
public:
	void Draw();
};