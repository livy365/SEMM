#include "Method.h"

Method::Method(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Method::~Method()
{}

void Method::setMethoditem(int i,Node* p)
{
	ui.introduction_textBrowser->setText(QString::fromStdString(p->data.method[i][1]));
	ui.Procedure_textBrowser_2->setText(QString::fromStdString(p->data.method[i][2]));
	ui.Input_textBrowser_4->setText(QString::fromStdString(p->data.method[i][3]));
	ui.Output_textBrowser_3->setText(QString::fromStdString(p->data.method[i][4]));
}
