#include <fl/Headers.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
using namespace fl;
using namespace std;			// cout, endl
using namespace this_thread;	// sleep_for
using namespace chrono;			// seconds, milliseconds
using namespace std::chrono_literals;

enum class ProgramStates { OFF, LOW_ORANGE, LOW_WHITE, LOW_BLUE, MID_ORANGE, MID_WHITE, MID_BLUE, HIGH_ORANGE, HIGH_WHITE, HIGH_BLUE };

ProgramStates program_state = ProgramStates::OFF;

std::string TEMP_MODE = "NONE";

bool TEMP_MODE_ORANGE = false;
bool TEMP_MODE_WHITE = false;
bool TEMP_MODE_BLUE = false;

bool BRIGHT_MODE_LOW = false;
bool BRIGHT_MODE_MID = false;
bool BRIGHT_MODE_HIGH = false;

std::string BRIGHT_MODE = "NONE";


void Controls()
{
	std::cout << "Controls:" << endl;
	std::cout << "Enter a value for the temperature and brightness of the bulb (from 0 - 100)" << endl;
	std::cout << "Type 'enter' to continue" << endl;
	std::cout << "--------------------------------------------------------------------------" << endl;
	int cont;
	cin >> cont;

}

void ChangeState()
{
	if (BRIGHT_MODE_LOW == true and TEMP_MODE_ORANGE == true)
	{
		program_state = ProgramStates::LOW_ORANGE;
	}
	else if (BRIGHT_MODE_LOW == true and TEMP_MODE_WHITE == true)
	{
		program_state = ProgramStates::LOW_WHITE;
	}
	else if (BRIGHT_MODE_LOW == true and TEMP_MODE_BLUE == true)
	{
		program_state = ProgramStates::LOW_BLUE;
	}
	else if (BRIGHT_MODE_MID == true and TEMP_MODE_ORANGE == true)
	{
		program_state = ProgramStates::MID_ORANGE;
	}
	else if (BRIGHT_MODE_MID == true and TEMP_MODE_WHITE == true)
	{
		program_state = ProgramStates::MID_WHITE;
	}
	else if (BRIGHT_MODE_MID == true and TEMP_MODE_BLUE == true)
	{
		program_state = ProgramStates::MID_BLUE;
	}
	else if (BRIGHT_MODE_HIGH == true and TEMP_MODE_ORANGE == true)
	{
		program_state = ProgramStates::HIGH_ORANGE;
	}
	else if (BRIGHT_MODE_HIGH == true and TEMP_MODE_WHITE == true)
	{
		program_state = ProgramStates::HIGH_WHITE;
	}
	else if (BRIGHT_MODE_HIGH == true and TEMP_MODE_BLUE == true)
	{
		program_state = ProgramStates::HIGH_BLUE;
	}
	else
	{
		program_state = ProgramStates::OFF;
	}
}

void SetBright(int b)
{
	if (b <= 33)
	{
		BRIGHT_MODE = "LOW";
		BRIGHT_MODE_LOW = true;
	}
	else if (b > 33 and b < 66)
	{
		BRIGHT_MODE = "MID";
		BRIGHT_MODE_MID = true;
	}
	else if (b >= 66)
	{
		BRIGHT_MODE = "HIGH";
		BRIGHT_MODE_HIGH = true;
	}
	else
	{
		BRIGHT_MODE = "NONE";
		BRIGHT_MODE_LOW = false;
		BRIGHT_MODE_MID = false;
		BRIGHT_MODE_HIGH = false;
	}
}

void SetTemp(int t)
{
	if (t <= 33)
	{
		TEMP_MODE = "ORANGE";
		TEMP_MODE_ORANGE = true;

	}
	else if (t > 33 and t < 66)
	{
		TEMP_MODE = "WHITE";
		TEMP_MODE_WHITE = true;
	}
	else if (t >= 66)
	{
		TEMP_MODE = "BLUE";
		TEMP_MODE_BLUE = true;
	}
	else
	{
		TEMP_MODE = "NONE";
		TEMP_MODE_ORANGE = false;
		TEMP_MODE_WHITE = false;
		TEMP_MODE_BLUE = false;
	}
}

