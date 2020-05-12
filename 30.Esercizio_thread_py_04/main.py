import threading
import logging as log
import time

def ping():
    i = 0
    while(i < 10):
        s1.acquire()
        print("PING")
        i = i + 1
        time.sleep(1)
        s2.release()

def pong():
    i = 0
    while(i < 10):
        s2.acquire()
        print("PONG")
        i = i + 1
        time.sleep(1)
        s1.release()


#mutex creating
s1 = threading.Lock()
s2 = threading.Lock()
s2.acquire()

def main():
    
    #configuring log message info
    format = "%(asctime)s: %(message)s"
    log.basicConfig(format = format, level = log.INFO, datefmt= "%H:%M:%S")

    log.info("PADRE, creo un threads")

    #thread creating
    t1 = threading.Thread(target = ping)
    t2 = threading.Thread(target = pong)

    #starting thread
    t1.start()
    t2.start()

    t1.join()
    t2.join()


if __name__ == "__main__":
    main()