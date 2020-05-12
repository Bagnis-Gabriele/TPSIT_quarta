import threading
import time
import logging as log
import random

mutex = threading.Lock()
biglietti = 100
n_clienti = 50

def cassa(index):
    global biglietti
    mutex.acquire()
    num = random.randrange(1,5)
    print(f"Processo {index}: {num} biglietti")
    if biglietti == 0:
        print("Biglietti terminati!")
    elif biglietti > 0 and num <= biglietti:
        print(f"{num} biglietti comprati.")
        biglietti = biglietti - num
    elif biglietti > 0 and num > biglietti:
        print(f"{biglietti} biglietti comprati.")
        biglietti = 0

    print(f"Biglietti rimanenti: {biglietti}")
    mutex.release()

def main():
    global n_clienti

    format = "%(asctime)s: %(message)s"
    log.basicConfig(format = format, level = log.INFO, datefmt= "%H:%M:%S")

    log.info("PADRE, creazione dei processi in corso...")

    clienti = []

    for i in range(0,n_clienti):
        clienti.append(threading.Thread(target = cassa, args = (i+1, )))
    for c in clienti:
        c.start()

    for c in clienti:
        c.join()

    log.info("PADRE, tutti i processi terminali...")

if __name__ == "__main__":
    main()