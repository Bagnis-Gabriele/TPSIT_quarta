import threading
import logging as log
import time

def fn_thread(val):
    l.acquire()
    log.info(f"Thread {val}, inizio.")
    time.sleep(2)
    log.info(f"Thread {val}, fine.")
    l.release()

l = threading.Lock()    #initializing mutex

def main():
    #configuring log message info
    format = "%(asctime)s: %(message)s"
    log.basicConfig(format = format, level = log.INFO, datefmt= "%H:%M:%S")

    log.info("PADRE, creo un threads")

    threads = list()
    for i in range(0,5):
        log.info(f"PADRE, creo ed avvio il thread {i}")
        x = threading.Thread(target = fn_thread, args = (i, ))
        threads.append(x)
        x.start()

    for i, value in enumerate(threads):
        log.info(f"PADRE, prima dell'attesa del thread {i}")
        value.join()
        log.info(f"PADRE, thread {i} terminato")

if __name__ == "__main__":
    main()