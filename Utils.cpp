#include "lightning.h"

vector<string> Utils::CreateStringVector(char **array, int start, int size)
{
	vector<string> new_array;
	for (int i = start + size - 1; i != start - 1; i--)
	{
		new_array.push_back(array[i]);
	}
	return (new_array);
}

string Utils::GetFileContent(string filename)
{
	ifstream file;
	file.open(filename);
	if (file.is_open())
	{
		string file_content;
		string current_line;
		while (!file.eof())
		{
			getline(file, current_line);
			current_line += '\n';
			file_content += current_line;
		}
		return (file_content);
	}
	cout << "Please provide a correct filename" << endl;
	return (NULL);
}
