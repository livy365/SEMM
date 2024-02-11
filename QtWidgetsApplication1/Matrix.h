#pragma once

#include <QWidget>
#include "ui_Matrix.h"
#include"activity.h"
class Matrix : public QWidget
{
	Q_OBJECT

public:
	Matrix(QWidget *parent = nullptr);
	~Matrix();
	void Matrix::list_activity();
private:
	Ui::MatrixClass ui;
};
