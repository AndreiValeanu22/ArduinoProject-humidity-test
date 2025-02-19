# Proiect Arduino: Test de Umiditate

## 1. Scenariu practic

Un sistem de monitorizare a umidității și temperaturii pentru o casă sau un birou. Menținerea unui nivel optim de umiditate și temperatură este esențială pentru confortul și sănătatea oamenilor. Un nivel prea ridicat sau prea scăzut al acestora poate cauza disconfort sau probleme de sănătate. Prin urmare, un sistem care monitorizează și controlează aceste variabile poate fi extrem de util.

### Arhitectura sistemului:

- **Senzor analogic**: Senzorul DHT11 este utilizat pentru a măsura temperatura și umiditatea din încăpere. Acesta este conectat la un pin analogic pe placa Arduino.
- **Microcontroller**: Placa Arduino preia datele de la senzorul DHT11 și le procesează. Dacă umiditatea depășește un anumit prag, Arduino aprinde un LED corespunzător (verde pentru umiditate normală, galben pentru umiditate ușor ridicată și roșu pentru umiditate foarte ridicată).
- **Actuator**: LED-urile sunt actuatorii în acest sistem. Acestea sunt aprinse în funcție de nivelul de umiditate detectat de senzor.
- **Afișaj**: Valorile de umiditate și temperatură sunt afișate în consola serială a Arduino.

### Diagrama bloc a sistemului:
[Senzor DHT11] --(Date de umiditate și temperatură)--> [Arduino] --(Comandă LED)--> [LED-uri]
[Senzor DHT11] --(Date de umiditate și temperatură)--> [Arduino] --(Date de umiditate și temperatură)--> [Consola serială]


În acest scenariu, pragurile de umiditate vor fi setate astfel:
- **Umiditate normală**: 30-55%
- **Umiditate ușor ridicată**: 55-60%
- **Umiditate foarte ridicată**: peste 60%

## 2. Funcționarea sistemului

Sistemul nostru de monitorizare a umidității și temperaturii funcționează prin citirea valorilor de la senzorul DHT11 și afișarea acestora în consola serială. În același timp, în funcție de nivelul de umiditate, un LED corespunzător este aprins. 

- Dacă umiditatea este în intervalul normal (30-55%), LED-ul verde este aprins.
- Dacă umiditatea este ușor ridicată (55-60%), LED-ul galben este aprins.
- Dacă umiditatea este foarte ridicată (peste 60%), LED-ul roșu este aprins.

Simulăm creșterea umidității prin punerea degetului peste senzorul de umiditate pentru a prelua umiditatea din piele și observăm cum umiditatea crește iar LED-urile se schimbă.

## 3. Lista componente necesare

- **Breadboard 400 puncte**
- **Placa dezvoltare UNO R3 Arduino compatibil, AtMega328p, CH340G, MiniUSB**
- **Modul LED semafor, 56mm, 3.3-5V**
- **Senzor temperatura si umiditate DHT11, modul**
- **Fire Dupont 20cm, Tata-Tata**
- **Conector Baterie 9V cu mufa 5.5*2.1**
