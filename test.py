import urllib2
import httplib
import time

sleep_time = 1
urllib2.urlopen('http://192.168.24.67/Forward/Right')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Newtral/Right')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Brake/Right')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Forward/Left')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Backward/Left')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Newtral/Left')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Brake/Left')
time.sleep(sleep_time)

urllib2.urlopen('http://192.168.24.67/Forward/Center')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Backward/Center')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Newtral/Center')
time.sleep(sleep_time)
urllib2.urlopen('http://192.168.24.67/Brake/Center')
time.sleep(sleep_time)

urllib2.urlopen('http://192.168.24.67/Brake/Brake')
time.sleep(sleep_time)
