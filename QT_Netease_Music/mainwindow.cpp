﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QMenuBar>

#include <QToolBar>
#include <QStatusBar>

#include <QDockWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <QTabWidget>
#include <QComboBox>
#include <QGridLayout>

#include <QtDebug>
#include <QAction>

#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

#include "widget_tab1.h"
#include "widget_tab2.h"
#include "MiddleWidgetLeftList.h"
#include "MiddleWidgetRightStack.h"
#include "BottomWidget.h"
#include "TitleBar.h"
#include "PlaySongInfoWidget.h"
#include "TurntableWidget.h"
#include "SongListFrame.h"
#include "SkinWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 标题栏文本
    setWindowTitle(tr("Main Window"));

    // 标题栏bar
    m_TitleBar = new TitleBar(this);

    // 菜单栏
    QMenuBar* mBar = menuBar();

    //添加菜单1
    QMenu* pFile = mBar->addMenu("File");
    QAction* pNew  = pFile->addAction("New",  this, &MainWindow::newProject);
    QAction* pOPen = pFile->addAction("Open", this, &MainWindow::openProject);
    // 添加分割线
    pFile->addSeparator();
    pFile->addAction("Quit", this, &QWidget::close);

    //添加菜单2
    QMenu* pHelp   = mBar->addMenu("Help");
    pHelp->addAction("About", this, &MainWindow::aboutDialog);

    // 工具栏
    QToolBar* toolBar = addToolBar("toolbar");
    // 工具栏中，添加菜单
    toolBar->addAction(pNew);
    toolBar->addAction(pOPen);
    // 工具栏上，添加button
    QPushButton* tool_btn = new QPushButton(this);
    tool_btn->setText("tool_btn");
    toolBar->addWidget(tool_btn);
    //this->connect(tool_btn, &QPushButton::clicked, this, &MainWindow::toolBtnDialog);
    QObject::connect(tool_btn, &QPushButton::clicked, [](bool) {
        qDebug() << "Clicked.";}
    );

    // 状态栏
    QStatusBar* sBar = statusBar();
    QLabel *status_label1 = new QLabel(this);
    status_label1->setText("part 1");
    sBar->addWidget(status_label1);
    //addWidget从左往右添加
    QLabel *status_label2 = new QLabel(this);
    status_label2->setText("part 2");
    sBar->addWidget(status_label2);
    //addpermanentwidget从右往左添加
    QLabel *status_label3 = new QLabel(this);
    status_label3->setText("part 3");
    sBar->addPermanentWidget(status_label3);

//    // 浮动窗口----暂时关闭右侧的浮动窗口
//    QDockWidget* dock = new QDockWidget("dock1", this);
//    addDockWidget(Qt::RightDockWidgetArea, dock);
//    // 浮动窗口，添加各种控件
//    QTextEdit* dock_edit = new QTextEdit(this);
//    dock->setWidget(dock_edit);

//    QDockWidget* dock2 = new QDockWidget("dock2", this);
//    addDockWidget(Qt::BottomDockWidgetArea, dock2);
//    // 浮动窗口，添加各种控件
//    QTextEdit* dock_edit2 = new QTextEdit(this);
//    dock2->setWidget(dock_edit2);

    // 将客户区域，简单的拆分为2行，共3个区域
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QHBoxLayout* hLayout = new QHBoxLayout(this);

//    // TreeWidget控件
//    QTreeWidget* treeWidget = new QTreeWidget(this);
//    //第一组
//    QTreeWidgetItem *group1=new QTreeWidgetItem();
//    group1->setText(0,"group1");
//    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
//    group1->setCheckState(0,Qt::Unchecked);
//    QTreeWidgetItem *item11=new QTreeWidgetItem(group1);
//    item11->setText(0,"item11");
//    item11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
//    item11->setCheckState(0,Qt::Unchecked);
//    QTreeWidgetItem *item12=new QTreeWidgetItem(group1);
//    item12->setText(0,"item12");
//    item12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
//    item12->setCheckState(0,Qt::Unchecked);
//    QTreeWidgetItem *item13=new QTreeWidgetItem(group1);
//    item13->setText(0,"item13");
//    item13->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
//    item13->setCheckState(0,Qt::Unchecked);

