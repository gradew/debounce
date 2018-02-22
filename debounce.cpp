#include <debounce.h>

Debounce::Debounce(int _buttonPin=-1)
{
	this->lastButtonState=LOW;
	this->lastDebounceTime=0;
	this->debounceDelay=50;
	if(_buttonPin>=0){
		this->setButtonPin(_buttonPin);
	}
}

void Debounce::setButtonPin(int _buttonPin)
{
	this->buttonPin=_buttonPin;
	pinMode(this->buttonPin, INPUT);
}

int Debounce::getButton()
{
	unsigned long rightNow=millis();
	int reading=digitalRead(this->buttonPin);
	if(reading!=this->lastButtonState){
		this->lastDebounceTime=rightNow;
	}
	if(rightNow-this->lastDebounceTime)>this->debounceDelay){
		if(reading!=this->buttonState){
			this->buttonState=reading;
		}
		//if(this->buttonState==HIGH){
			// toggle here if needed
		//}
	}
	this->lastButtonState=reading;
	return reading;
}
