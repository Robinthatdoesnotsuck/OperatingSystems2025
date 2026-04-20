FROM golang

WORKDIR /app

## Copy dependencies
COPY go.mod go.sum ./
## Install dependencies
RUN go mod download
# Copy project
COPY *.go ./
# Copmpile project or bundle it
RUN CGO_ENABLED=1 GOOS=linux go build -o /my-app
# Change user
USER appUser
# Run whatever you need
ENTRYPOINT ["/my-app"]
