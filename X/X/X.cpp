
#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::stack<char> toClose;
	std::string line;
	bool insideQuotations = false;
	while (!std::cin.eof())
	{
		getline(std::cin, line);
		for (char c : line)
		{
			if (c == '"')
			{
				if (insideQuotations) insideQuotations = false;
				else insideQuotations = true;
			}
			else if(insideQuotations) continue;		
			switch (c)
			{
			case '[':
				toClose.push(']');
				break;
			case '{':
				toClose.push('}');
				break;
			case '(':
				toClose.push(')');
				break;
			case '<':
				toClose.push('>');
				break;
			case ']':
				if (toClose.empty() || toClose.top() != ']') {
					std::cout << "incorrect";
					return 0;
				}
				else toClose.pop();
				break;
			case '}':
				if (toClose.empty() || toClose.top() != '}') {
					std::cout << "incorrect";
					return 0;
				}
				else toClose.pop();
				break;
			case ')':
				if (toClose.empty() || toClose.top() != ')') {
					std::cout << "incorrect";
					return 0;
				}
				else toClose.pop();
				break;
			case '>':
				if (toClose.empty() || toClose.top() != '>') {				
					std::cout << "incorrect";
					return 0;
				}
				else toClose.pop();
				break;
			default:
				break;
			}
		}
	}
	if (insideQuotations || !toClose.empty()) std::cout << "incorrect";
	else std::cout << "correct";
	return 0;
}
