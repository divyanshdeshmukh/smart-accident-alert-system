import serial
import time
import requests
url='http://localhost:5000/getdata/'
ser = serial.Serial('/dev/ttyACM0')
while True:
    temp = ser.readline()
    data=temp.rstrip()
    k= url+data
    print(k)
    r= requests.get(url=k)
    print(r.text)
    