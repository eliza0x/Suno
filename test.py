import urllib2
import httplib

for var in range(0, 10):
    try:
        urllib2.urlopen('http://192.168.24.67')
    except httplib.BadStatusLine:
        pass
