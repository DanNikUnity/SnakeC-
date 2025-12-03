# SnakeC-

# Snake Game
**Autor:** Nicolaev Dan  
**An:** 2025  
**Tehnologii:** C++, Qt 6, Doxygen  

---

## 📌 Descrierea proiectului
Acest proiect reprezintă implementarea jocului clasic Snake, realizată în C++ și Qt.  
Logica jocului este separată într-o bibliotecă (`SnakeCore`), iar interfața grafică este construită folosind QWidget, QTimer și evenimente de tastatură.

Proiectul demonstrează:
- separarea logicii de randare și interfață
- utilizarea OOP în C++
- utilizarea Doxygen pentru documentarea codului
- gestionarea stării jocului
- implementarea unui sistem simplu de randare (Painter)

---

## 🎮 Regulile jocului
- Jucătorul controlează șarpele cu săgețile: ↑ ↓ ← →
- Scopul este să colectezi merele roșii
- Fiecare măr crește lungimea șarpelui
- Jocul se termină dacă:
  - șarpele lovește marginea
  - șarpele se lovește de propriul corp
- Apare o fereastră „Game Over” cu opțiunea **Replay**

---

## 📦 Dependențe
- **Qt 6.10.0** (mingw_64)
- **C++17**
- **MinGW-w64 11+**
- **Doxygen** (opțional pentru generarea documentației)
- **GNU Make** (pt. build manual)

---

## 🔧 Construirea proiectului

### 🛠 Construirea bibliotecii 
`SnakeCore`
```bash
cd SnakeCore
qmake
make

---

### 🛠 Construirea aplicației
`SnakeApp`
```bash
cd SnakeApp
qmake
make

---
### 🛠 Pornirea aplicației
`RUN`
```bash
cd build/bin
./Snake.exe

---