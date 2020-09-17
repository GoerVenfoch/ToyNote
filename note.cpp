/*!
 * \file
 * \brief Файл реализации класса Note.
 * \author Кирилл Пушкарёв
 * \date 2017
 */
#include "note.hpp"

Note::Note()
{
}

Note::Note(QString title, QString text, qint32 icon)
    : mTitle(title) // Передаём заголовок конструктору mTitle
    , mText(text) // Передаём заголовок конструктору mText
    , mIcon(icon) // Передаем заголовок конструктору mIcon
{
}

const QString &Note::title() const
{
    return mTitle;
}

void Note::setTitle(const QString &title)
{
    mTitle = title;
}

const QString &Note::text() const
{
    return mText;
}

void Note::setText(const QString &text)
{
    mText = text;
}

void Note::save(QDataStream &ost) const
{
    ost << mTitle << mText << mIcon;
}

void Note::load(QDataStream &ist)
{
    ist >> mTitle >> mText >> mIcon;
}

const qint32 &Note::icon() const
{
    return mIcon;
}

void Note::setidIcon(qint32 number)
{
    mIcon = number;
}
