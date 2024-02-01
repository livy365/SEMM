#pragma once

#include <QWidget>
#include "ui_Result_details.h"

class Result_details : public QWidget
{
	Q_OBJECT

public:
	Result_details(QWidget *parent = nullptr);
	~Result_details();

private:
	Ui::Result_detailsClass ui;
};
