#include "MethodList.h"
#include <QDebug>
MethodList::MethodList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	connect(ui.listWidget, &QListWidget::itemDoubleClicked, this, &MethodList::onItemClicked);
	connect(ui.pushButton, &QPushButton::clicked, this, &MethodList::buttonClicked);
	
}

MethodList::~MethodList()
{}
void MethodList::SetActivity(Node * _activity)
{
	currentactivity= _activity;

	ui.listWidget->clear();
	int method_number = _activity->data.method.size();
	for (int i = 0; i < method_number; i++)
	{
		QListWidgetItem* newItem = new QListWidgetItem;
		newItem->setText(QString::fromStdString(_activity->data.method[i][0]));  // ÉèÖÃitemµÄÃû³Æ
		ui.listWidget->addItem(newItem);

	}

}
void MethodList::onItemClicked(QListWidgetItem* item)
{
	qDebug() << "Item clicked: " << item->text();
	method.setMethoditem(ui.listWidget->row(item), currentactivity);
	method.show();
}

void MethodList::buttonClicked()
{

	methodedit.setMethod(currentactivity);
	methodedit.show();

}
