import threading
import logging as log
import time

def fn_thread(val):
    log.info(f"Thread {val}, inizio.")
    time.sleep(2)
    log.info(f"Thread {val}, fine.")

def main():
    #configuring log message info
    format = "%(asctime)s: %(message)s"
    log.basicConfig(format = format, level = log.INFO, datefmt= "%H:%M:%S")

    log.info("PADRE, creo un thread")
    x = threading.Thread(target = fn_thread, args = (1, ))   #thread creation

    log.info("PADRE, lacio il thread")
    x.start()   #thread lauching

    log.info("PADRE, aspetto la terminazione del processo creato")
    x.join()

    log.info("PADRE, fine")

if __name__ == "__main__":
    main()