#include "buttontabledelegate.h"
#include <QMouseEvent>

ButtonTableDelegate::ButtonTableDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void ButtonTableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                                const QModelIndex &index) const
{
    QStyleOptionButton button;
    QRect r = option.rect;

    // Уменьшаем размер кнопки для лучшего вида
    int x = r.left() + 5;
    int y = r.top() + 5;
    int w = r.width() - 10;
    int h = r.height() - 10;

    button.rect = QRect(x, y, w, h);
    button.text = index.data().toString();
    button.state = QStyle::State_Enabled;

    // Сохраняем кнопку для обработки событий
    m_buttons[index] = button;

    QApplication::style()->drawControl(QStyle::CE_PushButton, &button, painter);
}

bool ButtonTableDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (m_buttons.contains(index)) {
            if (m_buttons[index].rect.contains(mouseEvent->pos())) {
                emit buttonClicked(index.row(), index.column());
                return true;
            }
        }
    }

    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
