#pragma once

#include <QWidget>
#include "ui_Activity_edit.h"
#include"activity.h"
class Activity_edit : public QWidget
{
	Q_OBJECT

public:
	Activity_edit(QWidget *parent = nullptr);
	~Activity_edit();
	void SetActivity(Node* _activity);
	void save();
private:
	Ui::Activity_editClass ui;
Node* currentactivity;
}; 
