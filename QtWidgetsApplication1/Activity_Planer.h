#pragma once
#include<iostream>
#include <string>
#include <QMainWindow>
#include "ui_Activity_Planer.h"
#include"activity.h"


class Activity_Planer : public QMainWindow
{
	Q_OBJECT

public:
	Activity_Planer(QWidget *parent = nullptr);
	~Activity_Planer();

	void Activity_Planer::list();
public slots:
	void Activity_Planer::buttonClicked(); 
	

private:
	Ui::Activity_PlanerClass ui;
};
