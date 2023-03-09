

import requests
try:
    r = requests.head(
        "https://github.com/violet-dev/chunk/releases/download/1676989960/data-6381258676070783631.json")
    print(r.status_code)
except requests.ConnectionError:
    print("failed to connect")
