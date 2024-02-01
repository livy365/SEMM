#pragma once
#include<string>
#include<QString>
#include<qstringlist.h>
class activity
{
  

public:
    activity::activity();
    activity::activity(std::string name, std::string expected_output);
    void activity::edit_name(std::string name, std::string expected_output);
   void  activity::edit_output(std::string name, std::string expected_output);


	std::string name;
	//std::string expected_input;
	std::string expected_output;
    QString output_content;
    std::vector<std::vector<std::string>> method;
   

};


struct Node {
    //节点的数据域 
    activity data;

    Node* previous;

    Node* next;

    Node(const activity value, Node* p = NULL) {
        data = value;
        next = p;
    }
    Node(Node* p = NULL) {
        next = p;
    }
};

