import requests, time
from os import system, name

# define our clear function 
def clear(): 
    # for windows 
    if name == 'nt': 
        _ = system('cls') 
    # for mac and linux(here, os.name is 'posix') 
    else: 
        _ = system('clear') 

while True:
    url = "https://api.coincap.io/v2/assets"
    test = requests.get(url)

    info = test.json()
    #print(info['data'])
    print("This Application Gives You The Real Time Value Of Top 10 Crypto Currency\n")
    print("RANK -------------  UDS price --------------------- NAME\n")
    for i in range(0,10):
        rank = info['data'][i]['rank']
        price = info['data'][i]['priceUsd']
        name1 = info['data'][i]['id']

        text =f"Rank = {rank}   Price = {price}     Name = {name1}  "
        print(text)
        
    time.sleep(4)
    clear()
