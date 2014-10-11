#ifndef __LIGHTNING__
# define __LIGHTNING__
# include <iostream>
# include <string>
# include <vector>
# include <map>

using namespace std;

typedef void (*callback)();

class Command
{
public:
	enum Type {GENERATE_COMMAND, HELP, ERROR};
	Command(char **line);
	~Command();
	void Parse();
private:
	char						**line_array;
	map<Type, vector<string> >	commands;
	map<Type, callback>			commands_callback;
	Type 						checkType(string arg);	
};

class Utils
{
public:
	Utils();
	~Utils();
	static vector<string>	CreateStringVector(char **array, int start, int size);
};

#endif /* __LIGHTNING__ */
