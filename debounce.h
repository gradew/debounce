#ifndef include_debounce
#define include_debounce
class Debounce
{
private:
	int buttonPin;
	int buttonState;
	int lastButtonState;
	unsigned long lastDebounceTime;
	unsigned long debounceDelay,
public:
	Debounce(int _buttonPin);
	void setButtonPin(int _buttonpin);
	int getButton();
};
#endif
