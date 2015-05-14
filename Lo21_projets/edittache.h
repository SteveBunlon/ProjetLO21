#ifndef EDITTACHE_H
#define EDITTACHE_H

#include <QDialog>
#include "classes/Projet.h"
#include "classes/Tache.h"

namespace Ui {
class EditTache;
}

class EditTache : public QDialog
{
    Q_OBJECT

public:
    explicit EditTache(QWidget *parent = 0);
    ~EditTache();

public slots:
    void loadProjects();

private:
    Ui::EditTache *ui;
};

#endif // EDITTACHE_H