//    // 添加tree的顶层节点
//    treeWidget->insertTopLevelItem(0, group1);
//    // 节点始终展开某个节点
//    //treeWidget->setItemsExpandable(false);
//    treeWidget->expandItem(group1);

//    treeWidget->setMaximumWidth(190);

    // 左侧列表区域
    MiddleWidgetLeftList* m_list = new MiddleWidgetLeftList(this);

    // 左侧的播放歌曲信息区域
    PlaySongInfoWidget* playSongInfo = new PlaySongInfoWidget(this);

    // 右侧区域 修改为stackedwidget控件
    MiddleWidgetRightStack* myStack = new MiddleWidgetRightStack(this);


//    // 右侧区域 修改为TabWidget控件
//    //QTextEdit *textedit = new QTextEdit(this);
//    QTabWidget* tabWidget = new QTabWidget(this);

//    // 第一个tab选项卡
//    WidgetTab1* tab1 = new WidgetTab1(this);
//    tabWidget->addTab(tab1, "tab1");

//    // 第二个tab选项卡
//    //QLabel* tab1_label2 = new QLabel("label2", this);
//    WidgetTab2* tab2 = new WidgetTab2(this);
//    tabWidget->addTab(tab2, "tab2");

    // 底部播放区域
    bottomPlayWidget = new BottomWidget(this);

    // 底部区域
    QTextEdit *textedit2 = new QTextEdit(this);
    textedit2->setMaximumHeight(60);
    //
//    hLayout->addWidget(treeWidget);

    QVBoxLayout* vRightLayout = new QVBoxLayout(this);
    vRightLayout->addWidget(m_list);
    vRightLayout->addWidget(playSongInfo);

    hLayout->addLayout(vRightLayout);