void Version1FSM()
{
	cout << "Version 1 Launched" << endl;
	std::cout << endl;

	Controls();

	int temp;
	int bright;
	bool program_running = true;

	

	
	//TODO:: DESC LIGHTS AND WHAT THEY LOOK LIKE
	// >>> FUZZY LIGHT SYS

	do {

		if (program_state == ProgramStates::OFF)
		{
			system("CLS");
			std::cout << "<* light is off*>" << endl;
				sleep_for(milliseconds(500));
			std::cout << "<* temperature is 0% *>" << endl;
				sleep_for(milliseconds(500));
			std::cout << "<* brightness is 0% *>" << endl;
				sleep_for(milliseconds(500));
			std::cout << "set temperature : ";
			cin >> temp;
			std::cout << endl;
			std::cout << "set brightness : ";
			cin >> bright;
			std::cout << endl;
			sleep_for(milliseconds(1000));

			std::cout << "proccessing data ..." << endl;
			sleep_for(milliseconds(1000));
			std::cout << "sending data to light ..." << endl;
			sleep_for(milliseconds(1000));
			std::cout << endl;

			SetTemp(temp);
			SetBright(bright);

			std::cout << "new temperature is " << TEMP_MODE << endl;
			sleep_for(milliseconds(500));
			std::cout << "new brightness is " << BRIGHT_MODE << endl;
			sleep_for(milliseconds(500));
			std::cout << endl;

			std::cout << "sending data to light ..." << endl;
			sleep_for(milliseconds(1000));


			ChangeState();

		}
		else if (program_state == ProgramStates::LOW_ORANGE)
		{
			system("CLS");
			std::cout << "<* light glows a dim orange , like an old streetlight*>" << endl;
			sleep_for(milliseconds(500));
			std::cout << "<* temperature is "<< temp <<"% *>" << endl;
			sleep_for(milliseconds(500));
			std::cout << "<* brightness is " << bright << "% *>" << endl;
			sleep_for(milliseconds(500));
			std::cout << "set temperature : ";
			std::cin >> temp;
			std::cout << endl;
			std::cout << "set brightness : ";
			std::cin >> bright;
			std::cout << endl;
			sleep_for(seconds(1));

			std::cout << "proccessing data ..." << endl;
			sleep_for(milliseconds(1000));
			std::cout << "sending data to light ..." << endl;
			sleep_for(milliseconds(1000));
			std::cout << endl;

			SetTemp(temp);
			SetBright(bright);

			std::cout << "new temperature is " << TEMP_MODE << endl;
			sleep_for(milliseconds(500));
			std::cout << "new brightness is " << BRIGHT_MODE << endl;
			sleep_for(milliseconds(500));
			std::cout << endl;

			std::cout << "sending data to light ..." << endl;
			sleep_for(milliseconds(1000));


			ChangeState();
		}
		else if (program_state == ProgramStates::LOW_WHITE)
		{
			system("CLS");
			std::cout << "<* light is coloured low and white like dim sunlight*>" << endl;
			sleep_for(milliseconds(500));
			std::cout << "<* temperature is " << temp << "% *>" << endl;
			sleep_for(milliseconds(500));
			std::cout << "<* brightness is " << bright << "% *>" << endl;
			sleep_for(milliseconds(500));
			std::cout << "set temperature : ";
			std::cin >> temp;
			std::cout << endl;
			std::cout << "set brightness : ";
			std::cin >> bright;
			std::cout << endl;
			sleep_for(milliseconds(500));

			std::cout << "proccessing data ..." << endl;
			sleep_for(milliseconds(1000));
			std::cout << "sending data to light ..." << endl;
			sleep_for(milliseconds(1000));
			std::cout << endl;

			SetTemp(temp);
			SetBright(bright);

			std::cout << "new temperature is " << TEMP_MODE << endl;
			sleep_for(milliseconds(500));
			std::cout << "new brightness is " << BRIGHT_MODE << endl;
			sleep_for(milliseconds(500));
			std::cout << endl;

			std::cout << "sending data to light ..." << endl;
			sleep_for(milliseconds(1000));


			ChangeState();
		}
		else if (program_state == ProgramStates::LOW_BLUE)
		{
		system("CLS");
		std::cout << "<* light has a dim bluish hue*>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* temperature is " << temp << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* brightness is " << bright << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "set temperature : ";
		std::cin >> temp;
		std::cout << endl;
		std::cout << "set brightness : ";
		std::cin >> bright;
		std::cout << endl;
		sleep_for(milliseconds(500));

		std::cout << "proccessing data ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << endl;

		SetTemp(temp);
		SetBright(bright);

		std::cout << "new temperature is " << TEMP_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << "new brightness is " << BRIGHT_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << endl;

		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));


		ChangeState();
		}
		else if (program_state == ProgramStates::MID_ORANGE)
		{
		system("CLS");
		std::cout << "<* light has the glow of a typical house lamp*>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* temperature is " << temp << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* brightness is " << bright << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "set temperature : ";
		std::cin >> temp;
		std::cout << endl;
		std::cout << "set brightness : ";
		std::cin >> bright;
		std::cout << endl;
		sleep_for(milliseconds(500));

		std::cout << "proccessing data ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << endl;

		SetTemp(temp);
		SetBright(bright);

		std::cout << "new temperature is " << TEMP_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << "new brightness is " << BRIGHT_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << endl;

		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));


		ChangeState();
		}
		else if (program_state == ProgramStates::MID_WHITE)
		{
		system("CLS");
		std::cout << "<* light glows like a typical overhead light*>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* temperature is " << temp << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* brightness is " << bright << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "set temperature : ";
		std::cin >> temp;
		std::cout << endl;
		std::cout << "set brightness : ";
		std::cin >> bright;
		std::cout << endl;
		sleep_for(milliseconds(500));

		std::cout << "proccessing data ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << endl;

		SetTemp(temp);
		SetBright(bright);

		std::cout << "new temperature is " << TEMP_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << "new brightness is " << BRIGHT_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << endl;

		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));


		ChangeState();
		}
		else if (program_state == ProgramStates::MID_BLUE)
		{
		system("CLS");
		std::cout << "<* light has the subtle blue glow of a computer screen*>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* temperature is " << temp << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* brightness is " << bright << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "set temperature : ";
		std::cin >> temp;
		std::cout << endl;
		std::cout << "set brightness : ";
		std::cin >> bright;
		std::cout << endl;
		sleep_for(milliseconds(500));

		std::cout << "proccessing data ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << endl;

		SetTemp(temp);
		SetBright(bright);

		std::cout << "new temperature is " << TEMP_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << "new brightness is " << BRIGHT_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << endl;

		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));


		ChangeState();
		}
		else if (program_state == ProgramStates::HIGH_ORANGE)
		{
		system("CLS");
		std::cout << "<* light glows like the flame of a candle*>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* temperature is " << temp << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* brightness is " << bright << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "set temperature : ";
		std::cin >> temp;
		std::cout << endl;
		std::cout << "set brightness : ";
		std::cin >> bright;
		std::cout << endl;
		sleep_for(milliseconds(500));

		std::cout << "proccessing data ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << endl;

		SetTemp(temp);
		SetBright(bright);

		std::cout << "new temperature is " << TEMP_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << "new brightness is " << BRIGHT_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << endl;

		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));


		ChangeState();
		}
		else if (program_state == ProgramStates::HIGH_WHITE)
		{
		system("CLS");
		std::cout << "<* light is bright like the beams on a cars headlights *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* temperature is " << temp << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* brightness is " << bright << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "set temperature : ";
		std::cin >> temp;
		std::cout << endl;
		std::cout << "set brightness : ";
		std::cin >> bright;
		std::cout << endl;
		sleep_for(milliseconds(500));

		std::cout << "proccessing data ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << endl;

		SetTemp(temp);
		SetBright(bright);

		std::cout << "new temperature is " << TEMP_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << "new brightness is " << BRIGHT_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << endl;

		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));


		ChangeState();
		}
		else if (program_state == ProgramStates::HIGH_BLUE)
		{
		system("CLS");
		std::cout << "<* light is almost blinding and tinted blue, like a high resolution monitor*>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* temperature is " << temp << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "<* brightness is " << bright << "% *>" << endl;
		sleep_for(milliseconds(500));
		std::cout << "set temperature : ";
		std::cin >> temp;
		std::cout << endl;
		std::cout << "set brightness : ";
		std::cin >> bright;
		std::cout << endl;
		sleep_for(milliseconds(500));

		std::cout << "proccessing data ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));
		std::cout << endl;

		SetTemp(temp);
		SetBright(bright);

		std::cout << "new temperature is " << TEMP_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << "new brightness is " << BRIGHT_MODE << endl;
		sleep_for(milliseconds(500));
		std::cout << endl;

		std::cout << "sending data to light ..." << endl;
		sleep_for(milliseconds(1000));


		ChangeState();
		}

	} while (program_running);

	std::cout << "Ending Verson 1" << endl;
	return;
}

