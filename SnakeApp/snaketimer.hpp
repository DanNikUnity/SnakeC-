/**
 * @file snaketimer.hpp
 * @author Nicolaev Dan
 * @date 2025
 * @brief Timer personalizat pentru jocul Snake, gestionând tick-urile jocului.
 */

#ifndef SNAKETIMER_HPP
#define SNAKETIMER_HPP
#define DEFAULT_TICK_INTERVAL 100

#include <QDebug>
#include <QObject>
#include <QTimer>

/**
 * @class SnakeTimer
 * @brief Clasă care gestionează intervalele de actualizare ale jocului.
 *
 * Este un wrapper peste QTimer, adăugând funcționalități
 * precum pauză, schimbarea vitezei și tick manual.
 */
class SnakeTimer : public QObject {
  Q_OBJECT

 public:
  /**
   * @brief Creează timer-ul Snake.
   * @param parent Obiect părinte.
   */
  explicit SnakeTimer(QObject* parent = nullptr);

  /**
   * @brief Pornește timer-ul cu un anumit interval.
   * @param intervalMs Intervalul în milisecunde.
   */
  void start(int intervalMs);

  /**
   * @brief Oprește timer-ul.
   */
  void stop();

  /**
   * @brief Forțează emiterea imediată a unui tick.
   */
  void tickNow();

 public slots:
  /**
   * @brief Forțează actualizarea instantă.
   */
  void forceUpdate();

  /**
   * @brief Schimbă intervalul timer-ului.
   * @param newIntervalValue Noul interval în ms.
   */
  void intervalChange(const int newIntervalValue);

  /**
   * @brief Activează/dezactivează pauza timer-ului.
   */
  void pauseToggled();

 signals:
  /**
   * @brief Semnal emis la fiecare tick.
   */
  void tick();

 private slots:
  /**
   * @brief Callback intern pentru expirarea timer-ului.
   */
  void onTimeout();

 private:
  QTimer* m_timer; ///< Timer-ul intern Qt.
  int interval;    ///< Intervalul curent al timer-ului.
  bool isPaused = false; ///< Stare de pauză.
};

#endif
