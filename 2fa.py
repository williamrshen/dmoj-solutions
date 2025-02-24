import pyotp
from dotenv import load_dotenv
import os

load_dotenv()

TOTP_SECRET = os.getenv("TOTP_SECRET")

totp = pyotp.TOTP(TOTP_SECRET)
print("Generated 2FA Code:", totp.now())
