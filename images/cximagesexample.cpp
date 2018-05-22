#include "cximagesexample.h"
#include <QFileIconProvider>
#include <QStyle>
#include <QPixmap>
#include <QImage>
#include <QApplication>
#include <QImageWriter>
#include <QImageReader>
#include <QDebug>
#include <QGraphicsRectItem>

CxImagesExample::CxImagesExample(QObject *parent) : QObject(parent)
{
    //get icon ways:
    //1 ==> QStyle::SP_DriveCDIcon
    //2 ==> Qt::ToolButtonTextBesideIcon
    //3 ==> QFileIconProvider::Folder
    QStyle* style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_DriveCDIcon);
    QPixmap pixmap = icon.pixmap(60, 60);
    QImage  image  = pixmap.toImage();

    QImageWriter imageWrite("createdCd.jpeg", "jpeg");
    if (imageWrite.supportsOption(QImageIOHandler::Description))
    {
        imageWrite.setText("author", "Mr chan");
        imageWrite.setText("description", "qter");
    }
    imageWrite.setQuality(100);
    if (imageWrite.canWrite())
    {
        imageWrite.write(image);
    }
    else
    {
        QImageWriter::ImageWriterError error  = imageWrite.error();
        QString strError = imageWrite.errorString();
        qDebug() << "Last Error:" << strError;
    }
}

void   CxImagesExample::imageRead()
{
    QImageReader reader;
    reader.setFileName("createdCd.jpeg");

    if (reader.canRead())
    {
        QImage image = reader.read();

        QStringList keys = reader.textKeys();
        QString strvalue("");

        foreach (QString strKey, keys)
        {
            strvalue = reader.text(strKey);
            qDebug() << QString("Key: %1").arg(strvalue);
        }

    }
        else
        {
            QImageReader::ImageReaderError error = reader.error();
            QString strError = reader.errorString();
            qDebug() << "Last Error : " << strError;
        }
}
