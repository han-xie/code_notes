#!/usr/bin/python
import os
import time

network = os.system('ping -c 1 8.8.8.8 > /dev/null 2>&1')
while network:
    print('Network is not connected, waiting for 20s...')
    time.sleep(20)
    network = os.system('ping -c 1 8.8.8.8 > /dev/null 2>&1')

print('Network is connected')
