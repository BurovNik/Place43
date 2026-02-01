#ifndef BUTTONTABLEDELEGATE_H
#define BUTTONTABLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>
#include <QPushButton>
#include <QApplication>

class ButtonTableDelegate : public QStyledItemDelegate
{
    Q_OBJECT

 public:
     explicit ButtonTableDelegate(QObject *parent = nullptr);

     void paint(QPainter *painter, const QStyleOptionViewItem &option,
                const QModelIndex &index) const override;

     bool editorEvent(QEvent *event, QAbstractItemModel *model,
                      const QStyleOptionViewItem &option, const QModelIndex &index) override;

 signals:
     void buttonClicked(int row, int column);

 private:
     mutable QMap<QModelIndex, QStyleOptionButton> m_buttons;
};

#endif // BUTTONTABLEDELEGATE_H
