#include "Result_details.h"

Result_details::Result_details(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Result_details::~Result_details()
{}

void Result_details::SetActivity(Node* _activity)
{
	currentactivity = _activity;

	ui.textBrowser->setSource("file:///" + currentactivity->data.output_content);
}