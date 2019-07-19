#include<string>
#include<fmt/format.h>
using namespace std;

int main()
{
	string s = "hello";
	fmt::print("wrote {}", s);
}

