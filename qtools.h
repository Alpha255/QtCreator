#ifndef QTOOLS_H
#define QTOOLS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QTools; }
QT_END_NAMESPACE

class QTools : public QMainWindow
{
    Q_OBJECT

public:
    QTools(QWidget *parent = nullptr);
    ~QTools();

private slots:
    void on_SetSourcePath_clicked();

    void on_SetDestinationPath_clicked();

    void on_MakeLink_clicked();

private:
    Ui::QTools *ui;
};
#endif // QTOOLS_H
