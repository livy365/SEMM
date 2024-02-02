#pragma once

#include <QWidget>
#include "ui_MethodList.h"
#include"Method.h"
#include"activity.h"
#include"MethodEdit.h"
#include "Method_editor.h"
class MethodList : public QWidget
{
	Q_OBJECT

public:
	MethodList(QWidget *parent = nullptr);
	~MethodList();
	void SetActivity(Node *p);
	void MethodList::onItemClicked(QListWidgetItem* item);
	void buttonClicked();
private:
	Ui::MethodListClass ui;
	Node * currentactivity;
	Method method;
	MethodEdit methodedit;
	Method_editor methodeditor;
};
