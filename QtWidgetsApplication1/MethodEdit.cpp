#include "MethodEdit.h"

extern Node* head;
extern Node* tail;
extern int curLength;

MethodEdit::MethodEdit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &MethodEdit::buttonClicked);


}

MethodEdit::~MethodEdit()
{}



void MethodEdit::setMethod(Node* p)
{
	current = p;

}

void MethodEdit::buttonClicked()
{
	
	current->data.method.push_back({ ui.textEdit_name->toPlainText().toStdString(),ui.textEdit_introduction->toPlainText().toStdString(),
		ui.textEdit_input->toPlainText().toStdString(),ui.textEdit_procedure->toPlainText().toStdString(),ui.textEdit_out->toPlainText().toStdString()});

}
