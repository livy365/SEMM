#include "SEMM1.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

#include<iostream>
#include<fstream>

extern Node* head;
extern Node* tail;
extern int curLength;

SEMM1::SEMM1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    head = new Node();
    curLength = 0;
    
   // connect(ui.listWidget, SIGNAL(QListWidget::itemClicked()), this, SLOT(onItemClicked()));
    connect(ui.listWidget, &QListWidget::itemDoubleClicked, this, &SEMM1::onItemClicked);
    connect(ui.actionExport, &QAction::triggered, this, &SEMM1::Exported);

    connect(ui.pushButton_3, &QPushButton::clicked, this, &SEMM1::restore);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &SEMM1::nextbuttonClicked);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &SEMM1::select);


  //  activity activity1("Determine Stakeholder Needs and Requirements", "1. Stakeholders\n 2. Requirements of users");
  //  activity activity2("Analyze System Context ", "1. System boundary\n 2. Operating environment");
   // addnew(activity1);
   // addnew(activity2);


    restore();
}

SEMM1::~SEMM1()
{}

void SEMM1::addnew(activity _activity)
{
    Node* p = head;
    Node* q;
    int count = 0;
    while (count < curLength) {
        p = p->next;
        count++;
    }
    
    q = new Node(_activity, p->next);
    p->next = q;
    q->previous = p;
    tail->previous = q;
    curLength++;
  
}

void SEMM1::Exported()
{
    

    output.show();
}

void SEMM1::onItemClicked(QListWidgetItem* item)
{
  

    qDebug() << "Item clicked: " << item->text();
    method.setMethoditem(ui.listWidget->row(item), p);
    method.show();
}

void SEMM1::restore()
{

    read();
    p = head->next;
    ui.label_name->setText(QString::fromStdString(p->data.name));
    ui.textBrowser_last->setText(QString::fromStdString(p->previous->data.expected_output));
    
    ui.textBrowser->setSource("file:///" + p->previous->data.output_content);

    ui.textBrowser_2->setSource("file:///" + p->data.output_content);

    ui.textBrowser_Cresult->setText(QString::fromStdString(p->data.expected_output));
    ui.listWidget->clear();
    int method_number = p->data.method.size();
    for (int i = 0; i < method_number; i++)
    {
        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(QString::fromStdString(p->data.method[i][0]));  // 设置item的名称
        ui.listWidget->addItem(newItem);

    }
 
  //  
}

void SEMM1::nextbuttonClicked()
{
    if(p->next)
  { 
    p = p->next;
    ui.label_name->setText(QString::fromStdString(p->data.name));
    ui.textBrowser_last->setText(QString::fromStdString(p->previous->data.expected_output));
    ui.textBrowser_Cresult->setText(QString::fromStdString(p->data.expected_output));
    ui.textBrowser->setSource("file:///"+p->previous->data.output_content);
    ui.textBrowser_2->setSource("file:///" + p->data.output_content);
    ui.listWidget->clear();
    int method_number = p->data.method.size();
    for (int i = 0; i < method_number; i++)
    {
        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(QString::fromStdString(p->data.method[i][0]));  // 设置item的名称
        ui.listWidget->addItem(newItem);

    }
  }
  else
  {
        std::cerr << "Last!" << std::endl;
  }
}

void SEMM1::select()
{
    QString filter = "All Files (*.*) ;;  Files (*.html)";
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Select a file", "/home", filter);
    p->data.output_content = fileName;
    ui.textBrowser_2->setSource("file:///" + p->data.output_content);

    save();


}

