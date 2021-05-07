FROM gcc:latest
WORKDIR /my-game

build:
    COPY src src
    COPY Makefile Makefile
    RUN make
    RUN make run
    RUN make install
    SAVE ARTIFACT bin /bin AS LOCAL build/bin

docker:
    COPY +build/bin bin
    ENTRYPOINT ["/my-game/bin/hello"]
    SAVE IMAGE ngs-mygame:latest
