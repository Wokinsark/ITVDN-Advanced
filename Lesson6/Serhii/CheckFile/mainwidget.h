#pragma once

#include <QWidget>
#include <QLayout>
#include <QCheckBox>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QPlainTextEdit>
#include <QFile>

class MainWidget : public QWidget {
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget() = default;

private slots:
    void getFile_clicked();
    void analysis_clicked();

private:
    void connect();
    void disconnect();

    void start(const QString & value);
    bool isPalindrome(const QString & text, bool isCheckRegister, bool isCheck1Letter, bool isCheck2Letter);

    QVBoxLayout * layoutMain;
    QHBoxLayout * layout1;
    QHBoxLayout * layout2;
    QHBoxLayout * layout3;
    QHBoxLayout * layout4;

    QLabel    * label;
    QCheckBox * addRegister;
    QCheckBox * addPalindrome1;
    QCheckBox * addPalindrome2;
    QPushButton * getFile;
    QPushButton * analysis;
    QPlainTextEdit * textEdit;
};
