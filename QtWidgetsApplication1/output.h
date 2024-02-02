#pragma once

#include <QWidget>
#include "ui_output.h"
#include"MethodList.h"
#include"Result_details.h"
//#include"activity.h"
#include"Activity_edit.h"
#include"Activity_Planer.h"
class output : public QWidget
{
	Q_OBJECT

public:
	output(QWidget *parent = nullptr);
	~output();
	
public slots:
	void output::onItemClicked(QTableWidgetItem* item);
	void output::buttonClicked();
	void output::list_activity();
private:
	Ui::outputClass ui;
	MethodList methodlist;
	Result_details result_detail;
	Activity_Planer activity_plan;
	Activity_edit activity_edit;
};
