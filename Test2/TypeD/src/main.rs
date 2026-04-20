use std::io::prelude::*;
use std::net::TcpListener;

fn main() {
    let listener = TcpListener::bind("0.0.0.0:8080").unwrap();
    println!("Rust server on 8080...");

    for stream in listener.incoming() {
        let mut stream = stream.unwrap();
        
        let response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 11\r\n\r\nHello Rust!";
        stream.write_all(response.as_bytes()).unwrap();
        stream.flush().unwrap();
    }
}