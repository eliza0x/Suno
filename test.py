#!/usr/bin/env python2

import urllib2
from httplib import BadStatusLine

for var in range(0, 100):
    try:
        urllib2.urlopen('http://192.168.24.67/moveFoward')
    except BadStatusLine:
        pass
