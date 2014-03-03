/*
 * lcd_spinbox.h - class lcdSpinBox, an improved QLCDNumber
 *
 * Copyright (c) 2005-2014 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 *
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#ifndef _LCD_SPINBOX_H
#define _LCD_SPINBOX_H

#include "LcdWidget.h"
#include "AutomatableModelView.h"


class EXPORT lcdSpinBox : public LcdWidget, public IntModelView
{
	Q_OBJECT
public:
	lcdSpinBox( int numDigits, QWidget* parent, const QString& name = QString::null );

	lcdSpinBox( int numDigits, const QString& style, QWidget* parent, const QString& name = QString::null );

	virtual ~lcdSpinBox();

	virtual void modelChanged()
	{
		ModelView::modelChanged();
		update();
	}

	/*! Sets an offset which is always added to value of model so we can
	    display values in a user-friendly way if they internally start at 0 */
	void setDisplayOffset( int offset )
	{
		m_displayOffset = offset;
	}

	/*! \brief Returns internal offset for displaying values */
	int displayOffset() const
	{
		return m_displayOffset;
	}


public slots:
	virtual void update();


protected:
	virtual void contextMenuEvent( QContextMenuEvent * _me );
	virtual void mousePressEvent( QMouseEvent * _me );
	virtual void mouseMoveEvent( QMouseEvent * _me );
	virtual void mouseReleaseEvent( QMouseEvent * _me );
	virtual void wheelEvent( QWheelEvent * _we );

private:
	QPoint m_origMousePos;
	int m_displayOffset;


signals:
	void manualChange();

} ;

typedef IntModel lcdSpinBoxModel;

#endif