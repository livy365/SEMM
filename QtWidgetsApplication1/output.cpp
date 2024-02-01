#include "output.h"

extern Node* head;
extern Node* tail;
extern int curLength;



output::output(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.tableWidget, &QTableWidget::itemDoubleClicked, this, &output::onItemClicked);
	connect(ui.pushButton, &QPushButton::clicked, this, &output::buttonClicked);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &output::list_activity);
}

output::~output()
{}

void output::buttonClicked()
{
	activity_plan.show();

	list_activity();
}



void output::onItemClicked(QTableWidgetItem* item)
{
      Node* p = head->next;
	  int count = 0;

	  while (count < item->row()) {
			p = p->next;
			count++;
	  }


	if (item->column() == 1)
	{

	  methodlist.SetActivity(p);
	  methodlist.show();
	}
	
	else {
     result_detail.show();
	}
	
}

void output::list_activity()
{
	
	
	
	QStringList strs;

	Node* p = head;
	int count = 0;

    int rowPosition = ui.tableWidget->rowCount();
	for (int i = rowPosition-1; i >= 0; i--)
	{
		
		ui.tableWidget->removeRow(i);
	}
	

	while (count < curLength) {
		p = p->next;
		std::cout << p->data.name << "\n";
		ui.tableWidget->insertRow(count);
		ui.tableWidget->setItem(count, 0, new QTableWidgetItem(QString::fromStdString(p->data.name)));
	
		if(p->data.method.size()) { ui.tableWidget->setItem(count, 1, new QTableWidgetItem(QString::fromStdString(p->data.method[0][0]))); }
		
		ui.tableWidget->setItem(count, 2, new QTableWidgetItem(QString::fromStdString(p->previous->data.expected_output)));
		ui.tableWidget->setItem(count, 3, new QTableWidgetItem(QString::fromStdString(p->data.expected_output)));

		strs.push_back("Activity "+ QString::number(count+1));
		count++;
	}

    
	ui.tableWidget->setVerticalHeaderLabels(strs);

}