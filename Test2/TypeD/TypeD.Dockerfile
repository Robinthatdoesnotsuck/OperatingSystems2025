FROM rockylinux:latest

RUN cargo build --release

COPY --from=builder /app/target/release/my_http_server .