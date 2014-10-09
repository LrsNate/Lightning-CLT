#ifndef __LIGHTNING__
# define __LIGHTNING__
# include <iostream>
# include <string>
# include <vector>
# include <map>

using namespace std;

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
	Type 						checkType(string arg);	
};

class Utils
{
public:
	Utils();
	~Utils();
};

#endif /* __LIGHTNING__ */
