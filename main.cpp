#include "lightning.h"

int		main(int argc, char **argv)
{
	if (argc > 1 && argv[1])
	{
		Command *command = new Command(argv);
		command->Parse();
	}
	else
		cout << "Please provide a correct argument" << endl;
}
