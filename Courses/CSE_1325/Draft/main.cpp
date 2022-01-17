#include <iostream>

using namespace std;

int Print(char Alpha='A')

{

	cout << Alpha;

	return Alpha;

}


void Print(char Alpha, int Numeric=65)

{

	cout << Alpha << "=" << Numeric;

}

int main()
{
    Print('A');
    Print('A');
    return 0;
}
