#pragma once

#include <QWidget>
#include "ui_Method_editor.h"
#include"activity.h"
class Method_editor : public QWidget
{
	Q_OBJECT

public:
	Method_editor(QWidget *parent = nullptr);
	~Method_editor();
	void Method_editor::setMethoditem(int i, Node* p);
	void Method_editor::buttonClicked();
private:
	Ui::Method_editorClass ui;
	Node* currentactivity; 
	int row;
};
