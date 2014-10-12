#include "lightning.h"

void BundleGeneration::GenerateBundle(vector<string> args)
{
	if (args.size() < 1)
		cout << "Please provide a bundle file to generate" << endl;
	else
	{
		cout << "Launching Generate Command" << endl;
		string file = Utils::GetFileContent(args[0]);
		cout << file << endl;
		vector<string> modules_dependencies = BundleGeneration::getDependencies(file, MODULE_VAR);
		vector<string> bundles_dependencies = BundleGeneration::getDependencies(file, BUNDLE_VAR);
		for (vector<string>::iterator it = modules_dependencies.begin(); it != modules_dependencies.end(); ++it)
			cout << *it << endl;
		for (vector<string>::iterator it = bundles_dependencies.begin(); it != bundles_dependencies.end(); ++it)
			cout << *it << endl;
	}

}

vector<string> BundleGeneration::getDependencies(string file, string dependency_var)
{
	vector<string> dependencies;

	size_t found = file.find(dependency_var);
	size_t end_line = file.find('\n', found);
	string line = file.substr(found, end_line - found);
	found = line.find('(');
	end_line = line.find(')');
	line = line.substr(found + 1, end_line - found - 1);
	found = 0;
	while (found != line.length())
	{
		string dependency;
		if (dependency_var == MODULE_VAR)
			dependency += "Module:";
		else if (dependency_var == BUNDLE_VAR)
			dependency += "Bundle:";
		found = line.find("'", found);
		end_line = line.find("'", found + 1);
		dependency += line.substr(found + 1,  end_line - found - 1);
		dependencies.push_back(dependency);
		found = end_line + 1;
	}
	return (dependencies);
}
