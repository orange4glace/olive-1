/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef TASK_H
#define TASK_H

#include <QObject>

#include "task/taskthread.h"

class Task : public QObject
{
  Q_OBJECT
public:
  enum Status {
    kWaiting,
    kWorking,
    kFinished,
    kError
  };

  Task();

  bool Start();

  virtual bool Action();

  const Status& status();

  const QString& text();

  const QString& error();

  void AddDependency(Task* dependency);

protected:
  void set_error(const QString& s);

  void set_text(const QString& s);

signals:
  void StatusChanged(Task::Status s);

  void ProgressChanged(int p);

private:
  void set_status(const Status& status);

  Status status_;

  TaskThread thread_;

  QString text_;

  QString error_;

  QList<Task*> dependencies_;

private slots:
  void ThreadComplete();
};

#endif // TASK_H
