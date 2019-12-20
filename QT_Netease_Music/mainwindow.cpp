﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QMenuBar>

#include <QToolBar>
#include <QStatusBar>

#include <QtDebug>
#include <QAction>

#include <QMessageBox>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 标题栏文本
    setWindowTitle(tr("Main Window"));

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
    this->connect(tool_btn, &QPushButton::clicked, this, &MainWindow::toolBtnDialog);

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
