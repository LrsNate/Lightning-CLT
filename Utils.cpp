#include "lightning.h"

vector<string> Utils::CreateStringVector(char **array, int start, int size)
{
	vector<string> new_array(size);
	for (int i = start + size - 1; i != start - 1; i--)
		new_array.push_back(array[i]);
	return (new_array);
}
