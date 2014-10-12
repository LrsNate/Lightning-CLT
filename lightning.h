#ifndef __LIGHTNING__
# define __LIGHTNING__
# define MODULE_VAR "$using_modules"
# define BUNDLE_VAR "$using_bundles"
# include <unistd.h>
# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <map>

using namespace std;

typedef void (*callback)(vector<string>);

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
	static vector<string>		CreateStringVector(char **array, int start, int size);
	static string				GetFileContent(string filename);
};


class BundleGeneration
{
public:
	BundleGeneration();
	~BundleGeneration();
	static void 				GenerateBundle(vector<string> args);
private:
	static vector<string>		getDependencies(string file, string dependency_var);
};

#endif /* __LIGHTNING__ */