void Version2FzyLgc()
{
	cout << "Version 2 Launched" << endl;

	Engine* ghost = new Engine();
	std::string status;



	InputVariable* action = new InputVariable;
	ghost->addInputVariable(action);
	
	action->setName("action");
	action->setRange(0, 3);
	
	action->addTerm(new Ramp("low", 0, 1));
	action->addTerm(new Ramp("med", 1, 2));
	action->addTerm(new Ramp("high", 2, 3));

	OutputVariable* hunger = new OutputVariable;
	ghost->addOutputVariable(hunger);
	hunger->setName("hunger");
	hunger->setRange(0, 3);
	hunger->setAggregation(new Maximum);
	hunger->setDefuzzifier(new Centroid(100));
	hunger->setDefaultValue(fl::nan);
	hunger->addTerm(new Ramp("low", 0, 1));
	hunger->addTerm(new Ramp("med", 1, 2));
	hunger->addTerm(new Ramp("high", 2, 3));

	OutputVariable* happiness = new OutputVariable;
	ghost->addOutputVariable(happiness);
	happiness->setName("happiness");
	happiness->setRange(0, 3);
	happiness->setAggregation(new Maximum);
	happiness->setDefuzzifier(new Centroid(100));
	happiness->setDefaultValue(fl::nan);
	happiness->addTerm(new Ramp("low", 0, 1));
	happiness->addTerm(new Ramp("med", 1, 2));
	happiness->addTerm(new Ramp("high", 2, 3));

	OutputVariable* comfort = new OutputVariable;
	ghost->addOutputVariable(comfort);
	comfort->setName("comfort");
	comfort->setRange(0, 3);
	comfort->setAggregation(new Maximum);
	comfort->setDefuzzifier(new Centroid(100));
	comfort->setDefaultValue(fl::nan);
	comfort->addTerm(new Ramp("low", 0, 1));
	comfort->addTerm(new Ramp("med", 1, 2));
	comfort->addTerm(new Ramp("high", 2, 3));


	RuleBlock* needs = new RuleBlock;
	needs->setName("needs");
	needs->setConjunction(fl::null);
	needs->setDisjunction(fl::null);
	needs->setImplication(new AlgebraicProduct);
	needs->setActivation(new General);

	needs->addRule(Rule::parse("if action is high then hunger is low", ghost));
	needs->addRule(Rule::parse("if action is high then happiness is med", ghost));
	needs->addRule(Rule::parse("if action is high then comfort is high", ghost));

	needs->addRule(Rule::parse("if action is med then hunger is med", ghost));
	needs->addRule(Rule::parse("if action is med then happiness is high", ghost));
	needs->addRule(Rule::parse("if action is med then comfort is low", ghost));

	needs->addRule(Rule::parse("if action is low then hunger is high", ghost));
	needs->addRule(Rule::parse("if action is low then happiness is low", ghost));
	needs->addRule(Rule::parse("if action is low then comfort is med", ghost));

	ghost->addRuleBlock(needs);

	

	Controls();

	while (1)
	{
		std::string input = "";
		std::cin >> input;
		if (input == "E")
		{
			delete ghost;
			return;
		}
		else if (input == "C")
		{
			Controls();
		}
		std::stringstream ss(input);
		int number = 0;
		ss >> number;
		action->setValue(number);
		ghost->process();
		std::cout << number << " was entered..." << endl;

		sleep_for(seconds(1));

		if (input == "1") {
			cout << "<*you give the ghost a ghost-sandwich*>" << endl;
			cout << "<*ghost eats the ghost-sandwich*>" << endl;
			cout << "<*ghost is fed*>" << endl;
		}
		else if (input == "2") {
			cout << "<*you and the ghost play cards*>" << endl;
			cout << "<*you lose, ghost has a full house to your flush*>" << endl;
			cout << "<*ghost is happier*>" << endl;
		}
		else if (input == "3") {
			cout << "<*you give the ghost a hug*>" << endl;
			cout << "<*ghost hugs you back*>" << endl;
			cout << "<*ghost feels better*>" << endl;
		}

		std::cout << "adjusting values..." << endl;
		sleep_for(seconds(1));
		std::cout << "hunger: " << hunger->getValue() << endl;
		std::cout << "happiness: " << happiness->getValue() << endl;
		std::cout << "comfort: " << comfort->getValue() << endl;
	}

	
	if (not ghost->isReady(&status))
		std::cout << "Engine is not ready" << std::endl << status << std::endl;
	delete ghost;
	return;
}

int main()
{
	int version;
	cout << "Welcome to Virtual Lightbulb v1.1.0" << endl;
	cout << "Conmtroll a lightbulb from your keyboard" << endl;
	cout << "the ghost has 4 modes: off, low, medium & high" << endl;
	cout << "the light can be controlled via:" << endl;
	cout << "1: Finite State Machine | 2: Fuzzy Logic System" << endl;
	cout << "Please choose 1 or 2 " << endl;
	cin >> version;
	while (true)
	{
		switch (version)
		{
		case 1:
			cout << "Launching Version 1 ..." << endl;
			Version1FSM();
			return 0;

		case 2:
			cout << "Launching Version 2 ..." << endl;
			Version2FzyLgc();
			return 0;

		default:
			cout << "Incorrect input " << endl;
			cout << "Please choose 1 or 2" << endl;
			cin >> version;
		}
	}
}