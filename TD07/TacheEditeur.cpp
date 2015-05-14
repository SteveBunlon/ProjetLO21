#include "TacheEditeur.h"

TacheEditeur::sauverTache(){
    TacheManager& m = TacheManager::getInstance();
    if(m.isTacheExistante(idLineEdit->text()) && &m.getTache(idLineEdit->text())!=&t){
        QMessageBox::warning(this, "ATTENTION", "La tache existe déjà");
        return;
    }
    t.setId(idTextEdit->text());
    t.setTitre(titreTextEdit->toPlainText());
    t.setDatesDisponibiliteEcheance(dateDispo->date(), dateEcheance->date());
    t.setDuree(Duree(dureeH->value(), dureeM->value()));
    if(preemptive->isChecked() && !t.isPreemptive())
        t.setPreemptive();
    else
        t.setNonPreemptive;
    QMessageBox::information(this, "Sauvegarde", "La tache a été sauvegardé");
}

TacheEditeur::TacheEditeur(Tache& t, QWidget* parent):t(t), QWidget(parent){
    vertical = new QVBoxLayout(this);

    //couche1
    couche1 = new QHBoxLayout;
    id = new Qlabel("identificateur", this);
    idLineEdit = new QLineEdit(this);
    preemtive = new QCheckBox("preemptive",this);
    couche1->addWidget(id);
    couche1->addWidget(idLineEdit);
    couche1->addWidget(preemtive);

    //couche2
    couche2 = new QHBoxLayout;
    titre = new QLabel(this);
    titreTextEdit = new QTextEdit(this);
    couche2->addWidget(titre);
    couche2->addWidget(titreTextEdit);

    //couche3
    couche3 = new QHBoxLayout;
    dispo = new QLabel("Disponibilité", this);
    echeance = new QLabel("Écheance", this);
    duree = new QLabel("Durée", this);
    dateDispo = new QDateEdit(this);
    dateEcheance = new QDateEdit(this);
    dureeH = new QSpinBox(this);
    dureeM = new QSpinBox(this);
    couche3->addWidget(dispo);
    couche3->addWidget(dateDispo);
    couche3->addWidget(echeance);
    couche3->addWidget(dateEcheance);
    couche3->addWidget(duree);
    couche3->addWidget(dureeH);
    couche3->addWidget(dureeM);

    //couche4
    couche4 = new QHBoxLayout;
    annuler = new QPushButton("Annuler", this);
    save = new QPushButton("Sauvegarder", this);
    couche4->addWidget(annuler);
    couche4->addWidget(save);

    vertical->addItem(couche1);
    vertical->addItem(couche2);
    vertical->addItem(couche3);
    vertical->addItem(couche4);

    idLineEdit->setText(t.getId());
    titreTextEdit->setText(t.getTitre());
    dateDispo->setDate(t.getDateDisponibilite());
    dateEcheance->setDate(t.getDateEcheance());
    dureeH->setValue(t.getDuree().getHeure());
    dureeM->setValue(t.getDuree().getMinute());

    save->setEnabled(false);
    QObject::connect(annuler,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(save,SIGNAL(clicked()),this, sauverTache());
    QObject::connect(idLineEdit, SIGNAL(textChanged(QString)), this, SLOT(activerButton()));
    QObject::connect(preemtive, SIGNAL(stateChanged()),save, SLOT(activerButton()));
    QObject::connect(dateDipo, SIGNAL(dateChanged(QDate)), this, SLOT(verifierDate()));
}

void TacheEditeur::activerButton(){
    save->setEnabled(true);
}

void TacheEditeur::verifierDate(){
    if(dateEcheance->date().daysTo(dateDispo->date())>0)
        QMessageBox::Warning(this, "Date anterieur", "date de disponibilité est avant la date d'échéance");
}
