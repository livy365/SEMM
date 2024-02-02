#include "Activity_edit.h"

Activity_edit::Activity_edit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &Activity_edit::save);
}

Activity_edit::~Activity_edit()
{}

void Activity_edit::SetActivity(Node * _activity)
{
	currentactivity = _activity;

	ui.titleEdit->setText(QString::fromStdString(currentactivity->data.name));

	ui.outEdit->setText(QString::fromStdString(currentactivity->data.expected_output));

}

void Activity_edit::save()
{
	currentactivity->data.name = ui.titleEdit->toPlainText().toStdString();

	currentactivity->data.expected_output = ui.outEdit->toPlainText().toStdString();

}


