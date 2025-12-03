/**
 * @file gameoverdialog.hpp
 * @author Nicolaev Dan
 * @date 2025
 * @brief Dialog afișat la finalul jocului, oferind opțiunea de reluare.
 */

#pragma once
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

/**
 * @class GameOverDialog
 * @brief Fereastră simplă de dialog afișată atunci când jocul se termină.
 *
 * Afișează un mesaj „Game Over” și un buton pentru reluarea jocului.
 */
class GameOverDialog : public QDialog {
    Q_OBJECT
public:
    /**
     * @brief Creează dialogul Game Over.
     * @param parent Fereastra părinte.
     */
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
    /**
     * @brief Semnal emis când utilizatorul apasă butonul „Replay”.
     */
    void replayClicked();
};
