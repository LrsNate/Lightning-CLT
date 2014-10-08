#ifndef __LIGHTNING__
# define __LIGHTNING__
# include <iostream>
# include <string>

using namespace std;

class Command
{
public:
	string Line;
	Command(string line);
	~Command();
};

class Utils
{
public:
	Utils();
	~Utils();
	string ArrayToString(char** array);
}

#endif /* __LIGHTNING__ */
