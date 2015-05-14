#ifndef TACHEEDITEUR_H
#define TACHEEDITEUR_H
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QDateEdit>
#include <QLabel>
#include <QCheckBox>
#include <QMessageBox>

class TacheEditeur : public QWidget{
    Q_OBJECT
    public:
        Tache& t;
        QVBoxLayout* vertical;

        //première couche
        QHBoxLayout* couche1;
        QLabel* id;
        QLineEdit* idTextEdit;
        QCheckBox* preemtive;

        //deuxième couche
        QHBoxLayout* couche2;
        QLabel* titre;
        QTextEdit* titreLineEdit;

        //troisième couche
        QHBoxLayout* couche3;
        QLabel* dispo, *echeance, *duree;
        QDateEdit* dateDispo, *dateEcheance;
        QSpinBox* *dureeH, *dureeM;

        //quatrème couche
        QHBoxLayout* couche4;
        QPushButton* annuler, *save;

        TacheEditeur(Tache& t,QWidget* parent = 0);
    signals:
    public slots:
        void sauverTache();
        void activerButton();
        void verifierDate();
}
#endif // TACHEEDITEUR_H
