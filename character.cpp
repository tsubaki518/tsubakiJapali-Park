#include"character.h"

void Character::Draw() {

}


//if‚Åweight‚É’l‚Ì”ÍˆÍ‚ğw’è‚µ‚Äreturn‚³‚¹‚éƒLƒƒƒ‰‚ğŒˆ‚ß‚é
Character SetCharacter(float weight) {
	Character character;
	Elephant elephant;			//90kgˆÈã
	Bear bear;					//70`89kg
	Dog dog;					//60`69kg
	Rabbit rabbit;				//50`59kg
	Mouse mouse;				//49kgˆÈ‰º
	

	//--------------------------------
	//    ‚±‚±‚ÅƒLƒƒƒ‰‚ğŒˆ’è‚·‚é
	//-------------------------------

	if (weight <= 90)
	{
		return elephant;
	}
	else if (weight >= 89)
	{
		return bear;
	}
	else if (weight >= 69)
	{
		return dog;
	}
	else if (weight >= 59)
	{
		return rabbit;
	}
	else if (weight >= 49)
	{
		return mouse;
	}

	//---------------------------------


	//ğŒ‚É“–‚Ä‚Í‚Ü‚ç‚È‚¢ê‡character‚ğreturn‚³‚¹‚é
	return character;
}