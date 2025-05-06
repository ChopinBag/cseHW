FROM python:3.10-slim-buster
# FROM tiangolo/uwsgi-nginx-flask:python3.10

# ENV
ENV user dreamhack
ENV port 8000

RUN apt-get update && apt-get install -y python3-pip wget curl unzip gnupg2

RUN wget --no-verbose -O /tmp/chrome.deb https://dl.google.com/linux/chrome/deb/pool/main/g/google-chrome-stable/google-chrome-stable_114.0.5735.90-1_amd64.deb \
  && apt install -y /tmp/chrome.deb \
  && rm /tmp/chrome.deb
RUN apt-get update -y && apt-get install -y libnss3 sqlite3
RUN wget https://chromedriver.storage.googleapis.com/`curl -sS https://chromedriver.storage.googleapis.com/LATEST_RELEASE`/chromedriver_linux64.zip && unzip chromedriver_linux64.zip && rm chromedriver_linux64.zip

# SET challenges
RUN adduser $user
ADD ./deploy /app
WORKDIR /app
RUN pip3 install -r requirements.txt
RUN ls -al

RUN chown root:$user /app/flag.txt

# RUN
EXPOSE $port

ENTRYPOINT ["python3"]
CMD ["main.py"]