#pragma once
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class GameOverDialog : public QDialog {
    Q_OBJECT
public:
    explicit GameOverDialog(QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("Game Over");
        setModal(true);
        resize(200, 120);

        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *label = new QLabel("Game Over!", this);
        label->setAlignment(Qt::AlignCenter);

        QPushButton *replayBtn = new QPushButton("Replay", this);

        layout->addWidget(label);
        layout->addWidget(replayBtn);

        connect(replayBtn, &QPushButton::clicked, this, &GameOverDialog::replayClicked);
    }

signals:
    void replayClicked();
};
