#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	char str[] = "parrot,owl,,sparow,pigeon,crow";
	char delim[] = ",";
	cout << "The tokens are:" << endl;
	char *token = strtok(str, delim);
	while (token)                          // first call
	{
		cout << token << endl;
		token = strtok(NULL, delim);       // subsequent calls
	}
	return 0;
}