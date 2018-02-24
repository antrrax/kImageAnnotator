/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef TOOLPICKER_H
#define TOOLPICKER_H

#include <QToolBar>
#include <QActionGroup>
#include <QToolButton>
#include <QVBoxLayout>

#include "../AnnotationToolTypes.h"

class ToolPicker : public QToolBar
{
    Q_OBJECT
public:
    explicit ToolPicker();
    ~ToolPicker();
    void selectTool(ToolTypes newTool);

signals:
    void toolSelected(ToolTypes newTool);

private:
    QVBoxLayout*    mLayout;
    QActionGroup*   mActionGroup;
    QAction*        mSelectAction;
    QAction*        mLineAction;
    QAction*        mRectAction;
    QAction*        mEllipseAction;
    QAction*        mArrowAction;
    QList<QAction*> mListOfItemActions;
    ToolTypes       mSelectedToolType;

    void initGui();

private slots:
    void actionTriggered(QAction* action);
    void setToolAndNotify(ToolTypes newTool);
};

#endif // TOOLPICKER_H