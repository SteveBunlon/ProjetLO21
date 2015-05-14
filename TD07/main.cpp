#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include "Calendar.h"
#include <QFileDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setFixedSize(200, 200);

    QLineEdit I1(&fenetre);
    QTextEdit T1(&fenetre);
    QPushButton B1("Sauver");

    I1.setFixedWidth(180);
    T1.setFixedSize(180,110);
    B1.setFixedWidth(80);

    QVBoxLayout couche;
    couche.addWidget(&I1);
    couche.addWidget(&T1);
    couche.addWidget(&B1);
    /*I1.move(10,10);
    T1.move(10,45);
    B1.move(10,170);*/

    TacheManager& m = TacheManager::getInstance();
    QString chemin = QFileDialog::getOpenFileName();
    m.load(chemin);

    Tache& t = m.getTache("T1");
    I1.setText(t.getId());
    T1.setText(t.getTitre());

    fenetre.show();    
    return app.exec();
}
