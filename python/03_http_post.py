#!/usr/bin/python3

from datetime import datetime

import requests

def http_post():
    start_time = datetime.now()
    url = "http://www.httpbin.org/post"
    data = "whatever"
    headers = {"content-type": "application/json"}
    r = requests.post(url, data=data, headers=headers)
    print(r.text)

    end_time = datetime.now()
    whole_time = (end_time - start_time)
    print("Whole time is {}".format(whole_time))

if __name__ == "__main__":
    http_post()
