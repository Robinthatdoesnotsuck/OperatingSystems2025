FROM golang

WORKDIR /app

COPY . .

RUN go get -d -v ./...

RUN go build -o api.o .

EXPOSE 8000

CMD ["./api"]