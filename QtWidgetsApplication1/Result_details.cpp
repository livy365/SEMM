#include "Result_details.h"

Result_details::Result_details(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &Result_details::select);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &Result_details::save);
}

Result_details::~Result_details()
{}

void Result_details::SetActivity(Node* _activity)
{
	currentactivity = _activity;
	ui.label->setText("The result of " + QString::fromStdString(currentactivity->data.name));
	ui.textBrowser->setSource("file:///" + currentactivity->data.output_content);
	ui.textEdit->setText(currentactivity->data.output_overview);
}

void Result_details::select()
{
	QString filter = "All Files (*.*) ;;  Files (*.html)";
	QString fileName = QFileDialog::getOpenFileName(nullptr, "Select a file", "/home", filter);
	currentactivity->data.output_content = fileName;
	ui.textBrowser->setSource("file:///" + currentactivity->data.output_content);
	currentactivity->data.output_overview = ui.textEdit->toPlainText();
}

void Result_details::save()
{
	currentactivity->data.output_overview = ui.textEdit->toPlainText();
}
