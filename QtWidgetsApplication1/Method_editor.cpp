#include "Method_editor.h"

Method_editor::Method_editor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, &Method_editor::buttonClicked);


}

Method_editor::~Method_editor()
{}
void Method_editor::setMethoditem(int i, Node* p)
{
	row = i;
	currentactivity = p;
	ui.textEdit_name->setText(QString::fromStdString(p->data.method[i][0]));
	ui.textEdit_introduction->setText(QString::fromStdString(p->data.method[i][1]));
	ui.textEdit_input->setText(QString::fromStdString(p->data.method[i][2]));
	ui.textEdit_procedure->setText(QString::fromStdString(p->data.method[i][3]));
	ui.textEdit_out->setText(QString::fromStdString(p->data.method[i][4]));
}
void Method_editor::buttonClicked()
{

	currentactivity->data.method[row][0] = ui.textEdit_name->toPlainText().toStdString();
	currentactivity->data.method[row][1] = ui.textEdit_introduction->toPlainText().toStdString();
	currentactivity->data.method[row][2] = ui.textEdit_input->toPlainText().toStdString();
	currentactivity->data.method[row][3] = ui.textEdit_procedure->toPlainText().toStdString();
	currentactivity->data.method[row][4] = ui.textEdit_out->toPlainText().toStdString();
	
}