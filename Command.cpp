#include "lightning.h"

Command::Command(string line)
{
	Command::Line = line;
	cout << "Received command " << Command::Line << endl;
}
