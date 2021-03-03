#include "qtools.h"
#include "./ui_qtools.h"
#include <QFileDialog>
#include <QDir>
#include <QProcess>

QString openDirectory(QWidget* parent, QString title = QString("Select Directory"))
{
    return QFileDialog::getExistingDirectory(parent, title);
}

QTools::QTools(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QTools)
{
    ui->setupUi(this);
}

QTools::~QTools()
{
    delete ui;
}

void QTools::on_SetSourcePath_clicked()
{
    auto path = openDirectory(this);
    if (path.length() > 0)
    {
        ui->SourcePath->setText(path);
    }
}

void QTools::on_SetDestinationPath_clicked()
{
    auto path = openDirectory(this);
    if (path.length() > 0)
    {
        ui->DestinationPath->setText(path);
    }
}

void QTools::on_MakeLink_clicked()
{
    auto srcPath = ui->SourcePath->text().replace('/', '\\');
    auto dstPath = ui->DestinationPath->text().replace('/', '\\');

    if (srcPath.length() > 0 && dstPath.length() > 0 && QDir(srcPath).exists() && !QDir(dstPath).exists())
    {
        auto dstDir = QFileInfo(dstPath).dir();
        if (!dstDir.exists())
        {
            dstDir.mkpath(".");
        }

        QProcess::execute("cmd", QStringList{ "/c", "mklink", "/J", dstPath, srcPath });
    }
}
