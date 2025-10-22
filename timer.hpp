#ifndef SNAKETIMER_HPP
#define SNAKETIMER_HPP
#define DEFAULT_TICK_INTERVAL 100
#include <QDebug>
#include <QObject>
#include <QTimer>

class SnakeTimer : public QObject {
  Q_OBJECT

 public:
  explicit SnakeTimer(QObject* parent = nullptr);
  void start(int intervalMs);
  void stop();
  void tickNow();  // вызвать следующий тик сразу
 public slots:
  void forceUpdate();
  void intervalChange(const int newIntervalValue);
  void pauseToggled();

 signals:
  void tick();  // сигнал тика игры

 private slots:
  void onTimeout();

 private:
  QTimer* m_timer;
  int interval;
  bool isPaused = false;
};

#endif  // SNAKETIMER_HPP