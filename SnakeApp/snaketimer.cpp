#include "snaketimer.hpp"

SnakeTimer::SnakeTimer(QObject *parent) : QObject(parent) {
  m_timer = new QTimer(this);
  interval = DEFAULT_TICK_INTERVAL;
  connect(m_timer, &QTimer::timeout, this, &SnakeTimer::onTimeout);
}

void SnakeTimer::start(int intervalMs) {
  m_timer->start(intervalMs);
  interval = intervalMs;
}

void SnakeTimer::stop() { m_timer->stop(); }

void SnakeTimer::tickNow() {
  stop();
  onTimeout();
  start(interval);
}

void SnakeTimer::onTimeout() {
  if (isPaused) {
    return;
  }

  emit tick();
}
void SnakeTimer::forceUpdate() { tickNow(); }

void SnakeTimer::intervalChange(const int newIntervalValue) {
  interval = newIntervalValue;
  stop();
  start(interval);
}

void SnakeTimer::pauseToggled() { isPaused = !isPaused; }