#pragma once
#include <QFileDialog>
#include <QWidget>
#include "ui_Result_details.h"
#include"activity.h"
class Result_details : public QWidget
{
	Q_OBJECT

public:
	Result_details(QWidget *parent = nullptr);
	~Result_details();
	void SetActivity(Node* _activity);
	void select();
private:
	Ui::Result_detailsClass ui;
	Node* currentactivity;
};
