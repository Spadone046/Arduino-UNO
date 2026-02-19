import serial
import time

conteggio = 0
colp = "Rosso"

ser = serial.Serial("COM7", 9600)

file = open("dati_semaforo.csv", "w")
file.write("conteggio", "timestamp, colore\n")

while True:
    colore = data=ser.readline().decode("utf-8").strip()
    print(colore)
    if colp == "Rosso" and colore == "Verde":
        conteggio += 1
    elif colp == "Verde" and colore == "Giallo":
        conteggio += 1
    elif colp == "Giallo" and colore == "Rosso":
        conteggio += 1
    timestamp = time.strftime("%H:%M:%S")
    file.write(f"{conteggio}, {timestamp}, {colore}\n")
    file.flush()