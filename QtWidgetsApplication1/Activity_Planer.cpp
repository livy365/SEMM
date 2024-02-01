#include "Activity_Planer.h"

extern Node* head;
extern Node* tail;
extern int curLength;

Activity_Planer::Activity_Planer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, &Activity_Planer::buttonClicked);
	

}

Activity_Planer::~Activity_Planer()
{}


void Activity_Planer::buttonClicked()
{
	Node* p = head;
	Node* q;
	int count = 0;
	while (count < curLength) {
		p = p->next;
		count++;
	}
	activity newactivity;
	q = new Node(newactivity, p->next);
	p->next = q;
	q->previous = p;
	tail->previous = q;
	curLength++;

	q->data.name = ui.titleEdit->toPlainText().toStdString();

	q->data.expected_output = ui.outEdit->toPlainText().toStdString();

	

	
}
void Activity_Planer::list()
{
	Node* p = head;
	int count = 0;

	while (count < curLength) {
		p = p->next;
		std::cout << p->data.name << "\n";
		count++;
	}



}