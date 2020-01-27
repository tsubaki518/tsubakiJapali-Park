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
	 bool isSoundOnece = false;
public:
	void Init();
	bool Draw();
};

class GoalAnimation :public Animation {
private :
	int endCount = 0;
public:
	void Init();
	bool Draw();
};

class TezukaLine :public Animation {
private:
	int interval;
	int drawCount = 0;
public:
	void Init(int n);
	void Draw();
};