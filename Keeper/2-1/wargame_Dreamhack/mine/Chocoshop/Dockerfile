FROM python:3.7-alpine

# ENV
ENV APP_USER dreamhack
ENV APP_PORT 5000

# SET challenges
COPY . /app
WORKDIR /app

# install flask, redis
RUN adduser --disabled-password $APP_USER && pip install flask pyjwt redis  && chown $APP_USER:$APP_USER /app && apk add --update redis && \
    rm -rf /var/cache/apk/* && \
    mkdir /data && \
    chown -R redis:redis /data && \
    sed -i 's#logfile /var/log/redis/redis.log#logfile ""#i' /etc/redis.conf && \
    sed -i 's#daemonize yes#daemonize no#i' /etc/redis.conf && \
    sed -i 's#dir /var/lib/redis/#dir /data#i' /etc/redis.conf && \
    echo -e "# placeholder for local options\n" > /etc/redis-local.conf && \
    echo -e "include /etc/redis-local.conf\n" >> /etc/redis.conf

# RUN
USER $APP_USER
EXPOSE $APP_PORT

ENTRYPOINT ["/bin/sh"]
CMD ["-c", "redis-server &\nflask run -h 0.0.0.0"]

