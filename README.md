# **Battaglia Navale - Battleship**

Questo repository contiene il mio primo grande progetto in C++. Si tratta di un **gioco completo di Battaglia Navale**, implementato con i principi della **programmazione orientata agli oggetti (OOP)**.

## **Caratteristiche**
- **Modalità PvP**: Gioca contro un altro giocatore umano.
- **Modalità PvAI**: Combatti contro un avversario IA.
- **Interfaccia Console Interattiva**: Mostra una griglia di gioco strutturata e permette ai giocatori di effettuare mosse.
- **Gioco a Turni**: Include il cambio schermo per prevenire imbrogli.
- **Design OOP**: Classi come `Giocatore`, `Nave` e `Scacchiera` gestiscono la logica e la struttura del gioco.
- **Gestione Personalizzata dell'Input**: Garantisce una corretta validazione degli input dell'utente.

## **Struttura del Progetto**
```
BattagliaNavale/
│── bin/                  # Contiene il file binario compilato del gioco
│   ├── battleship
│── obj/                  # Contiene i file oggetto compilati (.o)
│   ├── Battaglia.o
│   ├── Giocatore.o
│   ├── Menu.o
│   ├── Nave.o
│   ├── PvAI.o
│   ├── PvP.o
│   ├── Scacchiera.o
│── src/                  # File sorgente
│   ├── Battaglia.cpp
│   ├── commenti.cpp
│   ├── Giocatore.cpp
│   ├── main.cpp
│   ├── Menu.cpp
│   ├── Nave.cpp
│   ├── PvAI.cpp
│   ├── PvP.cpp
│   ├── Scacchiera.cpp
│   ├── testMain.cpp
│── .gitignore            # Esclude i file binari e oggetto dalla versione
│── Makefile              # Automatizza la compilazione
│── README.md             # Documentazione del progetto
```

## **Come Compilare ed Eseguire**
### **1. Compilare il Gioco**
Assicurati di avere `g++` installato, quindi esegui:
```sh
make
```
Questo compilerà tutti i file `.cpp` e genererà l'eseguibile nella cartella `bin/`.

### **2. Avviare il Gioco**
Esegui il comando:
```sh
./bin/battleship
```

### **3. Eseguire i Test (se applicabile)**
Se `testMain.cpp` esiste, compila ed esegui la versione di test:
```sh
make test
./bin/testBattleship
```

### **4. Pulire la Compilazione**
Per rimuovere i file compilati e resettare il progetto:
```sh
make clean
```

## **Regole del Gioco**
1. I giocatori si alternano selezionando una coordinata da attaccare.
2. Il gioco segna i **colpi a segno (X)** e i **mancati (O)**.
3. Se tutte le parti di una nave vengono colpite, viene **affondata**.
4. Il primo giocatore che affonda tutte le navi nemiche vince.
