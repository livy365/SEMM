#include "activity.h"
Node* head;
Node* tail=new Node;
int curLength;

activity::activity()
{
	

}


activity::activity(std::string _name, std::string _expected_output)
{
	name= _name;
	//std::string expected_input;
	expected_output=_expected_output;
	//method.push_back({ "methodname","introduction", "input","precedure","output"});

}
