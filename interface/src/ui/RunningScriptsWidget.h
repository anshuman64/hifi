//
//  RunningScriptsWidget.h
//  interface
//
//  Created by Mohammed Nafees on 03/28/2014.
//  Copyright (c) 2014 High Fidelity, Inc. All rights reserved.

#ifndef __hifi__RunningScriptsWidget__
#define __hifi__RunningScriptsWidget__

#include <QDockWidget>

#include "ScriptsTableWidget.h"

namespace Ui {
    class RunningScriptsWidget;
}

class RunningScriptsWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit RunningScriptsWidget(QDockWidget *parent = 0);
    ~RunningScriptsWidget();

    void setRunningScripts(const QStringList& list);

signals:
    void stopScriptName(const QString& name);

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void paintEvent(QPaintEvent *);

private slots:
    void stopScript(int row, int column);
    void loadScript(int row, int column);
    void allScriptsStopped();

private:
    Ui::RunningScriptsWidget *ui;
    ScriptsTableWidget *_runningScriptsTable;
    ScriptsTableWidget *_recentlyLoadedScriptsTable;
    QStringList _recentlyLoadedScripts;
    QString _lastStoppedScript;

    void createRecentlyLoadedScriptsTable();
};

#endif /* defined(__hifi__RunningScriptsWidget__) */
