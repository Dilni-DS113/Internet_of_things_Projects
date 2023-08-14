from sqlite3 import Cursor
import serial
import pymysql

dervice = '/dev/ttys0'

arduino = serial.Serial(dervice,9600)


while True:
    sealeveldata = arduino.readline()
    print(sealeveldata)
    wLdbConn = pymysql.connect("localhost","pi","","sealevel_db") or die("Could not connect to database")

    with wLdbConn:
        cursor = wLdbConn.cursor()
        cursor.execute("INSERT INTO SLlog (sealevel) VALUE(%s)", sealeveldata)
        wLdbConn.commit
        cursor.close()
