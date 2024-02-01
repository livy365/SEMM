#pragma once

#include <QWidget>
#include "ui_Method.h"
#include"activity.h"
class Method : public QWidget
{
	Q_OBJECT

public:
	Method(QWidget *parent = nullptr);
	~Method();
	void setMethoditem(int i ,Node* p);
private:
	Ui::MethodClass ui;
};
