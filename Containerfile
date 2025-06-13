FROM docker.io/library/alpine:latest AS build
COPY comp2.c config.mk Makefile .
RUN <<EOT
  apk -UX https://dl-cdn.alpinelinux.org/alpine/edge/testing/ upgrade
  apk -X https://dl-cdn.alpinelinux.org/alpine/edge/testing/ add \
    cproc \
    make \
    musl-dev
  make
EOT
FROM scratch
COPY --from=build comp2 .
ENTRYPOINT ["/comp2"]
