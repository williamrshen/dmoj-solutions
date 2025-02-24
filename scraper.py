from selenium import webdriver
from selenium.webdriver.firefox.service import Service
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
import pyotp
import time
from webdriver_manager.firefox import GeckoDriverManager
from bs4 import BeautifulSoup
import os
from dotenv import load_dotenv
import random


load_dotenv()
TOTP_SECRET = os.getenv("TOTP_SECRET")
DMOJ_USERNAME = os.getenv("DMOJ_USERNAME")
DMOJ_PASSWORD = os.getenv("DMOJ_PASSWORD")

firefox_options = Options()
firefox_options.add_argument("--start-maximized")

service = Service(GeckoDriverManager().install())
driver = webdriver.Firefox(service=service, options=firefox_options)


try:
    driver.get("https://dmoj.ca/accounts/login/?next=/")
    time.sleep(5)

    username = driver.find_element(By.NAME, "username")
    username.send_keys(DMOJ_USERNAME)

    password = driver.find_element(By.NAME, "password")
    password.send_keys(DMOJ_PASSWORD)
    password.send_keys(Keys.RETURN)

    time.sleep(1)

    totp = pyotp.TOTP(TOTP_SECRET)
    otp_code = totp.now()
    print(f"Generated 2FA Code: {otp_code}")

    otp_field = driver.find_element(By.NAME, "totp_or_scratch_code")
    otp_field.send_keys(otp_code)
    otp_field.send_keys(Keys.RETURN)

    time.sleep(1)

    dir = 'submissions'
    cdir = 'solutions'
    for subs in os.listdir(dir):
        sub = os.path.join(dir, subs)
        f = sub[sub.index('\\') + 1: sub.index('.')]
        driver.get("https://dmoj.ca/submission/" + f)
        time.sleep(random.uniform(0.5, 1))
        soup = BeautifulSoup(driver.page_source, 'html.parser')
        out = soup.select('a')
        code = ''
        for x in out:
            link = x.get('href')
            if '/problem/' in link:
                code = link.split('/')[2]
                break
        print(code)
        path = f"{cdir}/{code}.txt"
        categories = ['aac', 'ccc', 'coci', 'dmopc', 'mccc', 'oly', 'sac']
        categorized = False
        
        for x in categories:
            if x in path:
                path = f"{cdir}/{x}/{code}.txt"
                categorized = True
        
        if not categorized:
            path = f"{cdir}/other/{code}.txt"
        
        if os.path.exists(path):
            continue

        with open(path, "w", encoding="utf-8") as file, open(sub, "r") as submission: 
            for line in submission:
                file.write(line)

    print("done")

finally:
    driver.quit()
