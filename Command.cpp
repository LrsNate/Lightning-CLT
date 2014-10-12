#include "lightning.h"

Command::Command(char **line)
{
	Command::line_array = line;
	vector<string> generate_vector;
	generate_vector.push_back("gen");
	generate_vector.push_back("generate");
	generate_vector.push_back("g");
	commands[GENERATE_COMMAND] = generate_vector;
	commands_callback[GENERATE_COMMAND] = BundleGeneration::GenerateBundle;

	vector<string> help_vector;
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
		vector<string> args;
		int size = 0;
		for (int i = 2; Command::line_array[i] != NULL; i++)
			size++;
		if (size >= 1)
			args = Utils::CreateStringVector(Command::line_array, 2, size);
		(*commands_callback[command_type])(args);
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
