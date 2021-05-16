FROM barichello/godot-ci:latest
WORKDIR /my-game

build:
    COPY src src
    RUN mkdir -v -p build
    RUN cd src && mkdir web && godot --export HTML5 web/index.html && mv web ../build
    RUN ls -lah . src build build/web
    SAVE ARTIFACT build  AS LOCAL build

docker:
    COPY +build/web web
    ENTRYPOINT ["/my-game/bin/hello"]
    SAVE IMAGE ngs-mygame:latest
