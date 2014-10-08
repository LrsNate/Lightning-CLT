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
		cout << "No command found" << endl;
	else if (command_type == HELP)
		cout << "== Lightning Help ==" << endl;
	else if (command_type == GENERATE_COMMAND)
		cout << "Generating Bundle" << endl;
	// for (int i = 1; Command::line_array[i] != NULL; i++)
	// {
	// 	string current(Command::line_array[i]);

	// }
}

Command::Type Command::checkType(string arg)
{
	for (int i = 0; i != ERROR; i++)
	{
		vector<string> current = commands[static_cast<Command::Type>(i)];
		for (vector<string>::iterator it = current.begin(); it != current.end(); ++it)
		{
			if (*it == arg)
				return (static_cast<Command::Type>(i));
		}
	}
	return (ERROR);
}
