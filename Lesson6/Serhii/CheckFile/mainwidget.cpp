#include "mainwidget.h"

#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    layoutMain(new QVBoxLayout {this}),
    layout1(new QHBoxLayout {this}),
    layout2(new QHBoxLayout {this}),
    layout3(new QHBoxLayout {this}),
    layout4(new QHBoxLayout {this}),
    label(new QLabel{this}),
    addRegister(new QCheckBox{"учитывать регистр", this}),
    addPalindrome1(new QCheckBox{"учитывать 1-но буквенные", this}),
    addPalindrome2(new QCheckBox{"учитывать 2-ух буквенные", this}),
    getFile(new QPushButton{"Выбрать файл", this}),
    analysis(new QPushButton{"Начать анализ", this}),
    textEdit(new QPlainTextEdit{this})
{
    this->setWindowTitle("Поиск палиндромов");

    textEdit->setReadOnly(true);

    layout1->addWidget(addRegister);
    layout1->addWidget(addPalindrome1);
    layout1->addWidget(addPalindrome2);

    layout2->addWidget(label);

    layout3->addWidget(getFile);
    layout3->addWidget(analysis);

    layout4->addWidget(textEdit);

    layoutMain->addLayout(layout1);
    layoutMain->addLayout(layout2);
    layoutMain->addLayout(layout3);
    layoutMain->addLayout(layout4);
    this->setLayout(layoutMain);

    connect();
}

void MainWidget::connect() {
    QObject::connect(getFile,  SIGNAL(clicked()), this, SLOT(getFile_clicked()));
    QObject::connect(analysis, SIGNAL(clicked()), this, SLOT(analysis_clicked()));
}

void MainWidget::getFile_clicked() {
    QString name = QFileDialog::getOpenFileName(this, "Открыть файл", "");
    if (!name.isEmpty()) {
        label->setText(name);
    }
}

void MainWidget::analysis_clicked() {
    if (label->text().isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Выберите файл");
        return;
    }

    QFile file(label->text());
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Внимание", "Ошибка чтения файла");
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");

    start(in.readAll());

    QMessageBox::warning(this, "Информация", "Анализ успешно окончен");
}

void MainWidget::start(const QString &value) {
    QString res = "";
    QStringList list = value.split(" ");
    for (auto str : list) {
        if (isPalindrome(str, addRegister->isChecked(), addPalindrome1->isChecked(), addPalindrome2->isChecked())) {
            res += " " + str;
        }
    }
    textEdit->setPlainText(res);
}

bool MainWidget::isPalindrome(const QString & text, bool isCheckRegister, bool isCheck1Letter, bool isCheck2Letter) {
    if (text.isEmpty()) {
        return false;
    }

    QString value(text);
    if (!isCheckRegister) {
        value = value.toLower();
    }

    if (!isCheck1Letter && value.length() == 1) {
        return false;
    }

    if (!isCheck2Letter && value.length() == 2) {
        return false;
    }

    for (int start = 0, finish = value.length() - 1; finish > start; ++start, --finish) {
        if (value[start] != value[finish]) {
            return false;
        }
    }

    return true;
}