//    hLayout->addWidget(tabWidget);
    hLayout->addWidget(myStack);

    vLayout->addWidget(m_TitleBar);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(bottomPlayWidget);
    vLayout->addWidget(textedit2);

    // 给垂直布局器，增加一个widget封装
    QWidget *nan_vlayout_widget = new QWidget() ;
    nan_vlayout_widget->setLayout(vLayout);
    nan_vlayout_widget->setWindowTitle("centralwidget");

    // 核心客户区域
    setCentralWidget(nan_vlayout_widget);

    //turntable widget
    m_turnTableLayoutWidget = new QWidget(nan_vlayout_widget);
    m_turntableWidget = new TurntableWidget(m_turnTableLayoutWidget);
    //set layout widget's background color equal to m_turntableWidget background color
    QPalette background_palette;
    background_palette.setColor(QPalette::Background,m_turntableWidget->backgroud_color);
    m_turnTableLayoutWidget->setPalette(background_palette);
    m_turnTableLayoutWidget->setAutoFillBackground(true);
    m_turnTableLayoutWidget->hide();
    //set layout widget's layout
    QHBoxLayout *h_turnTable_layout = new QHBoxLayout(m_turnTableLayoutWidget);
    h_turnTable_layout->addStretch();
    h_turnTable_layout->addWidget(m_turntableWidget);
    h_turnTable_layout->addStretch();

    connect(playSongInfo->cdLabel,&ClickLabel::clicked,this,&MainWindow::slot_showTurnTableWidget);
    connect(m_turntableWidget->hideButton,&QPushButton::clicked,this,&MainWindow::slot_hideTurnTableWidget);


    //播放列表
    m_SongListFrame = new SongListFrame(this);
    m_SongListFrame->hide();
    connect(bottomPlayWidget->listBtn,&QPushButton::clicked,this,&MainWindow::slot_showSongListWidget);

    //skin widget
    m_skinWidget = new SkinWidget(this);
    connect(m_TitleBar->skinBtn,&QPushButton::clicked,this,&MainWindow::slot_showSkinWidget);
    for(int i=0; i<m_skinWidget->m_ClickLabelVec.size(); ++i)
        connect(m_skinWidget->m_ClickLabelVec.at(i),&ClickLabel::clicked,[=]()
        {
            //widget_color = i;
            m_TitleBar->setStyleSheet("QFrame{background-color:"+m_skinWidget->color1_list[i]+";}");
            m_TitleBar->searchEdit->setStyleSheet("QLineEdit{border-radius:10px;\
                                                  background:"+m_skinWidget->color2_list[i]+";\
                                                  color:rgb(238,211,211);}");

            //m_MiniWidget->setStyleSheet("QFrame{background-color:"+m_skinWidget->color1_list[i]+";}");

            bottomPlayWidget->lastBtn->setStyleSheet("QPushButton{background:"+m_skinWidget->color1_list[i]+";border-radius:15px}");
            bottomPlayWidget->playBtn->setStyleSheet("QPushButton{background:"+m_skinWidget->color1_list[i]+";border-radius:15px}");
            bottomPlayWidget->nextBtn->setStyleSheet("QPushButton{background:"+m_skinWidget->color1_list[i]+";border-radius:15px}");

            bottomPlayWidget->playTimeSlider->setStyleSheet("QSlider::groove:horizontal{height: 4px;background: "+m_skinWidget->color1_list[i]+";}\
                                           QSlider::add-page:horizontal{background:#c2c2c4;}\
                                           QSlider::handle:horizontal{width: 14px;background: url(:/images/BottomPlay/curTimeHandle.png);margin: -5 0 -5 0;}");

            bottomPlayWidget->volumeSlider->setStyleSheet("QSlider::groove:horizontal{height: 4px;background: "+m_skinWidget->color1_list[i]+";}\
                                       QSlider::add-page:horizontal{background:#c2c2c4;}\
                                       QSlider::handle:horizontal{width: 12px;background: url(:/images/BottomPlay/volumeHandle.png);margin: -4 0 -4 0}");

            m_skinWidget->hide();
        });

    for(int i=0; i<m_list->m_btnVec.size(); ++i)
    {
        connect(m_list->m_btnVec.at(i),&QPushButton::clicked,myStack,[=](){myStack->setCurrentIndex(i);});
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newProject()
{
    QMessageBox::information(this, "warning", "newProject");
}

void MainWindow::openProject()
{
    QMessageBox::warning(this, "warning", "openProject");
}

void MainWindow::aboutDialog()
{
    static const char message[] = "<p><b>Qt Main Window Example</b></p>";
    QMessageBox::about(this, tr("About MainWindows"), message);
}

void MainWindow::toolBtnDialog()
{
    QMessageBox::information(this, tr("info"), "toolBtnDialog");
}

//show turntable widget
void MainWindow::slot_showTurnTableWidget()
{
    m_turnTableLayoutWidget->setGeometry(0, 0, this->width(), this->height());
    m_turnTableLayoutWidget->show();
    qDebug() << "show turn tablewidget";
}

//hide turntable widget
void MainWindow::slot_hideTurnTableWidget()
{
    m_turnTableLayoutWidget->hide();
    qDebug() << "hide turn tablewidget";
}

//when click list button
void MainWindow::slot_showSongListWidget()
{
    if(m_SongListFrame->isVisible())
        m_SongListFrame->hide();
    else
    {
        m_SongListFrame->setGeometry(width()-m_SongListFrame->width(),height()-m_SongListFrame->height()- bottomPlayWidget->height(),580,470);
        m_SongListFrame->show();
        m_SongListFrame->raise();
    }
}

void MainWindow::slot_showSkinWidget()
{
    if(m_skinWidget->isVisible())
        m_skinWidget->hide();
    else
    {
        m_skinWidget->setGeometry(m_TitleBar->skinBtn->pos().x()-115, m_TitleBar->skinBtn->pos().y()+80, 260, 169);
        m_skinWidget->show();
        m_skinWidget->raise();
    }
}
