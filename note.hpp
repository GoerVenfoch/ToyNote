/*!
 * \file
 * \brief Заголовочный файл класса Note.
 * \author Кирилл Пушкарёв
 * \date 2017
 */
#ifndef NOTE_HPP
#define NOTE_HPP

#include <QDataStream>
#include <QString>
#include <QIcon>

/*!
 * \brief Класс заметки.
 */
class Note
{
public:
    //! Конструктор по умолчанию
    Note();
    /*!
     * \brief Конструктор, устанавливающий заголовок и текст.
     * \param title Заголовок заметки.
     * \param text Текст заметки.
     * \param icon Иконка заменки
     *
     * Создаёт объект Note с заголовком \a title, текстом \a text и иконкой \a icon.
     */
    Note(QString title, QString text, qint32 icon);
    //! Возвращает заголовок заметки.
    const QString &title() const;
    //! Устанавливает заголовок заметки равным \a title.
    void setTitle(const QString &title);
    //! Возвращает текст заметки.
    const QString &text() const;
    //! Устанавливает заголовок заметки равным \a text.
    void setText(const QString &text);
    //! Сохраняет заметку в поток \a ost.
    void save(QDataStream &ost) const;
    //! Загружает заметку из потока \a ist.
    void load(QDataStream &ist);
    //! Устанавливает выбраную иконку заметки
    const qint32 &icon() const;
    //! Устанавливает номер иконки заметки
    void setidIcon (qint32 number);
private:
    //! Заголовок заметки.
    QString mTitle;
    //! Текст заметки.
    QString mText;
    //! Иконка заметки
    qint32 mIcon;
};

/*!
 * \brief Реализация оператора << для вывода Note в QDataStream.
 * \param ost Поток для вывода.
 * \param note Заметка.
 * \return Поток \a ost после вывода.
 *
 * Данная функция объявлена \c inline, чтобы компилятор мог подставить её код
 * вместо полноценного вызова функции. В данном случае это оправданно, так как
 * функция всего лишь перенаправляет вызов методу save().
 */
inline QDataStream &operator<<(QDataStream &ost, const Note &note)
{
    note.save(ost);
    return ost;
}

/*!
 * \brief Реализация оператора >> для ввода Note из QDataStream.
 * \param ist Поток для ввода.
 * \param note Заметка.
 * \return Поток \a ist после ввода.
 */
inline QDataStream &operator>>(QDataStream &ist, Note &note)
{
    note.load(ist);
    return ist;
}

#endif // NOTE_HPP
