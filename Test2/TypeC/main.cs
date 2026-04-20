using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program {
    static void Main() {
        TcpListener server = new TcpListener(IPAddress.Any, 8080);
        server.Start();
        Console.WriteLine("C# server on 8080...");

        while (true) {
            using TcpClient client = server.AcceptTcpClient();
            using NetworkStream stream = client.GetStream();

            string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 9\r\n\r\nHello C#!";
            byte[] msg = Encoding.UTF8.GetBytes(response);
            stream.Write(msg, 0, msg.Length);
        }
    }
}