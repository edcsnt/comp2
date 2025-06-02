FROM docker.io/library/alpine:latest AS build
RUN <<EOT
apk update
apk upgrade
apk add gcc make musl-dev
make
EOT
COPY comp2.c Makefile .
FROM scratch
STOPSIGNAL SIGTERM
COPY --from=build comp2 .
ENTRYPOINT ["./comp2"]
