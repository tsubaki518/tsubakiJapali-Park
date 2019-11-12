#include"character.h"

void Character::Draw() {

}


//if‚Åweight‚É’l‚Ì”ÍˆÍ‚ðŽw’è‚µ‚Äreturn‚³‚¹‚éƒLƒƒƒ‰‚ðŒˆ‚ß‚é
Character SetCharacter(float weight) {
	Character character;
	Elephant elephant;			//80kgˆÈã
	Bear bear;					//70`79kg
	Dog dog;					//60`69kg
	Rabbit rabbit;				//50`59kg
	Hamster hamster;			//49kgˆÈ‰º
	

	//--------------------------------
	//    ‚±‚±‚ÅƒLƒƒƒ‰‚ðŒˆ’è‚·‚é
	//-------------------------------

	if (weight >= 80)
	{
		return elephant;
	}
	else if (weight >= 70 && weight <= 79)
	{
		return bear;
	}
	else if (weight >= 60 && weight <= 69)
	{
		return dog;
	}
	else if (weight >= 50 && weight <= 59)
	{
		return rabbit;
	}
	else if (weight <= 49)
	{
		return hamster;
	}

	//---------------------------------


	//ðŒ‚É“–‚Ä‚Í‚Ü‚ç‚È‚¢ê‡character‚ðreturn‚³‚¹‚é
	return character;
}