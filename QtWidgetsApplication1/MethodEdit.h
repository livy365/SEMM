#pragma once

#include <QWidget>
#include "ui_MethodEdit.h"
#include"activity.h"
class MethodEdit : public QWidget
{
	Q_OBJECT

public:
	MethodEdit(QWidget *parent = nullptr);
	~MethodEdit();
	void setMethod(Node *p);
	void buttonClicked();
private:
	Ui::MethodEditClass ui;
	Node* current;
};
