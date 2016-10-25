#include "wdgsettingsvalues.h"
#include "ui_wdgsettingsvalues.h"

WdgSettingsValues::WdgSettingsValues(QWidget *parent) :
    QWidget(parent), ui(new Ui::WdgSettingsValues) {
    ui->setupUi(this);

    mngr = new ValuesMngr();

    this->data = mngr->getValues();

    refresh();
}

WdgSettingsValues::~WdgSettingsValues() {
    delete ui;
}

void WdgSettingsValues::addValue() {
    ValuesDTO *dto = new ValuesDTO(ui->txtName->text(), ui->txtValue->text(), ui->txtDesc->document()->toPlainText());

    mngr->saveValue(dto);

    data.append(dto);

    refresh();
}

void WdgSettingsValues::saveValue() {
    if (ui->tblValues->selectedRanges().size() > 0) {
        int row = ui->tblValues->selectedItems().at(0)->row();

        data.at(row)->setName(ui->txtName->text());
        data.at(row)->setValue(ui->txtValue->text());
        data.at(row)->setDesc(ui->txtDesc->document()->toPlainText());

        mngr->saveValue(data.at(row));

        refresh();
    }
}

void WdgSettingsValues::removeValue() {
    if (ui->tblValues->selectedRanges().size() > 0) {
        int row = ui->tblValues->selectedItems().at(0)->row();

        mngr->deleteValue(data.at(row));

        data.removeAt(row);

        refresh();
    }
}

void WdgSettingsValues::selectionChanged() {
    if (ui->tblValues->selectedRanges().size() > 0) {
        int row = ui->tblValues->selectedItems().at(0)->row();

        ui->txtName->setText(data.at(row)->getName());
        ui->txtValue->setText(data.at(row)->getValue());
        ui->txtDesc->setText(data.at(row)->getDesc());
    }
}

void WdgSettingsValues::refresh() {
    int rows = data.size();

    ui->tblValues->setRowCount(rows);
    ui->tblValues->clearContents();

    for (int i = 0; i < rows; i++) {
        QTableWidgetItem *twiName = new QTableWidgetItem(data.at(i)->getName());
        twiName->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tblValues->setItem(i, 0, twiName);
        QTableWidgetItem *twiValue = new QTableWidgetItem(data.at(i)->getValue());
        twiValue->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tblValues->setItem(i, 1, twiValue);
        QTableWidgetItem *twiDesc = new QTableWidgetItem(data.at(i)->getDesc());
        twiDesc->setFlags(Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tblValues->setItem(i, 2, twiDesc);
    }
}
