FROM docker.io/library/alpine:latest AS build
COPY comp2.c config.mk Makefile /
RUN <<EOT
  printf 'https://dl-cdn.alpinelinux.org/alpine/edge/testing\n' \
    >> /etc/apk/repositories
  apk -U upgrade
  apk add cproc musl-dev pdpmake
  ln -fs cproc /usr/bin/cc
  ln -s pdpmake /usr/bin/make
  make
EOT
FROM scratch
COPY --from=build comp2 /
ENTRYPOINT ["/comp2"]