void SEMM1::save()
{
    Node* p = head;
   
    int count = 0;

    std::string namefilePath = "activity/activity_name.txt";
    std::ofstream namefile(namefilePath, std::ios_base::out);    //定义输出流对象
    namefile.close();
    
    while (count < curLength) {
        p = p->next;
        count++;

       // std::string filePath = "activity/activity"+std::to_string(count)+"_logger.txt";
        
        
        namefile.open(namefilePath,std::ios::app);    //打开文件
        if (!namefile)
        {
            std::cout << "打开文件失败" << std::endl;
            exit(1);
        }

        //向文件中写入数据
       
       
         namefile << p->data.name << std::endl;
        

        namefile.close();    //关闭文件
    
    
    }

    p = head;
    count = 0;
    std::string outfilePath = "activity/activity_out.txt";
    std::ofstream outfile(outfilePath, std::ios_base::out);    //定义输出流对象
    outfile.close();

    while (count < curLength) {
        p = p->next;
        count++;

        // std::string filePath = "activity/activity"+std::to_string(count)+"_logger.txt";


        outfile.open(outfilePath, std::ios::app);    //打开文件
        if (!outfile)
        {
            std::cout << "打开文件失败" << std::endl;
            exit(1);
        }

        //向文件中写入数据
        
      
         outfile << p->data.expected_output + ";";
       

        outfile.close();    //关闭文件


    }



    p = head;
    count = 0;
  
    while (count < curLength) {
        p = p->next;
        count++;

        std::string MethodfilePath = "activity/activity" + std::to_string(count) + "out.txt";
        std::ofstream Methodsfile(MethodfilePath, std::ios_base::out);    //定义输出流对象
        Methodsfile.close();


        Methodsfile.open(MethodfilePath, std::ios::app);    //打开文件
        if (!Methodsfile)
        {
            std::cout << "打开文件失败" << std::endl;
            exit(1);
        }

        //向文件中写入数据

        int method_number = p->data.method.size();
        for (int i = 0; i < method_number; i++)
        {
            for (int k = 0; k < 5;k++) {
                Methodsfile << p->data.method[i][k] + ";";
            }
            

        }
        


        Methodsfile.close();    //关闭文件


    }


    p = head;
    count = 0;
    std::string outContentPath = "activity/activity_outContent.txt";
    std::ofstream outContentfile(outContentPath, std::ios_base::out);    //定义输出流对象
    outContentfile.close();

    while (count < curLength) {
        p = p->next;
        count++;

        // std::string filePath = "activity/activity"+std::to_string(count)+"_logger.txt";


        outContentfile.open(outContentPath, std::ios::app);    //打开文件
        if (!outfile)
        {
            std::cout << "打开文件失败" << std::endl;
            exit(1);
        }

        //向文件中写入数据


        outContentfile <<p->data.output_content.toStdString() + ";";


        outContentfile.close();    //关闭文件


    }




    QFile file("activity/activity.csv");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("Cannot open file for writing: %s", qPrintable(file.errorString()));
        return;
    }
    QTextStream stream(&file);
   
    stream << "sep =,\n";
    //创建表头
    stream << "Name,required input,result\n";

    // 添加数据行，包含超链接


    p = head;
    
    while (p->next) {
        p = p->next;
     

        stream << QString::fromStdString(p->data.name) + ",=HYPERLINK(\"" + p->previous->data.output_content + "\";\"" + QString::fromStdString(p->previous->data.expected_output) + "\")"+",=HYPERLINK(\""+p->data.output_content+"\";\""+ QString::fromStdString(p->data.expected_output)+"\")\n";

     
    }
    

    //stream << "Example Link,=HYPERLINK(\"file:///D:/semm/QtWidgetsApplication1/QtWidgetsApplication1/activity/activity1/method1/intr.htm\";\"Visit Example\")\n";
    //stream << "Google Link,=HYPERLINK(\"http://www.google.com\";\"Visit Google\")\n";

    //关闭文件
    file.close();




}




void SEMM1::read()
{
    Node* p ;
    Node* q;
    p = head->next;

    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
       
    }
    
    head->next = NULL;
    curLength = 0;



   std::string file_name = "activity/activity_name.txt";
    std::ifstream file_reader(file_name);
    if (file_reader.is_open())
    {
        while (file_reader.peek() != EOF)
        {
           std:: string line;
            getline(file_reader, line, '\n');
           std:: cout << line << "FFFF\n";
            // do something

           activity activity1(line, "test");

           addnew(activity1);

        }
        file_reader.close();
    }
    else
    {
        std::cerr << "Fail to open file !" << endl;
    }

    p = head->next;
    std::string file_out = "activity/activity_out.txt";
    std::ifstream outfile_reader(file_out);
    if (outfile_reader.is_open())
    {
        while (outfile_reader.peek() != EOF)
        {
            std::string line;
            getline(outfile_reader, line, ';');
          
            p->data.expected_output = line;
            p = p->next;
            // do something

           

        }
        outfile_reader.close();
    }
    else
    {
        std::cerr << "Fail to open file !" << endl;
    }


    p = head->next;
    std::string file_content = "activity/activity_outContent.txt";
    std::ifstream contentfile_reader(file_content);
    if (contentfile_reader.is_open())
    {
        while (contentfile_reader.peek() != EOF)
        {
            std::string line;
            getline(contentfile_reader, line, ';');

            p->data.output_content = QString::fromStdString(line);
            p = p->next;
            // do something



        }
        contentfile_reader.close();
    }
    else
    {
        std::cerr << "Fail to open file !" << endl;
    }


    p = head->next;

    for (int i = 1; i <= curLength; i++)
    {
      std::string MethodfilePath = "activity/activity" + std::to_string(i) + "out.txt";
      std::ifstream Methodfile_reader(MethodfilePath);
      if (Methodfile_reader.is_open())
      {   int row = 0;
          while (Methodfile_reader.peek() != EOF)
          {
              std::string line; 
              
            getline(Methodfile_reader, line, ';');
            if (row % 5 == 0) {
               // std::cout <<"row:"+ row<<"\n";
             p->data.method.push_back(std::vector<std::string>());
            }

           p->data.method[row/5].push_back(line);
           
            row++;
         

          }
          Methodfile_reader.close();
      }
    else
    {
        std::cerr << "Fail to open file !" << endl;
    }

        p = p->next;

    }

   
    

}
