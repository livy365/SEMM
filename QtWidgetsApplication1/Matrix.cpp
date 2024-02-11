#include "Matrix.h"
#include<iostream>
extern Node* head;
extern Node* tail;
extern int curLength;

Matrix::Matrix(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tableWidget->verticalHeader()->setDefaultSectionSize(100);
	ui.tableWidget->horizontalHeader()->setDefaultSectionSize(300);

}

Matrix::~Matrix()
{}
void Matrix::list_activity()
{

	int rowPosition = ui.tableWidget->rowCount();
	for (int i = rowPosition - 1; i >= 0; i--)
	{

		ui.tableWidget->removeRow(i);
	}

	int columnPosition = ui.tableWidget->columnCount();
	for (int i = columnPosition - 1; i >= 0; i--)
	{

		ui.tableWidget->removeColumn(i);
	}


	//QStringList strs;

	Node* p = head;
	int count = 0;

	

	ui.tableWidget->insertRow(count);
	ui.tableWidget->insertColumn(count);
	ui.tableWidget->insertColumn(count);

	while (count < curLength) {
		p = p->next;
		
		QFont boldFont;
		boldFont.setBold(true);
		QTableWidgetItem* name = new QTableWidgetItem(QString::fromStdString(p->data.name));
		name->setFont(boldFont);
		
		ui.tableWidget->insertRow(count+1);
		ui.tableWidget->setItem(count+1, 0, name);

		QTableWidgetItem* name2 = new QTableWidgetItem(QString::fromStdString(p->data.name));
		name2->setFont(boldFont);


		ui.tableWidget->insertColumn(count+2);
		ui.tableWidget->setItem(0, count + 2, name2);

		QString content;
		for (int i = 0; i < p->data.method.size(); i++)
		{
			content = content  +QString::fromStdString(p->data.method[i][0]) + "\n";

		}
	
		ui.tableWidget->setItem(count+1, 1, new QTableWidgetItem(content));

		QBrush Brush(QColor(0, 170, 0));

		
		QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(p->data.expected_output));

		
		item->setBackground(Brush);

		ui.tableWidget->setItem(count+1, count+2,item );

		Node* lastp = p->previous;
		for (int i = count; i > 0; i--)
		{
			ui.tableWidget->setItem(count + 1, i + 1, new QTableWidgetItem(lastp->data.output_overview));
			lastp = lastp->previous;
		}



		//strs.push_back("Activity " + QString::number(count + 1));
		count++;
	}


	//ui.tableWidget->setVerticalHeaderLabels(strs);

}