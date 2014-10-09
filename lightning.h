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

template <class T>
class Utils
{
public:
	Utils();
	~Utils();
	static vector<string> ResizeArray(T array, int start, int size)
	{
		vector<string> newArray(size);
		for (int i = start + size; i != start; i--)
			newArray.push_back(array[i]);
		return (newArray);
	}
};

#endif /* __LIGHTNING__ */
