#include "lightning.h"

Command::Command(char **line)
{
	Command::line_array = line;
	vector<string> generate_vector(3);
	generate_vector.push_back("gen");
	generate_vector.push_back("generate");
	generate_vector.push_back("g");
	commands[GENERATE_COMMAND] = generate_vector;

	vector<string> help_vector(3);
	help_vector.push_back("help");
	help_vector.push_back("h");
	commands[HELP] = help_vector;
}

void Command::Parse()
{
	Command::Type command_type = Command::checkType(Command::line_array[1]);
	if (command_type == ERROR)
		cout << "No command '"<< Command::line_array[1] <<"' found" << endl;
	else
	{
		int size = 0;
		for (int i = 2; Command::line_array[i] != NULL; i++)
			size++;
		if (size >= 1)
		{
			vector<string> test = Utils::CreateStringVector(Command::line_array, 2, size);
		}
	}
}

Command::Type Command::checkType(string arg)
{
	for (int i = 0; i != ERROR; i++)
	{
		vector<string> current = commands[static_cast<Command::Type>(i)];
		for (vector<string>::iterator it = current.begin(); it != current.end(); ++it)
		{
			if (*it == arg)
			{
				vector<string>().swap(current);		
				return (static_cast<Command::Type>(i));
			}
		}
		vector<string>().swap(current);
	}
	return (ERROR);
}
