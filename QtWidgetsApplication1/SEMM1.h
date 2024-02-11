#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SEMM1.h"
#include"Method.h"
#include"output.h"
#include"Matrix.h"
//#include"activity.h"


class SEMM1 : public QMainWindow
{
    Q_OBJECT

public:
    SEMM1(QWidget *parent = nullptr);
    ~SEMM1();
    void addnew(activity _activity);
public slots:
    void SEMM1::onItemClicked(QListWidgetItem* item);
    void SEMM1::Exported();

    void SEMM1::restore();
    void SEMM1::nextbuttonClicked();
    void select();
    void save();
    void read();
    void matrixshow();
private:
    Ui::SEMM1Class ui;
    Method method;
    output output;
    Matrix matrix;
    Node* p;

};
